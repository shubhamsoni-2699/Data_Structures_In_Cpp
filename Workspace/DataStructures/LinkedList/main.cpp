#include<iostream>

using namespace std;

struct Node {
    int Data;
    struct Node *next;
};

struct Node * Create (){
   
    struct Node *head = new Node;
    struct Node *t = head;
    
    int n;
    cout<<"Enter no. of nodes"<<endl;
    cin>>n;
    
    if (n!=0){
    cout<<"Enter Data in nodes"<<endl;
    cin>>t->Data;
    for (int i = 0 ; i<n-1; i++){
        t->next = new Node;
        t = t->next;
        cin>>t->Data;
    }
    
    t->next = NULL;
    
    return head; 
    }
    
    else{
        return NULL;
    }
    
    
    
}

void Display(struct Node *t){
    while(t!= NULL){
        cout << t->Data <<" ";
        t = t->next;
    }
    cout<<endl;
}

int Len(struct Node *t){
    
    int count = 0;
    
    while (t!=NULL){
        count++;
        t = t->next;
    }
    
    return count;
}

int Max(struct Node *t){
    
    int max = t->Data;
    t = t->next;
    
    while (t!= NULL){
        if (max<t->Data) max = t->Data;
        else t = t->next;
    }
    
    return max;
}

struct Node * Search(struct Node *t , int key){
    
    while(t!= NULL){
        if (t->Data == key) return t;
        else t = t->next;
    }
    
    return NULL;

}

struct Node * ImprovedSearch(struct Node *t , struct Node *head , int key){
    
    struct Node *q = NULL;
    
    while (t!=NULL){
        if (t->Data == key) {
            q->next = t->next;
            t->next = head;
            head = t;
            break;
        }
        else{
            q = t;
            t = t->next;
        }
    }
    
    if(head->Data == key){
        cout<<"Find out the ele"<<endl;
    }
    else cout<<"ele Not Found!"<<endl;
    
    return head;
}

void Insert (struct Node *t , int position , int Data ){
    
   
    struct Node *n;
    
    int len = Len(t) - 1 ;
    
    int i = 0;
    

    if ((t!=NULL) && (position <= len )){
        
        while (i < position - 1 ){
            t = t->next; 
            i++;
        }
        
        n = new Node ;
        n->Data = Data;
        n->next = t->next;
        t->next = n;
        n = NULL;
    }
    else{
        cout<<"Your linkedlist is not enough in Size"<<endl;
    }
}

void InsertLast(struct Node *t , int Data){
    
    struct Node *n;
    
    if (Len(t) ==0 ) {
        n = new Node;
        n->Data = Data;
        n->next = NULL;
        t = n;
    }
    
    else {
        while(t->next != NULL){
            t = t->next;
        }
        
        n = new Node;
        t->next = n;
        n->Data = Data;
        n->next = NULL;
    }
    
}

void InsertSorted(struct Node *t , int Data){
    
    struct Node *q = NULL;
    
    while (t!= NULL and t->Data < Data){
        q = t;
        t = t->next;
    }
    
    q->next = new Node;
    q = q->next;
    q->Data = Data;
    q->next = t;
    
}

struct Node * Delete(struct Node *t , int position){
    
    struct Node *head  =  t; 
    
    if (position == 0){
        struct Node *q;
        q = t;
        t = t->next;
        delete q;
        q = nullptr;
        
        return t;
    }
    else{
        int i = 0 ; 
        struct Node *q = NULL;
        
        while (i<position and t){
            q = t;
            t = t->next;
            i++;
        }
        q->next = t->next;
        delete t;
        t = nullptr;
        
        return head;
    }
}

bool IsSorted(struct Node *t){
    int x = t->Data;
    
    while(t->next != NULL){
        if (t->Data >= x){
            x = t->Data;
            t = t->next;
        }
        else return false;
    }
    
    return true;
}

void RemoveDuplicateSorted(struct Node *t){
   
    struct Node *q = t;
    struct Node *d = NULL;
    
    t = t->next;
    
    
    while(t != NULL){
        if (t->Data == q->Data){
            d = t;
            t =t->next;
            q->next = t;
            delete d;
            d = nullptr;
        }
        else{
            q = t;
            t = t->next;
        }
    }
}

struct Node * ReverseSlide(struct Node *t){
    struct Node *p ,*q;
    p = q = NULL;
    struct Node *r =t;
     
    
    while (r != NULL){
        p=q;
        q=r;
        r = r->next;
        q->next = p;
    }
    
    t = q;
    
    return t;
}

struct Node * ReverseRecursive(struct Node *q , struct Node *t ){
     struct Node *head = t;
    
    if (t != NULL){
        ReverseRecursive(t , t->next);
        t->next = q;
    }
    else{
        head = q;
    }
    
    return head;

}

struct Node * Concating(struct Node *t1 , struct Node *t2){
    struct Node *head = t1;
    
    while (t1->next != NULL){
        t1 = t1->next;
    }
    
    t1->next = t2;
    
    return head;
    
}

struct Node * Merging(struct Node *t1 , struct Node *t2){
    
    struct Node *head ;
    struct Node *last = NULL;
    
    if (t1->Data < t2->Data){
        head = last =  t1;
        t1 = t1->next;
        last->next = NULL;
    }
    else if (t1->Data > t2->Data){
        head = last =  t2;
        t2 = t2->next;
        last->next = NULL;
    }
     else if (t1->Data == t2->Data){
        head = last =t2;
        t2 = t2->next;
        t1 = t1->next;
        last->next = NULL;
    }
    
    while (t1 != NULL && t2 !=NULL){
        if (t1->Data < t2->Data){
            last->next = t1;
            last = t1;
            t1 = t1->next;
            last->next = NULL;
        }
        else if (t1->Data > t2->Data){
            last->next = t2;
            last = t2;
            t2 = t2->next;
            last->next = NULL;
        }
        
        else{
            last->next = t2;
            last = t2;
            t2 = t2->next;
            t1 = t1->next;
            last->next = NULL;
        }
    }
    
    while (t1 != NULL) {
        last->next = t1 ;
        last = t1;
        t1 = t1->next;
        last->next = NULL;
        
    }
    while (t2 != NULL) {
        last->next = t2;
        last = t2;
        t2 = t2->next;
        last->next = NULL;
    }
    
    return head;
}

int isLoop(struct Node *t){
    struct Node *q , *p;
    q=p=t;
    
    while (q!=NULL){
        q = q->next->next;
        p = p->next;
        
        if (p==q){
            return 1;
        }
    }
    
    return 0;
}

int main(){

//    int key;
    
    
    
//    cout<<"Enter key for searching"<<endl;
//    cin>>key;
    

    struct Node *head;
//    struct Node *t;
//    struct Node *l;
//    int ans ;

    
    head = Create();
    
//    t = head;
    
//    for (int i = 0 ; i < Len(head) -  1; i++){
//        if (i==4){
//            l = t;
//        }
//        t = t->next;
//    }
//    
//    t->next = l;
    
    Insert(head , 6 , 9);

    InsertLast(head , 10);
    InsertLast(head , 11);
    InsertLast(head , 12);
    InsertLast(head , 13);
    
//    InsertSorted(head , 6);

//    head = Delete(head , 3);
      
//      cout<<IsSorted(head);
    
//        RemoveDuplicateSorted(head1);

//    head = ReverseRecursive(NULL , head);


//    Concating(head1 , head2 );

//    ans = isLoop(head);
//    cout<<ans<<endl;

    Display(head);
    
    cout<<Len(head)<<endl;

    return 0 ; 
}