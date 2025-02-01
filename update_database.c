#include"inverted_search.h"

void update_database(Wlist *head[], Flist **f_head)
{
    //read the filename from the user
    char file[FNAME_SIZE];
    char *file_name[2] = {NULL};
    printf("\nenter the filename: ");
    scanf(" %s", file);
    file_name[0] = file;

    int ret_val = file_validation_n_file_list(f_head, file_name);

    if(ret_val == SUCCESS)
    {
        Flist *temp = *f_head;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        create_database(temp, head);
        printf("Database updated successfully\n");
    }
    else
    {
        printf("\nFailed to update database\n");
    }
}
