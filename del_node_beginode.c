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
struct node * delete_before(struct node *);

main()
{
 int option;

 do
 {
        printf("****MAIN MENU****\n");
        printf("1. Create link list\n");
        printf("2. Display link list\n");
        printf("3. Delete a node after a given node\n");
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

               start=delete_before(start);
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


struct node * delete_before(struct node *start)
{
	struct node *ptr1,*ptr,*preptr,*temp;
  	int val;

	printf("\n");
  	printf("Enter the value before which the node has to be deleted: ");
    	scanf("%d",&val);
	printf("\n");
	printf("\n");

	ptr=start;
	ptr1=ptr;
	preptr=ptr;
 
     	while(preptr->data != val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}

	while(ptr1->next != preptr)
	{
		temp=ptr1;
		ptr1=ptr1->next;
	}

	temp->next=preptr;
	free(ptr1);
	return start;
}
