#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(vector<string> v1,vector<string> v2){
    int shour1=stoi(v1[0].substr(0,2));
    int sminute1=stoi(v1[0].substr(3,2));
    int shour2=stoi(v2[0].substr(0,2));
    int sminute2=stoi(v2[0].substr(3,2));
    if(shour1==shour2){
        if(sminute1!=sminute2)return sminute1<sminute2;
        int ehour1=stoi(v1[1].substr(0,2));
        int eminute1=stoi(v1[1].substr(3,2));
        int ehour2=stoi(v2[1].substr(0,2));
        int eminute2=stoi(v2[1].substr(3,2));
        if(ehour1==ehour2)return eminute1<eminute2;
        else return ehour1<ehour2;
    }
    else return shour1<shour2;
}
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    //빨리 시작하는 순으로 정렬
    sort(book_time.begin(),book_time.end(),cmp);
    priority_queue<int,vector<int>,greater<int>> pq;//끝나는 시간 담음
    for(vector<string> v:book_time){
        int start=stoi(v[0].substr(0,2))*60+stoi(v[0].substr(3,2));
        int end=stoi(v[1].substr(0,2))*60+stoi(v[1].substr(3,2))+10;
        if(!pq.empty()){
            if(pq.top()<=start){
                pq.pop();
                answer--;
            }
        }
        pq.push(end);
        answer++;
    }
    return answer;
}