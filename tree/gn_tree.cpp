#include <iostream>
using namespace std;
struct Node {
    int data;
vector<Node*> childs;  
Node(int v):data(v){}
};
class GnTree{
public:
    Node* root;
    GnTree(int value){
        root= new Node(value);
    }
     Node* insert(int value,Node* r){
        Node* newNode = new Node(value);
        r->childs.push_back(newNode);
        return newNode;
    }
    Node* traverse(Node* root){
        if(root == nullptr){
            return nullptr;
        }
        if(root->childs.empty()){
            return root;
        }
        cout << "the root is "<<root->data << " 👑"<< endl;
        for(Node* n : root->childs){
            cout << "this is the childs " << n->data << " -> ";
            traverse(n);
        }
        return root;
    }

    void levelOrder(Node* node) {
        if (!node) return;

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            cout << curr->data << " ";

            for (Node* child : curr->childs)
                q.push(child);
        }
    }
};
int main(){
    GnTree gt(10);
    Node* x =gt.insert(20,gt.root);
    gt.insert(800,x);
    gt.insert(900,x);
    gt.insert(600,x);
    gt.insert(30,gt.root);
    gt.insert(40,gt.root);
    gt.insert(50,gt.root);
    gt.insert(60,gt.root);
    gt.insert(70,gt.root);
    gt.traverse(gt.root);
    cout << endl;
    gt.levelOrder(gt.root);
}