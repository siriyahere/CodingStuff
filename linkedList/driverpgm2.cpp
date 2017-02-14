#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	int data;
	struct Node *next;
}Node;



Node* reverse(Node *head,int k)
{
	Node *temp=head;
	Node *current=head;
	Node *prev=NULL;
	int count=0;
	printf("inside reverse");
	//reverses k nodes
	while(current!=NULL&&count<k)
	{
		
		current=current->next;
		temp->next=prev;
		prev=temp;
		temp=current;
		count++;
	}
	//
	if(head!=NULL)
		head->next = current;
	count=0;
	while(count<k-1&&current!= NULL){
		current=current->next;
		count++;
	}
	if(current!=NULL)
		current->next=reverse(current->next,k);
	return prev;
}
	


void add(Node** list,int data)
{
	
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->next=(Node*)malloc(sizeof(Node));
	temp->data=data;
	temp->next=NULL;
	Node *traversal=*list;
	Node *prev=*list;
	if(*list==NULL)
	{
		*list=temp;
		return;
	}
	while(traversal->next!=NULL)
	{
		//printf("inside add%d\n",traversal->data);
		prev=prev->next;
		traversal=traversal->next;
		
	}
		prev->next=temp;
	//	printf("inside prev not null");
		
}


void print(Node *head)
{
	while(head!=NULL)
	{
		printf("%d\n",head->data);
		head=head->next;
	}
}


int main()
{
		Node *head;//=(Node*)malloc(sizeof(Node));
		head=NULL;
		//head->next=NULL;
		for(int i=1;i<20;i++)
			add(&head,i);
		print(head);
		head=reverse(head,3);
		print(head);
		return 0;
}
		


