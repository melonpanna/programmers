#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int maxd=0;
    vector<int> answerset;
    vector<bool> visited=vector<bool>(n+1,0);
    vector<int> dist=vector<int>(n+1,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//dist,num
    vector<vector<int>> adj=vector<vector<int>>(n+1,vector<int>());
    for(vector<int> v:edge){
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    visited[1]=true;
    pq.push({0,1});
    while(!pq.empty()){
        int num=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        for(int e:adj[num]){
            if(!visited[e]){
                visited[e]=true;
                dist[e]=d+1;
                pq.push({d+1,e});
                if(d+1==maxd){
                    answerset.push_back(e);
                }else if(d+1>maxd){
                    answerset.clear();
                    maxd=d+1;
                    answerset.push_back(e);
                }
            }
        }
    }
    return answerset.size();
}