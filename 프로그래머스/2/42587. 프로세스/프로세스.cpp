#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int,int>> q;
    for(int i=0;i<priorities.size();i++){
        pq.push(priorities[i]);
        q.push({priorities[i],i});
    }
    int cnt=1;
    while(!pq.empty()&&!q.empty()){
        if(pq.top()==q.front().first){
            if(q.front().second==location)return cnt;
            pq.pop();
            q.pop();
            cnt++;
        }
        else{
            q.push(q.front());
            q.pop();
        }
    }
    return -1;
}