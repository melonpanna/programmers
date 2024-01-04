#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//{작업시간,시작시간}
//현재 시간 이전에 요청된 작업 중 가장 작업시간이 짧은 것부터 처리
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int timer=0;//현재 시간
    int cnt=jobs.size();
    while(!pq.empty()||!jobs.empty()){
        for(int i=0;i<jobs.size();i++){
            //작업 가능한 일들 찾아서 대기열에 넣기
            if(jobs[i][0]<=timer){
                pq.push({jobs[i][1],jobs[i][0]});
                cout<<jobs[i][0]<<' '<<jobs[i][1]<<'\n';
                jobs.erase(jobs.begin()+i);
                i--;
            }
        }
        //대기열의 맨 첫번째를 작업 및 시간 갱신
        if(!pq.empty()){
            //지연된 시간+작업에 걸리는 시간
            cout<<"do "<<pq.top().second<<'\n';
            answer+=timer-pq.top().second+pq.top().first;
            timer+=pq.top().first;
            pq.pop();
        }
        else timer++;
    }
    answer/=cnt;
    return answer;
}