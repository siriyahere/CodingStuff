#include<stdio.h>
#include<stdlib.h>
 
/* A Binary Tree node */
typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* newNode(int data)
{
	Node *node=(Node *)malloc(sizeof(Node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}
Node* construct(int *arr,int l,int r)
{
	if(l>r)
	{
		return NULL;
	}
	int mid=(l+r)/2;
	Node * node=newNode(arr[mid]);
	node->left =construct(arr,l,mid-1);
	node->right=construct(arr,mid+1,r);
	return node;
}

Node* createNode(int data)
{
		Node *node=(Node *)malloc(sizeof(Node));
		node->data = data;
		node->left = NULL;
		node->right= NULL;
		return node;
}

Node* search(Node *root,Node *temp)
{
	if(root->left==NULL&&root->right ==NULL)
		return root;
	if(root->data<temp->data)
	{
		return search(root->left,temp);
	}
	else
	{
		return search(root->right,temp);
	}
}

Node *buildTree(Node *root,int data)
{
		Node* node= createNode(data);
	if(root==NULL){
	
		root=node;
	}
	else
	{
		
		Node *pos=search(root,node);
		if(pos->data<data)
			pos->right=node;
		else
			pos->left=node;
	}
	
}

void preOrder(Node *root)
{
	if(root==NULL)
		return;
	printf("%d\n",root->data);
	preOrder(root->left);
	preOrder(root->right);
}

int size(Node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	return (size(root->left)+1+size(root->right));
}

int maxHeight(Node *root)
{
	if(root==NULL)
		return 0;
	int maxleft=maxHeight(root->left);
	int maxright=maxHeight(root->right);
	if(maxleft>maxright)
	{
		return maxleft+1;
	}
	return maxright+1;
}


bool compare(Node *tree1,Node *tree2 ){
	if(tree1==NULL&&tree2==NULL){
		return true;
	}
	else if(tree1!=NULL&&tree2!=NULL)
	{
		return ((tree1->data==tree2->data)&&compare(tree1->left,tree2->left)&&compare(tree1->right,tree2->right));
	}
	else
		return false;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    /* Convert List to BST */
    Node *root = construct(arr, 0, n-1);
    printf("\n PreOrder Traversal of constructed BST ");
    preOrder(root);
    printf("%d",size(root));
    printf("\n%d",maxHeight(root));
    Node *root1 = NULL;
    for(int i=0;i<n;i++)
		root1=buildTree(root1,arr[i]);
	preOrder(root1);
	printf("%d",compare(root,root1));
	//deleteTree(root1);
	return 0;
}
