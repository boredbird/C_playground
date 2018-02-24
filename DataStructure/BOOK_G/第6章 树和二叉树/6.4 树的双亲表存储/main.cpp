//��������������main����

#include "C6-4.H"

void main (){

   int i;
   PTree T,p;
   TElemType e,e1;
   InitTree(&T);
   TElemType cache;
   char select;
   printf("\n��ʼ���ɹ�!\n");
/*�������˵�*/
  while(1) {
    printf("\n**************************************************************\n");
	printf("��ѡ�����(�밴����ָʾ���������ִ�Сд)��\n");
    printf("a.�����¶�����    ");
    printf("b.ȡ������ֵ     ");
    printf("c.˫�׽���ֵ     ");
    printf("d.�������    \n");
    printf("e.��������        ");
    printf("f.ɾ������         ");
	printf("g.��ĳ���ĳ���   ");
	printf("h.��ĳ����¸��ֵ�\n");
	printf("i.���Ƿ�Ϊ��    ");
	printf("j.�������         ");
    printf("k.�滻����е�ֵ   ");
	printf("q.�˳�����\n");
	printf("**************************************************************\n");
    printf("�������ѡ��: ");
	scanf("%c",&select);
         switch(select) {
         case 'a': printf("\n���洴���¶�����\n");
	             CreateTree(&T);
			     if(!TreeEmpty(T))printf("\n�����������ɹ�\n");
			     else printf("\n����������ʧ��\n");
                 break;
         case 'b': 
			     if(!TreeEmpty(T)){
				 printf("\n�������ĸ��ڵ��ֵ��");
			 	 printf("%c",Root(T));
				 }
			     else
				 printf("\n��Ϊ�գ��޷���ȡ�����!");
			     printf("\n");
	             getchar();
                 break;
         case 'c':
			 if(!TreeEmpty(T)){
			     printf("\n������Ҫ����˫�׽��ֵ�Ľ��ֵ��");
			     getchar();	
			 	 cache=getchar();
				 if(Root(T)==cache)
					 printf("�Բ�����������Ǹ��ڵ㣬��û��˫�׽ڵ�\n");
    			 else
				 {
					 printf("\n���");
				     printf("%c",cache);
				     printf("��˫�׽����:");
					 cache=Parent(T,cache);
				     if(cache){printf("%c\n",cache);}
				     else{printf("δ�ҵ��ýڵ�ĸ��ڵ�\n");}
				 }
			 }
			 else printf("��Ϊ�գ��޷�����!");
				 getchar();
				 break;
         case 'd': 
			 if(!TreeEmpty(T)){
				 printf("\n������ȣ�");
	             printf("%d",TreeDepth(T));
				 printf("\n");
			 }
			 else printf("��Ϊ�գ��޷�����!");
				 getchar();
                 break;
		 case 'e':
			 if(!TreeEmpty(T)){ 
                 InitTree(&p);
				 printf("��p��ʼ���ɹ�! ");
                 CreateTree(&p);
				 printf("����ǰ�������ԭ��t:\n");
				 TraverseTree(T);
				 printf("����p�嵽��T�У�������T��p��˫�׽�� �������: ");
				 scanf("%c%d%*c",&e,&i);
				 InsertChild(&T,e,i,p);
				 Print(T);
			   }
			   else {
			       printf("δ�ҵ��������������ȴ�����������!\n");
			   }
	             break;
         case 'f': 
			     if(!TreeEmpty(T)){
				     printf("ɾ�����н��e�ĵ�i��������������e: ");
					 getchar();
					 e=getchar();
                     printf("ɾ�����н��e�ĵ�i��������������i: ");
                     scanf("%d",&i);
                     DeleteChild(&T,e,i);
					 printf("ɾ����Ľ��Ϊ:  ");
                     Print(T);
				 }
			     else
					 printf("��Ϊ�գ��޷�����!");
    			     printf("\n");
				     getchar();
                     break; 
	    	case 'g':
			 if(!TreeEmpty(T))
			 {
				 printf("������Ҫ���ҵĽڵ㣺");
				 getchar();
				 cache=getchar();
				 printf("�ڵ�");
				 printf("%c",cache);
				 printf("�ĳ���Ϊ�� ");
				 if(LeftChild(T,cache))
					 printf("%c",LeftChild(T,cache));
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
			 if(!TreeEmpty(T))
			 {
				 printf("������Ҫ���ҵĽڵ㣺");
				 getchar();
				 cache=getchar();
				 printf("�ڵ�");
				 printf("%c",cache);
				 printf("����һ���ֵ�Ϊ�� ");
				 if(RightSibling(T,cache))
					 printf("%c",RightSibling(T,cache));
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
			if(TreeEmpty(T))
				printf("������Ϊ��!!!");
			else
				printf("�������ǿ�!!!");
			getchar();
			break;
		case 'j':
			 if(!TreeEmpty(T))
			 {
				printf("����������Ϊ��");
                TraverseTree(T);
			 }
			 else
			 {
				 printf("��Ϊ�գ��޷�����!");
			 }
			 getchar();
             break;
         case 'k': 
			 if(!TreeEmpty(T)){
				 printf("����������Ľ��Ϊ :\n");
				 TraverseTree(T);
				 printf("��������޸ĵĽ���ֵ: ");
				 getchar();
				 e=getchar();
                 printf("��������޸ĵĽ�����ֵ: ");
				 getchar();
				 e1=getchar();
				 Assign(&T,e,e1);
				 printf("��������޸ĺ�����Ľ��Ϊ:\n");
				 TraverseTree(T);
				 }
			     else
				 printf("\n��Ϊ�գ��޷���ȡ�����!");
			     printf("\n");
	             getchar();
                 break;
		case 'q': 
			DeleteChild(&T,Root(T),0);
			exit(0);
			break;
		default:
			 printf("�����޷�ʶ������������!!!\n");
			 break;
      }//switch
	  }//while
}//main