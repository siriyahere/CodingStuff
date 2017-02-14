#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	int data;
	struct Node *next;
}Node;


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

int main()
{
		Node *head;//=(Node*)malloc(sizeof(Node));
		head=NULL;
		//head->next=NULL;
		add(&head,1);
		//printf("\nafter addibg");
		//print(head);
		add(&head,2);
		//printf("\nafter addibg");
		//print(head);
		add(&head,3);
		//printf("\nafter addibg");
		//print(head);
		
		add(&head,4);
		add(&head,5);
		add(&head,7);
		print(head);
		mergeSort(&head);
		print(head);
		head=reverse(head);
		printf("\n after reverse \n");
		print(head);
		return 0;
}
