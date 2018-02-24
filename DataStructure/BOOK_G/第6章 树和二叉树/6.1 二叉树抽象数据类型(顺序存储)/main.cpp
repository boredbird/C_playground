//��������������main����

#include "C6-1.H"

void main (){
   SqBiTree T,T1;
   int LoR;
   TElemType e,e1;
   char select;
   position pos;
   InitBiTree(T);
   printf("\n˳���������ʼ���ɹ�!\n");
/*�������˵�*/
  while(1) {
    printf("\n**************************************************\n");
	printf("��ѡ�����(�밴����ָʾ���������ִ�Сд)��\n");
    printf("a.�����¶�����    ");
    printf("b.ȡ���ڵ��ֵ     ");
    printf("c.˫�׽���ֵ     ");
    printf("d.�������\n");
    printf("e.��������        ");
    printf("f.ɾ������         ");
	printf("g.��ĳ�ڵ�����   ");
	printf("h.��ĳ�ڵ��Һ���\n");
	printf("i.��ĳ�ڵ����ֵ�  ");
	printf("j.��ĳ�ڵ����ֵ�   ");
	printf("k.�������Ƿ�Ϊ��   ");
	printf("l.�������\n");
    printf("m.�������        ");
	printf("n.�������         ");
	printf("o.��������ڵ�ֵ   ");
	printf("p.�滻�ڵ��е�ֵ\n");
	printf("q.�˳�����\n");
	printf("**************************************************\n");
    printf("�������ѡ��: ");
	scanf("%c",&select);
         switch(select) {
         case 'a': printf("\n���洴���¶�����\n");
	             CreateBiTree(T);
			     if(!BiTreeEmpty(T))printf("\n�����������ɹ�\n");
			     else printf("\n����������ʧ��\n");
                 break;
         case 'b': 
			     if(!BiTreeEmpty(T)){
				 printf("\n�������ĸ��ڵ��ֵ��");
			 	 printf("%c",Root(T));
				 }
			     else
				 printf("\n��Ϊ�գ��޷���ȡ�����!");
			     printf("\n");
	             getchar();
                 break;
         case 'c':
			 if(!BiTreeEmpty(T)){
			     printf("\n������Ҫ����˫�׽��ֵ�Ľ��ֵ��");
			     getchar();	
			 	 e=getchar();
				 if(Root(T)==e)
					 printf("�Բ�����������Ǹ��ڵ㣬��û��˫�׽ڵ�\n");
    			 else
				 {
					 printf("\n���");
				     printf("%c",e);
				     printf("��˫�׽���ǣ�  ");					 
                     e1=Parent(T,e);
				     if(e1){printf("%c\n",e1);}
				     else{printf("δ�ҵ��ýڵ�ĸ��ڵ�\n"); }
				 }
			 }
			 else printf("��Ϊ�գ��޷�����!");
				 getchar();
				 break;
         case 'd': 
			 if(!BiTreeEmpty(T)){
				 printf("\n������ȣ�");
	             printf("%d",BiTreeDepth(T));
				 printf("\n");
			 }
			 else printf("��Ϊ�գ��޷�����!");
				 getchar();
                 break;
		 case 'e':
			   if(!BiTreeEmpty(T)){
			     printf("\n�������ڲ���Ķ�����\n"); 
				 InitBiTree(T1);
			     if(!BiTreeEmpty(T)) 
				     printf("��ʼ���������ɹ������������д����¶�������������ԭ�����ཻ�����ҽڵ����Ϊ��!\n");
	             CreateBiTree(T1);
	             if(T1[2]!=' ')printf("\n�����������ɹ�!\n");
	             else printf("\n����ʧ��!�´����Ķ�������������Ϊ��!");
 				 printf("\n����Ҫ�����Ľ��Ģٽڵ�,�������(����������'0';����������'1')����ֵ��\n");
				 scanf("%d %d",&e,&LoR);
	             InsertChild(T,e,LoR,T1);
	             printf("\n���������ɹ�\n");
				 getchar();
				 printf("\n�¶��������������У�");
				 PreOrderTraverse(T);
			   }
			   else {
			       printf("δ�ҵ��������������ȴ�����������!\n");
			   }
	             break;
         case 'f': 
			     if(!BiTreeEmpty(T)){
					 printf("ɾ������ǰ��ǰ��������Ϊ��");
				     PreOrderTraverse(T);
					 printf("\n����Ҫ�����Ľ��Ģٲ��,�����,�������(����������'0';����������'1')����ֵ��\n");
					 scanf("%d %d %d",&pos.level,&pos.order,&LoR);
				     DeleteChild(T,pos,LoR);
				     printf("ɾ��������ǰ��������Ϊ��");
				     PreOrderTraverse(T);
				 }
			     else
					 printf("��Ϊ�գ��޷�����!");
    			     printf("\n");
				     getchar();
                     break; 
		 case 'g':
			 if(!BiTreeEmpty(T))
			 {
				 printf("������Ҫ���ҵĽڵ㣺");
				 getchar();
				 e=getchar();
				 printf("�ڵ�");
				 printf("%c",e);
				 printf("������Ϊ�� ");
				 if(LeftChild(T,e))
					 printf("%c",LeftChild(T,e));
				 else 
					 printf("  ��!");
			 }
			 else
			 {
				 printf("��Ϊ�գ��޷�����!");
			 }
			 getchar();
             break;
        case 'h':
			 if(!BiTreeEmpty(T))
			 {
				 printf("������Ҫ���ҵĽڵ㣺");
				 getchar();
				 e=getchar();
				 printf("�ڵ�");
				 printf("%c",e);
				 printf("������Ϊ�� ");
				 if(RightChild(T,e))
					 printf("%c",RightChild(T,e));
				 else 
					 printf("  ��!");
			 }
			 else
			 {
				 printf("��Ϊ�գ��޷�����!");
			 }
			 getchar();
              break;
		case 'i':
			 if(!BiTreeEmpty(T))
			 {
				 printf("������Ҫ���ҵĽڵ㣺");
				 getchar();
				 e=getchar();
				 printf("�ڵ�");
				 printf("%c",e);
				 printf("�����ֵ�Ϊ�� ");
				 if(LeftSibling(T,e))
					 printf("%c",LeftSibling(T,e));
				 else 
					 printf("  ��!");
			 }
			 else
			 {
				 printf("��Ϊ�գ��޷�����!");
			 }
			 getchar();
             break;
		case 'j':
             if(!BiTreeEmpty(T))
			 {
				 printf("������Ҫ���ҵĽڵ㣺");
				 getchar();
				 e=getchar();
				 printf("�ڵ�");
				 printf("%c",e);
				 printf("�����ֵ�Ϊ�� ");
				 if(RightSibling(T,e))
					 printf("%c",RightSibling(T,e));
				 else 
					 printf("  ��!");
			 }
			 else
			 {
				 printf("��Ϊ�գ��޷�����!");
			 }
			 getchar();
             break;
	    case 'k':
			if(BiTreeEmpty(T))
				printf("������Ϊ��!!!");
			else
				printf("�������ǿ�!!!");
			getchar();
			break;
		case 'l': printf("\n����������У�");
			     if(!BiTreeEmpty(T))PreOrderTraverse(T);
				 else printf(" ��Ϊ�գ��޷�����!");
				 printf("\n");
	             getchar();
				 break;
         case 'm': printf("\n����������У�");
	             if(!BiTreeEmpty(T)) InOrderTraverse(T);
				 else printf(" ��Ϊ�գ��޷�����!");
				 printf("\n");
	             getchar();
                  break;
		 case 'n': printf("\n����������У�");
	             if(!BiTreeEmpty(T))PostOrderTraverse(T);
				 else printf(" ��Ϊ�գ��޷�����!");
				 printf("\n");
				 getchar();
                 break;
		case 'o':
			if(!BiTreeEmpty(T)){
			printf("��㡢������������������\n");
			Print(T);
			}
			else
			{
				 printf("��Ϊ�գ��޷�����!");
			 }
			getchar();
			break;
		case 'p':
			if(!BiTreeEmpty(T)){
				printf("�޸�ǰ,����������Ϊ��");
				LevelOrderTraverse(T);
				printf("\n����Ҫ����ֵ�Ľ��Ģٲ��,���������ֵ,����ֵ��\n");
				scanf("%d %d %c",&pos.level,&pos.order,&e);
				Assign(T,pos,e);
				printf("�޸ĺ󣬲���������Ϊ��");
				LevelOrderTraverse(T);
				getchar();
			}
			else
			{
				 printf("��Ϊ�գ��޷�����!");
			 }

			getchar();
			break;
		case 'q':
			DestroyBiTree(T);
			exit(0);
			break;
		default:
			 printf("�����޷�ʶ������������!!!\n");
			 break;
      }//switch
	  }//while
}//main