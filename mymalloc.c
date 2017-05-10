#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define malloc(x) mymalloc(x,__FILE__,__LINE__)
#define free(x) myfree(x,__FILE__,__LINE__)


static char myblock[5000];


typedef struct node
{    
    int size;
    struct node * next;
    struct node * prev;    
} node;


// Note: these variable are declared out of the
// function on purpose so that the value is not kept
// the same for increment

int index=0;
int v=0;	//Basically another index
int byteAlloc; //To store the ByteSize allocation for myfree() func
int byteAlloc2;
int freebyteAllocChecker=0;		//To keep a check on the indexes when
								//derefenced and it can be overwritten
int freefunclastmemaddress;
int freefuncIndexBookKeeping=0;

node* mem2 = NULL;			// this node is set to a current node in mymalloc

void* mymalloc( size_t size2, char *file , int line )
{	
int check=0;
int nullChecker=0;
byteAlloc = size2;
byteAlloc2 = byteAlloc2 + size2;
node* mem = NULL;			
mem = (node*)&myblock[index];		// points to the address of the mem alloc
mem2=mem;							// mem2 set to mem so we can point to prev easily

v=index;		// First mymalloc starts with 0 so this keeps up with the index counting
				//and from this we know where to point in the array

if(mem<myblock[0])printf("out of bounds\n");
 
if(size2>5000 || byteAlloc2>5000)
{
	fprintf(stderr,"Allocation size exceeds available memory",file,line);
}
if(size2<=0)
{
	fprintf(stderr,"invalid allocation size",file,line);
}


if(check==0)
{ 
	while( v<index+size2 )
	{
		if(freebyteAllocChecker==1) goto ab3; //this step only runs if myfree() was called
		
		if((node*)myblock[v]==NULL)	//Checks NULL in the array
		{		
			ab3:
			check=1;
			node* mem = (node*)&myblock[v];
			mem->size=1;		// char 1-like the array.Byte alloc
			//v++;
		}
		else
		{
			nullChecker=1;	//If not null a check is turned on through thise
			goto ab4;
		}
		v++;
	}
mem = (node*)&myblock[index];		// pointing just like above
									// but if this step is ignore program
									// should work but might cause problem
}
ab4:		// goes to this step if not NULL
if(nullChecker==1)
{
	//if(freebyteAllocChecker==1)goto ab2;
	
	while(myblock[index]!=NULL)
	{
		index++;
	}
	
	if(freebyteAllocChecker==1)
	{
		index=index-freefuncIndexBookKeeping;
		freebyteAllocChecker=0;
	}
	mem->next = (node*)&myblock[index];	

}
else
{	
	check=0;
	nullChecker=0;
	index=v;
	mem->next = (node*)&myblock[index];
	myblock[index+1]=NULL;
}

freebyteAllocChecker = 0;
	return (void*)mem; //This is returning the main spot for the allocation/stored info
}

void* myfree(char *a, char *file , int line )
{	
int check=0;
node* mem = a;
node* mem3 = mem2;
if(mem==0)// Points to 0 error or &adress error
fprintf(stderr,"Invalid[due to &address or 0]\n",file,line);
mem=NULL;
mem=mem3; // points to that pointer
//printf("index %d\n",index);
index=index-byteAlloc;	
//if(index==0)
//fprintf(stderr,"exiting...memory not allocated by malloc or cant free any memory\n");

if(index>0)check=1;

if(index<0)
{if(check==0)
fprintf(stderr,"exiting...cant free any memory\n",file,line);
}

freefuncIndexBookKeeping = index;
freebyteAllocChecker = 1;
//printf("free(): %d\n",index);
return (void*)mem;
}
