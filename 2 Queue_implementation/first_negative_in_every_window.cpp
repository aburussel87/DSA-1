#include<iostream>
#include"QueueArray.h"

void first_negative(int arr[],int n, int k){
    Queue final;
    for(int i = 0; i<n; i++){
        int x = k;
        if(i+k>n) break;
        int j = i;
        while(x--){
            if(arr[j]<0){
                final.enqueue(arr[j]);
                break;
            }
            j++;
        }
        if(final.length()==i) final.enqueue(0);
    }
    while(!final.isEmpty()) cout<<final.dequeue()<<" ";
    cout<<endl;
}

int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    first_negative(arr, n, k);
    return 0;
}