#include "C6-3.H"

void main (){

  BiThrTree T,Thrt;//treeΪ��������ThrtΪͷ�ڵ�
  char select;
	
/*�������˵�*/
  while(1) {
    printf("\n**************************************************\n");
	printf("��ѡ�����(�밴����ָʾ���������ִ�Сд)��\n");
	printf("a.����������������������Ĺ����У�����������������\n");
    printf("b.����������������������Ĺ����У�����������������\n");
    printf("c.�������������ں�������Ĺ����У�����������������\n");
	printf("q.�˳�����\n");
	printf("**************************************************\n");
    printf("�������ѡ��: ");
	scanf("%c",&select);
         switch(select) {
		case 'a':
		      	printf("\n���洴���¶�����\n");
     	 	     printf("��ʾ: ���������������������ÿ���սڵ㶼Ҫ���ó�'#'���ţ�Ҷ�ӽڵ��ҲҪ��ӷ���'#'\n");	
			     CreateBiThrTree(&T);
			     PreOrderThreading(&Thrt,T);
				 printf("�������(���)����������:");
                 PreOrderTraverse_Thr(Thrt);
				 DestroyBiThrTree(&Thrt);
	             getchar();
                 break;
        case 'b':  
			 	printf("\n���洴���¶�����\n");
     	 	     printf("��ʾ: ���������������������ÿ���սڵ㶼Ҫ���ó�'#'���ţ�Ҷ�ӽڵ��ҲҪ��ӷ���'#'\n");	
			     CreateBiThrTree(&T);
			     InOrderThreading(&Thrt,T);
                 printf("�������(���)����������: ");
                 InOrderTraverse_Thr(Thrt);
                 DestroyBiThrTree(&Thrt);
				 printf("\n");
	             getchar();
				 break;
        case 'c':
				 printf("\n���洴���¶�����\n");
     	 	     printf("��ʾ: ���������������������ÿ���սڵ㶼Ҫ���ó�'#'���ţ�Ҷ�ӽڵ��ҲҪ��ӷ���'#'\n");	
			     CreateBiThrTree(&T);
		    	 PostOrderThreading(&Thrt,T);
				 printf("\n");
	             getchar();
				 break;
		case 'q': exit(0);
			     DestroyBiThrTree(&Thrt);
				 free(T);free(Thrt);
				 T=NULL;Thrt=NULL;
				break;
		default:
			 printf("�����޷�ʶ������������!!!\n");
			 break;
      }//switch
	  }//while
}//main