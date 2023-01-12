#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dec=0 , bin , rem ,num ,base=1;

    printf("Enter the binary number : ");
    scanf("%d", &bin);

    num=bin;
    while(bin!=0)
    {
        rem=bin%10;
        dec=dec+rem*base;
        bin=bin/10;
        base=base*2;
    }
    printf("the equivalant of binary %d is %d ", num ,dec);


    return 0;
}
