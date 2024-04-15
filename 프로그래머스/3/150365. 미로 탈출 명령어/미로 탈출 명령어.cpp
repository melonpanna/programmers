#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    if((abs(x-r)+abs(y-c))>k)return "impossible";
    if((abs(abs(x-r)+abs(y-c)-k))%2!=0)return "impossible";
    string answer = "impossible";
    int dr[4]={1,0,0,-1};
    int dc[4]={0,-1,1,0};
    char dir[4]={'d','l','r','u'};
    priority_queue<pair<string,pair<int,int>>,vector<pair<string,pair<int,int>>>,greater<pair<string,pair<int,int>>>> q;
    q.push({"",{x,y}});
    while(!q.empty()){
        int i=q.top().second.first;
        int j=q.top().second.second;
        string s=q.top().first;
        q.pop();
        if(s.size()==k){
            if(i==r&&j==c)return s;
            continue;
        }
        else if(i==r&&j==c){
            if((k-s.size())%2!=0)return "impossible";
        }
        for(int d=0;d<4;d++){
            int nexti=i+dr[d];
            int nextj=j+dc[d];
            if(nexti>=1&&nexti<=n&&nextj>=1&&nextj<=m
              &&(abs(r-nexti)+abs(c-nextj))<=(k-1-s.size())
              ){
                q.push({s+dir[d],{nexti,nextj}});
            }
        }
    }
    return answer;
}