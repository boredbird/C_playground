/*表7.11:整个程序为一条宏指令*/
#include<stdio.h>
#define DEMAND(ID) \
int main( )\
{\
	printf(#ID"\n");\
	printf("*******\n");\
    return 0;\
}
DEMAND(deliver)              //一条命令
