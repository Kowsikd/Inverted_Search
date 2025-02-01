#include "inverted_search.h"

extern char *fname;

int insert_at_last(Wlist **head, data_t *data)
{
	//printf("insert last\n");
	//create the main node ( word node)
	Wlist * new  = malloc(sizeof(Wlist));
	if( new == NULL )
		return FAILURE;

	//update the fields
	new -> file_count = 1 ;
	strcpy(new -> word , data);
	new -> Tlink = NULL;
	new -> link = NULL;

	//call fun() to crate or update sub node ( Ltable node )
	update_link_table(&new);
	if( *head == NULL )
	{
		*head = new;
		return SUCCESS;
	}
	//non empty, insert at last
	Wlist *temp = *head;
	//traverse though the main node
	while( temp -> link != NULL)
		temp = temp -> link;

	temp -> link = new ;
	return SUCCESS;
}

int update_link_table(Wlist **head)
{
	//craete sub node
	Ltable *new = malloc(sizeof(Ltable));
	if( new == NULL)
		return FAILURE;
	
	//update the fields
	new -> word_count = 1;
	strcpy(new -> file_name , fname);
	new -> table_link = NULL;

	(*head) -> Tlink = new;
	return SUCCESS;
}	   
