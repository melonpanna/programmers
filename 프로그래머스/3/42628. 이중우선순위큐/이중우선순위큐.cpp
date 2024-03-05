#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> pq;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for(string o:operations){
        if(o[0]=='I'){
            int i=stoi(o.substr(2,10));
            pq.push(i);
            continue;
        }
        if(pq.empty())continue;
        if(o.compare("D -1")){//C++는 equals 안 써도 되나
            pq.pop();
        }
        else{
            priority_queue<int> temp;
            while(!pq.empty()&&pq.size()>1){
                int t=pq.top();
                pq.pop();
                temp.push(t);
            }
            pq.pop();
            pq=temp;
        }
    }
    if(pq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(pq.top());
        while(pq.size()!=1){
            pq.pop();
        }
        answer.push_back(pq.top());
    }
    return answer;
}