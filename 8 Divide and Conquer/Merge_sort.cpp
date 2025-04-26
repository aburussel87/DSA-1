#include<iostream>
#include<vector>
using namespace std;


void merge(int low, int mid, int high, vector<int>& arr){
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
void mergesort(int low, int high, vector<int>& arr){
    if(low<high){
        int mid = low + (high-low)/2;
        mergesort(low,mid,arr);
        mergesort(mid+1,high,arr);
        merge(low,mid,high,arr);
    }
}

int main(){
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(-1);
    arr.push_back(0);
    
    mergesort(0,4,arr);
    for(auto val: arr){
        cout<<val<<" ";
    };
    return 0;
}
