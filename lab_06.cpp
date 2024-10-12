//01
#include <iostream>
using namespace std;

class Muqaddas_Mehboob_Lab06{
    int *arr;
    int capacity;
    int front;
    int rear;
    public:
        Muqaddas_Mehboob_Lab06(int size): front(-1), rear(-1), capacity(size){
            arr = new int[capacity];
        }
        ~Muqaddas_Mehboob_Lab06(){
            delete[] arr;
        }
        bool enqueue(int element){
            if(rear == capacity -1){
                cout << "Queue is full" << endl;
                return 0;
            }
            else{
                if(front == -1){
                    front = 0;
                }
                rear++;
                arr[rear] = element;
                cout << element << " inserted in queue"<< endl;
                return 1;
            }
        }
        void dequeue(){
            if(front == -1 || front > rear){
                cout << "Queue is empty"<< endl;
            }
            else{
                cout << "Dequeued: "<< arr[front] << endl;
                front++;
                if(front > rear){
                    front = rear = -1;
                }
            }
        }
        void display(){
            if(front == -1){
                cout << "Queue is empty"<< endl;
            }else{
            cout << "Elements in queue are: ";
            for(int i = front; i < rear ; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
            }
        }
};
int main(){
    Muqaddas_Mehboob_Lab06 q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();  

    q.dequeue();  
    q.display(); 
    
    return 0;
}

//02
#include <iostream>
using namespace std;

class Muqaddas_Mehboob_Lab06{
    int *arr;
    int front, rear, size, count;
    public:
        Muqaddas_Mehboob_Lab06(int capacity): front(-1), rear(-1), size(capacity), count(0){
            arr = new int[size];
        }
        ~Muqaddas_Mehboob_Lab06(){
            delete[] arr;
        }
        bool isEmpty(){
            return count == 0;
        }
        bool isFull(){
            return count == size;
        }
        void enqueue(int value){
            if(isFull()){
                cout << "Queue Overflow"<< endl;
                return;
            }
            rear = (rear + 1)% size;
            arr[rear] = value;
            if(front == -1){
                front = rear;
            }
            count ++;
            cout << value << " added in circular queue" << endl;
        }
        void dequeue(){
            if(isEmpty()){
                cout << "Queue Underflow"<< endl;
                return;
            }
            cout << "Dequeued: " << arr[front]<< endl;
            front = (front + 1) % size;
            count --;
            if(count == 0){
                front = rear = -1;
            }
        }
        int Front(){
            if(isEmpty()){
                cout << "Queue is empty"<< endl;
                return -1;
            }
            return arr[front];
        }
        int Rear(){
            if(isEmpty()){
                cout << "Queue is empty"<< endl;
                return -1;
            }
            return arr[rear];
        }
        int Size(){
            return size;
        }
        void display(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
            }
            cout << "Elements of queue: ";
            int x = front;
            for(int i = 0; i < count ; i++){
                cout << arr[x] << " ";
                x = (x + 1) % size;
            }
            cout << endl;
        }
};
int main(){
    Muqaddas_Mehboob_Lab06 cq(5);
     cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cq.display(); 

    cout << "Front element: " << cq.Front() << endl;
    cout << "Rear element: " << cq.Rear() << endl;
    cout << "Current size: " << cq.Size() << endl;

    cq.dequeue();
    cq.dequeue();

    cq.display(); 

    cout << "Enqueueing after dequeue:" << endl;
    cq.enqueue(60);
    cq.enqueue(70);

    cq.display();
    
    return 0;
}

//03
#include <iostream>
using namespace std;

class Muqaddas_Mehboob_Lab06{
    int *arr;
    int capacity, front, rear, count;
    public:
        Muqaddas_Mehboob_Lab06(int size): capacity(size), front(-1), rear(-1), count(0){
            arr = new int[capacity];
        }
        ~Muqaddas_Mehboob_Lab06(){
            delete[] arr;
        }
        bool isEmpty(){
            return count == 0;
        }
        bool isFull(){
            return count == capacity;
        }
        void insertFront(int value){
            if(isFull()){
                cout << "Queue Overflow" << endl;
                return;
            }
            if(isEmpty()){
                front = rear = 0;
            }
            else{
                front = (front - 1 + capacity) % capacity;
            }
            arr[front] = value;
            count ++;
            cout << value << " added from the front"<< endl;
        }
        void insertRear(int value){
            if(isFull()){
                cout << "Queue Overflow" << endl;
                return;
            }
            if(isEmpty()){
                front = rear = 0;
            }
            else{
                rear = (rear + 1) % capacity;
            }
            arr[rear] = value;
            if(front == -1){
                front = 0;
            }
            count ++;
            cout << value << " added in the queue" << endl;
        }
        void deleteFront(){
            if(isEmpty()){
                cout << "Queue Underflow"<< endl;
                return ;
            }
            else{
                cout <<arr[front] << " deleted from front" << endl;
                front = (front + 1) % capacity;
                count--;
                if(count == 0){
                    front = rear = -1;
                }
            }
        }
        void deleteRear(){
            if(isEmpty()){
                cout << "Queue Underflow" << endl;
                return;
            }
            cout << arr[rear] << " deleted from rear" << endl;
            rear = (rear - 1 + capacity) % capacity;
            count--;
            if(count == 0){
                front = rear = -1;
            }
        }
        int Size(){
            return count;
        }
        void display(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
                return;
            }
            cout << "Elements of queue: ";
            int x = front;
            for(int i = 0; i < count ; i++){
                cout << arr[x] << " ";
                x = (x + 1) % capacity;
            }
            cout << endl;
        }
};

int main(){
    Muqaddas_Mehboob_Lab06 dq(5);

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(1);
    
    dq.display();  // Expected: 1 5 10 20
    
    dq.deleteFront();
    dq.deleteRear();
    
    dq.display();  // Expected: 5 10
    
    dq.insertRear(30);
    dq.insertRear(40); 

    dq.display();  // Expected: 5 10 30 40

    cout << "Current size: " << dq.Size() << endl;
    return 0;
}