#include "inverted_search.h"

void save_database( Wlist *head[])
{
	//read a filename from the user
	char file_name[FNAME_SIZE];
	printf("\nenter the filename :");
	scanf("%s" , file_name);

	//open the file on write mdoe
	FILE *fptr = fopen(file_name , "w");

	//traverse though the hashtable
	for(int i =0 ; i < 27 ; i++)
	{
		if(head[i] != NULL )
		{
			write_databasefile(head[i] , fptr);
		}
	}
	printf("Database saved successfully\n");
}

void write_databasefile(Wlist *head, FILE *backupfile)
{
	int index = tolower(head->word[0]) % 97;
	while(head != NULL)
	{
		fprintf(backupfile, "In index [%d] word is [%s] and file count is %d\n", index, head->word, head->file_count);

		Ltable *temp = head->Tlink;
		while(temp != NULL)
		{
			fprintf(backupfile, "In file: %s word count is %d\n", temp->file_name, temp->word_count);
			temp = temp->table_link;
		}
		head = head->link;
		fprintf(backupfile, "\n");
	}
}
