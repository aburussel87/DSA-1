#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct{
 int start; 
 int end;
}meeting;

void printAct(meeting a){
    cout<<"Start time: "<<a.start<<" End time: "<<a.end<<endl;
}

bool compare(meeting a,meeting b){
    return a.end<b.end;
}

vector<meeting> meetingSelection(vector<meeting> meetings){
    vector<meeting> final;
    final.push_back(meetings[0]);
    int finish = meetings[0].end;
    for(int i = 1; i<meetings.size(); i++){
        if(meetings[i].start>finish){
            final.push_back(meetings[i]);
            finish = meetings[i].end;
        }
    }
    return final;
}

int main(){
    vector<meeting> meetings ={{1,2},{3,4},{0,6},{5,7},{8,9},{5,9}};
    sort(meetings.begin(),meetings.end(),compare);
    vector<meeting> final = meetingSelection(meetings);
    int i = 0;
    cout<<"Selected Meeting: \n";
    for(meeting a: final){
        cout<<++i<<". ";
        printAct(a);
    }
}