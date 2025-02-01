#include "inverted_search.h"

void display_database(Wlist *head[])
{
	printf("\n[index]		[word]				file_count 		filename			word_count\n");
	printf("------------------------------------------------------------------------------------------------------------------\n");
	for(int i = 0; i < 27; i++)
	{
		if(head[i] != NULL)
		{
			print_word_count(head[i]);
		}
	}
}

int print_word_count(Wlist *head)
{
	//traverse thrugh the main node ( word node )
	while(head != NULL)
	{
		printf("[%d]		[%s]				%d			", tolower(head -> word [ 0] )% 97 , head -> word , head -> file_count );

		//traverse through the sub node
		Ltable * Thead = head -> Tlink;
		int count = 0;
		while(Thead)
		{
			if(count == 0)
			{
				printf("%s   			%d\n", Thead -> file_name, Thead -> word_count);
				count++;
			}
			else
			{
				printf("									%s   			%d\n", Thead -> file_name, Thead -> word_count);
			}
			Thead = Thead -> table_link; //move to next node
		}
		head = head -> link; //move to next main node
	}
	printf("------------------------------------------------------------------------------------------------------------------\n");
}
