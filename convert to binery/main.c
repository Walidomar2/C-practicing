#include <stdio.h>
#include <stdlib.h>

void Print_Bin(unsigned int number,unsigned int size);

int main()
{
    unsigned int num=0;
    unsigned int temp;
    unsigned int counter=0;

    printf("Enter the number : ");
    scanf("%d", &num);

    temp=num;

    while(temp!=0)
    {
        temp=temp/2;
        counter++;

    }
    Print_Bin(num,counter);

    return 0;
}

void Print_Bin(unsigned int number,unsigned int size)
{
    unsigned int arr[size];
    unsigned int index=0;
    int i=0;

    while(number!=0)
    {
        if(number%2==0)
        {
            arr[index]=0;
        }
        else
        {
            arr[index]=1;
        }

        number=number/2;
        index++;

    }


    printf("The binery equivlent:0b");

    for(i=size-1; i>=0; i--)
    {
        printf("%i", arr[i]);
    }
}
