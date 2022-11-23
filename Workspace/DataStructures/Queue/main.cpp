#include <iostream>

using namespace std;

template <class T>
class queue{
private:
    int size;
    int front;
    int rear;
    T *arr;
public:
    queue(int size){
        this->size = size;
        this->front = this->rear = -1;
        this->arr = new T[this->size];
    }
    
    void enqueue(T x){
        if(this->rear != this->size - 1){
            this->rear++;
            this->arr[this->rear] = x;
            
        }
        else{
            cout<<"Queue is full"<<endl;
        }
        
    }
    
    T dequeue (){
        T x = -1;
        if(this->front < this->rear){
            this->front++;
            x = this->arr[this->front];        
        }
        return x;
    }

    bool isEmpty(){
        if(this->front==this->rear){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isFull(){
        if(this->rear == this->size - 1){
            return true;
        }
        else{
            return false;
        }
    }
    
    void Display(){
        if(isEmpty()){
            cout<<"Nothing in the Queue"<<endl;
        }
        
        else{
            int t = this->front +1;
        
            for (; t<=this->rear ;t++ ){
                cout<<this->arr[t]<<" ";
            }
            cout<<endl;
        }
    }
    
};

int main(){
    
    queue <int> q(10);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(45);
    q.enqueue(65);
    q.dequeue();
    q.Display();
	
	return 0;
}
