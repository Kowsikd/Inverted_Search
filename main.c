#include "inverted_search.h"

int main(int argc, char *argv[] )
{
	system("clear");
	
	Wlist *head[27] = {NULL};

	//validation, check CLA is passed or not
	if( argc <= 1 )
	{
		printf("Enter the valid no. of arg\n");
		printf("./a.out file1.exe file2.txt .......\n");
		return 0;
	}	

	//validate the file
	//declare th head pointer for the file node
	Flist *f_head = NULL ;

	file_validation_n_file_list(&f_head , argv);
	
	if(f_head  == NULL)
	{
		
		printf("\nNo files are available in file List\n");
		printf("Hence the process got terminated\n");
		return 1;
	}

	int choice;
	char ch = 'y';
	while(ch == 'y' || ch == 'Y')
	{
		printf("\nselect your choice\n1. create database\n2. display database\n3. update database\n4. search\n5. save database\n6. exit\nenter your choice: ");
		if(scanf("%d", &choice) == 0)
		{
			choice = 0;
			__fpurge(stdin);
		}

		switch (choice)
	    {
	    case 1 :
			create_database(f_head, head);
			printf("Database created successfully\n");
	   		break;
		case 2 :
			display_database(head);
			break;
		case 3 :
			update_database(head, &f_head);
			break;
		case 4 :
			char word[WORD_SIZE];
			int index;
			printf("\nEnter the word to search: ");
			scanf(" %s", word);
			index = tolower(word[0]) % 97;
			search(head[index], word);
			break;
		case 5 :
			save_database(head);
			break;
		case 6 :
			return SUCCESS;
		default:
			printf("Invalid choice!\nEnter a valid choice!\n");
	    }

		do
		{
			printf("\nDo you want to continue?\nEnter y/Y to continue and n/N to exit: ");
			scanf(" %c", &ch);
		}while(ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');
	}
	
	return SUCCESS;
}
