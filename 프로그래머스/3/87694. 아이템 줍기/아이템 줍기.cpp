#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#define MAX_N 105

using namespace std;
//우회전 우선!!
int dr[4]={-1,0,1,0};
int dc[4]={0,-1,0,1};
int answer = 1e8;
//직사각형의 선을 표시하는 배열
int lines[MAX_N][MAX_N];
//직사각형의 내부임을 표시하는 배열
int squares[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
void bfs(int y,int x,int itemX,int itemY){
    visited[y][x]=true;
    queue<pair<pair<int,int>,int>> q;
    q.push({{y,x},0});
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int dist=q.front().second;
        if(r==itemY&&c==itemX){
            answer=min(answer,dist);
            return;
        }
        q.pop();
        for(int d=0;d<4;d++){
            int nextr=r+dr[d];
            int nextc=c+dc[d];
            if((nextr>=0&&nextr<=100&&nextc>=0&&nextc<=100)&&
              !visited[nextr][nextc]&&
              lines[nextr][nextc]>0&&squares[nextr][nextc]==0
              ){
                visited[nextr][nextc]=true;
                q.push({{nextr,nextc},dist+1});
            }
        }
    }
    return;
}


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    memset(lines, 0, sizeof(lines));
    memset(squares, 0, sizeof(squares));
    memset(visited, 0, sizeof(visited));
    
    for (vector<int> r : rectangle) {
        //선 따기
        int height = r[3] - r[1];//dy
        int width = r[2] - r[0];//dx
        for (int i = 0; i <= width*2; i++) {//dx
            lines[2*r[1]][2*r[0] + i]++;
            lines[2*r[3]][2*r[0] + i]++;
        }
        for (int j = 0; j <=height*2; j++) {//dy
            lines[2*r[1] + j][2*r[0]]++;
            lines[2*r[3] - j][2*r[2]]++;
        }
        //밑색 칠하기
        for (int i = 1; i < height*2; i++) {
            for (int j = 1; j < width*2; j++) {
                squares[2*r[1] + i][2*r[0] + j]++;
            }
        }
    }
    bfs(2*characterY, 2*characterX, 2*itemX, 2*itemY);
    return answer/2;
}