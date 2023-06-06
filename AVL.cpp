#include<iostream>
using namespace std;

struct Node
{
	int data;
	int height;
	Node *left;
	Node *right;
}*root = NULL;


int nodeHeight(Node *root)
{
	int hl,hr;
	if(root!=NULL && root->left!=NULL)
		hl = root->left->height;
	else
		hl = 0;
	
	if(root!=NULL && root->right != NULL)
		hr = root->right->height;
	else
		hr = 0;
		
	return hl>hr?hl+1:hr+1;
}	


int balanceFactor(Node *root)
{
	int hl,hr;
	if(root && root->left)
		hl = root->left->height;
	else
		hl = 0;
	
	if(root && root->right)
		hr = root->right->height;
	else
		hr = 0;
	
	return hl-hr;
}

Node * LLRotation(Node *p)
{
	Node *pl = p->left;
	Node *plr = pl->right;
	
	pl->right = p;
	p->left = plr;
	
	p->height = nodeHeight(p);
	pl->height = nodeHeight(pl);
	
	if(p == root)
		root = pl;
	
	return pl;
}

Node *LRRotation(Node *p)
{
	Node *pl = p->left;
	Node *plr = pl->right;
	
	pl->right = plr->left;
	p->left = plr->right;
	
	plr->left = pl;
	plr->right = p;
	
	p->height = nodeHeight(p);
	pl->height = nodeHeight(pl);
	plr->height = nodeHeight(plr);
	
	if(p == root)
		root = plr;
	
	return plr;
}



Node *insert (Node *p,int key)
{
	Node *t = NULL;
	if(p == NULL)
	{
		t = new Node;
		t->data = key;
		t->left = NULL;
		t->right = NULL;
		t->height = 1;
		return t;
	}
	
	if(key < p->data)
		p->left = insert(p->left,key);
	else if(key > p->data)
		p->right = insert(p->right,key);
		
	p->height = nodeHeight(p);
	
	if(balanceFactor(p) == 2 && balanceFactor(p->left) == 1)
	{
		return LLRotation(p);
	}
	
	else if(balanceFactor(p) == 2 && balanceFactor(p->left) == -1)
	{
		return LRRotation(p);
	}
	else if(balanceFactor(p) == -2 && balanceFactor(p->left) == -1)
	{
		//return RRRotation(p);
	}
	else if(balanceFactor(p) == -2 && balanceFactor(p->left) == 1)
	{
		//return RLRotation(p);
	}
	
	return p;
}

void inorder(Node *root)
{
	if(root)
	{
		inorder(root->left);
		
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

Node* findMinValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}


Node *deleteNode (Node *node , int key)
{
	if(node == NULL)
		return node;
	if(key < node->data)
	{
		node->left = deleteNode(node->left,key);
	}
	else if(key > node->data)
	{
		node->right = deleteNode(node->right,key);
	}
	else
	{
		if(node->left == NULL || node->right == NULL)
		{
			Node *temp;
			if(node->left == NULL)
				temp = node->right;
			else
				temp = node->left;
			
			//No children
			if(temp == NULL)
			{
				temp = node;
				node = NULL;
			}
			//1 children
			else
			{
				node = temp;
			}
			delete temp;
		}
		else
		{
			Node *temp = findMinValueNode(node->right);
			node->data = temp->data;
			node->right = deleteNode(node->right,temp->data);
		}
	}
	
	if(node == NULL)
		return node;
	node->height = nodeHeight(node);
	
	if(balanceFactor(node) == 2 && balanceFactor(node->left) == 1)
	{
		return LLRotation(node);
	}
	
	else if(balanceFactor(node) == 2 && balanceFactor(node->left) == -1)
	{
		return LRRotation(node);
	}
	else if(balanceFactor(node) == -2 && balanceFactor(node->left) == -1)
	{
		//return RRRotation(p);
	}
	else if(balanceFactor(node) == -2 && balanceFactor(node->left) == 1)
	{
		//return RLRotation(p);
	}
	
	return node;
}


int main()
{
	root = insert(root,50);
	insert(root,10);
	insert(root,20);
	insert(root,15);
	deleteNode(root,20);
	
	inorder(root);
}
