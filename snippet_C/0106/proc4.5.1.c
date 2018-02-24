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
        if(score>=90)
            grade='A';
        else if(score>=80)
            grade='B';
        else if(score>=70)
            grade='C';
        else if(score>=60)
            grade='D';
        else
            grade = 'E';
        printf("%d--%c\n",score,grade);
    }
    return 0;
}
