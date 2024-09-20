//01
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Muqaddas_Mehboob_Lab04{
    public:
        void bubbleSort(vector <int>& vec, int size){   //Modified bubble sort
            bool isSorted;
            for(int i = 0; i < size-1; i++){
                isSorted = false;
                for(int j = 0; j < size - 1 -i ; j++){
                    if(vec[j] > vec[j+1]){
                        swap(vec[j], vec[j+1]);
                        isSorted = true;
                    }
                }
            if(!isSorted){
                break;
            }
        }
    }
    void print(vector<int> &vec, int size){
        for(int i = 0; i < size; i++){
            cout << vec[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector <int> vec(n);
    cout << "Enter the elements of the array: "<<endl;
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    Muqaddas_Mehboob_Lab04 array;
    cout << "Before sorting: ";
    array.print(vec, n);
    array.bubbleSort(vec, n);
    cout << "After sorting: ";
    array.print(vec, n);

    return 0;
}

//02
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Muqaddas_Mehboob_Lab04{
    public:
        void Sort(vector <int>& vec, int size){ //Simple bubble sort algortihm for sorting
            bool isSorted;
            for(int i = 0; i < size-1; i++){
                isSorted = false;
                for(int j = 0; j < size - 1 -i ; j++){
                    if(vec[j] > vec[j+1]){
                        swap(vec[j], vec[j+1]);
                        isSorted = true;
                    }
                }
            if(!isSorted){
                break;
            }
        }
    }
    void print(vector<int> &vec, int size){
        for(int i = 0; i < size; i++){
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    int maxToys(vector <int>& vec, int size, int amount){   //Calculate the max number of toys and return count of toys
        int total = 0;
        int toysCount = 0;
        for(int i = 0; i < size; i++){
            if(total + vec[i] <= amount){
                total += vec[i];
                toysCount++;
            }
            else{
                break;
            }
        }
        return toysCount;
    }
};
int main(){
    int n;
    cout << "How many toys are there: ";
    cin >> n;
    vector <int> vec(n);
    cout << "Enter the price of toys: "<<endl;
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    int amount;
    cout << "How much money do you have? ";
    cin >> amount;
    Muqaddas_Mehboob_Lab04 array;
    array.print(vec, n);
    array.Sort(vec, n);
    array.print(vec, n);
    int result = array.maxToys(vec,n,amount);
    cout << "You can buy "<< result << " toys in Rs."<< amount <<endl;
    return 0;
}

//03
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Muqaddas_Mehboob_Lab04{
    int comparisions;
    int swaps;
    public:
        void reset(){   //Reset the previous values of variables
            comparisions = 0;
            swaps = 0;
        }
        void bubbleSort(vector <int>& vec, int size){   //Bubble sort
            bool isSorted;
            reset();
            for(int i = 0; i < size-1; i++){
                isSorted = false;
                for(int j = 0; j < size - 1 -i ; j++){
                    if(vec[j] > vec[j+1]){
                        comparisions++;
                        swap(vec[j], vec[j+1]);
                        isSorted = true;
                        swaps++;
                    }
                }
            if(!isSorted){
                break;
            }
        }
    }
        void insertionSort(vector <int> &vec, int size){    //Insertion sort
            reset();
            for(int i = 0; i < size; i++){
                int element = vec[i];
                int j = i-1;
                while(j >= 0 && vec[j] > element){
                    comparisions++;
                    vec[j+1] = vec[j];
                    j--;
                }
                vec[j+1] = element;
                swaps++;
                if(j >= 0){
                    comparisions++;
                }
            }
        }
        void selectionSort(vector <int> &v, int size){  //Selection sort
            reset();
            for(int i = 0; i < size-1; i++){
                int min = i;
                for(int j = i+1; j < size; j++){
                    if(v[j] < v[min]){
                        comparisions++;
                        min = j;
                    }
                }
                if(min != i){
                    swap(v[min],v[i]);
                    swaps++;
                }
            }
        }
    void print(vector<int> &vec, int size){
        for(int i = 0; i < size; i++){
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    void sortArray(vector<int>& arr, int size, string choice) { //Return sorted array with no. of swaps and comparision
        if (choice == "bubble") {
            cout << "Using bubble sort\n";
            cout << "Before sorting: ";
            print(arr, size);
            bubbleSort(arr, size);
            cout << "After sorting: ";
            print(arr, size);
        } else if (choice == "selection") {
            cout << "Using selection sort\n";
            cout << "Before sorting: ";
            print(arr, size);
            selectionSort(arr, size);
            cout << "After sorting: ";
            print(arr, size);
        } else if (choice == "insertion") {
            cout << "Using insertion sort\n";
            cout << "Before sorting: ";
            print(arr, size);
            insertionSort(arr, size);
            cout << "After sorting: ";
            print(arr, size);
        } else {
            cout << "Invalid sorting technique!" << endl;
            return;
        }
        cout << "Number of comparisions: "<< comparisions << endl;
        cout << "Number of swaps: "<< swaps << endl;
    }
    void performAnalysis(int size, string technique) {  //Doing analysis with random array
        vector<int> arr(size);
        srand(time(0));
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 100;
        }
        cout << "Performing analysis on randomly generated array of size " << size << ":\n";
        sortArray(arr, size, technique);
    }
};

int main(){
    string technique;
    cout << "Which sorting you want to perform? ";
    cin >> technique;
    int size;
    cout << "Enter size of the array: ";
    cin >> size;
    Muqaddas_Mehboob_Lab04 array;
    array.performAnalysis(size, technique);
    
    return 0;
}

//04
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Muqaddas_Mehboob_Lab04{
    public:
        int findMaxIndex(vector <int>& vec, int size){  //Return index of the largest number
            int max = 0;
            for(int i = 0; i < size; i++){
                if(vec[i] > vec[max]){
                    max = i;
                }
            }
            return max;
        }
        void flip(vector <int> &vec, int size){ //Flip the numbers 
            int start = 0;
            while(start < size){
                swap(vec[start], vec[size]);
                start++;
                size--;
            }
        }
        void pancakeSort(vector <int> &vec, int size){  //Pancake flip sorting 
            int currentSize = size;
            while(currentSize > 1){
                int max = findMaxIndex(vec, currentSize);
                if(max != currentSize -1){
                    flip(vec, max);
                    flip(vec, currentSize-1);
                }
                currentSize--;
            }
        }
        void print(vector<int> &vec, int size){
        for(int i = 0; i < size; i++){
            cout << vec[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector <int> vec(n);
    cout << "Enter the elements of the array: "<<endl;
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    Muqaddas_Mehboob_Lab04 array;
    cout << "Before pancake flip: ";
    array.print(vec, n);
    array.pancakeSort(vec, n);
    cout << "After pancake flip: ";
    array.print(vec, n);

    return 0;
}

//05
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Muqaddas_Mehboob_Lab04{
    public:
        void sortColors(vector <int> &a, int n){    //Sorting using dutch national flag algorithm
            int low = 0;
            int high = n - 1;
            int mid = 0;
            while (mid <= high) {
                switch (a[mid]) {
                case 0:
                    swap(a[low++], a[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(a[mid], a[high--]);
                    break;
                }
            }
        }
        void printArray(vector <int>& arr, int n){
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
        }
};

int main(){
    vector <int> v = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int n = v.size();
    Muqaddas_Mehboob_Lab04 array;
    cout << "Before sorting: ";
    array.printArray(v, n);
    array.sortColors(v, n);
    cout << endl;
    cout << "After sorting: ";
    array.printArray(v, n);

    return 0;
}
