//��������������main����

#include "C6-5.H"

void main (){

   int i;
   CSTree T,p,q;
   TElemType e,e1;
   InitTree(&T);
   char select;
   printf("\n��ʼ���ն������ɹ�!!!\n\n");
	
/*�������˵�*/
  while(1) {
    printf("\n**************************************************\n");
	printf("��ѡ�����(�밴����ָʾ���������ִ�Сд)��\n");
    printf("a.��������       ");
    printf("b.ȡ���ڵ��ֵ     ");
    printf("c.�������       ");
	printf("d.�������\n");
    printf("e.�������       ");
    printf("f.˫�׽���ֵ     ");
    printf("g.�������       ");
    printf("h.���뺢��\n");
    printf("i.ɾ������       ");
    printf("j.������           ");
	printf("k.��ĳ�ڵ㳤��   ");
	printf("l.��ĳ�ڵ���һ���ֵ�\n");
	printf("m.�Ƿ����       ");
	printf("n.�޸Ľڵ�ֵ       ");
	printf("q.�˳�����\n");
	printf("**************************************************\n");
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
			 printf("��Ϊ�գ��޷���ȡ�����!");
			 printf("\n");
	         getchar();
             break;
         case 'c': 
			 printf("\n����������У�");
			 if(!TreeEmpty(T))    PreOrderTraverse(T);
			 else printf("��Ϊ�գ��޷�����!");
			 printf("\n");
	         getchar();
			 break;
		case 'd': 
			 printf("\n����������У�");
	         if(!TreeEmpty(T))    PostOrderTraverse(T);
			 else printf("��Ϊ�գ��޷�����!");
			 printf("\n");
			 getchar();
             break;
        case 'e':
			printf("\n����������У�");
	         if(!TreeEmpty(T))    LevelOrderTraverse(T);
			 else printf("��Ϊ�գ��޷�����!");
			 printf("\n");
	         getchar();
             break;
         case 'f':
			 if(!TreeEmpty(T)){
			     printf("\n������Ҫ����˫�׽��ֵ�Ľ��ֵ��");
			     getchar();	
			 	 e=getchar();
				 if(Root(T)==e)
					 printf("�Բ�����������Ǹ��ڵ㣬��û��˫�׽ڵ�\n");
    			 else
				 {
					 printf("\n���%c��˫�׽���� �� ",e);					 
				     if(Parent(T,e)){printf("%c\n",Parent(T,e));}
				     else{printf("δ�ҵ��ýڵ�ĸ��ڵ�\n"); }
				 }
			 }
			 else printf("��Ϊ�գ��޷�����!");
				 getchar();
				 break;
         case 'g': 
			 if(!TreeEmpty(T)){
				 printf("\n������ȣ�");
	             printf("%d",TreeDepth(T));
				 printf("\n");
			 }
			 else printf("��Ϊ�գ��޷�����!");
				 getchar();
                 break;
		 case 'h': 
			   if(!TreeEmpty(T)){
			     printf("\n�������ڲ���Ķ�����p\n"); 
                 InitTree(&p);
	             CreateTree(&p);    
 				 printf("\n����p�嵽��T�У�������T��p��˫�׽�� �������: \n");
                 scanf("%c%d%*c",&e,&i);
 	             q=Point(T,e);
                 InsertChild(&T,q,i,p);
                 printf("�������������T: \n");
                 LevelOrderTraverse(T);
				 getchar();
			   }
			   else {
			       printf("δ�ҵ��������������ȴ�����������!\n");
			   }
	             break;
         case 'i': 
			     if(!TreeEmpty(T)){
					    printf("\nɾ����T�н��e�ĵ�i������");
						printf("\n����ڵ�e:");
						getchar();
						e=getchar();
						printf("����iֵ:");
						getchar();
						scanf("%d",&i);
						q=Point(T,e);
						DeleteChild(&T,q,i);
						printf("ɾ����������������T:\n");
                        LevelOrderTraverse(T);
				 }
			     else
					 printf("��Ϊ�գ��޷�����!");
    			     printf("\n");
				     getchar();
                     break;
		 case 'j':
			     if(!TreeEmpty(T)){
			         printf("\n��ȷ��Ҫ���/���ٶ�������y/n��:");
		    	     getchar();
				     e=getchar();
				     if(e=='y'||e=='Y')
					 {
					 DestroyTree(&T);//DeleteTree��ClearTre��DestroyTreee������ͬ
					 //tree=NULL;
                     printf("��ն������ɹ�!");
					 }
				     else if(e=='n'||e=='N')
						 printf("\n ���β������˳�������������!");
				     else
					     printf("\n ����ֵ�����˳����β���!");
				 }
				 else  
					 printf("��Ϊ�գ��޷�����!");
				     getchar();
                     break;
		 case 'k':
			 if(!TreeEmpty(T))
			 {
				 printf("������Ҫ���ҵĽڵ㣺");
				 getchar();
				 e=getchar();
				 printf("�ڵ�");
				 printf("%c",e);
				 printf("�ĳ���Ϊ�� ");
				 e1=LeftChild(T,e);
				 if(e1)
					 printf("%c",e1);
				 else 
					 printf("  ��!");
			 }
			 else
			 {
				 printf("��Ϊ�գ��޷�����!");
			 }
			 getchar();
             break;
		case 'l':
             if(!TreeEmpty(T))
			 {
				 printf("������Ҫ���ҵĽڵ㣺");
				 getchar();
				 e=getchar();
				 printf("�ڵ�");
				 printf("%c",e);
				 printf("�ĳ��ӵ���һ���ֵ�Ϊ�� ");
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
		case 'm':
			if(TreeEmpty(T))
				printf("������Ϊ��!!!");
			else
				printf("�������ǿ�!!!");
			getchar();
			break;
		 case 'n':
			 printf("\n ������޸ĵĽڵ�ֵ");
			 getchar();
			 e=getchar();
			 printf("\n ������ֵ");
			 getchar();
			 e1=getchar();
			 Assign(&T,e,e1);
			 printf("��������޸ĺ����T:\n");
			 LevelOrderTraverse(T);
		     printf("\n");
			 getchar();
			 break;
		case 'q':
            DestroyTree(&T);
			exit(0);	break;
		default:
			 printf("�����޷�ʶ������������!!!\n");
			 break;
      }//switch
	  }//while
}//main