#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

typedef struct TreeNode{
	int val;
	 TreeNode *left;
	 TreeNode *right;
	TreeNode(int val):val(val),left(NULL),right(NULL){};
}TreeNode;

class Solution{
	
	public:
		
	TreeNode *dR(TreeNode *root){
		if(!root->left&&!root->right)
			return NULL;
		if(!root>left)
			return root->right;
		if(!root->right)
			return root->left;
		TreeNode *curr=root->right;
		TreeNode *pre=NULL;
		while(curr->left){
			pre=curr;
			curr=curr->left;
	}
	curr->left=root->left;
	if(root->right!=curr){
		pre->left=curr->right;
		curr->right=root->right;
	}
	
		return curr;
	}
	
	TreeNode *delete(TreeNode *root,int val){
		
		TreeNode *curr=root;
		TreeNode *pre=NULL;
		while(curr&&curr->val!=key){
			pre=curr;
			if(curr->data>val)
				curr=curr->left;
			else if(curr->data<val)
				curr=curr->right;
		}
		if(pre==NULL)
			return dR(curr);
		if(curr=pre->left)
			pre->left=dR(curr);
		else
			pre->right=dR(curr);
		return root;
	}
	
	TreeNode* insert(TreeNode *root,int val){
	
		TreeNode *newNode=new TreeNode(val);
		if(!root){
			root=newNode;
			return root;
		}	
		TreeNode *curr=root;
		while(curr){
			if(val<curr->val){
				if(curr->left){
				
					curr=curr->left;
				}
				else{
					curr->left=newNode;
					break;
			}
		}
			else if(val>curr->val){
				if(curr->right)
					curr=curr->right;
				else{
				
					curr->right=newNode;
					break;
			}
			}
			else
				return root;
		}
		return root;
	}
	
	TreeNode* search(TreeNode *root,int val){
		TreeNode *curr=root;
		while(curr){
			
				if(curr->val==val)
					return curr;
				else if(curr->val<val)
					curr=curr->right;
				else
					curr=curr->left;
				
		}
		return NULL;
	}
	
	void print(TreeNode *root){
		
		if(!root)
			return;
		print(root->left);
		cout<<root->val<<"\n";
		print(root->right);
	}
	//Inorder
	void printMorris(TreeNode *root){
		
		TreeNode *curr=root;
		TreeNode *pre;
		if(!root)
			return;
		while(curr){
			if(curr->left){
				pre=curr->left;
				while(pre->right&&pre->right!=curr)
					pre=pre->right;
				if(!pre->right){
					pre->right=curr;
					curr=curr->left;
				}
				else{
					pre->right=NULL;
					cout<<curr->val<<endl;
					curr=curr->right;
				}
			}
			else{
				cout<<curr->val<<endl;
				curr=curr->right;
			}
			
		}
	}
	//Inorder
	void printStack(TreeNode *root){
		if(!root)
			return ;
		stack<TreeNode *> st;
		TreeNode *curr=root;
		while(curr||!st.empty()){
			while(curr){
				st.push(curr);
				curr=curr->left;
			}
			
			curr=st.top();
			st.pop();
			cout<<curr->val<<endl;
			curr=curr->right;
		}
	}
	
	//Preorder - root left right
	void preOrder(TreeNode *root){
		if(!root)
			return;
		cout<<root->val<<endl;
		preOrder(root->left);
		preOrder(root->right);
		
	}
	
	void preorderSta(TreeNode *root){
		if(!root)
			return;
		stack<TreeNode *> st;
		st.push(root);
		while(!st.empty()){
			TreeNode *top=st.top();
			cout<<top->val<<"\n";
			st.pop();
			if(top->right) 		
				st.push(top->right);
			if(top->left)
				st.push(top->left);	
		}
	}
	
	void zigzag(TreeNode *root){
		
		if(!root)
			return;
		vector<vector <int> > res;
		vector<int> path;
		stack<TreeNode *> next;
		stack<TreeNode *> curr;
		int d=1;
		curr.push(root);
		while(!curr.empty()){
			
			TreeNode *top=curr.top();
			curr.pop();
		//	path.push_back(top->val);
		cout<<top->val;
			if(d==1){
				if(top->left)
					next.push(top->left);
				if(top->right)
					next.push(top->right);
			}
			else
			{
					if(top->right)
					next.push(top->right);
					if(top->left)
					next.push(top->left);
			}
			if(curr.empty()){
				swap(curr,next);
				res.push_back(path);
				path.resize(0);
				d^=1;
			}
			
		}
		/*for(int n=0;n<res.size();n++){
			for(int m=0;m<res[n].size();m++)
				cout<<res[n][m]<<" ";
			cout<<endl;
		}*/
		
	}
	
	void printddls(TreeNode *root){
		
		if(!root)
			return;
		queue<TreeNode *> q;
		q.push(root);
		while(!q.empty()){
			TreeNode *top=q.front();
			cout<<top->val<<endl;
			q.pop();
			if(top->left)
				q.push(top->left);
			if(top->right)
				q.push(top->right);
		}
	}
	
	
	void printlevelwise(TreeNode *root){
		
		vector<vector <int> > res;
		vector<int> curr;
		queue<TreeNode *> q;
		if(!root)
			return;
		q.push(root);
		q.push(NULL);
		while(!q.empty()){
			
			TreeNode *top=q.front();
			q.pop();	
			
			if(top){
				curr.push_back(top->val);
				if(top->left)
					q.push(top->left);
				if(top->right)
					q.push(top->right);
			}
			else{
				res.push_back(curr);
				curr.resize(0);
				if(q.size())
					q.push(NULL);
			}
		}
		for(int n=0;n<res.size();n++){
			for(int m=0;m<res[n].size();m++)
				cout<<res[n][m]<<" ";
			cout<<endl;
		}
	}
	
	
	void inOrderSuccessor(TreeNode *root,TreeNode *node){
		
		if(!root||!node)
			return;
		if(node->right){
			while(node->left)
				node=node->left;
			cout<<node->val;
			return ;
		}
		TreeNode *succ=NULL;
		while(root){
			
			if(root->val>node->val){
				succ=root;
				root=root->left;
			}
			else if(root->val<node->val)
				root=root->right;
			else
				break;
		}
		if(succ)
			cout<<succ->val<<endl;
		
	}
 /*void connect(TreeLinkNode *root) {
        
        if(!root)
            return;
        TreeLinkNode *curr=root;
        TreeLinkNode *prev=NULL;
        TreeLinkNode *head=NULL;
        curr->next=NULL;
        while(curr){
            while(curr){
                if(curr->left){
                    if(prev){
                    prev->next=curr->left;
                     prev=prev->next;
                    
                    }
                    else{
                        prev=curr->left;
                        if(!head)
                            head=curr->left;
                    }
                   
                }
                 if(curr->right){
                    if(prev){
                    prev->next=curr->right;
                     prev=prev->next;
                    }
                    else{
                        prev=curr->right;
                        if(!head)
                            head=curr->right;
                    }
                   
                }   
                curr=curr->next;
                
            }
            curr=head;
            prev=NULL;
            head=NULL;
        }
    }*/
};

typedef struct LLNode{
	TreeNode *data;
    LLNode *next;
	LLNode(TreeNode *data):data(data),next(NULL){};
	
}LLNode;
class Queue1{

		LLNode *front,*rear;
		public:
		Queue1():front(NULL),rear(NULL){
		};
		Queue1(TreeNode *data){
			front=new LLNode(data);
			rear=front;
		}
		TreeNode *peek(){
			
			if(front)
				return front->data;
			else
				return NULL;
		}	
		
		void enqueue(TreeNode *node){
			if(!front){
				front=new LLNode(node);
				rear=front;
				
			}
			else{
				LLNode *temp=new LLNode(node);
				rear->next=temp;
				rear=rear->next;
				
			}
			
		}
		
		void dequeue(){
			if(front){
				LLNode *temp=front;
				front=front->next;
				free(temp);
			}
		}
		bool isEmpty(){
			return (!front||!rear);
				
			
		}
		void init_q(TreeNode *root){
			
			if(!root)
				return;
			enqueue(root);
			LLNode *curr=front;
			while(curr){
				if(curr->data->left)
					enqueue(curr->data->left);
				if(curr->data->right)
					enqueue(curr->data->right);
				curr=curr->next;	
			}
		}
		

	
};

int main(){
	
	Solution tree;
	TreeNode *root=NULL;
	root=tree.insert(root,50);
	tree.insert(root,90);
	tree.insert(root,10);
	tree.insert(root,40);
	tree.insert(root,70);
	tree.insert(root,30);
	tree.insert(root,20);
	tree.insert(root,80);
	tree.insert(root,9);
	tree.insert(root,19);
	tree.insert(root,98);
	tree.print(root);
	cout<<"Morris\n";
	tree.printMorris(root);
	cout<<"Stack\n";
	tree.printStack(root);
	cout<<"Queue Template\n";
	tree.printddls(root);
	cout<<"level wise\n";
	tree.printlevelwise(root);
	cout<<"Zig Zag Order\n";
	tree.zigzag(root);
	cout<<"Preoder\n";
	tree.preOrder(root);
	cout<<"Preoder-Stack\n";
	tree.preorderSta(root);
	cout<<"FInd Inorder successor\n";
	tree.inOrderSuccessor(root,tree.search(root,20));
	cout<<"Temp over\n";
//	tree.populateNextPointers(root);
	Queue1 *q=new Queue1();
	q->init_q(root);
	while(!q->isEmpty()){
		TreeNode *temp=q->peek();
		cout<<temp->val<<"\n";
		q->dequeue();
	}
}

