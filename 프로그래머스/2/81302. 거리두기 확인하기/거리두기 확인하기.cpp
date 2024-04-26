#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer=vector<int>(places.size(),1);
    queue<pair<pair<int,int>,int>> q;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
    bool visited[5][5];
    for(int t=0;t<places.size();t++){
        for(int i=0;i<places[t].size();i++){
            for(int j=0;j<places[i][0].size();j++){
                if(places[t][i][j]=='P'){
                    memset(visited,0,sizeof(visited));
                    visited[i][j]=true;
                    q.push({{i,j},0});
                    while(!q.empty()){
                        int dist=q.front().second;
                        int r=q.front().first.first;
                        int c=q.front().first.second;
                        q.pop();
                        for(int d=0;d<4;d++){
                            if(dist<2&&r+dr[d]>=0&&r+dr[d]<places.size()
                              &&c+dc[d]>=0&&c+dc[d]<places[i].size()
                              &&places[t][r+dr[d]][c+dc[d]]!='X'
                              &&!visited[r+dr[d]][c+dc[d]]
                              ){
                                if(places[t][r+dr[d]][c+dc[d]]=='P'){
                                    answer[t]=0;
                                    break;
                                }
                                visited[r+dr[d]][c+dc[d]]=true;
                                q.push({{r+dr[d],c+dc[d]},dist+1});
                            }
                        }
                    }
                }
                if(answer[t]==0)break;
            }
            if(answer[t]==0)break;
        }
    }
    return answer;
}