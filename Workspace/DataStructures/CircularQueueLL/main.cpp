#include <iostream>

using namespace std;


class Node  {
public:
    int data;
    Node *next;
};

class CircularQueueLL{
private:
  Node *front;
  Node *rear;
public:
    CircularQueueLL(){
        front = rear = NULL;
    }
    
    void enqueue(int x){
        Node *t = new Node;
        if (t==NULL){
            cout<<"No space for new Node"<<endl;
        }
        else{
             t->data =x;
             t->next = NULL;
             
            if (front==NULL){
                front = rear = t;
            }
            else{
                rear->next = t;
                rear = rear->next;
            }
            t = nullptr;
        }
    }
    
    int dequeue(){
        Node *t = NULL;
        int x = -1;
        
        if(front == NULL){
            cout<<"No element in Queue"<<endl;
        }
        else{
            x = front->data;
            t = front;
            front = front->next;
            delete t;
            t = nullptr;
        }
        return x;
    }
    
    void Display(){
        Node *t = front;
        
        while(t!=NULL){
            cout<<t->data<<" ";
            t = t->next;
        }
        cout<<endl;
        t = nullptr;
    }
};

int main(){
    
    CircularQueueLL cql;
    cql.enqueue(1);
    cql.enqueue(2);
    cql.enqueue(3);
    cql.enqueue(4);
    cql.enqueue(5);
    cql.enqueue(6);
    
    cql.dequeue();
    cql.dequeue();
    
    cql.Display();
    
	return 0;
}
