/*main5-2.cpp ����bo5-2.cpp��������*/
#include <stdio.h>

#include "C5-2.h"

int main()
{
    TSMatrix A, B, C;

    printf("��������A: ");
    CreateSMatrix( &A );
    PrintSMatrix( A );

    printf("�ɾ���A���ƾ���B: ");
    CopySMatrix(A, &B);
    PrintSMatrix( B );

    printf("\n���پ���B��:\n");
    DestroySMatrix( &B );
    PrintSMatrix( B );

    printf("\n��������B2:(�����A���С�������ͬ���С��зֱ�Ϊ%d,%d)\n",A.mu, A.nu);
    CreateSMatrix( &B );
    PrintSMatrix( B );

    printf("\n����C1(A+B): ");
    AddSMatrix(A, B, &C);
    PrintSMatrix( C );

    DestroySMatrix( &C );
    printf("\n����C2(A-B): ");
    SubtSMatrix(A, B, &C);
    PrintSMatrix( C );
    DestroySMatrix( &C );

    printf("\n����C3(A��ת��): ");
    TransposeSMatrix(A, &C);
    PrintSMatrix( C );

    DestroySMatrix( &A );
    DestroySMatrix( &B );
    DestroySMatrix( &C );

    printf("\n��������A2: ");
    CreateSMatrix( &A );
    PrintSMatrix( A );
    printf("��������B3:(����Ӧ�����A2��������ͬ=%d)\n", A.nu);

    CreateSMatrix( &B );
    PrintSMatrix( B );
    printf("����C5(A*B): ");
    MultSMatrix(A, B, &C);
    PrintSMatrix( C );

    DestroySMatrix( &A );
    DestroySMatrix( &B );
    DestroySMatrix( &C );

	return 0;
}