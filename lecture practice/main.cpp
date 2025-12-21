#include <iostream>
using namespace std;
struct Node{
    Node* prev;
    int data;
    Node* next;
};
class DoubleLinkedList{
    Node* head;
public:
    DoubleLinkedList() {
        head=nullptr;
    }
    bool add_begin(int value){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        newNode->prev =nullptr;
        return true;
    }
    bool del_begin(){
        if (head == nullptr) {
        return false;  
        }
        Node *temp=head ;
        head = temp->next;
        head->prev =nullptr;
        delete temp;
        return true;
    }   
};
struct CirNode{
    int data;
    CirNode* next;
};
class circularLinkedList{
    CirNode* tail;
public:
    circularLinkedList(){
        tail = NULL;
    }
    bool add_begin(int value){
        CirNode* newNode= new CirNode;
        newNode->data = value;
        if(tail==NULL){
        newNode->next = newNode;
        tail = newNode;
        return true;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        return true;
    }
    bool add_end(int value){
        CirNode* newNode= new CirNode;
        newNode->data = value;
        if(tail==NULL){
        return add_begin(value);
        }
        newNode->next = tail->next;
        tail->next =  newNode;
        tail = newNode;
        return true;
    }
    bool add_between_nodes(int value,int pos){
        if(tail == NULL || pos <=1){
            return add_begin(value);
        }
        CirNode* newNode= new CirNode;
        newNode->data = value;
        CirNode* temp=tail;
        int c=1;
        while(temp->next != tail && c!= pos-1 ){
            temp=temp->next;
            c++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail) tail = newNode;
        return true;
    }
   void printList() {
    if (tail == NULL) {
        cout << "List is empty\n";
        return;
    }
    CirNode* temp = tail->next;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != tail->next);

    cout << endl;
}
};