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

void print(Node *head)
{
	while(head!=NULL)
	{
		printf("%d\n",head->data);
		head=head->next;
	}
}

void delet(Node **list,int data)
{
	Node *temp=*list;
	Node *prev=NULL;

	while(temp!=NULL)
	{
		if(temp->data==data)
		{
			Node *del=temp;
			if(prev!=NULL){
			
				prev->next=temp->next;
			}
			else
			{
					*list=temp->next;
					
			}
			temp=temp->next;
			free(del);
		}
		else
		{
			prev=temp;
			temp=temp->next;
		}
	}
}
void insert(Node **head,int data)
{
	Node *prev=NULL;
	Node *temp=(*head);
	Node *created=(Node *)malloc(sizeof(Node));
	created->data=data;
	created->next=NULL;		
	while(temp!=NULL)
	{
		if(temp->data>data)
		{
			created->next=temp;
			if(prev!=NULL)
				prev->next=created;
			else
				*head=created;
			return;
		}
		prev=temp;
		temp=temp->next;
	}
	prev->next=created;
}
int findmiddle(Node *head)
{
	if(head!=NULL){
	
	Node *fast=head;
	Node *slow=head;
	while(fast!=NULL&&fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow->data;
  }
}
int findnthfromend(Node *head,int n)
{
	if(head!=NULL)
	{
		Node *ref=head;
		Node *main=head;
		for(int i=0;i<n;i++)
		{
			if(ref!=NULL)
				ref=ref->next;
			else
			return -2222;
		}
		while(ref!=NULL)
		{
			ref=ref->next;
			main=main->next;
		}
		return main->data;
	}
}
void deletelist(Node **head)
{
	Node *temp=*head;
	Node *next=temp;
	while(temp!=NULL)
	{
		next=temp->next;
		printf("\ndeleteing %d",temp->data);
		free(temp);
		temp=next;
	}
	*head=NULL;
	
}
Node* reverse(Node *head)
{
	Node *current=head;
	Node *prev=NULL;
	Node *temp=current;
	while(temp!=NULL)
	{
		temp=temp->next;
		current->next=prev;
		prev=current;
		current=temp;
		
	}
	head=prev;
	return head;
}

void findLoop(Node *head)
{
	Node *slow=head;
	Node *fast=head;
	while(fast!=NULL&&fast->next!=NULL&&slow!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(slow==fast)
		{
			printf("\n loop detected");
			return ;
		}
		
		
	}
	printf("No Loop");
}


bool isPalindrome(Node *head)
{
	if(head!=NULL){
	
	Node *fast=head;
	Node *slow=head;
	while(fast!=NULL&&fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	Node *middle=slow;
	middle->next=reverse(slow->next);
	Node *current=middle->next;
	while(head!=middle)
	{
		if(head->data!=current->data)	
			return 0;
		head=head->next;
		current=current->next;
	}
	middle->next=reverse(middle->next);
	return 1;
}
	
}
//4 3 2 1
void pairwiseSplit(Node **head)
{
	Node *curr=(*head)->next;
/*	if(head!=NULL&&(*head)->next!=NULL)
	{
		*head=(*head)->next;
	}
*/	
	Node *temp=(Node*)malloc(sizeof(Node));
	Node *prev=*head;
	Node *prev1=NULL;
	temp=NULL;
	int a;
	while(curr!=NULL&&curr->next!=NULL)
	{
		  //4 2
		  temp=curr->next; //2   nu
		  curr->next=prev; //3 4  
		  prev->next=temp; //3 4 2
		  
		  
		  if(prev1!=NULL)
		  {
		  	prev1->next=curr;  //
		  	prev1=prev;
		  }
		  else
		  {
		  		*head=curr; //3
				 prev1=prev; //4	
		  }
		  curr=temp->next; //1
		  prev=temp; //2
	}
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
		delet(&head,5);
		printf("delted");
		print(head);
		//insert(&head,7);
		//insert(&head,10);
		print(head);
		printf("%d\n",findmiddle(head));
		printf("%d node%d",3,findnthfromend(head,3));
		//free(head);
		head=reverse(head);
		print(head);
		findLoop(head);
		if(isPalindrome(head))
			printf("\nyes");
		else
			printf("\nno");
		print(head);
		pairwiseSplit(&head);
		printf("\nAfter pairwise swap\n");
		print(head);
		//deletelist(&head);
		//print(head);
		return 0;
}
