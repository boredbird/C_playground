//��������������main����

#include "C6-6.H"

void main (){

   int i;
   BiPTree T,p,q;
   TElemType e1,e2;
   InitBiTree(&T);
   e1=Root(T);
   char select;
   printf("\n��ʼ���ɹ�!\n");

  while(1) {
    printf("\n**************************************************************\n");
	printf("��ѡ�����(�밴����ָʾ���������ִ�Сд)��\n");
    printf("a.�����¶�����    ");
    printf("b.ȡ���ڵ��ֵ     ");
    printf("c.˫�׽���ֵ     ");
    printf("d.�������    \n");
    printf("e.���뺢��        ");
    printf("f.�������         ");
	printf("g.��ڵ������   ");
	printf("h.��ڵ���Һ���\n");
	printf("i.��ڵ�����ֵ�  ");
	printf("j.��ڵ�����ֵ�   ");
	printf("k.�������         ");
	printf("l.�������      \n");
	printf("m.�������        ");
	printf("n.�������         ");
	printf("o.�������Ƿ�Ϊ��   ");
    printf("p.�滻�ڵ��е�ֵ  \n");
	printf("q.�˳�����\n");
	printf("**************************************************************\n");
    printf("�������ѡ��: ");
	scanf("%c",&select);
         switch(select) {
         case 'a': printf("\n���水�������д����¶�������'#'��ʾ�սڵ㣬Ҷ�ӽ��Ҳ��Ҫ����\n");
	             CreateBiTree(&T);
			     if(!BiTreeEmpty(T))printf("\n�����������ɹ�\n");
			     else printf("\n����������ʧ��\n");
				 getchar();
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
			 	 e1=getchar();
				 if(Root(T)==e1)
					 printf("�Բ�����������Ǹ��ڵ㣬��û��˫�׽ڵ�\n");
    			 else
				 {
					 printf("\n���");
				     printf("%c",e1);
				     printf("��˫�׽����:");
					 e2=Parent(T,e1);
				     if(e2){printf("%c\n",e2);}
				     else{printf("δ�ҵ��ýڵ�ĸ��ڵ�\n");}
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
                 InitBiTree(&p);
				 printf("��p��ʼ���ɹ�! ");
                 printf("\n���������д����¶�����,����������Ϊ��,'#'��ʾ�սڵ�,Ҷ�ӽ��Ҳ��Ҫ����\n");
                 CreateBiTree(&p);
				 if(p->rchild!=NULL)
				 {
					 printf("��������ʧ��!��������������Ϊ��!");
					 getchar();
					 break;
				 }
				 printf("����ǰ���������ԭ��T:\n");
				 LevelOrderTraverse(T);
				 printf("\n����p�嵽��T�У�������T��p��˫�׽��: ");
				 getchar();
				 e1=getchar();
				 printf("����p�嵽��T�У�������T��p���������(0:����������;1:����������): ");
				 scanf("%d",&i);
				 q=Point(T,e1);
				 InsertChild(q,i,p);
				 printf("����󣬲��������T:\n");
				 LevelOrderTraverse(T);
			   }
			   else {
			       printf("δ�ҵ��������������ȴ�����������!\n");
			   }
			   getchar();
	           break;
         case 'f': 
			     if(!BiTreeEmpty(T)){
				     printf("ɾ��ǰ,��������Ľ��Ϊ:  ");
                     LevelOrderTraverse(T);
					 printf("\nɾ�����н��e�ĵ�i��������������e: ");
					 getchar();
					 e1=getchar();
					 printf("\nɾ�����н��e�ĵ�i��������������i(i=0:ɾ����������i=1:ɾ��������): ");
					 getchar();
					 scanf("%d",&i);
					 q=Point(T,e1);
                     DeleteChild(q,i);
					 printf("ɾ����Ĳ�������Ľ��Ϊ:  ");
                     LevelOrderTraverse(T);
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
				    e1=getchar();
				    printf("�ڵ�");
				    printf("%c",e1);
				    printf("������Ϊ�� ");
				    if(LeftChild(T,e1))
						printf("%c",LeftChild(T,e1));
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
				 e1=getchar();
				 printf("�ڵ�");
				 printf("%c",e1);
				 printf("���Һ���Ϊ�� ");
				 if(RightChild(T,e1))
					 printf("%c",RightChild(T,e1));
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
			    	 e1=getchar();
			    	 printf("�ڵ�");
			    	 printf("%c",e1);
			    	 printf("�����ֵ�Ϊ�� ");
				     if(LeftSibling(T,e1))
				 	 printf("%c",LeftSibling(T,e1));
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
				 e1=getchar();
				 printf("�ڵ�");
				 printf("%c",e1);
				 printf("�����ֵ�Ϊ�� ");
				 if(RightSibling(T,e1))
					 printf("%c",RightSibling(T,e1));
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
			if(!BiTreeEmpty(T))
			 {
				printf("����������Ϊ��");
                PreOrderTraverse(T);
			 }
			 else
			 {
				 printf("��Ϊ�գ��޷�����!");
			 }
			 getchar();
             break;
	    case 'l':
			if(!BiTreeEmpty(T))
			 {
				printf("����������Ϊ��");
                InOrderTraverse(T);
			 }
			 else
			 {
				 printf("��Ϊ�գ��޷�����!");
			 }
			 getchar();
             break;
		case 'm':
			if(!BiTreeEmpty(T))
			 {
				printf("����������Ϊ��");
                PostOrderTraverse(T);
			 }
			 else
			 {
				 printf("��Ϊ�գ��޷�����!");
			 }
			 getchar();
             break;
        case 'n':
			if(!BiTreeEmpty(T))
			 {
				printf("����������Ϊ��");
                LevelOrderTraverse(T);
			 }
			 else
			 {
				 printf("��Ϊ�գ��޷�����!");
			 }
			 getchar();
             break;
        case 'o':
			if(BiTreeEmpty(T))
				printf("������Ϊ��!!!");
			else
				printf("�������ǿ�!!!");
			getchar();
			break;
         case 'p': 
			 if(!BiTreeEmpty(T))
			 {
				 printf("����������Ľ��Ϊ :\n");
				 LevelOrderTraverse(T);
				 printf("\n��������޸ĵĽ���ֵ: ");
				 getchar();
				 e1=getchar();
				 q=Point(T,e1);
                 printf("��������޸ĵĽ�����ֵ: ");
				 getchar();
				 e2=getchar();
				 Assign(q,e2);
				 printf("��������޸ĺ�����Ľ��Ϊ:\n");
				 LevelOrderTraverse(T);
			 }
			 else
				 printf("\n��Ϊ�գ��޷���ȡ�����!");
			 printf("\n");
	         getchar();
             break;
		case 'q': exit(0);	break;
		default:
			 printf("�����޷�ʶ������������!!!\n");
			 break;
      }//switch
	  }//while
}//main
