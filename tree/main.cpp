#include <iostream>
using namespace std;
class Node 
{
public:
int data;
Node *left , *right;
Node(int value){
    data = value;
    left = right = nullptr;
}
};
class BST {
public:
Node* root;
BST(){
    root=nullptr;
}
Node* insert(Node* r,int item){
    if(r==nullptr){
        Node* newNode = new Node(item);
        r = newNode;
    }
    else if(item <= r->data){
        r->left = insert(r->left,item);
    }else{
        r->right = insert(r->right,item);
    }
    return r;
}
void insert(int item){
    root = insert(root,item);
}
void preOrder(Node* r) // root -> left ->right
{
    if(r==nullptr) return;
    cout << r->data << endl;
    preOrder(r->left);
    preOrder(r->right);
}
void inOrder(Node* r) // left -> root ->right
{
    if(r==nullptr) return;
    inOrder(r->left);
    cout << r->data << endl;
    inOrder(r->right);
}
void postOrder(Node* r) // left -> right ->root
{
    if(r==nullptr) return;
    postOrder(r->left);
    postOrder(r->right);
    cout << r->data << endl;
}
Node* Search(Node* r,int key){
    if (r==nullptr){
        return nullptr;
    }
    else if (r->data == key){
        return r;
    }else if(r->data < key){
            r = Search(r->right,key);
    }else{
            r = Search(r->left,key);
    }
    
    return r;
}
bool Search(int key)
	{
		Node* result = Search(root, key);

		if (result == NULL)
			return false;
		else
			return true;
}
Node* Findmax(Node* r)
	{
		if (r == NULL)
			return NULL;
		else if (r->right == NULL)
			return r;
		else
			return Findmax(r->right);
}
	Node*  Delete(Node* r, int key)
	{
		if (r == NULL) 
			return NULL;
		if (key < r->data)
			r->left = Delete(r->left, key);
		else if (key > r->data)
			  r->right =Delete(r->right, key);
		else
		{
			if (r->left == NULL && r->right == NULL) 
				r = NULL;
			else if (r->left != NULL && r->right == NULL) 
			{
				r->data = r->left->data;
				delete r->left;
				r->left = NULL;
			}
			else if (r->left == NULL && r->right != NULL) 
			{
				r->data = r->right->data;
				delete r->right;
				r->right = NULL;
			}
			else
			{
				Node* max = Findmax(r->left);
				r->data = max->data;
			   	r->left= Delete(r->left, max->data);
				
			}

		}
		return r;
	}
};
int main()
{
	BST btree;
	btree.insert(45);
	btree.insert(15);
	btree.insert(79);
	btree.insert(90);
	btree.insert(10);
	btree.insert(55);
	btree.insert(12);
	btree.insert(20);
	btree.insert(50);

	cout << " Display the Tree Contenet \n";
	btree.preOrder(btree.root);

	cout << " \n Delete Items \n ";
	Node *result = btree.Delete (btree.root , 12);
	cout << "\n preorder After Delete 12 \n ";
	btree.preOrder(result);

	result = btree.Delete(btree.root, 15);
	cout << "\n preorder After Delete 15 \n ";
	btree.preOrder(result);
	
}