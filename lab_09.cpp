//01
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class Muqaddas_Mehboob_Lab09{
    Node* front;
    Node* rear;
    public:
        Muqaddas_Mehboob_Lab09(){
            front = NULL;
            rear = NULL;
        }
        bool isEmpty(){
            return front== NULL;
        }
        void enqueue(int value){
            Node* newNode = new Node(value);
            if(isEmpty()){
                front = rear = newNode;
                rear->next = front;
            }
            else{
                rear->next = newNode;
                rear = newNode;
                rear->next = front;
            }
            cout << value << " enqueued in the queue"<<endl;
        }
        void dequeue(){
            if(isEmpty()){
                cout << "Queue is empty\n";
                return;
            }
            int value;
            if(front==rear){
                value = front->data;
                delete front;
                front = rear = NULL;
            }
            else{
                Node* temp = front;
                value = temp->data;
                front = front->next;
                rear->next = front;
                delete temp;
            }
            cout << value << " dequeud from the queue"<<endl;
        }
        void display(){
            if(isEmpty()){
                cout << "Queue is empty"<<endl;
                return;
            }
            Node* temp = front;
            do{
                cout << temp->data << " ";
                temp = temp->next;
            }while(temp != front);
            cout << endl;
        }
};
int main(){
    Muqaddas_Mehboob_Lab09 q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();  

    q.dequeue();  
    q.display();  
    return 0;
}

//02
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
        Node(int data){
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};
class Muqaddas_Mehboob_Lab09{
    Node* front;
    Node* rear;
    public:
        Muqaddas_Mehboob_Lab09(): front(nullptr), rear(nullptr){}

        bool isEmpty(){
            return front==nullptr;
        }
        void enqueueFront(int value){
            Node* newNode = new Node(value);
            if(isEmpty()){
                front = rear = newNode;
            }
            else{
                newNode->next = front;
                front->prev = newNode;
                front = newNode;
            }
            cout << value << " inserted from the front"<<endl;
        }
        void enqueueRear(int value){
            Node* newNode = new Node(value);
            if(isEmpty()){
                front = rear = newNode;
            }
            else{
                rear->next = newNode;
                newNode->prev = rear;
                rear = newNode;
            }
            cout << value << " inserted from the rear" << endl;
        }
        void dequeueFront(){
            if(isEmpty()){
                cout << "Queue is empty"<<endl;
                return;
            }
            int value = front->data;
            Node* temp = front;
            front = front->next;
            if(front == NULL){
                rear = nullptr;
            }else{
                front->prev = NULL;
            }
            delete temp;
            cout <<  value <<" deleted from front" << endl;
        }
        void dequeueRear(){
            if(isEmpty()){
                cout << "Queue is empty\n";
                return;
            }
            int value = rear->data;
            Node* temp = rear;
            rear = rear->prev;
            if(rear == NULL){
                front == NULL;
            }else{
                rear->next = NULL;
            }
            delete temp;
            cout << value << " deleted from the rear"<< endl;
        }
        void display(){
            if(isEmpty()){
                cout << "Queue is empty\n";
                return;
            }
            Node* temp = front;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main(){
    Muqaddas_Mehboob_Lab09 dq;

    dq.enqueueFront(10);
    dq.enqueueRear(20);
    dq.enqueueFront(30);
    dq.enqueueRear(40);

    dq.display(); 
    dq.dequeueFront(); 
    dq.dequeueRear(); 

    dq.display();

    return 0;
}

//03
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
        Node(int data){
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};
class Muqaddas_Mehboob_Lab09{
    Node* head;
    Node* tail;
    public:
        Muqaddas_Mehboob_Lab09() : head(nullptr), tail(nullptr){}

        void insertFromEnd(int value){
            Node* newNode = new Node(value);
            if(head == NULL){
                head = tail = newNode;
            }
            else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
        void concatenate(Muqaddas_Mehboob_Lab09& other){
            if(head == nullptr){
                head = other.head;
                tail = other.tail;
            }else if(other.head != NULL){
                tail->next = other.head;
                other.head->prev = tail;
                tail = other.tail;
            }
        }
        void display(){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main(){
    Muqaddas_Mehboob_Lab09 L, M;

    for (int i = 2; i <= 10; i += 2) {
        L.insertFromEnd(i);
    }
    for (int i = 1; i <= 9; i += 2) {
        M.insertFromEnd(i);
    }

    cout << "List L = ";
    L.display();

    cout << "List M = ";
    M.display();

    Muqaddas_Mehboob_Lab09 N = L; 
    N.concatenate(M); 

    cout << "Concatenated List N = ";
    N.display(); 
    return 0;
}

//04
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
        Node(int data){
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};
class Muqaddas_Mehboob_Lab09{
    Node* head;
    Node* tail;
    public:
        Muqaddas_Mehboob_Lab09() : head(nullptr), tail(nullptr){}

        void insertFromEnd(int value){
            Node* newNode = new Node(value);
            if(head == NULL){
                head = tail = newNode;
            }
            else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
        void concatenate(Muqaddas_Mehboob_Lab09& other){
            if(head == nullptr){
                head = other.head;
                tail = other.tail;
            }else if(other.head != NULL){
                tail->next = other.head;
                other.head->prev = tail;
                tail = other.tail;
            }
        }
        void sort(){
            if(head == NULL){
                return;
            }
            for(Node* i = head; i != NULL; i = i->next){
                Node* current = head;
                bool swap = false;
                while(current->next != nullptr){
                    if(current->data < current->next->data){
                        int temp = current->data;
                        current->data = current->next->data;
                        current->next->data = temp;
                        swap = true;
                    }
                    current = current->next;
                }
                if(!swap){
                    break;
                }
            }
        }
        void display(){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main(){
    Muqaddas_Mehboob_Lab09 L, M;

    for (int i = 2; i <= 10; i += 2) {
        L.insertFromEnd(i);
    }
    for (int i = 1; i <= 9; i += 2) {
        M.insertFromEnd(i);
    }

    cout << "List L = ";
    L.display();

    cout << "List M = ";
    M.display();

    Muqaddas_Mehboob_Lab09 N = L; 
    N.concatenate(M); 

    cout << "Concatenated List N = ";
    N.display(); 

     N.sort();

    cout << "Sorted List N in descending order = ";
    N.display();
    return 0;
}

//05
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string url;
    Node* prev;
    Node* next;

    Node(string url) {
        this->url = url;
        prev = nullptr;
        next = nullptr;
    }
};

class Muqaddas_Mehboob_Lab09{
    Node* current;
public:
    Muqaddas_Mehboob_Lab09(string homepage){
        current = new Node(homepage);
    }
    
    void visit(string url){
        Node* newNode = new Node(url);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;

        Node* temp = current->next;
        while(temp){
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
        current->next = NULL;
    }
    
    string back(int steps){
        while(steps > 0 && current->prev != NULL){
            current = current->prev;
            steps--;
        }
        return current->url;
    }
    
    string forward(int steps){
        while(steps > 0 && current->next != NULL){  
            current = current->next;
            steps--;
        }
        return current->url;
    }
};

int main(){
    Muqaddas_Mehboob_Lab09 browserHistory("leetcode.com");

    browserHistory.visit("google.com");
    browserHistory.visit("facebook.com");
    browserHistory.visit("youtube.com");

    cout << browserHistory.back(1) << endl;        // Output: "facebook.com"
    cout << browserHistory.back(1) << endl;        // Output: "google.com"
    cout << browserHistory.forward(1) << endl;     // Output: "facebook.com"

    browserHistory.visit("linkedin.com");
    cout << browserHistory.forward(2) << endl;     // Output: "linkedin.com"
    cout << browserHistory.back(2) << endl;        // Output: "google.com"
    cout << browserHistory.back(7) << endl;        // Output: "leetcode.com"
    return 0;
}
