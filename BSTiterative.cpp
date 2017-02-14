#include<iostream>
#include<vector>
#include<algorithm>
#include <cstddef>

using namespace std;

typedef struct TreeNode{
	
	int val;
	TreeNode *left;
	TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

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

	return 0;
}
