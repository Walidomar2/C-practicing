/******************************************************
** @ author: Walid Omar Khalaf
** @ brief : A Database Program for Managing Student Records
**
** This C program implements a simple database system for managing student records
** using a double linked list. It provides various functionalities to create, search,
** delete, edit, update scores, get the list size, delete the entire list, and display
** the list of students.
**
** @ Global Variables:
** - ErrorState_t stateFlag: Keeps track of the current error state.
** - List_t list_1: Represents the main linked list for storing student records.
**
** @ Functions:
** - void getStudentData(ListEntry_t *info): Helper function to input student information..
** - Provides a menu-driven interface for different database operations.
** - Uses a while loop for continuous interaction until the user decides to exit.
**
** @ Database Operations:
** - 1. Create a new student entity
** - 2. Search for a student by ID
** - 3. Delete a student's data by ID
** - 4. Edit a student's data by ID
** - 5. Update a student's scores by ID
** - 6. Get the size of the student list
** - 7. Delete the entire student list
** - 8. Display the list of students
******************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"
#include "Config.h"
#include "ErrorState.h"
#include "school.h"

//static u8 list_number;
ErrorState_t stateFlag=OUT_OF_RANGE_ERR;
List_t list_1;
u32 sizeResult;

void getStudentData(ListEntry_t *info);

int main()
{
    printf("Hello\n");
    stateFlag = List_create(&list_1);

    while(1)
    {
        u32 choice=0;
        printf("**********************************************\n");
        printf("\nPlease select an option \n");
        printf("To create a new student entity enter --> 1 \n");
        printf("To make a search by the ID enter --> 2 \n");
        printf("To delete a student's data enter --> 3 \n");
        printf("To edit a student's data --> 4 \n");
        printf("To update a student's degrees --> 5 \n");
        printf("To get a list size enter --> 6\n");
        printf("To delete your list enter --> 7\n");
        printf("To display a list enter --> 8\n");

        scanf("%d",&choice);

        printf("----------------------------------------------------------\n");

        switch(choice)
        {
            case 1:
                {
                    ListEntry_t newStudent;
                    getStudentData(&newStudent);
                    stateFlag = List_insertStudent(&list_1,&newStudent);
                    break;
                }
            case 2:
                {
                    u8 tempID=0;
                    ListNode_t *tempNode=NULL;
                    fflush(stdin);
                    printf("Enter student ID for searching :");
                    scanf("%u",&tempID);
                    fflush(stdin);
                    stateFlag = List_searchStudent(&list_1,tempID,&tempNode);
                    break;
                }
            case 3:
                {
                    u8 deleted_ID=0;
                    fflush(stdin);
                    printf("Enter student ID for deleting :");
                    scanf("%u",&deleted_ID);
                    fflush(stdin);
                    stateFlag = List_deleteStudent(&list_1,deleted_ID);
                    break;
                }
            case 4:
                {
                    u8 edit_ID=0;
                    fflush(stdin);
                    printf("Enter student ID for deleting :");
                    scanf("%u",&edit_ID);
                    fflush(stdin);
                    stateFlag = List_editStudent(&list_1,edit_ID);
                    break;
                }
            case 5:
                {
                    u8 updated_ID=0;
                    fflush(stdin);
                    printf("Enter student ID for updating Scores :");
                    scanf("%u",&updated_ID);
                    fflush(stdin);
                    stateFlag = List_updateScore(&list_1,updated_ID);
                    break;
                }
            case 6:
                {
                    stateFlag = List_listSize(&list_1,&sizeResult);
                    printf("number of students in the list %d\n",sizeResult);
                    break;

                }
            case 7:
                {
                    stateFlag = List_freeList(&list_1);
                    break;
                }
            case 8:
                {
                    stateFlag = List_printList(&list_1);
                    break;
                }
            default :
                {
                    printf("Please Enter a valid number\n");

                }
        }
    }
    return 0;
}

void getStudentData(ListEntry_t *info)
{
    printf("Please Enter student Info\n");
    fflush(stdin);

    printf("Student ID : \n");
    scanf("%u",&(info->ID));
    fflush(stdin);

    printf("Student age : \n");
    scanf("%u",&(info->age));
    fflush(stdin);

    printf("Student Phone Number : \n");
    gets(info->data.phone);
    fflush(stdin);

    printf("Student Name : \n");
    gets(info->Name);
    fflush(stdin);

    printf("Student Address : \n");
    gets(info->data.address);
    fflush(stdin);
}
