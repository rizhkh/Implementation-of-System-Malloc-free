/*
*
*This file is intended to count the number of occurrences
*of each word present in the passed file
*
*The intended output is a list of all the words present
*and the occurrence for each individual word
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

//struct to hold what we need
struct Node {
	char word[50];//array to hold word
	int occurrence;//number of occurrence of word
	struct Node * next;//ptr to next node 
};

int main (int argc, char ** argv)
{
	char input = NULL;//char read in
	char wordInput[50] = NULL;//store word for later comparison
	struct Node counter = NULL;//first word in linked list
	struct Node curr = NULL;//curr ptr in linked list for searching purposes
	int numChar = 0;//num of char in wordInput
	
	FILE * fp = fopen(argv[1], "r");//ptr to file read
	
	if (fp == NULL)
	{
		printf("File failed to open, Line 36\n");
		exit(-1);
	}
	
	while ((input = fgetc(fp) != EOF)//read input; continue if not EOF
	{
		if (isalnum(input))//if char is alphanumeric
		{
			//make lowercase before storing
			if (isalpha(input))
			{
				input = tolower(input);
			}
			
			wordInput[numChar] = input;
			numChar++;
		}else if (input == NULL)
		{
			printf("Character read is NULL, exiting at line 46\n");
			exit(-1);
		}
		else
		{
			//char is not alphanumeric
			wordInput[numChar] = '\0';//end of word
			numChar = 0;//reset for next word, if exists
			
			//send word to linked list; if word exists, update occurrence
			
			if (counter == NULL)//first occurrenc of linked list
			{
				counter->word = wordInput;//send word to list
				counter->occurrenc = 0;//first occurrence 
				counter->next = NULL;
			}else
			{
				//list has words, check if input exists
				curr = counter;
				while (curr != NULL)//loop through list
				{
					int result = strcmp(curr->word, wordInput);
					if (result == 0)//strings are the exact same
					{
						curr->occurrence++;//new occurrence
					}else
					{
						//strings are not the same, check next if exists
						
						if (curr->next == NULL)
						{
							//if at the end, this is new word, insert into list
							curr = curr->next
							
							curr->word = wordInput;
							curr->occurrence = 0;//first occurrence
							curr->next = NULL;
						}
						
						curr = curr->next;
					}
				}
			}
		}
	}
	
	fclose(fp);//close file ptr
}
