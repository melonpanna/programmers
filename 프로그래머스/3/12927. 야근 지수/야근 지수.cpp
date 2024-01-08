#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for(int e:works){
        pq.push(e);
    }
    for(int i=0;i<n;i++){
        int temp=pq.top();
        if(temp==0)break;
        pq.pop();
        pq.push(temp-1);
    }
    while(!pq.empty()){
        int temp=pq.top();
        pq.pop();
        answer+=temp*temp;
    }
    return answer;
}