#include<iostream>
#include<vector>
using namespace std;

void Bubblesort(int *arr,int size){
    for(int i= 0; i<size; i++){
        for(int j = 0; j<size-1-i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void InsertionSort(int *arr, int size){
    for(int i = 1; i<size; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


void merge(int *arr, int low, int mid, int high){
    int n1 = (mid-low)+1;
    int n2 = high - mid;
    vector<int> larr(n1),rarr(n2);
    for(int i = 0; i<n1; i++){
        larr[i]  = arr[low+i];
    }
    for(int i = 0; i<n2; i++){
        rarr[i]  = arr[mid + i + 1];
    }
    int i = 0;
    int j = 0;
    int k = low;
    while(i<n1 && j<n2){
        if(larr[i]<rarr[j]){
            arr[k++] = larr[i++];
        }else{
            arr[k++] = rarr[j++];
        }
    }
    while(i<n1){
        arr[k++] = larr[i++];
    }
    while(j<n2){
        arr[k++] = rarr[j++];
    }
}
void MS(int *arr, int low, int high){
    if(low == high){
        return;
    }
    int mid = (high+low)/2;
    MS(arr,low,mid);
    MS(arr,low+1,high);
    merge(arr,low,mid,high);
}
void merge_sort(int *arr, int n){
    int low = 0;
    int high = n-1;
    int mid = n/2;
    MS(arr,low,high);
}

int Partition(int *arr, int low,int high){
    int pivot = arr[high];
    int pivot_pos = low-1;
    for(int j = low; j<=high-1; j++){
        if(pivot>=arr[j]){
            pivot_pos += 1;
            swap(arr[j],arr[pivot_pos]);
        }
    }
    pivot_pos += 1;
    swap(arr[pivot_pos],arr[high]);
    return pivot_pos;
}

void QS(int *arr, int low, int high){
    if(low<high){
        int partition = Partition(arr,low,high);
        QS(arr,low,partition-1);
        QS(arr,partition+1,high);
    }
    return;
}
void quick_sort(int *arr, int n){
    int low = 0;
    int high = n-1;
    QS(arr,low,high);
}