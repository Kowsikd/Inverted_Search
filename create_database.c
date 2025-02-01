#include "inverted_search.h"

char *fname;

void create_database(Flist *f_head, Wlist *head[])
{
	// traverse through the file LL
	while(f_head != NULL)
	{
		read_datafile(f_head, head, f_head->file_name);
		f_head = f_head->link;
	}
}

Wlist *read_datafile(Flist *file, Wlist *head[], char *filename)
{
	//open the file on read mode
	FILE *fptr = fopen(filename, "r");

	//declare an array to store the fetched word from the file
	char word[WORD_SIZE];
	fname = filename;

	int flag;
	int index;

	while(fscanf(fptr, "%s", word) != EOF)
	{
		flag = 1; //words are same or not

		//calculate the index
		index = (tolower(word[0]) % 97);

		//other than alphabets
		if(!(index >= 0 && index <= 25))
		{
			index = 26;
		}

		if(head[index] == NULL)
		{
			insert_at_last(&head[index], word);
		}
		else
		{
			//traverse though the main node and check words are same or not
			Wlist *temp = head[index];
			while(temp != NULL)
			{
				//compare words
				if(strcmp(temp->word, word) == 0)
				{
					if(update_word_count(&temp, filename) == SUCCESS)
					{
						flag = 0; //words are same 
						break;
					}
					else
					{
						printf("Failure\n");
					}
				}
				temp = temp->link;
			}
			if(flag == 1) //words are not same
			{
				//create new main node and sub node , perform insert at last
				if(insert_at_last(&head[index], word) != SUCCESS) 
				{
					printf("New word insert Failure\n");
				}
			}
		}
	}
}

int update_word_count(Wlist **head, char *file_name)
{
	Ltable *temp = (*head)->Tlink;
	Ltable *prev;

	while(temp != NULL)
	{
		if(strcmp(temp->file_name, file_name) == 0)
		{
			(temp->word_count)++;
			return SUCCESS;
		}
		prev = temp;
		temp = temp->table_link;
	}

	Ltable *new = malloc(sizeof(Ltable));
	if(new == NULL)
	{
		return FAILURE;
	}

	//update fields
	((*head)->file_count)++;
	strcpy(new->file_name, file_name);
	new->word_count = 1;
	new->table_link = NULL;
	
	prev->table_link = new;
	return SUCCESS;
}
