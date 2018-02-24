数据结构课程设计——哈夫曼加密解密算法2008年10月13日 14:56课程描述：对于存储在磁盘上的ASCII格式文件（汉字不能识别），根据字符出现的频率作为字符权值，利用Huffman算法进行处理，形成Huffman树，得到Huffman码，利用Huffman码对字符进行加密，已二进制的形式存储到磁盘。 再利用Huffman码对加密后的文件解密。

#include<stdio.h>

typedef struct LNode{                                 /*-------------链表-------------------*/

        int data;

        struct LNode *next;

}LNode,*Linklist;

typedef struct Character{                             /*-------------字符结构体-------------*/

        char data;                                    /*--------------字符值----------------*/

        int frequency;                               /*-------------字符出现频率-----------*/

}Character;

typedef struct HTNode{                                /*-------------哈夫曼接点-------------*/

        char data;                                    /*-------------接点值-----------------*/

        unsigned int weight;                          /*--------------权值------------------*/

        unsigned int parent,lchild,rchild;

}HTNode,*HuffmanTree;

Linklist L;                                           /*-------------链表头接点--------------*/

Character T[256];                                     /*-----存放信息中出现的字符（不含汉字）----*/

HuffmanTree HT;                                     /*--------------存放哈夫曼接点--------------*/

char *HC[257],*HA[256];          /*------HC中紧密存放哈夫曼编码，HA中按字符值位置存放该字符的编码，如A存放于HA中第65号元---*/

int len=0;                                        /*-------------信息中出现的字符数量-----------*/

int s1,s2;

int i,j;

char ch;

char Infile[10],Outfile[10],decfile[10];     /*------分别为源信息文件，加密后的2进制文件（解密源文件），解密后的文件------*/

FILE *fp,*fin,*fout;

void Create_L(int n)                                /*------对有n接点建一条带头接点的链表（头插法）-----*/

{

        int i;

        Linklist p,k;

        L=(Linklist)malloc(sizeof(LNode));

        k=L;

        for(i=1;i<=n;i++)

        {

                p=(Linklist)malloc(sizeof(LNode));

                p->next=NULL;

                p->data=i;

                k->next=p;k=p;

        }

}

void Init() /*-------初始化，统计Infile中的字符数目len及每个字符出现的频率------*/

{            /*-------将这len个字符存于T[0]到T[len-1]中，然后按频率值将这len个字符按升序排列------*/

        void QuickSort(Character A[],int p,int r);

        printf("Input the Infilename:\n");

        scanf("%s",Infile);

        if((fp=fopen(Infile,"r"))==NULL)

        {

           printf("Cannot open Infile!\n");

           exit(0);

        }

        for(i=0;i<256;i++)

        {

                T[i].data=i;

                T[i].frequency=0;

        }

        while(!feof(fp))

        {

                ch=fgetc(fp);

                T[ch].frequency++;

        }

    for(i=0,j=0;i<256;i++)

        {

                while(!T[i].frequency&&i<256)

                        T[i++].data=0;

                if(i<256)

                        T[j++]=T[i];

        }

        len=j;

        Create_L(len);

        QuickSort(T,0,len-1);

        fclose(fp);

}

void QuickSort(Character A[],int p,int r)            /*--------冒泡法对A数组元素按频率升序排列---------*/

{

      Character t;

      for(i=p;i<r;i++)

       for(j=p;j<r-i;j++)

        if(A[j].frequency>A[j+1].frequency)

        {

          t=A[j]; A[j]=A[j+1]; A[j+1]=t;

        }

}

void Select()                        /*------------取出链表的前两个权值最小的元素，将新增元素按升序规则插于链表-------*/

{

        Linklist p,q;

        int w,t;

        p=L->next;

        s1=p->data;

        q=p->next;

        s2=q->data;

        w=HT[s1].weight+HT[s2].weight;

        q->data=i;

        L->next=q;

        free(p);

        while(q->next)

        {

                if(w>HT[q->next->data].weight)

                { t=q->data;q->data=q->next->data;q->next->data=t;}

                q=q->next;

        }

}

void HuffmanCoding(int n)            /*-------对n种字符进行编码存于*HA[257]中---------*/

{

        int m,c,f,start;

        int lencd;

        HuffmanTree p;

        char *cd;

        if(n<=1) return;

        m=2*n-1;

        HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));

        for(p=HT+1,i=1;i<=n;++i,++p)

                {

                    p->data=T[i-1].data;

                    p->weight=T[i-1].frequency;

                    p->parent=0;

                    p->lchild=0;

                    p->rchild=0;

                }

        for(;i<=m;++i,++p)

                {

                    p->data=0;

                    p->weight=0;

                    p->parent=0;

                    p->lchild=0;

                    p->rchild=0;

                }

        for(i=n+1;i<=m;++i)

        {

                Select();

                HT[s1].parent=i;

                HT[s2].parent=i;

                HT[i].lchild=s1;

                HT[i].rchild=s2;

                HT[i].weight=HT[s1].weight+HT[s2].weight;

        }

        cd=(char *)malloc(n*sizeof(char));

        for(start=0;start<n;start++) cd[i]='\0';

        for(i=1;i<=n;++i)

       {

                start=0;

                for(c=i,f=HT[i].parent;f!=0;f=HT[f].parent,c=HT[c].parent)

                {

                        if(HT[f].lchild==c)

                           cd[start++]='0';

                        else

                          cd[start++]='1';

                }

                lencd=start;

                HC[i]=(char *)malloc((lencd+1)*sizeof(char));

                ch=HT[i].data;

                HA[ch]=(char *)malloc((lencd+1)*sizeof(char));

                for(start=lencd-1,j=0;start>=0;start--)

                 {

                   HC[i][j]=cd[start];

                   j++;

                 }

                   HC[i][j]='\0';

                   strcpy(HA[ch],HC[i]);

        }

        free(cd);

}

void Encrytion()                 /*-------按HA中的编码把Infile文件中的每一个字符翻译成2进制文件存于outfile文件中----*/

{

        printf("Input the outfilename:\n");

        scanf("%s",Outfile);

        if((fout=fopen(Outfile,"a"))==NULL)

        {

                printf("Cannot open outfile!\n");

                exit(0);

        }

    if((fin=fopen(Infile,"r"))==NULL)

    {

                printf("Cannot open Infile in the Encrytion!\n");

                exit(0);

    }

    while(!feof(fin))

    {

                ch=fgetc(fin);

                fputs(HA[ch],fout);

    }

    fclose(fin);

    fclose(fout);

}

void Decryption()      /*--------对存于outfile文件中的密文解码，从哈夫曼树的根接点按0，1分别选择左右子树，

                                                                              直到叶子接点，输出叶子接点值-----*/

{

        int m=2*len-1;

        if((fin=fopen(Outfile,"r"))==NULL)

        {

                printf("Cannot open sourcefile!\n");

                exit(0);

        }

        printf("Input the decfile!\n");

        scanf("%s",decfile);

        if((fout=fopen(decfile,"a"))==NULL)

        {

                printf("Cannot open decfile!\n");

                exit(0);

        }

        while(!feof(fin))

        {

           i=m;

           while(HT[i].lchild&&HT[i].rchild)

           {

                ch=fgetc(fin);

                if(ch=='0') i=HT[i].lchild;

                else if(ch=='1') i=HT[i].rchild;

                else

                {

                        printf("END!\n");

                        exit(0);

                }

            }

                printf("%c",HT[i].data);

                fprintf(fout,"%c",HT[i].data);

        }

        fclose(fin);

        fclose(fout);

}

/*----------------主函数----------------------*/

void main()          

{

        void Init();              /*---------------声明部分-------------------*/

        void HuffmanCoding(int n);

        void Encrytion();

        void Decryption();

        Init();                  /*--------------初始化函数------------------*/

        HuffmanCoding(len);      /*--------------编码函数--------------------*/

        Encrytion();             /*--------------加密函数--------------------*/

        Decryption();            /*--------------解密函数--------------------*/

}
 

