#include "stdio.h"
#include "stdlib.h"  
#include "string.h"
#define MAX_LEN 100
#define NOT_FOUND -1 
struct line
{   
   char   text[MAX_LEN];   
   int   num;            /*�к�*/
   struct line *next; /*ָ����һ���е�ָ��*/
   struct line *prior; /*ָ��ǰһ���е�ָ��*/
};
int lnum;
struct line *start;  /*ָ����е�һ�е�ָ��*/
struct line *last;   /*ָ���������һ�е�ָ��*/
struct line *find(int);/*����ָ�����Ƿ����*/
void patchup(int,int);/*�Ե�ǰ���Ժ��ÿ�е��кż�1���1*/
void delete_text(int);/*ɾ��һ������*/
void list();  /*��ʾ�ļ���ȫ������*/
void save();  /*�����ļ�*/
void load();  /*���ļ�,��ʼ�����Ա�*/
void insert(char str[],int linenum,int position);/*�������ֵ�һ�е��м�*/
void printline(int linenum);/*��ӡһ������*/
void deletestr(int linenum,int position, int lenth);/*ɾ��һ���ַ���*/
int findstr(char *to_find);/*�����ַ���*/
int menu_select();    /*��ʾ���˵�*/
int menu_select_insert();/*��ʾ���빦���Ӳ˵�*/
int menu_select_delete();/*��ʾɾ�������Ӳ˵�*/
int menu_select_print(); /*��ʾ��ӡ�����Ӳ˵�*/
int menu_select_move();   /*��ʾ�ƶ������Ӳ˵�*/
void enter(int   linenum); /*����һ������*/
void enter_empty(int   linenum);/*����һ���հ���*/
void   main()
{   
   char str[MAX_LEN];
   int choice;
   int linenum=1;
   int number=0;
   start=NULL;   
   last=NULL;   
   load(); /*���ļ�,��ʼ�����Ա�*/
   do{
        choice=menu_select();
        switch(choice)
		{
        case 1: /*����*/
			   choice=menu_select_insert();/*�����Ӳ˵�*/
               switch(choice)
			   {
                  case 1:printf("\t�кţ�");
                         scanf("%d",&linenum);
                         enter(linenum);
                         break;
                   case 2:
                          printf("�������λ��--�кţ�");
                          scanf("%d",&linenum); 
                          printf("�������λ��--�кţ�");
                          scanf("%d",&number);
                          printf("Ҫ������ַ�����");
                          scanf("%s",str);
                          insert(str,linenum,number);
                          break;
                    case 3:break;
			   }
               break;
         case 2:choice=menu_select_delete();/*ɾ���Ӳ˵�*/
                switch(choice)
				{
                   case 1:printf("\t�к�:");   
                          scanf("%d",&linenum);
                          delete_text(linenum);
                          break; 
                   case 2:printf("Ҫɾ�����ַ�����");
                           scanf("%s",str);
						   number=findstr(str);
						   if(number==NOT_FOUND)
                                printf("û���ҵ�");
                           else
                               deletestr(lnum,number,strlen(str));
                           break;
                    case 3:break;
				}
                 break; 
          case   3:choice=menu_select_print();/*��ʾ�Ӳ˵�*/
                   switch(choice)
				   {
				      case 1:printf("\t�кţ�");
                             scanf("%d",&linenum);
                             printline(linenum);
                             break; 
                      case 2:list();
                             break;
                      case 3:break;
                     }
                    break; 
          case   4:printf("������Ҫ���ҵ��ַ�����");
                  scanf("%s",str);
                  number=findstr(str);
                  if(number==NOT_FOUND)
                     printf("û���ҵ�");
                  else
                     printf("Ҫ���ҵ��ַ��������кţ�%d,�кţ�%d\n",lnum,number+1);
                  break;
           case   5:printf("���뱻�滻���ַ�����");
                  scanf("%s",str);
                  number=findstr(str);
                  if(number==NOT_FOUND)
                         printf("û���ҵ�");
                  else
                  {
                      deletestr(lnum,number,strlen(str));
                      printf("Ҫ�滻���ַ�����");
                      scanf("%s",str);
                      insert(str,lnum,number+1);
                   }
                   break;
           case   6:choice=menu_select_move();
                    switch(choice)
					{
                       case 1:printf("����Ҫ�ƶ����ַ��������кţ�");
                              scanf("%d",&linenum);
                              enter_empty(linenum);  
                              break; 
                        case 2:printf("����Ҫ�ƶ����ַ��������кţ�");
                              scanf("%d",&linenum);
                              delete_text(linenum-1);
                              break;
                        case 3:printf("����Ҫ�ƶ����ַ��������кţ�");
                              scanf("%d",&linenum);
                              printf("����Ҫ�ƶ����ַ��������кţ�");
                              scanf("%d",&number);
                              str[0]=' ';
                              str[1]='\0';
                              insert(str,linenum,number);
                              break;
                        case 4:printf("����Ҫ�ƶ����ַ��������кţ�");
                              scanf("%d",&linenum);
                              printf("����Ҫ�ƶ����ַ��������кţ�");
                              scanf("%d",&number);
                              if(number<=0)
                               printf("���в�����");
                               else
                                  deletestr(linenum,number-2,1);
                               break;

                         case 5:break;
                      }
                     break; 
            case   7:save();   
                       break;   
            case   8:load();   
                       break;   
            case   9:exit(0); break; 
			
           }   
     }while(1);   

  }

  /* ��ʾ�˵������û�ѡ��   */
int menu_select()
{
      int c;
      printf("\n\t\t1.����\n");
      printf("\t\t2.ɾ��\n");
      printf("\t\t3.��ʾ\n");
      printf("\t\t4.����\n");
      printf("\t\t5.�滻\n");
      printf("\t\t6.�ƶ�\n");
      printf("\t\t7.�ļ�����\n");   
      printf("\t\t8.װ���ļ�\n");   
      printf("\t\t9.�˳�\n");   
      do
	  {   
         printf("\n\n\t\t�밴����ѡ��");   
         scanf("%d",&c);
		 
      }while(!(c>=1&&c<=9));   
      return(c);   
}
int menu_select_insert()
  {
      
      int   c;   
      printf("\n\t\t1.����һ������\n");   
      printf("\t\t2.����һ������\n");   
      printf("\t\t3.�����ϼ��˵�\n");      
      do{   
            printf("\n\n\t\t�밴����ѡ��");   
            scanf("%d",&c);
                      
      }while(!(c>=1&&c<=3));   
      return(c);   
  }
int menu_select_delete()
  {
     
      int   c;   
      printf("\n\t\t1.ɾ��һ������\n");   
      printf("\t\t2.ɾ��һ������\n");   
      printf("\t\t3.�����ϼ��˵�\n");      
      do{   
           printf("\n\n\t\t�밴����ѡ��");   
           scanf("%d",&c);
      }while(!(c>=1&&c<=3));   
      return(c);   
  }
 int menu_select_print()
  {
      
      int   c;   
      printf("\n\t\t1.��ʾһ��\n");   
      printf("\t\t2.ȫ����ʾ\n");   
      printf("\t\t3.�����ϼ��˵�\n");      
      do
	  {   
        printf("\n\n\t\t�밴����ѡ��");   
        scanf("%d",&c);
      }while(!(c>=1&&c<=3));   
      return(c);   
  }
int menu_select_move()
  {
      
      int   c;   
      printf("\n\t\t1.�����ƶ�һ��\n");   
      printf("\t\t2.�����ƶ�һ��\n");   
      printf("\t\t3.�����ƶ�һ��\n");
      printf("\t\t4.�����ƶ�һ��\n");
      printf("\t\t5.�����ϼ��˵�\n");
      do
	  {   
           printf("\n\n\t\t�밴����ѡ��");   
           scanf("%d",&c);
       }while(!(c>=1&&c<=5));   
      return(c);   
  }
    
  /*����һ������*/   
  void enter(int linenum)
  {   
     
	  struct line *info,*q,*p;   
      info=(struct line *)malloc(sizeof(struct line));   
      p=start;
	  q=NULL;
	  while(p&&p->num!=linenum)
	  {
	      q=p;
		  p=p->next;
	  }
	  if(p==NULL&&(q->num+1)!=linenum)
	  {	 
		 printf("������кŲ�����");
	     
	  }
	  else 
	  {
		  printf("����Ҫ������ַ���");         
	      scanf("%s",info->text);  
          info->num=linenum;   
          if(linenum==1)    /*�����ڵ�һ��*/
		  {
	          info->next=p;
		      p->prior=info;
		      info->prior=NULL;
		      start=info;
		  }   
		  else if(q->num!=linenum)/*���������һ��*/
		  {
		     q->next=info;
	        info->next=p;
	        info->prior=q;
		  }
	      else                  /*������������*/
		  {
	        q->next=info;
	        info->next=p;
	        p->prior=info;
	        info->prior=q;
		  }

	  }
	  while(p)      /*������ǲ��������һ�У������к�����кŶ���1*/
	  {
	     p->num=p->num+1;
		 p=p->next;
	  }
          

  }   
    
 /*���ı����ݲ����ļ��м�ʱ����������ݵ��кű�������1����ɾ��ʱ����ɾ�����ı�������кű����1*/   
 void   patchup(int  n,int   incr)   
  {   
      struct   line   *i;   
      i=find(n);
	  i=i->next;
      while(i)
		 {   
            i->num=i->num+incr;   
            i=i->next;   
		 }
 }  
 
  /*����һ�հ���*/   
  void enter_empty(int   linenum)
  {   
      struct   line   *info,*p;    
      info=(struct line *)malloc(sizeof(struct line));   
      if(!info)
      {   
         printf("\t!   �ڴ治����\n");   
         exit(0);   
      }
      info->text[0]=' ';
      info->text[1]='\0';
      info->num=linenum;   
      if(find(linenum))
	  {	   
		  p=start;
		  if(linenum==1)
		  {
		     info->next=p;
			 start=info;
			 info->prior=NULL;
			 p->prior=info;
		  }
		  else
		  {
			  while(p->next->num!=linenum)
			     p=p->next;
		      info->next=p->next;
		      p->next->prior=info;
		      p->next=info;
		      info->prior=p;
		  }
		  patchup(linenum,1);
		  
	  }
	  else
	   printf("���в�����");
     
  }
  
  /*�������ֵ�һ�е��м�*/
  void insert(char str[],int linenum,int position)
  { 
    struct line *info;
    int len,i;
    int lenth;
    char rest_str[MAX_LEN],nostr[2]={" "};
    info=start;
    while(info&&info->num!=linenum)
	 {
	      info=info->next;
	 }
    if(info==NULL)
       printf("�����ڸ��У�\n");
    else if(position<0)
       printf("�����ڸ��У�\n");
	else
    {
       
	   lenth=strlen(info->text);
       if(lenth<position)            
        {
          len=position-lenth-1;
          for(i=0;i<len;i++)
            strcat(info->text,nostr);        /*������Ĳ��ֲ���ո��*/
            strcat(info->text,str);
        }
        else
        {
          strcpy(rest_str,&info->text[position-1]);
          strcpy(&info->text[position-1],str);
          strcat(info->text,rest_str);
        }
    }
  }
  
  /*ɾ��һ������*/
  void deletestr(int linenum,int position,int lenth)
  {
    struct   line   *info;
    char rest_str[MAX_LEN];
    info=find(linenum);
    if(info==NULL)
        printf("����û���ַ���\n");
	else
    {
        if(strlen(info->text)<=(position+lenth))
            info->text[position]='\0';
        else
        {
            strcpy(rest_str,&info->text[position+lenth]);
            strcpy(&info->text[position],rest_str);
        }
    }
  }

  /*ɾ��һ������*/   
  void   delete_text(int   linenum)   
  {   
      struct   line   *info,*p;    
      info=start;
      while((info->num<linenum)&&info)
	  {
	      info=info->next;
           
	  }
	
	 if(info->next==NULL)
         printf("���в�����");
	 else
	 {   p=info->next;
         if(start==info)
		 {   
              start=info->next;   
              if(start)
				  start->prior=NULL;   
               else 
				  last=NULL;   
          }   
          else
		  {   
               info->prior->next=info->next;   
               if(info!=last)   
                   info->next->prior=info->prior;   
               else
				   last=info->prior;   
           }   
           free(info);  
		   while(p)
		   {   
              p->num=p->num-1;   
              p=p->next;   
		   }   
                   
      }   
  }   

  /*����һ���ı�*/
  int findstr(char *to_find)
  {
    struct   line   *info;

    int i=0,find_len,found=0,position;
    char substring[MAX_LEN];
    info=start;
    lnum=0;
    find_len=strlen(to_find);
    while(info&&!found)
    {    
        i=0;
        while(!found&&i<=strlen(info->text)-find_len)
        {
            strncpy(substring,&info->text[i],find_len);
            substring[find_len]='\0';
            if(strcmp(substring,to_find)==0)
            {
                found=1;
                lnum=info->num;
            }
            else 
				++i;
        }
        info=info->next;
    }
        if(found)
            position=i;
        else 
            position=NOT_FOUND;
    return(position);
  }
  /*����һ���ı�*/   
struct   line   *find(int   linenum)   
  {   
      struct   line   *info;   
      info=start;   
      while(info)
	  {   
          if(linenum!=info->num)
	           info=info->next;
		  else
			  break;
      }   
     return(info);   
  } 
    
/*��ʾһ���ı�*/
void     printline(int linenum)
{    
    struct   line   *info;
    info=find(linenum);
    if(info)
		printf("%d:%s\n",info->num,info->text);
	else
		printf("���в�����");
  }
/*��ʾ�����ı�*/   
void list()   
{   
   struct   line   *info;   
   info=start;   
   while(info)
   {   
      printf("%d:%s\n",info->num,info->text);   
      info=info->next;   
   }   
   printf("\n\n");   
}   
    
  /*���ļ�*/   
  void   save()
  {   
      struct line   *info;   
      char   *p;   
      FILE   *fp;   
      if((fp=fopen("text.txt","w"))==NULL){   
                  printf("\t�ļ��򲻿���\n");   
                  exit(0);   
      }   
      printf("\t���ڴ����ļ���\n");   
      info=start;   
      while(info)
	  {   
         p=info->text;   

         while(*p)
			 putc(*p++,fp);   
             putc('\n',fp);
             info=info->next;   
        }   
      fclose(fp);   
  }   
    
  /*װ���ļ�*/   
  void   load()
  {   
      struct line *info,*temp; /*infoָ��ǰ�У�tempָ��info��ǰ����*/  
      char c;   
      FILE *fp;/*�ļ�ָ��*/   
      int inct,i;/*�м�����*/
	  temp=NULL;
      if((fp=fopen("text.txt","r"))==NULL)
	  {   
         printf("\t�ļ��򲻿���\n");
         exit(0);
      }   
       printf("\n\t��װ���ļ�!\n");   
       start=(struct line*)malloc(sizeof(struct line)); /*��̬����һ�еĽ��ռ�*/  
       info=start;   
       inct=1;   
	   while((c=fgetc(fp))!=EOF)
	   {   i=0;
	       info->text[i]=c;
	       i++;
           while((c=fgetc(fp))!='\n') /*���ļ��ж�ȡһ���ַ������Ա���,�ļ���ÿһ����\nΪ������־*/
		   {   info->text[i]=c;
			   i++; 
		   }	     
           info->text[i]='\0'; /*���Ա���ÿ��ĩβ�Ľ�����־*/ 
           info->num=inct++; /*����һ���ַ�����������1*/  
           info->next=(struct line*)malloc(sizeof(struct line));   
           if(!info->next)
			{   
               printf("\n\t�ڴ��Ѿ����꣡");   
               exit(0);   
            }   
            info->prior=temp;   
            temp=info;   
            info=info->next;   
        }   
        temp->next=NULL;   
        last=temp;   
        free(info);   
        start->prior=NULL;   
        fclose(fp);   
  }   


