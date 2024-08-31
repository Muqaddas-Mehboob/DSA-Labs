#include <iostream>
using namespace std;

//01
int main() {
    int rows, cols;

    // Taking user input for number of rows and columns
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Declaring a 2D array with the user-defined size
    int array2D[rows][cols];

    // Taking user input to populate the 2D array
    cout << "Enter the elements of the 2D array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> array2D[i][j];
        }
    }

    // Declaring a 1D array to store the elements in column-major order
    int array1D[rows * cols];
    int index = 0;

    // Converting 2D array to 1D array in column-major order
    for (int column = 0; column < cols; column++) {
        for (int row = 0; row < rows; row++) {
            array1D[index] = array2D[row][column];
            index++;
        }
    }

    // Displaying the 1D array
    cout << "1D Array in Column Major Order: ";
    for (int i = 0; i < rows * cols; i++) {
        cout << array1D[i] << " ";
    }

    return 0;
}

//02
#include <iostream>
#include <string>
using namespace std;

double calculateGPA(double grades[], int numberOfGrades, int creditHours) {
    double totalPoints = 0; 
    int validGradesCount = 0; 

    for (int i = 0; i < numberOfGrades; i++) {
        if (grades[i] != -1) { 
            totalPoints += grades[i] * creditHours; 
            validGradesCount++; 
        }
    }
    return totalPoints / (validGradesCount * creditHours); 
}

int main() {
    const int numStudents = 5; 
    const int numCourses = 5;  
    const int creditHours = 3; 

    string students[numStudents] = {"Ali", "Hiba", "Asma", "Zain", "Faisal"};
    
    double grades[numStudents][numCourses] = {
        {3.66, 3.33, 4.0, 3.0, 2.66}, // Ali
        {3.33, 3.0, 3.66, 3.0, -1},   // Hiba
        {4.0, 3.66, 2.66, -1, -1},    // Asma
        {2.66, 2.33, 4.0, -1, -1},    // Zain
        {3.33, 3.66, 4.0, 3.0, 3.33}  // Faisal
    };

    // Calculate and display GPA for each student
    for (int i = 0; i < numStudents; i++) {
        double gpa = calculateGPA(grades[i], numCourses, creditHours);
        cout << "GPA of " << students[i] << ": " << gpa << endl;
    }

    return 0; 
}

//03
#include <iostream>
using namespace std;

class MedianFinder {
private:
    int* nums;
    int size;
    int capacity;

public:
    MedianFinder() {
        size = 0;
        capacity = 1;
        nums = new int[capacity];  // Initial capacity of 1
    }

    ~MedianFinder() {
        delete[] nums;
    }

    void addNum(int num) {
        if (size == capacity) {
            int* temp = new int[capacity * 2];
            capacity *= 2;
            for (int i = 0; i < size; i++) {
                temp[i] = nums[i];
            }
            delete[] nums;
            nums = temp;
        }

        int i = size - 1;
        while (i >= 0 && nums[i] > num) {
            nums[i + 1] = nums[i];
            i--;
        }
        nums[i + 1] = num;
        size++;
    }

    double findMedian() {
        if (size % 2 == 0) {
            return (nums[size / 2 - 1] + nums[size / 2]) / 2.0;
        } else {
            return nums[size / 2];
        }
    }
};

int main() {
    MedianFinder medianFinder;
    int num;

    while (true) {
        cout << "Add number: ";
        cin >> num;

        medianFinder.addNum(num);
        cout << "Median: " << medianFinder.findMedian() << endl;
    }

    return 0;
}

//04
#include <iostream>
using namespace std;

int search(int nums[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Calculate the midpoint to avoid overflow
        
        if (nums[mid] == target) {
            return mid;  // Target found, return the index
        } else if (nums[mid] < target) {
            left = mid + 1;  // Search in the right half
        } else {
            right = mid - 1;  // Search in the left half
        }
    }

    return -1;  // Target not found, return -1
}

int main() {
    int size;
    
    // Take input for the size of the array
    cout << "Enter the size of the array: ";
    cin >> size;
    
    int nums[size];  // Declare an array of the given size

    // Take input for the elements of the array
    cout << "Enter " << size << " elements in ascending order: ";
    for (int i = 0; i < size; ++i) {
        cin >> nums[i];
    }
    
    int target;
    
    // Take input for the target value
    cout << "Enter the target value: ";
    cin >> target;
    
    // Perform the search
    int result = search(nums, size, target);

    // Output the result
    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target found at -1." << endl;
    }

    return 0;
}

//05
#include <iostream>
using namespace std;

bool searchMatrix(int matrix[][4], int m, int n, int target) {
    if (m == 0 || n == 0) return false;

    int left = 0;
    int right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int mid_value = matrix[mid / n][mid % n];  // Convert 1D index to 2D index

        if (mid_value == target) {
            return true;  // Target found
        } else if (mid_value < target) {
            left = mid + 1;  // Search in the right half
        } else {
            right = mid - 1;  // Search in the left half
        }
    }
    return false;  // Target not found
}

int main() {
    int m, n, target;

    // Input matrix dimensions
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    int matrix[m][4]; 

    // Input matrix values
    cout << "Enter the matrix values:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Input target value
    cout << "Enter the target value: ";
    cin >> target;

    // Search for the target value in the matrix
    bool result = searchMatrix(matrix, m, n, target);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
