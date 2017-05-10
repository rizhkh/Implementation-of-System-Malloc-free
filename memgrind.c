

void testcaseA()
{
	void *testArray[1000];
	int a;
	for(a=0; a<1000 ; a++)
	{
		testArray[a]= malloc(1);
		//testArray[a]= mymalloc(1);
	}
	
	int b;
	for(b=1000; b>0 ; b--)
	{
		//printf("freeing %d :\n",b);
		free(testArray[b]);
		//myfree(testArray[b]);
	}	
	
}

void testcaseB()
{
	int r;
	for(r=0;r<100;r++)
	{
		char *acd = malloc(1);
		free(acd);
		//char *acd = mymalloc(1);
		//myfree(acd);
	}	
}
/*
void testcaseB()
{
static long long averageB;
int workloadCounter = 0;
for(workloadCounter= 1; workloadCounter<=100; workloadCounter++)
{
struct timeval tv;
suseconds_t begin;
gettimeofday(&tv, NULL);
begin = tv.tv_usec;
int r;
for(r=0;r<100;r++)
{
char *acd = malloc(1);
free(acd);
} 
suseconds_t end;
  gettimeofday(&tv , NULL);
end = tv.tv_usec;
average = (end - begin) + average;
}
average = (unsigned long int)average/100;

 printf("Average time of workload B: %ld microseconds\n" , averageB);
}
*/

void testcaseC()
{
//Randomly assuming it means getting random mem locations and random 
//calls to mallocs and free

int counterTestCaseC=0;
int indexforTestCase=0;
int mallocIncrementer=0;
int freeincrementer=0;

int mallocbytes=1000;
int two = 2;
int location = rand(); 		//LOCATION OF MEM INDEX IS RANDOM BECAUSE
							//IT SAYS IN THE PROJECT					
int randomValue = rand()%2;		// this only prints 1 or 0 	

char arrayTest[1000];	//need this for random mallocing of bytes
 
//location=location+indexforTestCase; //This is for randomly taking 
									//random location on mem index

									
while(mallocbytes>0)
{	
//mallocbytes--;	//because of this the loops work 1000 times
	randomValue = rand()%2; // this only prints 1 or 0 
							 // random selection
									 
	if(randomValue==0) 	//If 0 then ccalls malloc
	{
	counterTestCaseC++;
	arrayTest[indexforTestCase] = malloc(1);
	//arrayTest[indexforTestCase] = mymalloc(1);
	indexforTestCase++;
	mallocIncrementer++;
	}									 
	else
	{	
	free(arrayTest[indexforTestCase]);
	//myfree(arrayTest[indexforTestCase]);
	indexforTestCase--;			
	}		
	/*
	if(mallocIncrementer==1000)
	{
		if(indexforTestCase>0)
		{
			while(indexforTestCase>0)
			{
				free(arrayTest[indexforTestCase]);
				//myfree(arrayTest[indexforTestCase]);
				indexforTestCase--;
			}
		}
	}	*/
	
	mallocbytes--;
}

}


void testcaseD()
{	
//Randomly assuming it means getting random mem locations and random 
//calls to mallocs and free
int indexforTestCase=0;
int mallocIncrementer=0;
int freeincrementer;
int byteSize = rand()%(65);	
int byteSizeCounter;// = rand()%(65+1-0);
int lastByterecorded;	
int mallocbytes=1000;
int location = rand(); //location on mem
int random = rand()%2; // this only prints 1 or 0 
							 // random selection
char arrayTest[1000];	//need this for random mallocing of bytes

location=location+indexforTestCase; //This is for randomly taking 
									//random location on mem index
while(mallocbytes>0)
{
mallocbytes--;	//because of this the loops work 1000 times
int random = rand()%(1+1-0); // this only prints 1 or 0 
							 // random selection
byteSize = rand()%(65+1-0);				 	
	if(byteSizeCounter>5000)break;//	goto ab5;
	
	//if(byteSizeCounter<0)byteSizeCounter=0;
	
	if(random==0) 	//If 0 then ccalls malloc
	{	lastByterecorded = byteSize;
		byteSizeCounter = byteSizeCounter +	byteSize;
		lastByterecorded = byteSize;	
		arrayTest[indexforTestCase] = malloc(byteSize);
		//arrayTest[indexforTestCase] = mymalloc(byteSize);
		indexforTestCase++;
		mallocIncrementer++;
	}									 
	else ///
	{	
		free(arrayTest[indexforTestCase]);	
		//myfree(arrayTest[indexforTestCase]);			
		if(indexforTestCase<0)indexforTestCase=0;			
		indexforTestCase--;	
	}
		/*	
	if(mallocIncrementer==1000)
	{
		if(indexforTestCase>0)
		{
			while(indexforTestCase>0)
			{
				free(arrayTest[indexforTestCase]);
				//myfree(arrayTest[indexforTestCase]);
				indexforTestCase--;
			}
		}
	} */					 
}

}

void testcaseE()
{
	
//allocated memory when free  goes back
//and checks index if free allocates there	

char *a = malloc(1);
char *b = malloc(10);
char *c = malloc(1);
char *e = malloc(5);
char *f = malloc(1);
free(c);
free(e);
free(f);
char *g = malloc(1);
char *h = malloc(1);
char *i = malloc(1);
	
}

int timeCalc(int a)
{
long long average = 0;
int workloadCounter = 0;
for(workloadCounter= 1; workloadCounter<=100; workloadCounter++)
{
struct timeval tv;
suseconds_t begin;
gettimeofday(&tv, NULL);
begin = tv.tv_usec;

if(a==1)testcaseA();

if(a==2)testcaseB();

if(a==3)testcaseC();
//if(a==4)testcaseD();
if(a==5)testcaseE();
//if(a==3)testcaseF();


	suseconds_t end;
  gettimeofday(&tv , NULL);
end = tv.tv_usec;
average = (end - begin) + average;
}
average = average/100;

 printf("Average time of workload  : %ld microseconds\n" , average);
return average; 
}

int main()
{

//int a = timeCalc(1);
//int b = timeCalc(2);
int c = timeCalc(3);
//int d = timeCalc(4);
//int e = timeCalc(5);
//int f = timeCalc(6);

//printf("Average time for TestCase 1  : %ld microseconds\n" , a);



// printf("Average time of workload  : %ld microseconds\n" , a);

//printf("\n -Test case a- \n");
//testcaseA();
//printf("\n -Test case b- \n");
//testcaseB();
//printf("\n -Test case c- \n");
//testcaseC();
//printf("\n -Test case D- \n");
//testcaseD();
//printf("\n -Test case E- \n");
//testcaseE();


return 1;	

}