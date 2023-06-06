#include<bits/stdc++.h>

using namespace std;

class Dict
{
	struct Node
	{
		string keyword;
		string meaning;
		Node *left;
		Node *right;
	}*root;
	
	public:
	Dict()
	{
		root = NULL;
	}
	
	void insert(string keyword, string meaning)
	{
		Node *t = root;
		Node *p,*r;
		//string keyword,meaning;
		//cout<<"Enter word : ";
		//cin>>keyword;
		//cout<<"Enter Meaning : ";
		//cin.ignore();
                //getline(cin, meaning);
                
                if(root == NULL)
                {
                	root = new Node;
                	root->keyword = keyword;
                	root->meaning = meaning;
                	root->left = NULL;
                	root->right = NULL;
                }
                else
                {
                	while(t!=NULL)
                	{
                		r = t;
                		if(keyword < t->keyword)
                		{
                			t = t->left;
                		}
                		else if(keyword > t->keyword)
                		{
                			t = t->right;
                		}
                		else
                		{
                			cout<<"\nAlready Present";
                			return;
                		}
                	}
                	
                	p = new Node;
                	p->keyword = keyword;
                	p->meaning = meaning;
                	p->left = NULL;
                	p->right = NULL;
                	
                	if(keyword < r->keyword) r->left = p;
                	else r->right = p;
                }
	}
	
	
	void inorder(Node *root)
	{
		if(root)
		{
			inorder(root->left);
			cout<<"Word : "<<root->keyword<<"  Meaning : "<<root->meaning<<"\n";
			inorder(root->right);
		}
	}
	void ascendingOrder()
	{
		inorder(root);
	}
	
	void revinorder(Node *root)
	{
		inorder(root->right);
		cout<<"Word : "<<root->keyword<<"  Meaning : "<<root->meaning<<"\n";
		inorder(root->left);
	}
	
	void descendingOrder()
	{
		revinorder(root);
	}
	
	void search()
	{
		string keyword;
		int count=0;
		cout<<"Enter Keyword To Search : ";
		cin>>keyword;
		Node *t = root;
		while(t!=NULL)
		{
			if(keyword < t->keyword)
			{
				t = t->left;
				count++;
			}
			else if(keyword > t->keyword)
			{
				t = t->right;
				count++;
			}
			if(keyword == t->keyword)
			{
				cout<<"Word Found!!\nWord : "<<root->keyword<<"  Meaning : "<<root->meaning<<"\n Comparisons : "<<count;
				return;
			}
		}
		
		cout<<"\nWord Not Found!!";
	}	
};

int main()
{
	Dict d;
	d.insert("Speaker","Eletronic Gadget to listen to audio");
	d.insert("Case","Box to keep some items");
	d.insert("Telephone","Device used to call");
	d.insert("Monitor","Output display of a personal computer");
	//d.ascendingOrder();
	d.descendingOrder();
	d.search();
	
}
