#include "inverted_search.h"

void search(Wlist *head, char *word)
{
	//check hashtable[index] is null 
    if(head == NULL)
    {
	    printf("Index is empty, search not possible\n");
		return ;
    }

    //traverse through the main node
	while(head != NULL)
	{
		//compare the words are same
		if(!strcmp(head->word , word))
		{
			if(head->file_count == 1)
			{
				printf("Word [%s] is present in %d file\n", word, head->file_count);
			}
			else
			{
				printf("Word [%s] is present in %d files\n", word, head->file_count);
			}
		    
		    //print the sub node info, traverse through the sub node
		    Ltable *Thead = head->Tlink;
		    while(Thead != NULL)
		    {
				if(Thead->word_count == 1)
				{
					printf("In file : %s		%d time\n",Thead->file_name, Thead->word_count);
				}
				else
				{
					printf("In file : %s		%d times\n",Thead->file_name, Thead->word_count);
				}
				Thead = Thead -> table_link;
		   	}
			return ;
	   	}
	   	head = head->link; //move to next node, if words are not same
    }
    printf("Word [%s] not present in any file\n", word);
}
