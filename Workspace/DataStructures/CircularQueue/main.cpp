#include <iostream>

using namespace std;

template <class T>
class CircularQueue{
private:
    int size;
    int rear;
    int front;
    T *arr;
    
public:
    CircularQueue(int size){
        this->size = size;
        front = rear = 0;
        arr = new T[this->size];
    }
    
    void enqueue (T x){
        if ( (rear +1)%size == front){
            cout<<"Queue is Full"<<endl;
        }
        else{
            rear = (rear + 1) % size;
            arr[rear] = x;
        }
    }
    
    T dequeue(){
        T x = -1 ;
        if(rear == front){
            cout<<"Queue is Empty"<<endl;
        }
        else{
            front = (front + 1)%size;
            x = arr[front];
        }
        
        return x;
    }
    
    void Display(){
        for(int i = front +1; i!=front; i = (i+1)%size ){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
};


int main(){
	
    CircularQueue <int> cq(7);
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);
    cq.enqueue(6);
    
    cq.dequeue();
    cq.dequeue();
    
    cq.enqueue(7);
    cq.enqueue(8);
    
    cq.dequeue();
    cq.enqueue(9);
    
    cq.Display();
	return 0;
}
