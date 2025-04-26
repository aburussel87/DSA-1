#include<iostream>
using namespace std;

int getmax(int a, int b){
    return a>b?a:b;
}
int maxsum(int arr[],int n){
    if(n==1){
        return arr[0];
    }
    int mid = n/2;
    int leftmaxsum = maxsum(arr,mid);
    int rightmaxsum = maxsum(arr+mid,n-mid);
    int left = INT32_MIN;
    int right = INT32_MIN;
    int sum = 0;
    for(int i = mid-1; i>=0; i--){
        sum += arr[i];
        left = getmax(sum,left);
    }
    sum = 0;
    for(int i = mid; i<n; i++){
        sum += arr[i];
        right = getmax(sum,right);
    }
    return getmax(getmax(leftmaxsum,rightmaxsum),left+right);
}
int main() {
    int arr[6] = { -2,1,1,0,0,0};
    cout<<maxsum(arr,6);
}
