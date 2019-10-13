#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *Creat(int n)//函数申明，返回值是一个结构体类型的指针，参数是整型的数字
{
    struct node *head, *p;//申请结构体指针
    int i;
    head=(struct node *)malloc(sizeof(struct node));//头指针
    head->next=NULL;//建立一个空链表
    for(i=1;i<=n;i++)
    {
        p=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&p->data);//输入数据
        p->next=head->next;
        head->next=p;
    }
    return head;
}//头插法输入

struct node *Split(struct node *head1)//分离模3余0和其他两种
{
    struct node *head2, *p, *q, *p1, *q1;
    int a=0;
    head2=(struct node *)malloc(sizeof(struct node));
    head2->next=NULL;
    p=head1->next;
    head1->next=NULL;
    q=p->next;
    while(p!=NULL)
    {
        if(p->data%3==0)
        {
            p->next=head1->next;
            head1->next=p;
            a++;
        }
        else
        {
            p->next=head2->next;
            head2->next=p;
        }
        p=q;
        if(q!=NULL)
            q=q->next;
    }
    printf("%d ",a);    //打印出模3余0
    
    p1=head2->next;   //把第一次分离后的head2（余1&余2）就地逆置，不然后面输出的余1、余2顺序会反
    head2->next=NULL;
    while(p1!=NULL)
    {
        q1=p1;
        p1=p1->next;
        q1->next=head2->next;
        head2->next=q1;
    }
    
    return head2;
}

struct node *Split1(struct node *head2)//把余1和余2分开
{
    struct node *head3, *p, *q;
    int b=0, c=0;
    head3=(struct node *)malloc(sizeof(struct node));
    head3->next=NULL;
    p=head2->next;
    head2->next=NULL;
    q=p->next;
    while(p!=NULL)
    {
        if(p->data%3==1)
        {
            p->next=head2->next;
            head2->next=p;
            b++;
        }
        if(p->data%3==2)
        {
            p->next=head3->next;
            head3->next=p;
            c++;
        }
        p=q;
        if(q!=NULL)
            q=q->next;
    }
    printf("%d %d\n",b,c);  //打印出模3余1和模3余2
    return head3;
}

int main()
{
    int n;
    struct node *head, *head1, *head2, *p, *q, *r;
    printf("输入\n");
    scanf("%d",&n);//输入n值
    head=Creat(n);//创建最初的链表
    printf("输出\n");
    head1=Split(head);//分离模3余0与余1余2
    head2=Split1(head1);//分离模3余1与模3余2
    
    p=head->next;//head是模3余0链表的头指针
    while(p!=NULL)
    {
        if(p->next!=NULL)
            printf("%d ",p->data);
        else
            printf("%d\n",p->data);
        p=p->next;
    }
    
    q=head1->next;//head1是模3余1链表的头指针
    while(q!=NULL)
    {
        if(q->next!=NULL)
            printf("%d ",q->data);
        else
            printf("%d\n",q->data);
        q=q->next;
    }
    
    r=head2->next;//head2是模3余2链表的头指针
    while(r!=NULL)
    {
        if(r->next!=NULL)
            printf("%d ",r->data);
        else
            printf("%d\n",r->data);
        r=r->next;
    }
    return 0;
}
