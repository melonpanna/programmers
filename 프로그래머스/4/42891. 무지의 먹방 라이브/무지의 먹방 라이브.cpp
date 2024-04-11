#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> food_times, long long k) {
    auto cmp=[](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first==b.first)return a.second>b.second;
        return a.first>b.first;
    };
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
    for(int i=0;i<food_times.size();i++){
        pq.push({food_times[i],i+1});
    }
    k++;
    // cout<<pq.top().first<<' '<<pq.top().second;
    int del=0;
    while(1){
        long long cnt=(long long)pq.size()*(pq.top().first-del);
        if(cnt>=k)break;
        del=pq.top().first;
        k-=cnt;
        //같은애들도 다 pop
        while(!pq.empty()&&pq.top().first==del)pq.pop();
        if(pq.empty())return -1;
    }
    vector<int> v;
    while(!pq.empty()){
        v.push_back(pq.top().second);
        pq.pop();
    }
    sort(v.begin(),v.end());
    return v[(k-1)%v.size()];
}