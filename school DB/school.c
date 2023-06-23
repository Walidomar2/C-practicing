#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "std_types.h"
#include "Config.h"
#include "ErrorState.h"
#include "school.h"

ErrorState_t  List_create(List_t* pl)
{
    ErrorState_t state = OUT_OF_RANGE_ERR;

    if(pl == NULL)
    {
       state = NULL_PTR;
    }
    else
    {
        pl->pHead=NULL;
        pl->pTail=NULL;
        pl->ListSize=0;
        printf("List Created\n");
        state = SUCCESSFUL;
    }

    return state;
}

ErrorState_t  List_insertStudent( List_t* pl ,const ListEntry_t * pe)
{
    ErrorState_t state = OUT_OF_RANGE_ERR;

    if(pl == NULL)
    {
       state = NULL_PTR;
    }
    else
    {
        ListNode_t *TempNode=NULL;
        TempNode=(ListNode_t *)malloc(sizeof(ListNode_t));

        TempNode->pNext=NULL;
        TempNode->pPrev=NULL;

        TempNode->entry.data.phone=pe->data.phone;
        strcpy(TempNode->entry.data.address,pe->data.address);

        TempNode->entry.degress.arabic_deg=0;
        TempNode->entry.degress.english_deg=0;
        TempNode->entry.degress.math_deg=0;

        TempNode->entry.age = pe->age;
        TempNode->entry.ID = pe->ID;
        strcpy((TempNode->entry.Name),(pe->Name));

        /*Case the list is empty*/
        if(pl->pHead == NULL)
        {
            pl->pHead= TempNode;
            pl->pTail=TempNode;
        }
        else
        {
            TempNode->pNext=NULL;
            pl->pTail->pNext=TempNode;
            TempNode->pPrev=pl->pTail;
            pl->pTail = TempNode;
        }

        (pl->ListSize)++;
        printf("Node inserted \n");
        state = SUCCESSFUL;
    }
    return state;
}

ErrorState_t  List_searchStudent(const List_t* pl , u8 copy_u8ID,ListNode_t ** pFoundStudent )
{
    ErrorState_t state = OUT_OF_RANGE_ERR;

    if(pl==NULL)
    {
        state = NULL_PTR;
    }
    else
    {
        if(pl->pHead==NULL)
        {
          printf("List is Empty\n");
        }
        else
        {
            u8 flag=0;
            ListNode_t *TempNode=pl->pHead;
            while(TempNode!=NULL)
            {
                if(TempNode->entry.ID == copy_u8ID)
                {
                    *pFoundStudent = TempNode;
                    state = SUCCESSFUL;
                    flag=1;
                    break;
                }
                else
                {
                    TempNode=TempNode->pNext;
                }
            }

            if(flag==0)
            {
                *pFoundStudent = NULL;
                printf("Student Not found\n");
            }
            else
            {
                printf("Student %u found \n",copy_u8ID);
            }

            state = SUCCESSFUL;
        }
    }

    return state;
}

ErrorState_t  List_deleteStudent(List_t* pl , u8 copy_u8ID)
{
     ErrorState_t state = OUT_OF_RANGE_ERR;

    if(pl==NULL)
    {
        state = NULL_PTR;
    }
    else
    {
        if(pl->pHead==NULL)
        {
          printf("There is no Nodes to delete \n");
        }
        else
        {
            // if i have only one node
            if(pl->ListSize==1)
            {
                ListNode_t *currentNode=pl->pHead;
                free(currentNode);
                pl->pHead=NULL;
                pl->pTail=NULL;
            }
            else
            {
                int counter = pl->ListSize;
                ListNode_t *NextNode=pl->pHead->pNext;
                ListNode_t *prevNode=pl->pHead;
                ListNode_t *currentNode=pl->pHead;

                while(counter!=0)
                {
                    if(currentNode->entry.ID == copy_u8ID)
                    {
                        if(counter == pl->ListSize)
                        {
                            pl->pHead=NextNode;
                            free(currentNode);
                            (pl->ListSize)--;
                            break;
                        }
                        else if(counter == 1)
                        {
                            prevNode->pNext=NextNode;
                            free(currentNode);
                            (pl->ListSize)--;
                            break;
                        }
                        else
                        {
                            prevNode->pNext=NextNode;
                            NextNode->pPrev=prevNode;
                            free(currentNode);
                            (pl->ListSize)--;
                            break;
                        }
                     }
                    else
                    {
                        prevNode=currentNode;
                        currentNode=NextNode;
                        NextNode=NextNode->pNext;
                        counter--;
                    }
                }

            }
            printf("Deleted SUCCESSFULL\n");
            state = SUCCESSFUL;
        }
    }
    return state;
}

ErrorState_t  List_editStudent(const List_t* pl , u8 copy_u8ID)
{
    ErrorState_t state = OUT_OF_RANGE_ERR;
    if(pl==NULL)
    {
        state = NULL_PTR;
    }
    else
    {
        ListNode_t *TempNode = NULL;
        List_searchStudent(pl,copy_u8ID,&(TempNode));

        char choice = 0;
        printf("IF you need to edit age enter 1 .. edit phone number enter 2 .. edit address enter 3 :");
        scanf("%c",&choice);

        switch(choice)
        {
            case 1:
                {
                    int newAge=0;
                    printf("Enter The new age :");
                    scanf("%d",&newAge);
                    TempNode->entry.age=newAge;
                    break;
                }
            case 2:
                {
                    unsigned int newPhoneNum=0;
                    printf("Enter The new Phone Number :");
                    scanf("%i",&newPhoneNum);
                    TempNode->entry.data.phone=newPhoneNum;
                    break;
                }
            case 3:
                {
                    char newAddress[ADRESSSIZE];
                    printf("Enter The new Phone Number :");
                    gets(newAddress);
                    strcpy(TempNode->entry.data.address,newAddress);
                    break;
                }

            default:
                {
                    printf("Try again");
                }
        }
        state = SUCCESSFUL;
    }
    return state;
}

ErrorState_t  List_updateScore(const List_t* pl , u8 copy_u8ID)
{
    ErrorState_t state = OUT_OF_RANGE_ERR;
    if(pl==NULL)
    {
        state = NULL_PTR;
    }
    else
    {
        ListNode_t *TempNode = NULL;
        List_searchStudent(pl,copy_u8ID,&(TempNode));

        printf("Enter the New Math Degree : ");
        scanf("%u",&(TempNode->entry.degress.math_deg));

        printf("Enter the New English Degree : ");
        scanf("%u",&(TempNode->entry.degress.english_deg));

        printf("Enter the New Arabic Degree : ");
        scanf("%u",&(TempNode->entry.degress.arabic_deg));

        state = SUCCESSFUL;
    }
    return state;
}

ErrorState_t  List_printList(const List_t* pl )
{
    ErrorState_t state = OUT_OF_RANGE_ERR;

    if(pl==NULL)
    {
        state = NULL_PTR;
    }
    else
    {

        if(pl->pHead==NULL)
        {
          printf("There is no Nodes to delete \n");
        }
        else
        {
            ListNode_t *TempNode=NULL;
            TempNode = pl->pHead;
            int i=0;
            for(i=1;i<=pl->ListSize;i++)
            {

                printf("Student Name :%s\n",TempNode->entry.Name);
                printf("Student ID :%u\n",TempNode->entry.ID);
                printf("Student age :%u\n",TempNode->entry.age);
                printf("Student phone:%i\n",TempNode->entry.data.phone);
                printf("Student Address :%s\n",TempNode->entry.data.address);
                printf("Student Math Degree :%u\n",TempNode->entry.degress.math_deg);
                printf("Student English Degree :%u\n",TempNode->entry.degress.english_deg);
                printf("Student arabic Degree :%u\n\n",TempNode->entry.degress.arabic_deg);

                TempNode=TempNode->pNext;
            }
            state = SUCCESSFUL;
        }
    }

    return state;
}

ErrorState_t  List_listSize(const List_t* pl,u32 * pSize)
{

      ErrorState_t state = OUT_OF_RANGE_ERR;

    if(pl == NULL)
    {
       state = NULL_PTR;
    }
    else
    {
        *pSize=pl->ListSize;
        state = SUCCESSFUL;
    }
    return state;
}


ErrorState_t  List_freeList(List_t* pl)
{
     ErrorState_t state = OUT_OF_RANGE_ERR;

    if(pl == NULL)
    {
       state = NULL_PTR;
    }
    else
    {
        ListNode_t *CurrentNode=pl->pHead;
        ListNode_t *NextNode=NULL;

        while(CurrentNode->pNext!=NULL)
        {
            NextNode=CurrentNode->pNext;
            free(CurrentNode);
            CurrentNode=NextNode;
        }
        pl->ListSize = 0;

        state = SUCCESSFUL;
    }
    return state;
}


