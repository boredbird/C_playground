//二叉树基本操作main函数

#include "C6-4.H"

void main (){

   int i;
   PTree T,p;
   TElemType e,e1;
   InitTree(&T);
   TElemType cache;
   char select;
   printf("\n初始化成功!\n");
/*操作主菜单*/
  while(1) {
    printf("\n**************************************************************\n");
	printf("请选择操作(请按下列指示操作，区分大小写)：\n");
    printf("a.创建新二叉树    ");
    printf("b.取根结点的值     ");
    printf("c.双亲结点的值     ");
    printf("d.树的深度    \n");
    printf("e.插入子树        ");
    printf("f.删除子树         ");
	printf("g.求某结点的长子   ");
	printf("h.求某结点下个兄弟\n");
	printf("i.树是否为空    ");
	printf("j.层序遍历         ");
    printf("k.替换结点中的值   ");
	printf("q.退出程序\n");
	printf("**************************************************************\n");
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
				 printf("\n树为空，无法获取根结点!");
			     printf("\n");
	             getchar();
                 break;
         case 'c':
			 if(!TreeEmpty(T)){
			     printf("\n请输入要查找双亲结点值的结点值：");
			     getchar();	
			 	 cache=getchar();
				 if(Root(T)==cache)
					 printf("对不起，您输入的是根节点，它没有双亲节点\n");
    			 else
				 {
					 printf("\n结点");
				     printf("%c",cache);
				     printf("的双亲结点是:");
					 cache=Parent(T,cache);
				     if(cache){printf("%c\n",cache);}
				     else{printf("未找到该节点的父节点\n");}
				 }
			 }
			 else printf("树为空，无法操作!");
				 getchar();
				 break;
         case 'd': 
			 if(!TreeEmpty(T)){
				 printf("\n树的深度：");
	             printf("%d",TreeDepth(T));
				 printf("\n");
			 }
			 else printf("树为空，无法操作!");
				 getchar();
                 break;
		 case 'e':
			 if(!TreeEmpty(T)){ 
                 InitTree(&p);
				 printf("树p初始化成功! ");
                 CreateTree(&p);
				 printf("插入前层序遍历原树t:\n");
				 TraverseTree(T);
				 printf("将树p插到树T中，请输入T中p的双亲结点 子树序号: ");
				 scanf("%c%d%*c",&e,&i);
				 InsertChild(&T,e,i,p);
				 Print(T);
			   }
			   else {
			       printf("未找到主二叉树，请先创建主二叉树!\n");
			   }
	             break;
         case 'f': 
			     if(!TreeEmpty(T)){
				     printf("删除树中结点e的第i棵子树，请输入e: ");
					 getchar();
					 e=getchar();
                     printf("删除树中结点e的第i棵子树，请输入i: ");
                     scanf("%d",&i);
                     DeleteChild(&T,e,i);
					 printf("删除后的结果为:  ");
                     Print(T);
				 }
			     else
					 printf("树为空，无法操作!");
    			     printf("\n");
				     getchar();
                     break; 
	    	case 'g':
			 if(!TreeEmpty(T))
			 {
				 printf("输入需要查找的节点：");
				 getchar();
				 cache=getchar();
				 printf("节点");
				 printf("%c",cache);
				 printf("的长子为： ");
				 if(LeftChild(T,cache))
					 printf("%c",LeftChild(T,cache));
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
			 if(!TreeEmpty(T))
			 {
				 printf("输入需要查找的节点：");
				 getchar();
				 cache=getchar();
				 printf("节点");
				 printf("%c",cache);
				 printf("的下一个兄弟为： ");
				 if(RightSibling(T,cache))
					 printf("%c",RightSibling(T,cache));
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
			if(TreeEmpty(T))
				printf("二叉树为空!!!");
			else
				printf("二叉树非空!!!");
			getchar();
			break;
		case 'j':
			 if(!TreeEmpty(T))
			 {
				printf("层序遍历结果为：");
                TraverseTree(T);
			 }
			 else
			 {
				 printf("树为空，无法操作!");
			 }
			 getchar();
             break;
         case 'k': 
			 if(!TreeEmpty(T)){
				 printf("层序遍历树的结果为 :\n");
				 TraverseTree(T);
				 printf("请输入待修改的结点的值: ");
				 getchar();
				 e=getchar();
                 printf("请输入待修改的结点的新值: ");
				 getchar();
				 e1=getchar();
				 Assign(&T,e,e1);
				 printf("层序遍历修改后的树的结果为:\n");
				 TraverseTree(T);
				 }
			     else
				 printf("\n树为空，无法获取根结点!");
			     printf("\n");
	             getchar();
                 break;
		case 'q': 
			DeleteChild(&T,Root(T),0);
			exit(0);
			break;
		default:
			 printf("输入无法识别，请重新输入!!!\n");
			 break;
      }//switch
	  }//while
}//main