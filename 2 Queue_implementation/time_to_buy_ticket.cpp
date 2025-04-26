#include"QueueArray.h"
#include<iostream>

class Solution {
public:
    int timeRequiredToBuy( int *tickets,int n, int k) {
        int time = 0;
        Queue q;
        for(int i = 0; i<n; i++){
            q.enqueue(i);
        }
        while(tickets[k]!= 0){
            int x = q.dequeue();
            if(tickets[x] == 0) continue;
            tickets[x] = tickets[x] -1;
            cout<<tickets[x]<<" ";
            q.enqueue(x);
            time++;
        }
        cout<<endl;
        return time;
    }
};

int main(){
    Solution s;
    int arr[5] = {0,3,0,0,0};
    cout<<s.timeRequiredToBuy(arr,5,1)<<endl;
    return 0;
}
