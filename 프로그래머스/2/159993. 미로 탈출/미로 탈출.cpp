#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>

using namespace std;
int solution(vector<string> maps) {
    int answer = 1e10;
    int startr,startc,exitr,exitc,leverr,leverc;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].size();j++){
            switch(maps[i][j]){
                case 'S':startr=i;startc=j;break;
                case 'E':exitr=i;exitc=j;break;
                case 'L':leverr=i;leverc=j;break;
                default:break;
            }
        }
    }
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{startr,startc},{0,0}});
    int visited[101][101][2];
    memset(visited,0,sizeof(visited));
    visited[startr][startc][0]=true;
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int cnt=q.front().second.first;
        int lever=q.front().second.second;
        q.pop();
        if(r==leverr&&c==leverc)lever=1;
        for(int d=0;d<4;d++){
            int nextr=r+dr[d];
            int nextc=c+dc[d];
            if(nextr>=0&&nextr<maps.size()&&nextc>=0&&nextc<maps[0].size()&&!visited[nextr][nextc][lever]){
                if(maps[nextr][nextc]=='X')continue;
                if(nextr==exitr&&nextc==exitc&&lever)return cnt+1;
                visited[nextr][nextc][lever]=true;
                q.push({{nextr,nextc},{cnt+1,lever}});
                
            }
        }
    }
    return -1;
}