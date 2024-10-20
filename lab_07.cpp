//01
#include <iostream>
using namespace std;

class Muqaddas_Mehboob_Lab07{
    int front;
    int rear;
    int *arr;
    int maxSize;    //maximum size of the array
    int capacity;   //number of elements initially in the deque
    public:
        Muqaddas_Mehboob_Lab07(int k): front(0), rear(0), maxSize(k), capacity(0){
            arr = new int[k];
        }
        ~Muqaddas_Mehboob_Lab07(){
            delete[] arr;
        }
        bool isEmpty(){
            return (capacity==0);
        }
        bool isFull(){
            return(capacity == maxSize);
        }
        void insertFront(int element){
            if(isFull()){
                cout << "Queue is full"<< endl;
                return;
            }
            front = (front - 1 + maxSize) % maxSize;
            arr[front] = element;
            capacity++;
        }
        void insertRare(int element){
            if(isFull()){
                cout << "Queue is full" << endl;
                return;
            }
            arr[rear] = element;
            rear = (rear + 1) % maxSize;
            capacity++;
        }
        void deleteFront(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
                return;
            }
            front = (front + 1)% maxSize;
            capacity--;
        }
        void deleteRear(){
            if(isEmpty()){
                cout << "Queue is empty" <<endl;
                return;
            }
            rear = (rear - 1 + maxSize) % maxSize;
            capacity--;
        }
        int getFront(){
            if(isEmpty()){
                cout << "Queue is empty"<<endl;
                return -1;
            }
            return arr[front];
        }
        int getRear(){
            if(isEmpty()){
                cout << "Queue is empty"<<endl;
                return -1;
            }
            return arr[(rear - 1 + maxSize)% maxSize];
        }
        void display(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
                return;
            }
            for(int i = 0; i < capacity; i++){
                cout << arr[(front + i) % maxSize] << " ";
            }
            cout << endl;
        }
};

int main(){
    Muqaddas_Mehboob_Lab07 myCircularDeque(5); // Initializes deque with capacity of 5
    
    // Insert elements at the front and rear
    myCircularDeque.insertFront(10); // Deque: 10
    myCircularDeque.insertRare(20);  // Deque: 10 20
    myCircularDeque.insertRare(30);  // Deque: 10 20 30
    myCircularDeque.insertFront(5);  // Deque: 5 10 20 30
    myCircularDeque.insertRare(40);  // Deque: 5 10 20 30 40
    myCircularDeque.display();       // Displays: 5 10 20 30 40

    // Attempt to insert when full
    myCircularDeque.insertRare(50);  // The queue is full.

    // Check front and rear values
    cout << "Front: " << myCircularDeque.getFront() << endl;  // Expected: 5
    cout << "Rear: " << myCircularDeque.getRear() << endl;    // Expected: 40

    // Delete front and rear elements
    myCircularDeque.deleteFront();   // Deque: 10 20 30 40
    myCircularDeque.deleteRear();    // Deque: 10 20 30
    myCircularDeque.display();       // Displays: 10 20 30

    // Insert again after deletion
    myCircularDeque.insertFront(1);  // Deque: 1 10 20 30
    myCircularDeque.insertRare(50);  // Deque: 1 10 20 30 50
    myCircularDeque.display();       // Displays: 1 10 20 30 50

    return 0;
}

//02
#include <iostream>
#include <vector>
using namespace std;

class Muqaddas_Mehboob_Lab07 {
    public:
        int findWinner(int n, int k) {
            vector<int> friends;
            for (int i = 1; i <= n; i++) {
            }
            int index = 0;
            while (friends.size() > 1) {
                index = (index + k - 1) % friends.size();
                cout << "Friend " << friends[index] << " is eliminated." << endl;
                friends.erase(friends.begin() + index);
            }
            cout << "The winner is friend: " << friends[0] << endl; 
            return 1; 
        }
};

int main() {
    Muqaddas_Mehboob_Lab07 friends;
    int n = 5, k = 2;
    friends.findWinner(n, k);
    return 0;
}

//03
#include <iostream>
#include <queue>
using namespace std;

class Muqaddas_Mehboob_Lab07{
    queue <int> arr;
    public:
        void insert(int element){
            arr.push(element);
        }
        int getMin(){
            if(arr.empty()){
                cout << "Queue is empty"<<endl;
                return -1;
            }
            int minValue = arr.front();
            queue <int> tempQueue = arr;
            while(!tempQueue.empty()){
                minValue = min(minValue, tempQueue.front());
                tempQueue.pop();
            }
            return minValue;
        }
        int getMax(){
            if(arr.empty()){
                cout << "Queue is empty"<<endl;
                return -1;
            }
            int maxValue = arr.front();
            queue <int> tempQueue = arr;
            while(!tempQueue.empty()){
                maxValue = max(maxValue, tempQueue.front());
                tempQueue.pop();
            }
            return maxValue;
        }
        void removeMin(){
            if(arr.empty()){
                cout << "Queue is empty"<<endl;
                return;
            }
            int minValue = getMin();
            queue <int> tempQueue;
            while(!arr.empty()){
                if(arr.front() != minValue){
                    tempQueue.push(arr.front());
                }
                arr.pop();
            }
            arr = tempQueue;
        }
        void removeMax(){
            if(arr.empty()){
                cout << "Queue is empty"<<endl;
                return;
            }
            int maxValue = getMax();
            queue <int> tempQueue;
            while(!arr.empty()){
                if(arr.front() != maxValue){
                    tempQueue.push(arr.front());
                }
                arr.pop();
            }
            arr = tempQueue;
        }
        bool isEmpty(){
            return arr.empty();
        }
        void display(){
            if(arr.empty()){
                cout << "Queue is empty"<< endl;
                return;
            }
            queue <int> tempQueue = arr;
            while(!tempQueue.empty()){
                cout <<tempQueue.front() << " ";
                tempQueue.pop();
            }
            cout << endl;
        }
};

int main(){
    Muqaddas_Mehboob_Lab07 pq;

    pq.insert(10);
    pq.insert(5);
    pq.insert(20);
    pq.insert(15);

    cout << "Current Queue: ";
    pq.display();  // Expected: 10 5 20 15

    cout << "Min: " << pq.getMin() << endl;  // Expected: 5
    cout << "Max: " << pq.getMax() << endl;  // Expected: 20

    pq.removeMin();  // Removes 5
    pq.removeMax();  // Removes 20

    cout << "Queue after removing min and max: ";
    pq.display();  // Expected: 10 15
    return 0;
}