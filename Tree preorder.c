#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Binarynode
{
    int info;
    struct node *r;
    struct node *l;
};
typedef struct Binarynode node;
node *root=NULL;
node* create_node()
{
    node *p;
    p=(node *)malloc(sizeof(node));
    printf("Enter the element : ");
    scanf("%d",&p->info);
    p->r=NULL;
    p->l=NULL;
    return(p);
}
node* create_node();
void insertnode();
void showlist();
void main()
{
    while(1)
    {
        system("cls");

        insertnode();
        showlist();


    }


}


void insertnode()
{

    node *temp,*tp;
    temp=create_node();
    if(root==NULL)
       root=temp;
    else
    {
        tp=root;
        while(tp!=NULL)
        {
       if(tp->info>temp->info)
       {
           if(tp->l==NULL)
            tp->l=temp;
           tp=tp->l;
       }
       else if(tp->info<temp->info)
       {
         if(tp->r==NULL)
            tp->r=temp;
         tp=tp->r;

       }
       else
         {
             break;
         }
        }
    }
    printf("gaya");
}
void showlist()
{
    node *temp;
    temp=root;
    if(root==NULL)
        printf("list is empty");
    else
    while(temp!=NULL)
    {
      printf("%d",temp->info);
      temp=temp->r;
    }
    getch();


}






