#include "C6-3.H"

void main (){

  BiThrTree T,Thrt;//tree为二叉树，Thrt为头节点
  char select;
	
/*操作主菜单*/
  while(1) {
    printf("\n**************************************************\n");
	printf("请选择操作(请按下列指示操作，区分大小写)：\n");
	printf("a.创建二叉树，在先序遍历的过程中，先序线索化二叉树\n");
    printf("b.创建二叉树，在中序遍历的过程中，中序线索化二叉树\n");
    printf("c.创建二叉树，在后序遍历的过程中，后序线索化二叉树\n");
	printf("q.退出程序\n");
	printf("**************************************************\n");
    printf("输入你的选择: ");
	scanf("%c",&select);
         switch(select) {
		case 'a':
		      	printf("\n下面创建新二叉树\n");
     	 	     printf("提示: 以先序序列输入二叉树，每个空节点都要设置成'#'符号，叶子节点后也要添加符号'#'\n");	
			     CreateBiThrTree(&T);
			     PreOrderThreading(&Thrt,T);
				 printf("先序遍历(输出)线索二叉树:");
                 PreOrderTraverse_Thr(Thrt);
				 DestroyBiThrTree(&Thrt);
	             getchar();
                 break;
        case 'b':  
			 	printf("\n下面创建新二叉树\n");
     	 	     printf("提示: 以先序序列输入二叉树，每个空节点都要设置成'#'符号，叶子节点后也要添加符号'#'\n");	
			     CreateBiThrTree(&T);
			     InOrderThreading(&Thrt,T);
                 printf("中序遍历(输出)线索二叉树: ");
                 InOrderTraverse_Thr(Thrt);
                 DestroyBiThrTree(&Thrt);
				 printf("\n");
	             getchar();
				 break;
        case 'c':
				 printf("\n下面创建新二叉树\n");
     	 	     printf("提示: 以先序序列输入二叉树，每个空节点都要设置成'#'符号，叶子节点后也要添加符号'#'\n");	
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
			 printf("输入无法识别，请重新输入!!!\n");
			 break;
      }//switch
	  }//while
}//main