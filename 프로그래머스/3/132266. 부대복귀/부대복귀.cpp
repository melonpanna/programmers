#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> adj=vector<vector<int>>(n+1,vector<int>());
    for(vector<int> e:roads){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    answer=vector<int>(sources.size(),0);
    vector<int> dist=vector<int>(n+1,1e8);
    dist[destination]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,destination});
    while(!pq.empty()){
        int v=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        for(int e:adj[v]){
            if(dist[e]<=d+1)continue;
            pq.push({d+1,e});
            dist[e]=d+1;
        }
    }
    for(int i=0;i<sources.size();i++){
        if(dist[sources[i]]==1e8)answer[i]=-1;
        else answer[i]=dist[sources[i]];
    }
    return answer;
}