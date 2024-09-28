//01
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Muqaddas_Mehboob_Lab05{
    public:
        int partition(int* arr, int low, int high){
            int pivot = arr[low];
            int i = low + 1;
            for(int j = low + 1; j <= high ; j++){
                if(arr[j] < pivot){
                    swap(arr[i], arr[j]);
                    i++;
                }
            }
            swap(arr[low], arr[i-1]);
            return i-1;
        }
        void quickSort(int *arr, int low, int high){
            stack <int> s;
            s.push(low);
            s.push(high);
            while(!s.empty()){
                high = s.top();
                s.pop();
                low = s.top();
                s.pop();
                int pivot = partition(arr, low, high);
                if(pivot - 1 > low){
                    s.push(low);
                    s.push(pivot - 1);
                }
                if(pivot + 1 < high){
                    s.push(pivot + 1);
                    s.push(high);
                }
            }
        }
        void printArray(int arr[], int size) {
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    Muqaddas_Mehboob_Lab05 array;
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    array.printArray(arr, n);

    array.quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    array.printArray(arr, n);
    return 0;
}

//02
#include <iostream>
#include <algorithm>
using namespace std;

class Muqaddas_Mehboob_Lab05{
    public:
        void printArray(int arr[], int size) {
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        void merge(int *arr, int low, int mid, int high){
            int i = 0, j = 0, k = low;
            int n1 = mid - low + 1;
            int n2 = high - mid;
            int subArray1[n1];
            int subArray2[n2];

            for(int i = 0; i < n1; i++){
                subArray1[i] = arr[low + i];
            }
            for(int j = 0; j < n2; j++){
                subArray2[j] = arr[j + mid + 1];
            }
            while(i < n1 && j < n2){
                if(subArray1[i] <= subArray2[j]){
                    arr[k++] = subArray1[i++];
                }
                else{
                    arr[k++] = subArray2[j++];
                }
            }
            while( i < n1){
                arr[k++] = subArray1[i++];
            }
            while( j < n2){
                arr[k++] = subArray2[j++];
            }
        }
        void mergeSort(int *arr, int size){
            for(int currentSize = 1; currentSize < size; currentSize = 2* currentSize){
                for(int leftStart = 0; leftStart < size - 1; leftStart += 2 * currentSize){
                    int mid = min(leftStart + currentSize - 1, size - 1);
                    int rightEnd = min(leftStart + 2 * currentSize - 1, size - 1);
                    merge(arr, leftStart , mid, rightEnd);
                }
            }
        }
};

int main(){
    Muqaddas_Mehboob_Lab05 array;
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    array.printArray(arr, n);

    array.mergeSort(arr, n);

    cout << "Sorted array: ";
    array.printArray(arr, n);
    return 0;
}

//03
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Muqaddas_Mehboob_Lab05{
    public:
        vector<vector <int>> mergeIntervals(vector<vector<int>> &array){
            vector<vector <int>> mergedArray;
            sort(array.begin(), array.end());
            for(const auto& i : array){
                if(mergedArray.empty() || mergedArray.back()[1] < i[0]){
                    mergedArray.push_back(i);
                }
                else{
                    mergedArray.back()[1] = max(mergedArray.back()[1], i[1]);
                }
            }
            return mergedArray;
        }
};

int main(){
    Muqaddas_Mehboob_Lab05 array;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    cout << "Before Merged Intervals: ";
    for (const auto& interval : intervals) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    vector<vector<int>> result = array.mergeIntervals(intervals);
    cout << endl;
    cout << "Merged Intervals: ";
    for (const auto& interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    return 0;
}

//04
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Muqaddas_Mehboob_Lab05{
    public:
        int findLongest(vector < int > &arr){
            sort(arr.begin(), arr.end());
            int longest = 0;
            int start = 0;
            for(int end = 1; end < arr.size(); end++){
                while(arr[end] - arr[start] > 1){
                    start++;
                }
                if (arr[end] - arr[start] == 1) {
                longest = max(longest, end - start + 1);
                }
            }
            return longest;
        }
};

int main(){
    Muqaddas_Mehboob_Lab05 solution;

    vector<int> nums1 = {1, 3, 2, 2, 5, 2, 3, 7};
    cout << "Longest Harmonious Subsequence length: " << solution.findLongest(nums1) << endl; // Output: 5

    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Longest Harmonious Subsequence length: " << solution.findLongest(nums2) << endl; // Output: 2

    vector<int> nums3 = {1, 1, 1, 1};
    cout << "Longest Harmonious Subsequence length: " << solution.findLongest(nums3) << endl; // Output: 0

}

//05
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Muqaddas_Mehboob_Lab05{
    public:
        bool carPooling(vector<vector <int>> &vec, int capacity){
            vector <int> timeline(1001,0);
            for(const auto& trip : vec){
                timeline[trip[1]] += trip[0];   //Pickup passengers
                timeline[trip[2]] -= trip[0];   //drop off passengers
            }
            int currentPassengers = 0;
            for(int i = 0; i <= 1000; i++){
                currentPassengers += timeline[i];
                if(currentPassengers > capacity){
                    return false;
                }
            }
            return true;
        }
};

int main(){
    Muqaddas_Mehboob_Lab05 vec, vec1;
    vector<vector<int>> trips = {{2, 1, 5}, {3, 3, 7}};
    int capacity = 5;
    int capacity1 = 4;

    cout << "Correct output\n";
    if (vec.carPooling(trips, capacity)) {
        cout << "Possible to pick up and drop off all passengers because capacity is " << capacity << endl;
    } else {
        cout << "Not possible to pick up and drop off all passengers because capacity is " << capacity << endl;
    }
    cout << endl;
    cout << "Worng output\n";
    if (vec1.carPooling(trips, capacity1)) {
        cout << "Possible to pick up and drop off all passengers because capacity is " << capacity1  << endl;
    } else {
        cout << "Not possible to pick up and drop off all passengers because capacity is " << capacity1  << endl;
    }
    return 0;
}