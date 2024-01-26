#include <string>
#include <vector>
#define MAX_N 201
#include <cstring>

using namespace std;
bool visited[MAX_N];
void dfs(int i,vector<vector<int>> adj){
    for(int e:adj[i]){
        if(!visited[e]){
            visited[e]=true;
            dfs(e,adj);
        }
    }
    return;
}
//인접 행렬로 나타남-이걸 인접 리스트로 바꿔서 풀까?
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    memset(visited,0,sizeof(visited));
    vector<vector<int>> adj;
    for(int i=0;i<n;i++){
        adj.push_back(vector<int>());
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(computers[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            answer++;
            visited[i]=true;
            dfs(i,adj);
        }
    }
    return answer;
}