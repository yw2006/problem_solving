#include <iostream>
using namespace std;
class Node {
public:
    int vertex;
    int weight;
    Node* next;

    Node(int v , int w){
        vertex = v;
        weight = w;
        next = nullptr;
    }
};
class Graph {
private:
    int vertices;
    bool directed;
    bool weighted;

    int matrix[10][10];

    Node* list[10];
public:
    Graph(int v,  bool isDirected , bool isWeighted){
     vertices = v;
     directed = isDirected;
     weighted = isWeighted;
     for (size_t i = 0; i < vertices; i++)
     {
        for (size_t j = 0; j < vertices; j++)
        {
            matrix[i][j]=0;
        }
     }

     for (size_t i = 0; i < vertices; i++)
     {
        list[i]=nullptr;
     }
     
    }
    void addEdge(int from , int to , int weight = 1){
        int w = weighted ? weight : 1;

        matrix[from][to]=w;
        if(!directed){
            matrix[to][from]=w;
        }
        Node* newNode = new Node(to,w);
        newNode->next = list[from];
        list[from] = newNode;
        if(!directed){
            Node* reverseNode = new Node(from,w);
            reverseNode->next = list[to];
            list[to] = reverseNode;
        }
    }
    void printList()
    {
        cout << "\nA";
    }
};