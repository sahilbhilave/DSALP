#include<bits/stdc++.h>
using namespace std;



class BST
{
  struct Node
  {
    int data;
    Node *left;
    Node *right;
  }*root;
public:
  BST()
  {
    root = NULL;
  }

  void insert()
  {
    int data;
    cout<<"Enter Data : ";
    cin>>data;

    Node *p,*t;
    t = root;

    if(root == NULL)
    {
      root = new Node;
      root->data = data;
      root->left = NULL;
      root->right = NULL;
    }
    else
    {
      while(t!=NULL){
        p = t;
        if(data < t->data)
        {
          t = t->left;
        }
        else if(data > t->data)
        {
          t = t->right;
        }
        else
        {
          cout<<"\nDublicate Value\n";
          return;
        }
      }

      t = new Node;
      t->data = data;
      t->left = NULL;
      t->right = NULL;
      if(t->data < p->data)
        p->left = t;
      else p->right = t;

    }
  }

  void inorder()
  {
    Node *t = root;
    stack<Node *> st;
    cout<<"\nInorder\n";
    while(t!=NULL || !st.empty())
    {
      if(t!=NULL)
      {
        st.push(t);
        t = t->left;
      }
      else
      {
        t = st.top();
        st.pop();
        cout<<t->data<<" ";
        t = t->right;
      }
    }
  }
  
  void preorder()
  {
    Node *t = root;
    stack<Node *> st;
    cout<<"\nInorder\n";
    while(t!=NULL || !st.empty())
    {
      if(t!=NULL)
      {
      	cout<<t->data<<" ";
        st.push(t);
        t = t->left;
      }
      else
      {
        t = st.top();
        st.pop();
        t = t->right;
      }
    }
  }
  
  
  
  
  void height()
  {
      if (root != NULL)
      {
    
    stack<std::pair<Node*, int>> stack;
    stack.push({root, 1});
    
    int maxHeight = 0;
    
    while (!stack.empty()) {
        Node* current = stack.top().first;
        int height = stack.top().second;
        stack.pop();
        
        if (height > maxHeight)
            maxHeight = height;
        
        if (current->left != NULL)
            stack.push({current->left, height + 1});
        
        if (current->right != NULL)
            stack.push({current->right, height + 1});
    }
    

      cout<<"\nHeight : "<<maxHeight<<"\n";
  }
  }
  
  void minvalue()
  {
  	Node *t = root,*p;
  	while(t != NULL)
  	{
  		p=t;
  		t=t->left;
  	}
  	cout<<"Minimum Data : "<<p->data;
  }
  
  void swap()
  {
  	if (root != NULL)
        {
    stack<Node*> stack;
    stack.push(root);
    
    while (!stack.empty()) {
        Node* current = stack.top();
        stack.pop();
        
        Node* temp = current->left;
        current->left = current->right;
        current->right = temp;
        
        if (current->left != NULL)
            stack.push(current->left);
            
        if (current->right != NULL)
            stack.push(current->right);
    }
    }

  }
  
  Node *findSuccessor(Node *node)
    {
        Node *currNode = node->right;

        while (currNode->left != nullptr)
        {
            currNode = currNode->left;
        }

        return currNode;
    }

    void deleteNode(int value)
    {
    	
        Node *currNode = root;
        Node *parent = nullptr;

        while (currNode != nullptr && currNode->data != value)
        {
            parent = currNode;

            if (value < currNode->data)
            {
                currNode = currNode->left;
            }
            else
            {
                currNode = currNode->right;
            }
        }

        if (currNode == nullptr)
        {
            std::cout << "Node with value " << value << " does not exist in the BST.\n";
            return;
        }

        // Case 1: Node has no children (leaf node)
        if (currNode->left == nullptr && currNode->right == nullptr)
        {
            if (parent == nullptr)
            {
                // Deleting the root node
                root = nullptr;
            }
            else if (parent->left == currNode)
            {
                parent->left = nullptr;
            }
            else
            {
                parent->right = nullptr;
            }

            delete currNode;
        }
        // Case 2: Node has one child
        else if (currNode->left == nullptr || currNode->right == nullptr)
        {
            Node *child = (currNode->left != nullptr) ? currNode->left : currNode->right;

            if (parent == nullptr)
            {
                // Deleting the root node
                root = child;
            }
            else if (parent->left == currNode)
            {
                parent->left = child;
            }
            else
            {
                parent->right = child;
            }

            delete currNode;
        }
        // Case 3: Node has two children
        else
        {
            Node *successor = findSuccessor(currNode);
            int successorValue = successor->data;
            deleteNode(successorValue); // Delete the successor recursively

            currNode->data = successorValue;
        }

        std::cout << "Node with value " << value << " deleted from the BST.\n";
    }
  
};


int main()
{
  BST a;
  int c=-1;
  while(c!=0)
  {
  	cout<<"\n0.Exit";
  	cout<<"\n1.Insert Element";
  	cout<<"\n2.Height of Tree";
  	cout<<"\n3.Min Value of Tree";
  	cout<<"\n4.Swap Tree Pointers";
  	cout<<"\n5.Delete Node";
  	cout<<"\n6.Inorder";
  	cout<<"\nEnter choice : ";
  	cin>>c;
  	switch(c)
  	{
  		case 1:
  			a.insert();
  		break;
  		case 2:
  			a.height();
  		break;
  		case 3:
  		
  			a.minvalue();
  		break;
  		case 4:
  			a.swap();
  		break;
  		case 5:
  		int value;
    		cout<<"Enter value : ";
    		cin>>value;
  			a.deleteNode(value);
  		break;
  		case 6:
  			a.inorder();
  		break;
  	}
  } 
  

}
