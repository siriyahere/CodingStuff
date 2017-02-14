void printLevelOrder(struct TreeNode* root)
{
	  TreeNode **q=new TreeNode*[100];
        int front,end;
        front=0,end=0;
        if(!root)
            return ;
        q[end]=root;
        end++;
        //q.push(NULL);
        //vector<int> curr;
        while(front!=end){
            TreeNode* top=q[front];
            front++;
            
            /*if(top==NULL){
                result.push_back(curr);
                curr.resize(0);
                if(q.size()>0)
                    q.push(NULL);
                continue;
            }*/
            cout<<top->val;
            //curr.push_back(top->val);
            if(top->left)
                q[end++]=top->left;
            if(top->right)
                q[end++]=(top->right);
        }
}
