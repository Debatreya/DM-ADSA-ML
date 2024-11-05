#include<bits/stdc++.h>
using namespace std;

int partition(int left, int right, vector<double> &arr){
    int pivotVal = arr[left];
    int i = left+1, j = right;
    while(i<=j){
        // Move i ->
        while(i <= right and arr[i] < pivotVal){
            i++;
        }
        // Move j <-
        while(j > left and arr[j] >= pivotVal){
            j--;
        }
        // Where the i and j stop (swap if i < j)
        if(i<j){
            // swap(arr[i], arr[j]);
            double temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // After the loop stops replace arr[left] with arr[j] and return j;
    // swap(arr[left], arr[j]);
    double temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;

    // Print the Array
    cout<<"After Partition: ";
    for(double f: arr){
        cout<<f<<" ";
    }
    cout<<endl;
    return j; // pivot = j;
}

void quick_sort(int left, int right, vector<double> &arr){
    // If Left pointer has crossed the Right pointer: RETURN
    cout<<"Left: "<<left<<" Right: "<<right<<endl;
    if(left>=right){
        return;
    }
    // Else: FIND PIVOT
    int pivot = partition(left, right, arr);
    cout<<"\tPivot: "<<pivot<<endl;
    // Now only pivot is at its correct position.
    // QUICKSORT the two parts separately.
    quick_sort(left, pivot-1, arr);
    cout<<"After Left Part: ";
    for(double f: arr){
        cout<<f<<" ";
    }
    cout<<endl;
    quick_sort(pivot+1, right, arr);
    cout<<"After Right Part: ";
    for(double f: arr){
        cout<<f<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of the Array: ";
    cin>>n;
    vector<double> arr(n, 0);
    cout<<"Enter the elements of the Array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    // Quick Sort
    quick_sort(0, arr.size()-1, arr);
    // Print the Sorted Array
    cout<<"Sorted Array: ";
    for(double f: arr){
        cout<<f<<" ";
    }
    cout<<endl;
    return 0;
}

// Testcase: 
// 8
// 12.4 12.5 19.9 10.67 15.8 23.9 90 51.34