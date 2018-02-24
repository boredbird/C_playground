//二叉树基本操作main函数

#include "C6-1.H"

void main (){
   SqBiTree T,T1;
   int LoR;
   TElemType e,e1;
   char select;
   position pos;
   InitBiTree(T);
   printf("\n顺序二叉树初始化成功!\n");
/*操作主菜单*/
  while(1) {
    printf("\n**************************************************\n");
	printf("请选择操作(请按下列指示操作，区分大小写)：\n");
    printf("a.创建新二叉树    ");
    printf("b.取根节点的值     ");
    printf("c.双亲结点的值     ");
    printf("d.树的深度\n");
    printf("e.插入子树        ");
    printf("f.删除子树         ");
	printf("g.求某节点左孩子   ");
	printf("h.求某节点右孩子\n");
	printf("i.求某节点左兄弟  ");
	printf("j.求某节点右兄弟   ");
	printf("k.二叉树是否为空   ");
	printf("l.先序遍历\n");
    printf("m.中序遍历        ");
	printf("n.后序遍历         ");
	printf("o.按层输出节点值   ");
	printf("p.替换节点中的值\n");
	printf("q.退出程序\n");
	printf("**************************************************\n");
    printf("输入你的选择: ");
	scanf("%c",&select);
         switch(select) {
         case 'a': printf("\n下面创建新二叉树\n");
	             CreateBiTree(T);
			     if(!BiTreeEmpty(T))printf("\n创建二叉树成功\n");
			     else printf("\n创建二叉树失败\n");
                 break;
         case 'b': 
			     if(!BiTreeEmpty(T)){
				 printf("\n二叉树的根节点的值：");
			 	 printf("%c",Root(T));
				 }
			     else
				 printf("\n树为空，无法获取根结点!");
			     printf("\n");
	             getchar();
                 break;
         case 'c':
			 if(!BiTreeEmpty(T)){
			     printf("\n请输入要查找双亲结点值的结点值：");
			     getchar();	
			 	 e=getchar();
				 if(Root(T)==e)
					 printf("对不起，您输入的是根节点，它没有双亲节点\n");
    			 else
				 {
					 printf("\n结点");
				     printf("%c",e);
				     printf("的双亲结点是：  ");					 
                     e1=Parent(T,e);
				     if(e1){printf("%c\n",e1);}
				     else{printf("未找到该节点的父节点\n"); }
				 }
			 }
			 else printf("树为空，无法操作!");
				 getchar();
				 break;
         case 'd': 
			 if(!BiTreeEmpty(T)){
				 printf("\n树的深度：");
	             printf("%d",BiTreeDepth(T));
				 printf("\n");
			 }
			 else printf("树为空，无法操作!");
				 getchar();
                 break;
		 case 'e':
			   if(!BiTreeEmpty(T)){
			     printf("\n创建用于插入的二叉树\n"); 
				 InitBiTree(T1);
			     if(!BiTreeEmpty(T)) 
				     printf("初始化二叉树成功，请先序序列创建新二叉树，此树与原树不相交，且右节点必须为空!\n");
	             CreateBiTree(T1);
	             if(T1[2]!=' ')printf("\n创建二叉树成功!\n");
	             else printf("\n创建失败!新创建的二叉树右子树不为空!");
 				 printf("\n输入要操作的结点的①节点,②左或右(左子树输入'0';右子树输入'1')两个值：\n");
				 scanf("%d %d",&e,&LoR);
	             InsertChild(T,e,LoR,T1);
	             printf("\n插入子树成功\n");
				 getchar();
				 printf("\n新二叉树的先序序列：");
				 PreOrderTraverse(T);
			   }
			   else {
			       printf("未找到主二叉树，请先创建主二叉树!\n");
			   }
	             break;
         case 'f': 
			     if(!BiTreeEmpty(T)){
					 printf("删除子树前，前序遍历结果为：");
				     PreOrderTraverse(T);
					 printf("\n输入要操作的结点的①层号,②序号,③左或右(左子树输入'0';右子树输入'1')三个值：\n");
					 scanf("%d %d %d",&pos.level,&pos.order,&LoR);
				     DeleteChild(T,pos,LoR);
				     printf("删除子树后，前序遍历结果为：");
				     PreOrderTraverse(T);
				 }
			     else
					 printf("树为空，无法操作!");
    			     printf("\n");
				     getchar();
                     break; 
		 case 'g':
			 if(!BiTreeEmpty(T))
			 {
				 printf("输入需要查找的节点：");
				 getchar();
				 e=getchar();
				 printf("节点");
				 printf("%c",e);
				 printf("的左孩子为： ");
				 if(LeftChild(T,e))
					 printf("%c",LeftChild(T,e));
				 else 
					 printf("  空!");
			 }
			 else
			 {
				 printf("树为空，无法操作!");
			 }
			 getchar();
             break;
        case 'h':
			 if(!BiTreeEmpty(T))
			 {
				 printf("输入需要查找的节点：");
				 getchar();
				 e=getchar();
				 printf("节点");
				 printf("%c",e);
				 printf("的左孩子为： ");
				 if(RightChild(T,e))
					 printf("%c",RightChild(T,e));
				 else 
					 printf("  空!");
			 }
			 else
			 {
				 printf("树为空，无法操作!");
			 }
			 getchar();
              break;
		case 'i':
			 if(!BiTreeEmpty(T))
			 {
				 printf("输入需要查找的节点：");
				 getchar();
				 e=getchar();
				 printf("节点");
				 printf("%c",e);
				 printf("的左兄弟为： ");
				 if(LeftSibling(T,e))
					 printf("%c",LeftSibling(T,e));
				 else 
					 printf("  空!");
			 }
			 else
			 {
				 printf("树为空，无法操作!");
			 }
			 getchar();
             break;
		case 'j':
             if(!BiTreeEmpty(T))
			 {
				 printf("输入需要查找的节点：");
				 getchar();
				 e=getchar();
				 printf("节点");
				 printf("%c",e);
				 printf("的右兄弟为： ");
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
	    case 'k':
			if(BiTreeEmpty(T))
				printf("二叉树为空!!!");
			else
				printf("二叉树非空!!!");
			getchar();
			break;
		case 'l': printf("\n先序遍历序列：");
			     if(!BiTreeEmpty(T))PreOrderTraverse(T);
				 else printf(" 树为空，无法遍历!");
				 printf("\n");
	             getchar();
				 break;
         case 'm': printf("\n中序遍历序列：");
	             if(!BiTreeEmpty(T)) InOrderTraverse(T);
				 else printf(" 树为空，无法遍历!");
				 printf("\n");
	             getchar();
                  break;
		 case 'n': printf("\n后序遍历序列：");
	             if(!BiTreeEmpty(T))PostOrderTraverse(T);
				 else printf(" 树为空，无法遍历!");
				 printf("\n");
				 getchar();
                 break;
		case 'o':
			if(!BiTreeEmpty(T)){
			printf("逐层、按本层序号输出二叉树\n");
			Print(T);
			}
			else
			{
				 printf("树为空，无法操作!");
			 }
			getchar();
			break;
		case 'p':
			if(!BiTreeEmpty(T)){
				printf("修改前,层序遍历结果为：");
				LevelOrderTraverse(T);
				printf("\n输入要更改值的结点的①层号,②序号两个值,③新值：\n");
				scanf("%d %d %c",&pos.level,&pos.order,&e);
				Assign(T,pos,e);
				printf("修改后，层序遍历结果为：");
				LevelOrderTraverse(T);
				getchar();
			}
			else
			{
				 printf("树为空，无法操作!");
			 }

			getchar();
			break;
		case 'q':
			DestroyBiTree(T);
			exit(0);
			break;
		default:
			 printf("输入无法识别，请重新输入!!!\n");
			 break;
      }//switch
	  }//while
}//main