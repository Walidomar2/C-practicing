#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2;
    printf("Please enter the two numbers\n");
    scanf("%d %d", &num1, &num2);

    if(num2 < 0)
    {
        while(num2!=0)
        {
            num1--;
            num2++;
        }
    }
    else
    {
        while(num2!=0)
        {
            num1++;
            num2--;
        }
    }

    printf("the sum is %d",num1);
    return 0;
}
