//��������������main����

#include "C6-2.H"

void main (){

  BiTree T,T1,p;
  TElemType e,parent;
  int LoR;
  TElemType node[NUM_OF_NODE]; 
  char select;
  //BiTNode p;
  /*��ʼ���������*/
  if(InitBiTree(T))printf("\n��ʼ���ն������ɹ�!!!\n\n");
	
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
	printf("o.����ݹ����     ");
	printf("p.�޸Ľ��ֵ\n");
	printf("q.�˳�����\n");
	printf("**************************************************\n");
    printf("�������ѡ��: ");
	scanf("%c",&select);
         switch(select) {
         case 'a': printf("\n���洴���¶�����\n");
	    		 DeleteBiTree(&T);
    		     printf("�������������봴����������ÿ�������Ӷ�Ҫ���óɿո��'#'����\n");
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
				 printf("��Ϊ�գ��޷���ȡ�����!\n");
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
                     e=Parent(T,e);
				     if(e){printf("%c\n",e);}
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
			 }
			 else printf("��Ϊ�գ��޷�����!");
			 printf("\n");
			 getchar();
             break;
		 case 'e': 
			   if(!BiTreeEmpty(T))
			   {
			     printf("\n�������ڲ���Ķ�����\n"); 
			     if(InitBiTree(T1)) 
				  printf("�������������봴����������ÿ�������Ӷ�Ҫ���óɿո��'#'����\n");
	             CreateBiTree(&T1);
	             if(!(T1->rchild))
				 {
					 printf("\n�����������ɹ�!\n");
	                 printf("��������Ҫ����Ľڵ�ֵ: ");
                     getchar();
	                 e=getchar();
 				     printf("�뽫������Ϊ����������������0,��Ϊ������������1��");
				     scanf("%d",&LoR);
	                 p=Point(T,e);
					 printf("\n����ǰ��ԭ���������������У�");
				     PreOrderTraverse(T);
	                 InsertChild(p,LoR,T1);
	                 printf("\n���������ɹ�");
				     printf("\n������¶��������������У�");
				     PreOrderTraverse(T);
				 }// if(!(T1->rchild))
			     else 
				 {
				   printf("\n����ʧ��!�´����Ķ�������������Ϊ��!,�������������!");
				 } 
			   }//if(!BiTreeEmpty(T))
			   else {
			       printf("δ�ҵ��������������ȴ�����������!\n");
			   }
			   getchar();
	           break;
         case 'f': 
			     if(!BiTreeEmpty(T)){
				     printf("ɾ������ǰ��ǰ��������Ϊ��");
				     PreOrderTraverse(T);					 
					 printf("\n����Ҫ�����Ľ���ֵ��");
					 getchar();
				     e=getchar();
				     p=Point(T,e);
                     printf("Ҫɾ��������������0,ɾ��������������1:");
				     scanf("%d",&LoR);
				     if(p->lchild&&LoR==0||p->rchild&&LoR==1)DeleteChild(p,LoR);
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
				 printf("���Һ���Ϊ�� ");
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
				 else printf("��Ϊ�գ��޷�����!");
				 printf("\n");
	             getchar();
				 break;
         case 'm': printf("\n����������У�");
	             if(!BiTreeEmpty(T)) InOrderTraverse(T);
				 else printf("��Ϊ�գ��޷�����!");
				 printf("\n");
	             getchar();
                  break;
		 case 'n': printf("\n����������У�");
	             if(!BiTreeEmpty(T)) PostOrderTraverse(T);
				 else printf("��Ϊ�գ��޷�����!");
				 printf("\n");
				 getchar();
                 break;
		 case 'o': printf("\n����������У�");
	             if(!BiTreeEmpty(T)) LevelOrderTraverse(T);
				 else printf("��Ϊ�գ��޷�����!");
				 printf("\n");
				 getchar();
                 break;
		case 'p':
			if(!BiTreeEmpty(T))
			{
				printf("\n�޸�ǰ�����������:");
				LevelOrderTraverse(T);
				printf("\n������޸ĵĽ��ֵ");
				getchar();
				parent=getchar();
				p=Point(T,parent);
             	printf("\n������޸ĵĽ����ֵ");
				getchar();
				e=getchar();
				Assign(p,e);
				printf("\n�޸ĺ󣬲��������:");
				LevelOrderTraverse(T);
			}
		    else printf("��Ϊ�գ��޷�����!");
		    printf("\n");
			getchar();
			break;
		case 'q': 
			DeleteBiTree(&T);
			exit(0);
			break;
		default:
			 printf("�����޷�ʶ������������!!!\n");
			 break;
      }//switch
	  }//while
}//main
