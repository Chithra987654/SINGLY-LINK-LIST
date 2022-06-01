/* program to implement singly linked list(Insert, Display Operations,count,search,deletion) */
#include<stdio.h>
#include<stdlib.h>

void main()
{
	struct node
	{
	int data;
	struct node *next;
};

	struct node *head=NULL,*pos=NULL,*tail=NULL;
	int ch,entry,k,count=0,flag;


	while(1)
	{
	printf("\n 1.Insert \n 2.Display \n 3.Count \n 4.Search for an element \n 5.Deletion of an element \n 6.Exit");
	printf("\nEnter your choice:");
	scanf("%d",&ch);

		switch(ch)
		{
			case 1:{
			printf("\n Enter the data:");
			scanf("%d",&entry);

				if(head==NULL)
				{
				head=(struct node *)malloc(sizeof(struct node));
				head->data=entry;
				pos=head;
				tail=head;
				}
				else
				{
				tail->next=(struct node *)malloc(sizeof(struct node));
				tail=tail->next;
				tail->data=entry;
				}
			break;
			}

			case 2:{
			pos=head;
			printf("\n Elements are:");
			while(pos!=NULL)
			{
			printf("\t %d",pos->data);
			pos=pos->next;
			}
			break;
			}

			case 3:{
			pos=head;
			while(pos!=NULL)
			{
			//printf("%d",pos->data);
			pos=pos->next;
			
			count=count+1;
			}

			printf("\nThe number of elements :");
			printf("%d",count);
			break;
			}

			case 4:{
			flag=0;
			printf("Enter the element to be searched:");
			scanf("%d",&k);
			pos=head;
			while(pos!=NULL)
			{
			if(pos->data==k){
				flag=1;}
				pos=pos->next;}
			if(flag==1){
			printf("Element found: %d",k);}
			else{
			printf("Element not found\n");}
			
			break;	
			}

			case 5:{
			struct node *temp=head;
			printf("\n Enter the position of data to be deleted from '0' :");
			scanf("%d",&entry);
			 
			 if(entry==0)
			{
			head=head->next;
			temp->next=NULL;
			free(temp);
			}
			else
			{
			for(int i=0;i<entry-1;i++)
			{
			temp=temp->next;}
			struct node *del=temp->next;
			temp->next=temp->next->next;
			del->next=NULL;
			free(del);
			}
			break;
			}


			case 6:{
			printf("\n Good Bye\n");
			exit(0);
			}
		   } 
	}	
} 
