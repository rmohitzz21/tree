#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct tree
{
	int info;

	struct tree *left;
	struct tree *right;

};

struct tree *insert(struct tree *,int);
void inorder(struct tree *);
void preorder(struct tree *);
void postorder(struct tree *);

int main()
{
	struct tree *root;
	int ch,val;
	root=NULL;
	clrscr();
	do
	{
		printf("\n1:INSERT");
		printf("\n2:INORDER");
		printf("\n3:PREORDER");
		printf("\n4:POSTORDER");
		printf("\n5:EXIT");

		printf("\n ENTER YOUR CHOICE:");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("\n enter new element :");
				scanf("%d",&val);
				root=insert(root,val);

				printf("\n");
				inorder(root);
				break;

			case 2:
				printf("Inorder traversal of tree is...");
				inorder(root);
				break;
			case 3:
				printf("preorder traversal of tree is..");
				preorder(root);
				break;
			case 4:
				printf("postorder of traversal is...");
				postorder(root);
				break;
			case 5:

				break;
		}
	}while(ch!=5);
   return 0;

}

struct tree *insert(struct tree *root ,int x)
{
	if(!root)
	{
		root=(struct tree *)malloc(sizeof(struct tree));
		root->info=x;
		root->left=NULL;
		root->right=NULL;
		return(root);
	}

	if(root->info>x)
	root->left=insert(root->left,x);
	else
{
		if(root->info<x)

			root->right=insert(root->right,x);
	}
     return(root);

}
void inorder(struct tree *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("\t%d",root->info);
		inorder(root->right);
	}
	return;
}

void preorder(struct tree *root)
{
	if(root!=NULL)
	{
		printf("\t %d",root->info);
		preorder(root->left);
		preorder(root->right);
	}
      return;
}

void postorder(struct tree *root)
{
	 if(root!=NULL)
	 {
	       postorder(root->left);
	       postorder(root->right);
	       printf("\t %d",root->info);
	  }
     return;
}