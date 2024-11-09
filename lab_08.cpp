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

class Muqaddas_Mehboob_Lab08{
	Node* front;
	Node *rear;
	
	public:
		Muqaddas_Mehboob_Lab08(): front(NULL), rear(NULL){
		}
		
		bool isEmpty(){
			return front == NULL;
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
				cout << "Queue is empty"<< endl;
				return;
			}
			if(front==rear){
				delete front;
				front = rear = NULL;
			}
			else{
				Node* temp = front;
				cout << temp->data << " dequeued from the queue"<<endl;
				front = front->next;
				rear->next = front;
				delete temp;
			}
		}
		void display(){
			if(isEmpty()){
				cout << "Queue is empty"<< endl;
				return;
			}
			Node* temp = front;
			cout << "Elements in the queue: ";
			do{
				cout << temp->data<< " ";
				temp = temp->next;
			}while(temp!= front);
			cout << endl;
		}
		
		~Muqaddas_Mehboob_Lab08(){
			cout << endl;
			cout << "Destructor called! Deallocating memory" << endl;
			while(!isEmpty()){
				dequeue();
			}
	}
};
int main(){
	Muqaddas_Mehboob_Lab08 cq;
	cq.enqueue(10);
	cq.enqueue(20);
	cq.enqueue(30);
	cq.enqueue(40);
	
	cq.display();
	
	cq.dequeue();
	cq.display();
	
	cq.enqueue(50);
	cq.display();
	
	return 0;
}

//02
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

class Muqaddas_Mehboob_Lab08{
	Node* top;
	public:
		Muqaddas_Mehboob_Lab08(): top(NULL){
		}
		
		bool isEmpty(){
			return top == NULL;
		}
		
		void push(int value){
			Node* newNode = new Node(value);
			newNode->next = top;
			top = newNode;
			cout << value << " pushed in the stack"<< endl;
		}
		
		void pop(){
			if(isEmpty()){
				cout << "Stack is empty"<< endl;
				return;
			}
			Node* temp = top;
			cout << top->data << " poped from the stack"<< endl;
			top = top->next;
			delete temp;
		}
		void display(){
			if(isEmpty()){
				cout << "Stack is empty"<< endl;
				return;
			}
			Node* temp = top;
			cout << "Elements in the stack: ";
			while(temp != NULL){
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
		~Muqaddas_Mehboob_Lab08(){
			cout << endl;
			cout << "Destructor called! Deallocating memory" << endl;
			while(!isEmpty()){
				pop();
			}
	}
};
int main(){
	Muqaddas_Mehboob_Lab08 s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.display();
	
	s.pop();
	s.display();
	
	s.push(40);
	s.display();
	return 0;
}

//03
#include <iostream>
using namespace std;

class ListNode{
	public:
		int data;
		ListNode* next;
		
		ListNode(int data){
			this->data = data;
			this->next = NULL;
		}	
};

class Muqaddas_Mehboob_Lab08{
    public:
        ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* temp = new ListNode(-1);
        ListNode* current = temp;
        
        while(list1!=NULL && list2!= NULL){
            if(list1->data <= list2->data){
                current->next = list1;
                list1 = list1->next;
            }
            else{
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        
        if(list1 != NULL){
            current->next = list1;
        }
        else{
            current->next = list2;
        }
        
        ListNode* mergedHead = temp->next;
        delete temp;
        return mergedHead;
    }
    void display(ListNode* head){
        while(head != NULL){
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }

    ListNode* createList(int *arr, int size){
        if(size==0){
            return NULL;
        }
        ListNode* head = new ListNode(arr[0]);
        ListNode* current = head;
        for(int i = 1; i < size; i++){
            current->next = new ListNode(arr[i]);
            current = current->next;
        }
        return head;
    }
};

int main(){
	int arr1[] = {1,2,4};
	int arr2[] = {1, 3, 4};
	
    Muqaddas_Mehboob_Lab08 l;
	ListNode* list1 = l.createList(arr1, 3);
	ListNode* list2 = l.createList(arr2, 3);
	ListNode* mergedList = l.merge(list1, list2);
	cout << "Merged list: ";
	l.display(mergedList);
	
	return 0;
}

//04
#include <iostream>
using namespace std;

class ListNode{
	public:
		int data;
		ListNode* next;
		
		ListNode(int data){
			this->data = data;
			this->next = NULL;
		}	
};

class Muqaddas_Mehboob_Lab08{
    public:
        ListNode* deleteDuplicate(ListNode* head){
            if(head == NULL || head->next == NULL){
                return head;
            }
            ListNode* current = head;
            while(current!= NULL && current->next !=  NULL){
                if(current->data == current->next->data){
                    ListNode* duplicateNode = current->next;
                    current->next = current->next->next;
                    delete duplicateNode;
                }
                else{
                    current = current->next;
                }
            }
            return head;
        }

        void display(ListNode* head){
            while(head != NULL){
                cout << head->data << " ";
                head = head->next;
            }
            cout << endl;
        }

        ListNode* createList(int *arr, int size){
            if(size==0){
                return NULL;
            }
            ListNode* head = new ListNode(arr[0]);
            ListNode* current = head;
            for(int i = 1; i < size; i++){
                current->next = new ListNode(arr[i]);
                current = current->next;
            }
            return head;
        }
};

int main(){
	int arr[] = {1,1,2,3,3,4,4,5};
    Muqaddas_Mehboob_Lab08 l;
	ListNode* head = l.createList(arr, 8);
	cout << "Original List: ";
	l.display(head);
	
	head = l.deleteDuplicate(head);
	cout << "After removing duplicates: ";
	l.display(head);
	
	return 0;
}

//05
#include <iostream>
using namespace std;

class ListNode{
	public:
		int data;
		ListNode* next;
		
		ListNode(int data){
			this->data = data;
			this->next = NULL;
		}	
};

class Muqaddas_Mehboob_Lab08{
    public:
        ListNode* reverseList(ListNode* head){
        ListNode* previous = NULL;
        ListNode* current = head;
        while(current!= NULL){
            ListNode* nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }
        return previous;
    }
    bool isPalindrome(ListNode* head){
        if(head == NULL || head->next == NULL){
            return true;
        }
        ListNode* first = head;
        ListNode* second = head;
        
        while(first != NULL && first->next != NULL){
            first = first->next->next;
            second = second->next;
        }
        
        if(first != NULL) { 
            second = second->next;
        }
        
        ListNode* secondHalf = reverseList(second);
        ListNode* firstHalf = head;
        ListNode* secondCopy = secondHalf;
        
        bool isPalindrome = true;
        while(secondHalf != NULL){
            if(firstHalf->data != secondHalf->data){
                isPalindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        reverseList(secondCopy);
        
        return isPalindrome;
    }

    void display(ListNode* head){
        while(head != NULL){
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }

    ListNode* createList(int *arr, int size){
        if(size==0){
            return NULL;
        }
        ListNode* head = new ListNode(arr[0]);
        ListNode* current = head;
        for(int i = 1; i < size; i++){
            current->next = new ListNode(arr[i]);
            current = current->next;
        }
        return head;
    }
};

int main(){
	int arr[] = {1,2,3,2,1};
    Muqaddas_Mehboob_Lab08 l;
	ListNode* head = l.createList(arr, 5);
	
	cout << "Original list: ";
	l.display(head);
	
	if(l.isPalindrome(head)){
		cout << "Linked list is Palindrome"<<endl;}
	else{
		cout << "Linked list is not Palindrome"<< endl;
	}
	return 0;
}