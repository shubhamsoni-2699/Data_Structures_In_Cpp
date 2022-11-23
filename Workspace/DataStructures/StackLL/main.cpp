#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

template <class T>
class StackLL{
private:
    Node *top = NULL;
    
public:
    
    void push(T data){
      Node * n = new Node;
        if (n!= NULL){
            n->data = data;
            n->next = top;
            top = n;
        }
        else{
            cout<<"Stack is OverFlow"<<endl;
        }
        
    }
    
    T pop(){
        T x = 0;
        if(top!=NULL){
            Node *t = top;
            top = top->next;
            x = t->data;
            delete t;
            t = nullptr;
        }
        else{
            x = -1;
            cout<<"Empty Stack"<<endl;
        }
        return x;
    }
    
    bool isEmpty(){
        if(top==NULL){
            return true;
        }
        else{
            return false;        }
    }
    bool isFull(){
        Node *t = new Node;
        if(t==NULL){
            return true;
        }
        else{
            return false;        }
    }
    
    T peek(int index){
        Node *t = top;
        
        for(int i = 0 ; i< index-1 ; i++ ){
            t = t->next;
        }
        return t->data;
    }
};


int main(){
    
    StackLL <char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    
    cout<<s.peek(3)<<endl;
    
   
    return 0;
}