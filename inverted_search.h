#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>

/* defining macros */
#define FAILURE   -1
#define SUCCESS    0
#define FNAME_SIZE 15
#define WORD_SIZE 10
#define FILE_EMPTY -2
#define FILE_NOTAVAILABLE -3
#define REPEATATION -4

/* Structure for file list */
typedef char data_t;
typedef struct file_node
{
	data_t file_name[FNAME_SIZE];
	struct file_node *link;

}Flist;

/* Structure for link table */
typedef struct linkTable_node
{
	int word_count;
	data_t file_name[FNAME_SIZE];
	struct linkTable_node *table_link;
}Ltable;

/* structure to store word count */
typedef struct word_node
{
	int file_count;
	data_t word[WORD_SIZE];
	Ltable *Tlink;
	struct word_node *link;

}Wlist;

/* To create a list to store exixting file names */
int to_create_list_of_files(Flist **f_head, char *name);

/* to create a database of words in existing files */
void create_database(Flist *f_head, Wlist *head[]);

/* to read the contents of a file */ 
Wlist *read_datafile(Flist *file, Wlist *head[], char *filename);

/* to create word_list */
int insert_at_last(Wlist **head, data_t *data);

/* to update linktable of every word */
int update_link_table(Wlist **head);

/* to update word count and file name of a word */
int update_word_count(Wlist ** head, char * file_name);

/* print_word_count */
int print_word_count(Wlist *head);

/* to searching a word in database */
void search(Wlist *head, char *word);

/* to display the contents of database */
void display_database( Wlist *head[] );

/* to save database in a file */
void save_database( Wlist *head[]);

/* to write database contents to the file */
void write_databasefile(Wlist *head, FILE* databasefile);

/* to update database with new file contents */
void update_database( Wlist *head[], Flist **f_head);

/* to check if the given file has contents */
int isFileEmpty(char *filename);

/* to validate files in CLA and save in file list */
int file_validation_n_file_list(Flist **f_head, char *argv[]);

#endif
