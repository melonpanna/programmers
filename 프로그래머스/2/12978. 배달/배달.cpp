#include <vector>
#include <queue>
#include <algorithm>
using namespace std;



int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<pair<int,int>>> adj=vector<vector<pair<int,int>>>(N+1,vector<pair<int,int>>());
    for(vector<int> r:road){
        int a=r[0];
        int b=r[1];
        adj[a].push_back({-r[2],b});
        adj[b].push_back({-r[2],a});
    }
    vector<int> dist;
    vector<bool> visited=vector<bool>(N+1,0);
    dist=vector<int>(N+1,1e6);
    dist[1]=0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        int d=-pq.top().first;
        int v=pq.top().second;
        pq.pop();
        if(visited[v])continue;
        visited[v]=true;
        dist[v]=d;
        if(dist[v]<=K){
            answer++;
        }
        for(pair<int,int> p:adj[v]){
            if(!visited[p.second]){
                pq.push({-d+p.first,p.second});
            }
        }
    }
    return answer;
}