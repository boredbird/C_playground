//二叉树基本操作main函数

#include "C6-6.H"

void main (){

   int i;
   BiPTree T,p,q;
   TElemType e1,e2;
   InitBiTree(&T);
   e1=Root(T);
   char select;
   printf("\n初始化成功!\n");

  while(1) {
    printf("\n**************************************************************\n");
	printf("请选择操作(请按下列指示操作，区分大小写)：\n");
    printf("a.创建新二叉树    ");
    printf("b.取根节点的值     ");
    printf("c.双亲结点的值     ");
    printf("d.树的深度    \n");
    printf("e.插入孩子        ");
    printf("f.清空子树         ");
	printf("g.求节点的左孩子   ");
	printf("h.求节点的右孩子\n");
	printf("i.求节点的左兄弟  ");
	printf("j.求节点的右兄弟   ");
	printf("k.先序遍历         ");
	printf("l.中序遍历      \n");
	printf("m.后序遍历        ");
	printf("n.层序遍历         ");
	printf("o.二叉树是否为空   ");
    printf("p.替换节点中的值  \n");
	printf("q.退出程序\n");
	printf("**************************************************************\n");
    printf("输入你的选择: ");
	scanf("%c",&select);
         switch(select) {
         case 'a': printf("\n下面按先序序列创建新二叉树，'#'表示空节点，叶子结点也需要输入\n");
	             CreateBiTree(&T);
			     if(!BiTreeEmpty(T))printf("\n创建二叉树成功\n");
			     else printf("\n创建二叉树失败\n");
				 getchar();
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
			 	 e1=getchar();
				 if(Root(T)==e1)
					 printf("对不起，您输入的是根节点，它没有双亲节点\n");
    			 else
				 {
					 printf("\n结点");
				     printf("%c",e1);
				     printf("的双亲结点是:");
					 e2=Parent(T,e1);
				     if(e2){printf("%c\n",e2);}
				     else{printf("未找到该节点的父节点\n");}
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
                 InitBiTree(&p);
				 printf("树p初始化成功! ");
                 printf("\n按先序序列创建新二叉树,右子树必须为空,'#'表示空节点,叶子结点也需要输入\n");
                 CreateBiTree(&p);
				 if(p->rchild!=NULL)
				 {
					 printf("创建子树失败!新树右子树必须为空!");
					 getchar();
					 break;
				 }
				 printf("插入前，层序遍历原树T:\n");
				 LevelOrderTraverse(T);
				 printf("\n将树p插到树T中，请输入T中p的双亲结点: ");
				 getchar();
				 e1=getchar();
				 printf("将树p插到树T中，请输入T中p的子树序号(0:插入左子树;1:插入右子树): ");
				 scanf("%d",&i);
				 q=Point(T,e1);
				 InsertChild(q,i,p);
				 printf("插入后，层序遍历树T:\n");
				 LevelOrderTraverse(T);
			   }
			   else {
			       printf("未找到主二叉树，请先创建主二叉树!\n");
			   }
			   getchar();
	           break;
         case 'f': 
			     if(!BiTreeEmpty(T)){
				     printf("删除前,层序遍历的结果为:  ");
                     LevelOrderTraverse(T);
					 printf("\n删除树中结点e的第i棵子树，请输入e: ");
					 getchar();
					 e1=getchar();
					 printf("\n删除树中结点e的第i棵子树，请输入i(i=0:删除左子树，i=1:删除右子树): ");
					 getchar();
					 scanf("%d",&i);
					 q=Point(T,e1);
                     DeleteChild(q,i);
					 printf("删除后的层序遍历的结果为:  ");
                     LevelOrderTraverse(T);
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
				    e1=getchar();
				    printf("节点");
				    printf("%c",e1);
				    printf("的左孩子为： ");
				    if(LeftChild(T,e1))
						printf("%c",LeftChild(T,e1));
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
				 e1=getchar();
				 printf("节点");
				 printf("%c",e1);
				 printf("的右孩子为： ");
				 if(RightChild(T,e1))
					 printf("%c",RightChild(T,e1));
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
			    	 e1=getchar();
			    	 printf("节点");
			    	 printf("%c",e1);
			    	 printf("的左兄弟为： ");
				     if(LeftSibling(T,e1))
				 	 printf("%c",LeftSibling(T,e1));
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
				 e1=getchar();
				 printf("节点");
				 printf("%c",e1);
				 printf("的右兄弟为： ");
				 if(RightSibling(T,e1))
					 printf("%c",RightSibling(T,e1));
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
			if(!BiTreeEmpty(T))
			 {
				printf("先序遍历结果为：");
                PreOrderTraverse(T);
			 }
			 else
			 {
				 printf("树为空，无法操作!");
			 }
			 getchar();
             break;
	    case 'l':
			if(!BiTreeEmpty(T))
			 {
				printf("中序遍历结果为：");
                InOrderTraverse(T);
			 }
			 else
			 {
				 printf("树为空，无法操作!");
			 }
			 getchar();
             break;
		case 'm':
			if(!BiTreeEmpty(T))
			 {
				printf("后序遍历结果为：");
                PostOrderTraverse(T);
			 }
			 else
			 {
				 printf("树为空，无法操作!");
			 }
			 getchar();
             break;
        case 'n':
			if(!BiTreeEmpty(T))
			 {
				printf("层序遍历结果为：");
                LevelOrderTraverse(T);
			 }
			 else
			 {
				 printf("树为空，无法操作!");
			 }
			 getchar();
             break;
        case 'o':
			if(BiTreeEmpty(T))
				printf("二叉树为空!!!");
			else
				printf("二叉树非空!!!");
			getchar();
			break;
         case 'p': 
			 if(!BiTreeEmpty(T))
			 {
				 printf("层序遍历树的结果为 :\n");
				 LevelOrderTraverse(T);
				 printf("\n请输入待修改的结点的值: ");
				 getchar();
				 e1=getchar();
				 q=Point(T,e1);
                 printf("请输入待修改的结点的新值: ");
				 getchar();
				 e2=getchar();
				 Assign(q,e2);
				 printf("层序遍历修改后的树的结果为:\n");
				 LevelOrderTraverse(T);
			 }
			 else
				 printf("\n树为空，无法获取根结点!");
			 printf("\n");
	         getchar();
             break;
		case 'q': exit(0);	break;
		default:
			 printf("输入无法识别，请重新输入!!!\n");
			 break;
      }//switch
	  }//while
}//main
