#include<stdio.h>
int main()
{
    int score;
    char grade;
    printf("Please enter score:");
    scanf("%d",&score);
    if(score>100||score<0)
        printf("Input error!\n");
    else
    {
        switch(score/10)
        {
            case 10:
            case 9: grade='A'; break;
            case 8: grade='B'; break;
            case 7: grade='C'; break;
            case 6: grade='D'; break;
            case 5:
            case 4:
            case 3:
            case 2:
            case 1:
            case 0: grade='E';break; 
        }
        printf("%d--%c\n",score,grade);
    }
    return 0;
}