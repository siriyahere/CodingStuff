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

Node *reverse(Node *head)
{
	Node *s,*t,*prev;
	s=head;
	t=head;
	prev=NULL;
	while(t!=NULL)
	{
		t=t->next;
		s->next=prev;
		prev=s;
		s=t;
	}
	return prev;
}

void *findMid(Node *head,Node **a,Node **b)
{
	Node *slow=head;
	Node *fast=head;
	if(head==NULL||head->next==NULL)
	{
		*a=head;
		*b=NULL;
	}
	else{
	
/*	while(fast!=NULL)
	{
		fast = fast->next;
		if(fast!=NULL){
		fast=fast->next;
		slow=slow->next;
	}
	}*/
		while(fast!=NULL&&fast->next!=NULL)
		{
			fast=fast->next->next;
			if(fast!=NULL)  //withoiut this condition similar to mid-1 pbm
				slow=slow->next;
		}
	*a=head;
	*b=slow->next;
	//if(slow!=NULL)
		slow->next=NULL;
}
}
Node *SortedMerge(Node *l,Node *r)
{
	if(l==NULL)
		return r;
	if(r==NULL)
		return l;
		Node *result=(Node *)malloc(sizeof(Node));
	if(l->data<r->data)
	{
		result=l;
		result->next=SortedMerge(l->next,r);
	}
	else
	{
		result=r;
		result->next=SortedMerge(l,r->next);
	}
		return result;
}

void mergeSort(Node **href)
{
	Node *head=*href;
	Node *a,*b;
	if(head==NULL||head->next==NULL)
	{
		return ;
	}
//	a=(Node *)malloc(sizeof(Node));
//	b=(Node *)malloc(sizeof(Node));
	a=NULL;
	b=NULL;
	
	printf("b4 mid");
	findMid(head,&a,&b);
	printf("after mid");
	//print(a);

	mergeSort(&a);
	//print(b);
	mergeSort(&b);
	printf("before merge");
	*href=SortedMerge(a,b);
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
