#include<iostream>
#include <stdlib.h>
using namespace std;

typedef struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int val):right(NULL),left(NULL),val(val){};
	
}TreeNode;

typedef struct LLNode{
	TreeNode *data;
	struct LLNode *next;
	LLNode(TreeNode *root):next(NULL),data(root){};
	LLNode():next(NULL){};
}LLNode;

class queue{
	public:
	LLNode *front,*rear;
	public:
	queue():front(NULL),rear(NULL){};
	
	
	TreeNode* peek(){
			if(rear&&front)
			{
				TreeNode *top=front->data;
				return top;
			}
				return NULL;
		
			
	}
	void enqueue(TreeNode *root){
	
			LLNode *next=new LLNode(root);
			rear->next=next;
			rear=rear->next;	
		
	}
	void dequeue(){//,LLNode* &front,LLNode* &rear){
		int top;
		
			top=front->data->val;
			LLNode *temp=front;
			front=front->next;
			free(temp);
		//	return temp;
		
		
	//	return NULL;
	}
	
	bool isEmpty(){//}LLNode *front,LLNode *rear){
		
		return (!front||!rear);
			
	}
	
};

class Solution{
	
	public:
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
	
	public:
	 TreeNode* insert(TreeNode *root,int val){
		
			TreeNode* head=root;
			TreeNode* r=new TreeNode(val);
			if(!head)
				return r;
			while(head){
				if(head->val>val){
					if(!head->left){
					
						head->left=r;
						break;
				}
					else
						head=head->left;
				}
				else if(head->val<val)
				if(head->right)
					{
						head=head->right;
						
						}
				else{
				
					head->right=r;
					break;}
				else
					break;
			}	
					
			return root;
	}
	
	public:
	void print(TreeNode *root){
		if(!root)
			return ;
		print(root->left);
		cout<<root->val<<" ";
		print(root->right);
		
		
	}
};

int main(){
	
	Solution S;
	TreeNode *root=NULL;
    root = S.insert(root, 50);
	S.insert(root, 30);
	S.insert(root, 20);
	S.insert(root, 40);
	S.insert(root, 70);
	S.insert(root, 60);
	S.insert(root, 80);
	S.print(root);
	int val=40;
	if(S.search(root,val)!=NULL)
		cout<<"Found";
	else
		cout<<"Not found";
	
	queue q;
	if(!root)
		return 0;
	q.front=new LLNode();
	
	q.front->data=root;
	q.rear=q.front;
	
	LLNode *curr=q.front;
	while(curr!=NULL){
		if(curr->data->left){
			q.enqueue(curr->data->left);
		}
			if(curr->data->right){
			q.enqueue(curr->data->right);
		}
		curr=curr->next;
	}
	
	while(!q.isEmpty()){
		TreeNode *top=q.peek();
		cout<<top->val<<"\n";
		q.dequeue();
	}
	
	return 0;
}
