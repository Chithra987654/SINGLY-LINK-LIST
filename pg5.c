/* doubly linklist */
#include<stdio.h>
#include<stdlib.h>
	void main()
	{
	struct node 
	{
	struct node *prev;
	int data;
	struct node *next;
	};


int ch,entry;
struct node *head=NULL,*pos=NULL,*tail=NULL;


while(1)
{
printf("\n\t\t MENU \n 1.Append \n 2.Display(Forward) \n 3.Display(Reverse) \n 4.Deletion \n 5.Exit \n");
printf("Enter your choice");
scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		{
		printf("Enter Data :");
		scanf("%d",&entry);
		if(head==NULL)
		{
		head=(struct node *)malloc(sizeof(struct node));
		head->prev=NULL;
		head->data=entry;
		head->next=NULL;
		pos=head;
		tail=head;
		}
		else{
		tail->next=(struct node *)malloc(sizeof(struct node));
		tail->next->prev=tail;
		tail->next->data=entry;
		tail->next->next=NULL;
		tail=tail->next;
		}
		break;
		}


		case 2:{
		pos=head;
		printf("\n Elements are :");
		while(pos!=NULL)
		{
		printf("\t %d",pos->data);
		pos=pos->next;
		}break;}


		case 3:{
		pos=tail;
		printf("\n Elements in reverse order are :");
		while(pos!=NULL)
		{
		printf("\t %d",pos->data);
		pos=pos->prev;
		}break;
		}


	        case 4:
			{
			struct node *del, *temp;
			printf("\nenter the position the element needs to be deleted from zero:");
			scanf("%d",&entry);
			if(entry==0)
			{
			struct node *del=head;
			head=head->next;
			del->next=NULL;
			head->prev=NULL;
			free(del);
			}
			else
			{
			temp=head;
			for(int i=0;i<entry-1;i++)
			{
			temp=temp->next;
			}
			if(temp->next->next==NULL)
			{
			struct node *del=tail;
			tail=temp;
			temp->next=NULL;
			del->prev=NULL;
			free(del);
			}
			else
			{
			struct node *del= temp->next;
			temp->next=temp->next->next;
			temp->next->prev=temp;
			del->prev=NULL;
			del->next=NULL;
			free (del);
			}
			}
			break;
			}
	case 5:{
			printf("\n Good Bye\n");
			exit(0);
			}
}}}
