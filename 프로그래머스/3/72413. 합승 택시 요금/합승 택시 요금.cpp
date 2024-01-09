#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#define MAX_N 205

using namespace std;
int dist[MAX_N][MAX_N];
vector<vector<pair<int,int>>> adj;
void dijkstra(int s){
    dist[s][s]=0;
    queue<pair<int,int>> q;
    q.push({s,0});
    while(!q.empty()){
        int d=q.front().second;//출발점-현재 정점까지의 거리
        int v=q.front().first;//현재 정점
        q.pop();
        for(pair<int,int> e:adj[v]){
            int nextv=e.first;
            if(dist[s][nextv]==-1||dist[s][nextv]>e.second+d){
                dist[s][nextv]=e.second+d;
                q.push({nextv,dist[s][nextv]});
            }
        }
    }
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    memset(dist,-1,sizeof(dist));
    for(int i=0;i<=n;i++){
        adj.push_back(vector<pair<int,int>>());
    }
    for(vector<int> f:fares){
        int u=f[0];
        int v=f[1];
        int fare=f[2];
        adj[u].push_back({v,fare});
        adj[v].push_back({u,fare});
    }
    //최단거리 초기화
    dijkstra(s);
    //어쩔 수 없이 얘네도..
    dijkstra(a);
    dijkstra(b);
    int answer=dist[s][a]+dist[s][b];
    for(int i=1;i<=n;i++){
        if(i==s)continue;
        //i을 중간 노드로 했을 때, 최소 운임?
        //a 또는 b가 중간 노드일 수도 있음
        if(dist[s][i]!=-1&&dist[a][i]!=-1&&dist[b][i]!=-1){
            int temp=dist[s][i]+dist[a][i]+dist[b][i];
            answer=min(answer,temp);
        }
    }
    return answer;
}