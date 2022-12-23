#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>

using namespace std;

class TNode{
public:
    TNode *left;
    int Data;
    TNode *Right;
}*root;

class Tree{
public:
   void Create(){
        
        
        TNode *p , *t;
        queue <TNode*> *q = new queue<TNode*>;
        
//        cout<<"Enter height of the tree"<<endl;
//        int h ;
//        cin>>h;
       
//        int nnodes = pow(2,(h+1)) - 1;
       
        cout<<"Enter data in root Node"<<endl;
        int data;
        cin>>data;
        
        root = new TNode;
        root->Data = data;
        root->left = NULL;
        root->Right = NULL;
        
        q->push(root);
        
        while(! (q->empty()) ){
            
            p = q->front();
            q->pop();
            
            printf("Enter Left Child of %d :" , p->Data);
            cin>>data;
            
            if(data!=-1){
                t = new TNode;
                q->push(t);
                t->left = t->Right = NULL;
                t->Data = data;
                p->left = t;
                t = nullptr;
            }
            
            printf("Enter Right Child of %d :" , p->Data);
            cin>>data;
            
            if(data!=-1){
                t = new TNode;
                q->push(t);
                t->left = t->Right = NULL;
                t->Data = data;
                p->Right = t;
                t = nullptr;
            }
        }
   }
   
   void preOrder(TNode *m){
       if(m){
           cout<<m->Data<<" ";
           preOrder(m->left);
           preOrder(m->Right);
       }
   }
   
   void inOrder(TNode *m){
	   if(m){
		   inOrder(m->left);
		   cout<<m->Data<<" ";
		   inOrder(m->Right);
	   }
   }
   
   void postOrder(TNode *m){
	   if(m){
		   postOrder(m->left);
		   postOrder(m->Right);
		   cout<<m->Data<<" ";
	   }
   }
   
};

int main(){
    
    Tree *t = new Tree;
    t->Create();
	
    t->preOrder(root);
	cout<<endl;
	t->inOrder(root);
	cout<<endl;
	t->postOrder(root);
	cout<<endl;
	
 
    return 0;
}
