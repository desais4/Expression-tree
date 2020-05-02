#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string.h>
#include "tree_stack.h"	//USER DEFINED HEADER FILE

class extree
{
	struct node *root=NULL;
	public:
	struct node *cons_post(char a[20],struct node *root);
	struct node *cons_pre(char a[20],struct node *root);
};

struct node *extree :: cons_post(char post[20],struct node *root)
{
	struct node *exp,*ch1,*ch2;
	stack_t st;
	for(int i=0;post[i]!='\0';i++)
	{
		if(isalnum(post[i]))	//For pushing operands onto the stack
		{
			exp=new node;
			exp->left=exp->right=NULL;
			exp->data=post[i];
			st.push(exp);	
		}
		else			//For popping two operands if an operator is encountered
		{
			ch1=st.pop();
			ch2=st.pop();
			exp=new node;
			exp->data=post[i];
			exp->left=ch2;	
			exp->right=ch1;
			st.push(exp);	//For pushing evaluated expression onto the stack
		}
	}
	root=st.pop();
	cout<<"\nExpression tree created";
	return root;
}

struct node *extree :: cons_pre(char pre[20],struct node *root1)
{
	struct node *exp,*ch1,*ch2;
	stack_t st;
	int l=strlen(pre);
	for(int i=(l-1);i>=0;i--)
	{
		if(isalnum(pre[i]))
		{
			exp=new node;
			exp->left=exp->right=NULL;
			exp->data=pre[i];
			st.push(exp);	
		}
		else
		{
			ch1=st.pop();
			ch2=st.pop();
			exp=new node;
			exp->data=pre[i];
			exp->left=ch1;
			exp->right=ch2;
			st.push(exp);
		}
	}
	root1=st.pop();
	cout<<"\nExpression tree created ...\n";
	return root1;
}

int main()
{
	extree T;
	struct node *root=NULL,*root1=NULL;
	int ch,choice,ch1,len;
	char post[20],pre[20];
	do
	{
		cout<<"\n1.Operations on Postfix expression \n2.Operations on Prefix expression \n3.exit";
		cout<<"\nEnter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			int cnt, cnt1;
			cout<<"\nEnter postfix expression : ";
			cin>>post;
			len=strlen(post);
			cnt=cnt1=0;
			if(isalnum(post[0]) && isalnum(post[1]) && !isalnum(post[len-1]) )
			{
				for(int i=0;i<len;i++)
				{
					if( isalnum(post[i]) )
						cnt++;
					else
						cnt1++;
				}
				if( cnt>cnt1)	
					cout<<post;
				else
				{
					cout<<"\n Invalid expression..\n";
					break;
				}
			}
			else
			{
				cout<<"\n Invalid expression..\n";
				break;
			}	
			
			int x;
			do
			{
				cout<<"\n1.Construct tree \n2.Display using recursion \n3.Display using non-recursion \n4.exit : ";
				cin>>x;
				switch(x)
				{
					case 1:
					root=T.cons_post(post,root);
					break;
					
					case 2:
					cout<<"\nDisplay in : \n1.Preorder \n2.Inorder \n3.Postorder  : ";
					int ch;
					cin>>ch;
					switch(ch)
					{
						case 1:
						cout<<"\nPreorder traversal is : ";
						preorder(root);
						break;
						
						case 2:
						cout<<"\nInorder traversal is : ";
						inorder(root);
						break;
						
						case 3:
						cout<<"\nPostorder traversal is : ";
						postorder(root);
						break;
					}
					break;
				
					case 3:
					cout<<"\nDisplay in : \n1.Preorder \n2.Inorder \n3.Postorder  : ";
					int ch1;
					cin>>ch1;
					switch(ch1)
					{
						case 1:
						cout<<"\nPreorder traversal is : ";
						nrec_preorder(root);
						break;
						
						case 2:
						cout<<"\nInorder traversal is : ";
						nrec_inorder(root);
						break;
						
						case 3:
						cout<<"\nPostorder traversal is : ";
						nrec_postorder(root);
						break;
					}
					break;
				}
			}while(x!=4);
			break;	
				
			case 2:
			cout<<"\nEnter prefix expression : ";
			cin>>pre;
			len=strlen(pre);
			cnt=cnt1=0;
			if(!isalnum(pre[0]) && isalnum(pre[len-1]) && isalnum(pre[len-2]) )
			{
				for(int i=0;i<len;i++)
				{
					if( isalnum(pre[i]) )
						cnt++;
					else
						cnt1++;
				}
				if( cnt>cnt1)	
					cout<<pre;
				else
				{
					cout<<"\n Invalid expression..\n";
					break;
				}
			}
			else
			{
				cout<<"\n Invalid expression..\n";
				break;;
			}	
			
			int x1;
			do
			{
				cout<<"\n1.Construct tree \n2.Display using recursion \n3.Display using non-recursion \n4.exit : ";
				cin>>x1;
				switch(x1)
				{
					case 1:
					root1=T.cons_pre(pre,root1);
					break;
					
					case 2:
					cout<<"\nDisplay in : \n1.Postorder \n2.Inorder \n3.Preorder  : ";
					int c;
					cin>>c;
					switch(c)
					{
						case 1:
						cout<<"\nPostorder traversal is : ";
						postorder(root1);
						break;
						
						case 2:
						cout<<"\nInorder traversal is : ";
						inorder(root1);
						break;
					
						case 3:
						cout<<"\nPreorder traversal is : ";
						preorder(root1);
						break;
					}
					break;
					
					case 3:
					cout<<"\nDisplay in : \n1.Postorder \n2.Inorder \n3.Preorder  : ";
					int c1;
					cin>>c1;
					switch(c1)
					{
						case 1:
						cout<<"\nPostorder traversal is : ";
						nrec_postorder(root1);
						break;
						
						case 2:
						cout<<"\nInorder traversal is : ";
						nrec_inorder(root1);
						break;
						
						case 3:
						cout<<"\nPreorder traversal is : ";
						nrec_preorder(root1);
						break;
					}
					break;
				}
			}while(x1!=4);
			break;
		}
	}while(choice<3);
	return 0;
}


