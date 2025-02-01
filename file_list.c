#include "inverted_search.h"

int file_validation_n_file_list(Flist **f_head, char *argv[])
{
	int i = 0, empty ,ret_val;
	while(argv[i] != NULL)
	{
		if(strcmp(argv[i], "./a.out") == 0)
		{
			i++;
			continue;
		}

		empty = isFileEmpty(argv[i]);

		if(empty == FILE_NOTAVAILABLE)
		{
			printf("File : %s is not available\n", argv[i]);
	   		printf("Hence we are not adding that file\n");
			i++;
			continue;
		}
		else if (empty == FILE_EMPTY)
		{
	    	printf("File : %s is not having any contents in it\n" , argv[i]);
	    	printf("Hence we are not adding that file\n");
			i++;
			continue;
		}
		else
		{
			//file is a valid file
			ret_val = to_create_list_of_files(f_head , argv[i]);
			if(ret_val == SUCCESS)
			{
				printf("Successful: inserting the file %s into file List \n", argv[i]);
				if(argv[i + 1] == NULL)
				{
					return SUCCESS;
				}
			}
			else if(ret_val == REPEATATION)
			{
				printf("The file %s is repeated\nHence we are not adding the file to file list \n", argv[i]);
			}
			else
			{
				printf("Failure in inserting file in file_list\n");
			}
			i++;
			continue;
		}
	}
	return FAILURE;
}

//this function is used to check the file availability and check for file content
int isFileEmpty(char *filename)
{
	FILE *fptr = fopen(filename , "r");

	//check file is present or not
	if( fptr == NULL)
	{
		return FILE_NOTAVAILABLE;
	}

	//check for the content
	fseek(fptr , 0 , SEEK_END);
	if( ftell(fptr) == 0 )
	{
		return FILE_EMPTY;
	}
	
	return SUCCESS;
}

int to_create_list_of_files(Flist **f_head , char *name)
{
	Flist *new = malloc(sizeof(Flist));
	if(new == NULL)
	{
		return FAILURE;
	}

	strcpy(new->file_name, name);
	new->link = NULL;

	if(*f_head == NULL)
	{
		*f_head = new;
		return SUCCESS;
	}

	Flist *temp = *f_head;
	Flist *prev;

	while(temp != NULL)
	{
		if(strcmp(name, temp->file_name) == 0)
		{
			return REPEATATION;
		}
		prev = temp;
		temp = temp->link;
	}
	
	prev->link = new;
	return SUCCESS;
}
