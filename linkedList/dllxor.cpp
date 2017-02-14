#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	int data;
	struct Node* next;
}Node;

Node *XOR(Node *p,Node *n)
{
	return (struct node*) ((unsigned int) (p) ^ (unsigned int) (n));
}

void addNode(Node **list,int data)
{
	Node *head=*list;
	Node *temp=(Node *)malloc(sizeof(Node));
	temp->data=data;
	temp->next=NULL;
	if(head==NULL)
	{
		*list=temp;
		return;
	}
	Node *prevAddr=NULL;
	Node *current=XOR(prevAddr,head->next);
	Node *next;
	while(current!=NULL)
	{
		next=XOR(prevAddr,current->next);
		prevAddr=current;
		current=next;
	}
	temp->next=XOR(prevAddr,NULL);
	prevAddr->next=XOR(temp,prevAddr->next);
}

void print(Node *head)
{
	Node *current=head;
	Node *prev = head;
	while(current!=NULL)
	{
		printf("%d\n",current->data);
		Node *next=XOR(current,prev);
		prev=current;
		current=next;
	}
}

int main()
{
	Node *head=(Node *)malloc(sizeof(Node));
	head->next=(Node *)malloc(sizeof(Node));
	addNode(&head,1);
	addNode(&head,2);
	addNode(&head,3);
	addNode(&head,4);
	addNode(&head,5);
	addNode(&head,6);
	print(head);
	return 0;
}
