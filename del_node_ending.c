#include<stdio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *next;
};

struct node *start=NULL;
struct node * create_ll(struct node *);
struct node * display(struct node *);
struct node * delete_end(struct node *);

main()
{
 int option;

 do
 {
        printf("****MAIN MENU****\n");
        printf("1. Create link list\n");
        printf("2. Display link list\n");
        printf("3. Delete a node from end\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d",&option);

        switch(option)
        {

           case 1:
  
               start=create_ll(start);
               printf("\nLink list created\n");
		printf("\n");
               break;


           case 2:
        
               start=display(start);
           
               break;

           case 3:

               start=delete_end(start);
		printf("\nEnding node deleted\n");
		printf("\n");
               break;

        }
    
    }while(option !=4);

}

struct node * create_ll(struct node *start)
{

  struct node *new_node,*ptr;
  int num;
  printf("Enter -1 to end\n");
  printf("Enter the data: ");
  scanf("%d",&num);

  while(num != -1)
  {

   new_node=(struct node *)malloc(sizeof(struct node));
   new_node->data=num;

   if(start==NULL)
   {
     new_node->next=NULL;
     start=new_node;
   }
   else
   {

     ptr=start;

     while(ptr->next != NULL)
        ptr=ptr->next;

     ptr->next=new_node;
     new_node->next=NULL;
    }
    printf("Enter the data: ");
    scanf("%d",&num);
   }
 return start;
}

struct node * display(struct node *start)
{
  struct node *ptr;
  ptr=start;
printf("\n");
  while(ptr != NULL)
  {

    printf("%d ",ptr->data);
    ptr=ptr->next;
  }
printf("\n");
printf("\n");
  return start;
}

struct node * delete_end(struct node *start)
{

  struct node *ptr,*preptr;

     ptr=start;

     while(ptr->next != NULL)
     {
      
       preptr=ptr;
       ptr=ptr->next;

     }
     preptr->next=NULL;
     free(ptr);

 return start;
}
