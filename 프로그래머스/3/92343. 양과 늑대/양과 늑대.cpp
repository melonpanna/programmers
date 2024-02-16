#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAX_N 18
using namespace std;
int answer=0;
vector<vector<int>> adj;//부모 뒤에 자식을 붙임
bool visited[MAX_N][MAX_N][MAX_N];
int sheep=0,wolf=0;
void dfs(int node,vector<int> info){
    if(info[node]==1){
        if(wolf+1>=sheep)return;
        else wolf++;
    }
    else if(info[node]==0){
        sheep++;
    }
    answer=max(sheep,answer);
    int temp=info[node];
    visited[node][sheep][wolf]=true;
    info[node]=-1;
    for(int e:adj[node]){
        if(!visited[e][sheep][wolf]){
            dfs(e,info);
        }
    }
    visited[node][sheep][wolf]=false;
    info[node]=temp;
    if(temp==0)sheep--;
    else if(temp==1)wolf--;
    return;
}
int solution(vector<int> info, vector<vector<int>> edges) {
    memset(visited,0,sizeof(visited));
    for(int i=0;i<info.size();i++)adj.push_back(vector<int>());
    for(vector<int> e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
    dfs(0,info);
    return answer;
}