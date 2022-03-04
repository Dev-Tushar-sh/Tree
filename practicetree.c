#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *r;
  struct node *l;
};

struct node* createnode(int);
void insertnode(int , struct node*);
void print(struct node*);
struct node* search(struct node* , int);
struct node* deletenode(struct node* , int);
void preorder(struct node*);
void postorder(struct node*);
void inorder(struct node*);

struct node* createnode(int n)
{
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=n;
    p->r=NULL;
    p->l=NULL;
}
void main()
{
    struct node* root=NULL;
    struct node* temp;
    struct node* n;
    root=createnode(45);    
    struct node* t0=createnode(35);
    struct node* t1=createnode(50);
    struct node* t2=createnode(20);
    struct node* t3=createnode(40);
    struct node* t4=createnode(47);
    struct node* t5=createnode(55);
    struct node* t6=createnode(42);
    struct node* t7=createnode(38); 
    root->l=t0;
    root->r=t1;
    t0->r=t3;
    t0->l=t2;
    t3->r=t6;
    t1->r=t5;
    t1->l=t4;
    t3->l=t7;
    temp=root;
    temp=root;
    insertnode(60,root);
    n=search(root,20);
    printf("\n");
    if(n==NULL)
      printf("element not found");
     printf("\n");
     inorder(root);
     printf("\n");
    deletenode(root,45);
    printf("\n");
    inorder(root);
    
}
void insertnode(int n,struct node* root)
{
    struct node* temp,*tp,*ins;
    tp=root;
    temp=createnode(n);
    while(tp!=NULL)
    {
    ins=tp;
    if(tp->data==temp->data)
    {
        printf("number cant be insert");
        return;
    }
    else
    {
        if(tp->data>temp->data)
        {
           tp=tp->l;
        }
        else
        {
           tp=tp->r;
        }
    }
    }
    if(temp->data>ins->data)
    {
        ins->r=temp;
    }
    else
    {
        ins->l=temp;
    }
    
}
struct node* search(struct node* root , int n)
{
    struct node* tp;
    tp=root;
    while(tp!=NULL)
    {
        if(n==tp->data)
        {
           printf("element found %d ",tp->data);
           return(tp);  
        }
        else
        {
           if(n<tp->data)
           {
              tp=tp->l;
           }
           else
           {
               tp=tp->r;
           }
        }
    }
    return(NULL);
}
struct node *deletenode(struct node* root, int n)
{
    struct node* temp=root,*tp;
   struct node * newtemp;
   if(root==NULL)
   {
       printf("no data in a tree");
       return(NULL);
   }
   while(temp!=NULL && temp->data!=n) 
   {
      tp=temp;
      if(temp->data>n)
          temp=temp->l;
      else
          temp=temp->r;
   }
   if(temp == NULL)
   printf("element not found");

    if(temp->l==NULL || temp->r==NULL)
    {        
        if(temp->l == NULL)
            newtemp=temp->r;         
        else
           newtemp=temp->l;
        
        if(tp==NULL)
          return(newtemp);
        if(temp == tp->l)
          tp->l= newtemp;
        else
          tp->r = newtemp;
        free(temp);
    }
    else
    {
        struct node * t=NULL;
        struct node * temp2;
        temp2= temp->r;
        while(temp2->l !=NULL)
        {
            t=temp2;
            temp2 = temp2->l;
        }
        if(t!=NULL)
         t->l = temp2->r;
         else
         temp->r=temp2->r;

         temp->data=temp2->data;
         free(temp2);
    }
    return(root);

}
void print(struct node* root)
{
    printf("postorder- ");
    postorder(root);
    printf("\ninorder- ");
    inorder(root);
    printf("\npreorder- ");
    preorder(root);
    
}
void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->l);
        postorder(root->r);
        printf(" %d ",root->data);
    }   
}
void preorder(struct node* root)
{
 if(root!=NULL)
    {
        printf(" %d ",root->data);
        preorder(root->l);
        preorder(root->r);
       
    }
}
void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->l);
        printf(" %d ",root->data);
        inorder(root->r);
    }
}