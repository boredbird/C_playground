//二叉树基本操作main函数

#include "C6-5.H"

void main (){

   int i;
   CSTree T,p,q;
   TElemType e,e1;
   InitTree(&T);
   char select;
   printf("\n初始化空二叉树成功!!!\n\n");
	
/*操作主菜单*/
  while(1) {
    printf("\n**************************************************\n");
	printf("请选择操作(请按下列指示操作，区分大小写)：\n");
    printf("a.创建新树       ");
    printf("b.取根节点的值     ");
    printf("c.先序遍历       ");
	printf("d.后序遍历\n");
    printf("e.层序遍历       ");
    printf("f.双亲结点的值     ");
    printf("g.树的深度       ");
    printf("h.插入孩子\n");
    printf("i.删除子树       ");
    printf("j.销毁树           ");
	printf("k.求某节点长子   ");
	printf("l.求某节点下一个兄弟\n");
	printf("m.是否空树       ");
	printf("n.修改节点值       ");
	printf("q.退出程序\n");
	printf("**************************************************\n");
    printf("输入你的选择: ");
	scanf("%c",&select);
         switch(select) {
         case 'a': printf("\n下面创建新二叉树\n");
	             CreateTree(&T);
			     if(!TreeEmpty(T))printf("\n创建二叉树成功\n");
			     else printf("\n创建二叉树失败\n");
                 break;
         case 'b': 
			 if(!TreeEmpty(T)){
				 printf("\n二叉树的根节点的值：");
			 	 printf("%c",Root(T));
			 }
		     else
			 printf("树为空，无法获取根结点!");
			 printf("\n");
	         getchar();
             break;
         case 'c': 
			 printf("\n先序遍历序列：");
			 if(!TreeEmpty(T))    PreOrderTraverse(T);
			 else printf("树为空，无法遍历!");
			 printf("\n");
	         getchar();
			 break;
		case 'd': 
			 printf("\n后序遍历序列：");
	         if(!TreeEmpty(T))    PostOrderTraverse(T);
			 else printf("树为空，无法遍历!");
			 printf("\n");
			 getchar();
             break;
        case 'e':
			printf("\n层序遍历序列：");
	         if(!TreeEmpty(T))    LevelOrderTraverse(T);
			 else printf("树为空，无法遍历!");
			 printf("\n");
	         getchar();
             break;
         case 'f':
			 if(!TreeEmpty(T)){
			     printf("\n请输入要查找双亲结点值的结点值：");
			     getchar();	
			 	 e=getchar();
				 if(Root(T)==e)
					 printf("对不起，您输入的是根节点，它没有双亲节点\n");
    			 else
				 {
					 printf("\n结点%c的双亲结点是 ： ",e);					 
				     if(Parent(T,e)){printf("%c\n",Parent(T,e));}
				     else{printf("未找到该节点的父节点\n"); }
				 }
			 }
			 else printf("树为空，无法操作!");
				 getchar();
				 break;
         case 'g': 
			 if(!TreeEmpty(T)){
				 printf("\n树的深度：");
	             printf("%d",TreeDepth(T));
				 printf("\n");
			 }
			 else printf("树为空，无法操作!");
				 getchar();
                 break;
		 case 'h': 
			   if(!TreeEmpty(T)){
			     printf("\n创建用于插入的二叉树p\n"); 
                 InitTree(&p);
	             CreateTree(&p);    
 				 printf("\n将树p插到树T中，请输入T中p的双亲结点 子树序号: \n");
                 scanf("%c%d%*c",&e,&i);
 	             q=Point(T,e);
                 InsertChild(&T,q,i,p);
                 printf("插入后层序遍历树T: \n");
                 LevelOrderTraverse(T);
				 getchar();
			   }
			   else {
			       printf("未找到主二叉树，请先创建主二叉树!\n");
			   }
	             break;
         case 'i': 
			     if(!TreeEmpty(T)){
					    printf("\n删除树T中结点e的第i棵子树");
						printf("\n输入节点e:");
						getchar();
						e=getchar();
						printf("输入i值:");
						getchar();
						scanf("%d",&i);
						q=Point(T,e);
						DeleteChild(&T,q,i);
						printf("删除子树后层序遍历树T:\n");
                        LevelOrderTraverse(T);
				 }
			     else
					 printf("树为空，无法操作!");
    			     printf("\n");
				     getchar();
                     break;
		 case 'j':
			     if(!TreeEmpty(T)){
			         printf("\n你确定要清空/销毁二叉树（y/n）:");
		    	     getchar();
				     e=getchar();
				     if(e=='y'||e=='Y')
					 {
					 DestroyTree(&T);//DeleteTree、ClearTre和DestroyTreee操作相同
					 //tree=NULL;
                     printf("清空二叉树成功!");
					 }
				     else if(e=='n'||e=='N')
						 printf("\n 本次操作已退出，请重新输入!");
				     else
					     printf("\n 输入值错误，退出本次操作!");
				 }
				 else  
					 printf("树为空，无法操作!");
				     getchar();
                     break;
		 case 'k':
			 if(!TreeEmpty(T))
			 {
				 printf("输入需要查找的节点：");
				 getchar();
				 e=getchar();
				 printf("节点");
				 printf("%c",e);
				 printf("的长子为： ");
				 e1=LeftChild(T,e);
				 if(e1)
					 printf("%c",e1);
				 else 
					 printf("  空!");
			 }
			 else
			 {
				 printf("树为空，无法操作!");
			 }
			 getchar();
             break;
		case 'l':
             if(!TreeEmpty(T))
			 {
				 printf("输入需要查找的节点：");
				 getchar();
				 e=getchar();
				 printf("节点");
				 printf("%c",e);
				 printf("的长子的下一个兄弟为： ");
				 if(RightSibling(T,e))
					 printf("%c",RightSibling(T,e));
				 else 
					 printf("  空!");
			 }
			 else
			 {
				 printf("树为空，无法操作!");
			 }
			 getchar();
             break;
		case 'm':
			if(TreeEmpty(T))
				printf("二叉树为空!!!");
			else
				printf("二叉树非空!!!");
			getchar();
			break;
		 case 'n':
			 printf("\n 输入待修改的节点值");
			 getchar();
			 e=getchar();
			 printf("\n 输入新值");
			 getchar();
			 e1=getchar();
			 Assign(&T,e,e1);
			 printf("层序遍历修改后的树T:\n");
			 LevelOrderTraverse(T);
		     printf("\n");
			 getchar();
			 break;
		case 'q':
            DestroyTree(&T);
			exit(0);	break;
		default:
			 printf("输入无法识别，请重新输入!!!\n");
			 break;
      }//switch
	  }//while
}//main