//01
#include <iostream>
using namespace std;

class Muqaddas_Mehboob_Lab03{
    int* arr;       //Pointer to the dynamic array
    int capacity;
    int top;
        void adjust(){      //Function to adjust the stack when overflow occurs
            int* tempArray = new int[capacity*2];
            for(int i = 0; i < capacity; i++){
                tempArray[i] = arr[i];
            }
            delete[] arr;
            arr = tempArray;
            capacity = capacity*2;
        }
    public:
        //Constructor
        Muqaddas_Mehboob_Lab03(int size = 100): arr(new int[size]), capacity(size), top(-1){}
        //Destructor
        ~Muqaddas_Mehboob_Lab03(){
            delete[] arr;
        }

        bool push(int element){     //Function to insert elements in stack
            if(top >= (capacity - 1)){
                cout << "Stack Overflow. Resizing the stack\n";
                adjust();
                return false;
            }
            arr[++top] = element;
            cout << element << " pushed into stack\n";
            return true;
        }
        int pop(){      //Function to remove elements from stack
            if(top < 0){
                cout << "Stack Underflow\n";
                return 0;
            }
            int item = arr[top--];
            return item;
        }
        bool IsEmpty(){     //Check if stack is empty or not
            if(top < 0){
                cout << "Stack is Empty\n";
                return true;
            }
            return false;
        }
        int peek(){     //Return the element at the top of the stack
            if(top < 0){
                cout << "Stack is Empty\n";
                return 0;
            }
            int element = arr[top];
            return element;
        }
        void display(){
            for(int i = 0; i < capacity; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        void size(){
            cout << "The size of the array is: "<< capacity <<endl;
        }
};
int main(){
    int size;
    int element;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Muqaddas_Mehboob_Lab03 stack(size);
    int i = size;
    while(i > 0){
        cout << "Enter element: ";
        cin >> element;
        stack.push(element);
        i--;
    }
    cout << endl;

    cout << "--ELEMENTS IN THE STACK--\n";
    stack.display();
    cout << endl;
    stack.size();
    cout << endl;
    
    int item = stack.pop();
    cout << item << " poped from the stack\n";
    cout << endl;

    int result = stack.peek();
    cout << "Now the element at the top is: "<< result << endl;
    return 0;
}

//02
#include <iostream>
#include <string>
using namespace std;

class Muqaddas_Mehboob_Lab03{
    int* charArray;       //Pointer to the dynamic array
    int capacity;
    int top;
        void adjust(){      //Function to adjust the stack when overflow occurs
            int* tempArray = new int[capacity*2];
            for(int i = 0; i < capacity; i++){
                tempArray[i] = charArray[i];
            }
            delete[] charArray;
            charArray = tempArray;
            capacity = capacity*2;
        }
        public:
            //Constructor
            Muqaddas_Mehboob_Lab03(int size = 100): charArray(new int[size]), capacity(size), top(-1){}
            //Destructor
            ~Muqaddas_Mehboob_Lab03(){
                delete[] charArray;
        }
        char pop(){     //Function to remove elements from stack
            if(top < 0){
                cout << "Stack Underflow\n";
                return '\0';
            }
            char item = charArray[top--];
            return item;
        }
        bool push(int element){     //Function to insert elements in stack
            if(top >= (capacity - 1)){
                cout << "Stack Overflow. Resizing the stack\n";
                adjust();
                return false;
            }
            charArray[++top] = element;
            return true;
        }
        bool IsEmpty(){     //Check if stack is empty or not
            return top == -1;
        }
};

int main(){
    Muqaddas_Mehboob_Lab03 charArray;
    string input;
    cout << "Enter a string to reverse: ";
    getline(cin, input);
    for(int i = 0; i < input.length(); i++){
        charArray.push(input[i]);
    }

    cout << "Reverse string: ";
    while(!charArray.IsEmpty()){
        cout << charArray.pop();
    }

    return 0;
}

//03
#include <iostream>
#include <string>
using namespace std;

class Muqaddas_Mehboob_Lab03{
    int* charArray;       //Pointer to the dynamic array
    int capacity;
    int top;
        void adjust(){      //Function to adjust the stack when overflow occurs
            int* tempArray = new int[capacity*2];
            for(int i = 0; i < capacity; i++){
                tempArray[i] = charArray[i];
            }
            delete[] charArray;
            charArray = tempArray;
            capacity = capacity*2;
        }
        public:
            //Constructor
            Muqaddas_Mehboob_Lab03(int size = 100): charArray(new int[size]), capacity(size), top(-1){}
            //Destructor
            ~Muqaddas_Mehboob_Lab03(){
                delete[] charArray;
        }
        char pop(){     //Function to remove elements from stack
            if(top < 0){
                cout << "Stack Underflow\n";
                return '\0';
            }
            char item = charArray[top--];
            return item;
        }
        bool push(int element){     //Function to insert elements in stack
            if(top >= (capacity - 1)){
                cout << "Stack Overflow. Resizing the stack\n";
                adjust();
                return false;
            }
            charArray[++top] = element;
            return true;
        }
        bool IsEmpty(){     //Check if stack is empty or not
            return top == -1;
        }

        bool isPalindrome(string s) {       //Check whether the string is palindrome or not
            Muqaddas_Mehboob_Lab03 stack(s.length());
            for (int i = 0; i < s.length(); i++) {
                stack.push(s[i]);
            }

            for (int i = 0; i < s.length(); i++) {
                if (s[i] != stack.pop()) {
                    return false; 
                }
            }
            return true; 
        }
};

int main(){
    Muqaddas_Mehboob_Lab03 charArray;
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    
    if(charArray.isPalindrome(input)){
        cout << "String is palindrome"<< endl;
    }
    else{
        cout << "String is not palindrome"<<endl;
    }
    return 0;
}

//04
#include <iostream>
#include <string>
using namespace std;

class Muqaddas_Mehboob_Lab03{
    int* charArray;       //Pointer to the dynamic array
    int capacity;
    int top;
        void adjust(){      //Function to adjust the stack when overflow occurs
            int* tempArray = new int[capacity*2];
            for(int i = 0; i < capacity; i++){
                tempArray[i] = charArray[i];
            }
            delete[] charArray;
            charArray = tempArray;
            capacity = capacity*2;
        }
        public:
            //Constructor
            Muqaddas_Mehboob_Lab03(int size = 100): charArray(new int[size]), capacity(size), top(-1){}
            //Destructor
            ~Muqaddas_Mehboob_Lab03(){
                delete[] charArray;
        }
        char pop(){     //Function to remove elements from stack
            if(top < 0){
                cout << "Stack Underflow\n";
                return '\0';
            }
            char item = charArray[top--];
            return item;
        }
        bool push(char element){     //Function to insert elements in stack
            if(top >= (capacity - 1)){
                cout << "Stack Overflow. Resizing the stack\n";
                adjust();
                return false;
            }
            charArray[++top] = element;
            return true;
        }
        bool IsEmpty(){     //Check if stack is empty or not
            return top == -1;
        }
        char peek(){     //Return the element at the top of the stack
            if(top < 0){
                cout << "Stack is Empty\n";
                return '\0';
            }
            char element = charArray[top];
            return element;
        }
};
string processComparision(const string &s){     //Compare the string and return result
    Muqaddas_Mehboob_Lab03 stack(s.length());
    for(int i = 0; i < s.length(); i++){
        if(s[i] != '#'){
            stack.push(s[i]);
        }
        else if (! stack.IsEmpty()){
                    stack.pop();
        }
    }
    string result;
    while(!stack.IsEmpty()){
        result += stack.peek();
        stack.pop();
    }
    return result;
}

bool backspaceComparision(string s, string t){      //Check whether the two strings are same
    return processComparision(s) == processComparision(t);
}

int main(){
    string s, t;
    cout << "Enter string s: ";
    getline(cin,s);
    cout << "Enter string t: ";
    getline(cin, t);

    if(backspaceComparision(s, t)){
        cout << "True"<< endl;
    }
    else{
        cout << "False" << endl;
    }
    return 0;
}

//05
#include <iostream>
using namespace std;

class Muqaddas_Mehboob_Lab03{
    int* arr;       //Pointer to the dynamic array
    int capacity;
    int top;
    
    void adjust(){      //Function to adjust the stack when overflow occurs
        int* tempArray = new int[capacity*2];
        for(int i = 0; i < capacity; i++){
            tempArray[i] = arr[i];
        }
        delete[] arr;
        arr = tempArray;
        capacity = capacity*2;
    }
    
    public:
        // Constructor
        Muqaddas_Mehboob_Lab03(int size = 100): arr(new int[size]), capacity(size), top(-1){}

        // Destructor
        ~Muqaddas_Mehboob_Lab03(){
            delete[] arr;
        }
        
        bool push(int element){     //Function to insert elements in stack
            if(top >= (capacity - 1)){
                cout << "Stack Overflow. Resizing the stack\n";
                adjust();
            }
            arr[++top] = element;
            return true;
        }

        int pop(){     //Function to remove elements from stack
            if(top < 0){
                cout << "Stack Underflow\n";
                return 0;
            }
            int item = arr[top--];
            return item;
        }

        bool isEmpty() {   //Check if stack is empty
            return top == -1;
        }

        void fibonacci(int n){      //Calculate fibonacci series
            Muqaddas_Mehboob_Lab03 stack; 
            int next, num1, num2;
            
            stack.push(0); 
            if(n > 1){
                stack.push(1); 
            }
            
            this->push(0);      
            if(n > 1){
                this->push(1); 
            }
            
            for(int i = 2; i < n; i++){
                num1 = stack.pop();
                num2 = stack.pop();
                next = num1 + num2;
                stack.push(num1);
                stack.push(next);
                this->push(next);  
            }
            
            cout << "Fibonacci series in reverse order: ";
            while (!this->isEmpty()) {
                cout << this->pop() << " ";  
            }
            cout << endl;
        }
};

int main(){
    Muqaddas_Mehboob_Lab03 series;
    int size;
    cout << "Enter the size of the Fibonacci series: ";
    cin >> size;
    series.fibonacci(size);  
    return 0;
}
