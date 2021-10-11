#include <iostream>
using namespace std;
class BNode
{
public:
	int data;
	BNode* left, * right;
	BNode()
	{
		data = 0;
		left = right = NULL;
	}
	BNode(int data)
	{
		this->data = data;
		left = right = NULL;
	}
	BNode(const BNode& n)
	{
		this->data = n.data;
		if(n.left)
		{
			this->left = new BNode();
			*this->left = *n.left;
		}
		else
		{
			this->left = NULL;
		}
		if(n.right)
		{
			this->right = new BNode();
			*this->right = *n.right;
		}
		else
		{
			this->right = NULL;
		}
	}
	~BNode()
	{
		cout<<"Destruct node"<<endl;
		if(left) delete left;
		if(right) delete right;
	}
};

class BST
{
	BNode* root;
public:
	BST()
	{
		root = NULL;
	}
	BST(const BST& bst)
	{
		if(bst.root)
		{
			this->root = new BNode();
			*this->root = *bst.root;
		}
		else
		{
			this->root = NULL;
		}
	}
	~BST()
	{
		cout<<"Destruct bst"<<endl;
		if(root) delete root;
	}
	BNode* search(int data)
	{
		if (root == NULL)
		{
			return NULL;
		}
		else
		{
			BNode* current = root;
			while (data != current->data)
			{
				if (data < current->data)
				{
					if (current->left == NULL)
					{
						return NULL;
					}
					else
					{
						current = current->left;
					}
				}
				else
				{
					if (current->right == NULL)
					{
						return NULL;
					}
					else
					{
						current = current->right;
					}
				}
			}
			return current;
		}
	}
	void insert(int data)
	{
		if (root == NULL)
		{
			root = new BNode(data);
		}
		else
		{
			BNode* current = root;
			while (true)
			{
				if (data < current->data)
				{
					if (current->left == NULL)
					{
						current->left = new BNode(data);
						return;
					}
					else
					{
						current = current->left;
					}
				}
				else
				{
					if (current->right == NULL)
					{
						current->right = new BNode(data);
						return;
					}
					else
					{
						current = current->right;
					}
				}
			}
		}
	}
	void erase(int data)
	{
	}
	void preTra(BNode *current)
	{
		if (current!=NULL)
		{	
			cout << current->data << " ";
			preTra(current->left);
			preTra(current->right);
		}
	}
	void inTra(BNode *current)
	{
		if (current!=NULL)
		{	
			inTra(current->left);
			cout << current->data << " ";
			inTra(current->right);
		}
	}
	void postTra(BNode *current)
	{
		if (current!=NULL)
		{	
			postTra(current->left);
			postTra(current->right);
			cout << current->data << " ";			
		}
	}
	void preTraverse()
	{
		preTra(root);
		cout<<endl;
	}
	void inTraverse()
	{
		inTra(root);
		cout<<endl;
	}
	void postTraverse()
	{
		postTra(root);
		cout<<endl;
	}
};


int main()
{
	int n, m;
	cin >> n;

	BST bst;

	for (int i = 0; i < n; i++)
	{
		cin >> m;
		bst.insert(m);
	}

	bst.inTraverse();
}


