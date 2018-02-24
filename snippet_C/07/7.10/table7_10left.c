/*表7.10:宏可分多行定义*/
#include <stdio.h>
#define OUT(ID)  printf(#ID"\n");\
printf("*******\n");
int main( )
{	OUT(deliver)  
return 0;
}
