/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Walid Omar
 * @brief          : Multiplication of 2 Dimensional Arrays
 ******************************************************************************
 **/

#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int main()
{
    int Farr[MAX][MAX];
    int Sarr[MAX][MAX];
    int Resarr[MAX][MAX];
    int Frows,Fcols,Srows,Scols,sum=0;
    int i,j,k;

    printf("Enter the number of rows and columns of the first matrix : " );
    scanf("%d %d", &Frows, &Fcols);

    printf("Enter the elements of the first matrix \n");
    for(i=0; i<Frows; i++)
    {
        for(j=0; j<Fcols; j++)
        {
        scanf("%d", &Farr[i][j]);
        }
    }

     printf("Enter the number of rows and columns of the second matrix : " );
    scanf("%d %d" ,&Srows ,&Scols);

    if(Fcols!=Srows)
    {
    printf("The number of columns of first matrix must be equal to the number of row of second matrix \n");
    }

    else {

    printf("Enter the elements of the second matrix \n");
    for(i=0;i<Srows;i++)
        for(j=0;j<Scols;j++)
        scanf("%d", &Sarr[i][j]);

    for(i=0;i<Frows;i++)
    {
        for(j=0;j<Frows;j++)
        {
            for(k=0;k<Fcols;k++){
                sum+=Farr[i][k]*Sarr[k][j];
            }
                Resarr[i][j]=sum;
                sum=0;
        }
    }

    printf("The result matrix = \n");
    for(i=0;i<Frows;i++)
    {
        for(j=0;j<Frows;j++)
        printf("%d ", Resarr[i][j]);

        printf("\n");
    }

  }
    return 0;
}
