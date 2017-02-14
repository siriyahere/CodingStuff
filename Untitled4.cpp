// Iterative Queue based C program to do level order traversal
// of Binary Tree
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#define MAX_Q_SIZE 500
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(){}
	TreeNode(int val):val(val),left(NULL),right(NULL){}
}TreeNode;

typedef struct LLNode{
    TreeNode *data;
    LLNode *next;
    LLNode():next(NULL){};
}LLNode;

/* frunction prototypes */
struct node** createQueue(int *, int *);
void enQueue(struct node **, int *, struct node *);
struct node *deQueue(struct node **, int *);

/* Given a binary tree, print its nodes in level order
using array for implementing queue */

//void enqueue(TreeNode *)
void printLevelOrder(TreeNode* root)
{
	   
       LLNode *front=NULL,*end=NULL;
        if(!root)
            return ;

        front=new LLNode();

        front->data=root;
        end=front;

        LLNode *curr=front;
       while(curr){
            if(curr->data->left){
                LLNode *t=new LLNode();
                
                t->data=curr->data->left;
                end->next=t;
                end=end->next;
            }
            if(curr->data->right){
                LLNode *t=new LLNode();
                
                t->data=curr->data->right;
                end->next=t;
                end=end->next;
            }    
//            cout<<curr->data->val<<"\t";
            curr=curr->next;        
        }
        while(front!=end){
            cout<<front->data->val<<"\t";
            front=front->next;
            
        }
        cout<<front->data->val<<"\t";
        
}

/*UTILITY FUNCTIONS*/
/*struct node** createQueue(int *front, int *rear)
{
	struct node **queue =
		(struct node **)malloc(sizeof(struct node*)*MAX_Q_SIZE);

	*front = *rear = 0;
	return queue;
}

void enQueue(struct node **queue, int *rear, struct node *new_node)
{
	queue[*rear] = new_node;
	(*rear)++;
}

struct node *deQueue(struct node **queue, int *front)
{
	(*front)++;
	return queue[*front - 1];
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. 
struct node* newNode(int data)
{
	struct node* node = (struct node*)
						malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}
*/
/* Driver program to test above functions*/


	TreeNode* search(TreeNode *root,int val){
		while(root){
			if(root->val==val)
				return root;
			else if(val<root->val)
				root=root->left;
			else
				root=root->right;
		}
		return NULL;
	}
	
	
	 TreeNode* insert(TreeNode *root,int val){
		
			TreeNode* head=root;
			TreeNode* r=new TreeNode(val);
			if(!head)
				return r;
			while(head){
				if(head->val>val){
					if(!head->left)
						head->left=r;
					else
						head=head->left;
				}
				else if(head->val<val)
				if(head->right)
					head=head->right;
				else
					head->right=r;
				else
					break;
			}	
					
			return root;
	}
	
		void print(TreeNode *root){
		if(!root)
			return ;
		print(root->left);
	//	cout<<root->val<<" ";
		print(root->right);
		
		
	}
	
int main()
{
	TreeNode *root=NULL;// = new TreeNode(5);
	 root =insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
//	print(root);
	
//	cout<"before BFS";
	printf("Level Order traversal of binary tree is \n");
	printLevelOrder(root);

	return 0;
}

