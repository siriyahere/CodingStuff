
				TreeNode *head=root;
				TreeNode *r=new TreeNode(val);
				
				if(!head){
				
					return r;
				}
			//	cout<<root->val<<" ";
				while(true){
					
					if(head->val>val){
						
						if(head->left)
							head=head->left;
						else{
							head->left=r;
							return root;
						}
						
					}
					else if(head->val<val){
						
						if(head->right)
							head=head->right;
						else{
							head->right=r;
							return root;
						}
					}
					else
						break;
					
