//01
#include <iostream>
using namespace std;

class Matrix{
    int rows, cols;
    int ** ptr;     //For dynamic memory allocation
    public:
        Matrix(int r, int c) : rows(r), cols(c){
                ptr = new int*[rows];
                for(int j = 0; j < rows; j++){
                    ptr[j] = new int[cols];
                }
        }
        void inputArray(){
            cout << "Enter elements of arrays in sorted form: " <<endl;
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    cin >> ptr[i][j];
                }
            }
        }
        int binarySearch(int element){
            int left = 0;
            int right = rows * cols -1;
            while(left <= right){
                int mid = left + (right - left) / 2;
                int midElement = ptr[mid / cols][mid % cols];
                if(midElement == element){
                    return mid;
                }
                else if(midElement < element){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
            return -1;
        }
        ~Matrix(){
            for(int i = 0; i < rows; i++){
                delete[] ptr[i];
            }
            delete[] ptr;
        }

};
int main(){
    int rows, cols, element;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
    Matrix mat(rows, cols);
    mat.inputArray();
    cout << "Enter the element to search for: ";
    cin >> element;
    int result = mat.binarySearch(element);
    if (result != -1) {
        cout << "Element found at index "<< result << endl;
    } else {
        cout << "Element not found in the matrix!" << endl;
    }
    return 0;
}

//02
#include <iostream>
using namespace std;

class Matrix{
    int rows, cols;
    int ** ptr;     //For dynamic memory allocation
    public:
        Matrix(int r, int c) : rows(r), cols(c){
                ptr = new int*[rows];
                for(int j = 0; j < rows; j++){
                    ptr[j] = new int[cols];
                }
        }
        void inputArray(){    // Function to input the matrix
            cout << "Enter elements of arrays in sorted form: " <<endl;
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    cin >> ptr[i][j];
                }
            }
        }
        void displayMatrix() {  // Function to display the matrix
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << ptr[i][j] << " ";
                }
                cout << endl;
            }
        }
        Matrix add(Matrix &B){   //Function to add matrix
            Matrix result(rows, cols);
            if(rows == B.rows && cols == B.cols){
                for(int i = 0; i < rows; i++){
                    for(int j = 0; j < cols; j++){
                        result.ptr[i][j] = ptr[i][j] + B.ptr[i][j];
                    }
                }
            }
            return result;
        }
        Matrix sub(Matrix &B){   //Function to subtract matrix
            Matrix result(rows, cols);
            if(rows == B.rows && cols == B.cols){
                for(int i = 0; i < rows; i++){
                    for(int j = 0; j < cols; j++){
                        result.ptr[i][j] = ptr[i][j] - B.ptr[i][j];
                    }
                }
            }
            return result;
        }
        Matrix multiply(Matrix &B){   //Function to multiply matrix
            Matrix result(rows, B.cols);
            if(cols == B.rows){
                for(int i = 0; i < rows; i++){
                    for(int j = 0; j < B.cols; j++){
                        result.ptr[i][j] = 0;
                        for(int k = 0; k < cols; k++){
                            result.ptr[i][j] += ptr[i][k] * B.ptr[k][j];
                        }
                    }
                }
            }
            return result;
        }
        Matrix constantMultiply(int number){    //Function to multiply matrix by a constant
            Matrix result(rows, cols);
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    result.ptr[i][j] = number * ptr[i][j];
                }
            }
            return result;
        }
        Matrix transpose(){     //Function to transpose a matrix
            Matrix result(rows, cols);
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    result.ptr[j][i] = ptr[i][j];
                }
            }
            return result;
        }
};
int main(){
    int rows, cols, element;
    cout << "Enter the number of rows for matrix A: ";
    cin >> rows;
    cout << "Enter the number of columns for matrix A: ";
    cin >> cols;
    Matrix A(rows, cols);
    A.inputArray();

    cout << "Enter the number of rows for matrix B: ";
    cin >> rows;
    cout << "Enter the number of columns for matrix A: ";
    cin >> cols;
    Matrix B(rows, cols);
    B.inputArray();

    cout << "Matrix A:\n";
    A.displayMatrix();
    cout << "Matrix B:\n";
    B.displayMatrix();

    cout << "\nMatrix A + B:\n";
    Matrix resultAdd = A.add(B);
    resultAdd.displayMatrix();
    
    cout << "\nMatrix A - B:\n";
    Matrix resultSubtract = A.sub(B);
    resultSubtract.displayMatrix();
    
    cout << "\nMatrix A * B:\n";
    Matrix resultMultiply = A.multiply(B);
    resultMultiply.displayMatrix();
    
    cout << "Enter a constant to multiply Matrix A: ";
    cin >> element;
    cout << "\nMatrix A * " << element << ":\n";
    Matrix resultConstMultiply = A.constantMultiply(element);
    resultConstMultiply.displayMatrix();
    
    cout << "\nTranspose of Matrix A:\n";
    Matrix resultTranspose = A.transpose();
    resultTranspose.displayMatrix();
    return 0;
}

//03
#include <iostream>
#include <vector>
using namespace std;

class Vector{
    int n;      //size of the vector
    vector <int> A, B;     //Vectors declaration
    int X, Y;       //scalars
    
    public:
        Vector(int size, int scalar_X, int scalar_Y) : n(size), X(scalar_X), Y(scalar_Y){
            A.resize(n);
            B.resize(n);
        }

        void inputElements(){   //Function to take input of vector elements
            cout << "Enter elements of vector A"<< endl;
            for(int i = 0; i < n; i++){
                cin >> A[i];
            }
            cout << "Enter elements of vector B"<< endl;
            for(int i = 0; i < n; i++){
                cin >> B[i];
            }
        }
        vector<int> scalarMultiplication(){  //Function for multplication of vectors by scalars
            vector <int> result(n);
            for(int i = 0; i < n; i++){
                result[i] = X*A[i] + Y*B[i];
            }
            return result;
        }
        int dotProduct(){   //Function to calculate dot product
            int product = 0;
            for (int i = 0; i < n; i++){
                product += A[i] * B[i];
            }
            return product;
        }
        void display(const vector <int> &v){    //Function to display vectors
            for(int i = 0; i < n; i++){
                cout << v[i] << " ";
            }
            cout << endl;
        }
};
int main(){
    int n, X, Y;
    
    cout << "Enter the size of the vectors: ";
    cin >> n;
    cout << "Enter scalar X: ";
    cin >> X;
    cout << "Enter scalar Y: ";
    cin >> Y;

    Vector vec(n, X, Y);
    vec.inputElements();
    vector<int> result = vec.scalarMultiplication();
    cout << "\nResult of XA + YB:\n";
    vec.display(result);
    int dotProduct = vec.dotProduct();
    cout << "\nDot product (A . B): " << dotProduct << endl;

    return 0;
}