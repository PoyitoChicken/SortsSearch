/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

void bubbleSort(vector <int> arr){
    int pivot;
    for (int j = 0; j < arr.size()-1; j++){
        for (int i = 0; i<arr.size()-1; i++){
                if (arr[i] > arr[i+1]){
                    pivot = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = pivot;
                }
            }
    }
    for (int i = 0; i< arr.size(); i++){
        cout << arr[i] << " ";
    }
}

void SelectionSort(vector<int> &arr){
    int max, max_pos;
    for (int i = 0; i < arr.size() - 1; i++){
        max = arr[0];
        max_pos = 0;
        for (int j = 1; j < arr.size() - i; j++){
            if (arr[j] > max){
                max = arr[j];
                max_pos = j;
            }
        }
        swap(arr[max_pos], arr[arr.size() - i - 1]);
    }
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}
void InsertionSort(vector<int> &arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    for (int i = 0; i <10; i++){
        cout << arr[i] << " ";
    }
}
void merge(vector<int> &left, vector<int> &right, vector<int> &sorted) {
    int i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            sorted.push_back(left[i++]);
        } else {
            sorted.push_back(right[j++]);
        }
    }
    while (i < left.size()) {
        sorted.push_back(left[i++]);
    }
    while (j < right.size()) {
        sorted.push_back(right[j++]);
    }
    
}

void mergeSort(vector<int>& arr) {
    if (arr.size() <= 1) {
        return;
    }
    int half = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + half);
    vector<int> right(arr.begin() + half, arr.end());
    mergeSort(left);
    mergeSort(right);
    arr.clear();
    merge(left, right, arr);
}

vector <int> createVector(int size){
    vector <int> arr;
    for (int i = 0; i< size; i++){
        arr.push_back(rand());
    }
    return arr;
}
void sequentialSearch(vector <int> arr, int value){
    for (int i = 0; i< arr.size(); i++){
        if (arr[i] == value){
            cout << "El valor se encuentra en la posicion: " << i << endl;
            return;
        }
    }
}

void binarySearch(vector <int> arr, int value){
    int left = 0;
    int right = arr.size() - 1;
    int middle;
    while (left <= right){
        middle = (left + right) / 2;
        if (arr[middle] == value){
            cout << "La posicion del valor es: " << middle << endl;
            return; 
        }
        else if (arr[middle] < value){
            left = middle + 1;
        }
        else{
            right = middle - 1;
        }
    }
    cout << "No encontrado" << endl;
    return;
}
void mFunc(){
        vector <int> sorted;
        cout << "Que tamaño de vector quieres? ";
        int answerSize;
        cin >> answerSize;
        vector <int> cVec = createVector(answerSize);
        cout << "Que metodo quieres utilizar? " << endl;
        cout << "1. Bubble Sort, 2. Selection Sort, 3. Insertion Sort, 4. Merge Sort" << endl;
        int answerSort;
        cin >> answerSort;
        auto start = high_resolution_clock::now();
        switch(answerSort){
            case 1:
                bubbleSort(cVec);
                break;
            case 2:
                SelectionSort(cVec);
                break;
            case 3:
                InsertionSort(cVec);
                break;
            case 4:
                mergeSort(cVec);
                break;
            default:
                mergeSort(cVec);
                break;
        }

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout << "Duration: " << duration.count() << " microseconds" << endl;
        cout << "Que valor deseas buscar? ";
        int answerSearchNum;
        cin >> answerSearchNum;
        cout << "Que metodo deseas utilizar? " << endl;
        cout << "1. Sequential Search, 2. Binary Search" << endl;
        int answerSearchMethod;
        cin >> answerSearchMethod;
        start = high_resolution_clock::now();
        switch (answerSearchMethod){
            case 1:
                sequentialSearch(cVec, answerSearchNum);
                break;
            case 2:
                binarySearch(cVec, answerSearchNum);
                break;
            default:
                binarySearch(cVec, answerSearchNum);
                break;
        }
        end = high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start);
        cout << "Duration: " << duration.count() << " microseconds" << endl;

}
int main()
{
    string answer = "y";
    while (answer == "y"){
        mFunc();
        cout << "Deseas continuar? (y/n) ";
        cin >> answer;
    }
    return 0;
}
