#include <vector>
#include <set>
#include <cstring>
#include <queue>

using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer=vector<int>(2,0);
    // set<int> s;
    queue<pair<int,int>> q;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
    bool visited[101][101];
    memset(visited,0,sizeof(visited));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(picture[i][j]!=0
               &&!visited[i][j]
               // &&(s.empty()||!(s.find(picture[i][j])!=s.end()))
              ){
                answer[0]++;
                int num=picture[i][j];
                // s.insert(num);
                q.push({i,j});
                visited[i][j]=true;
                int cnt=0;
                while(!q.empty()){
                    int r=q.front().first;
                    int c=q.front().second;
                    cnt++;
                    q.pop();
                    for(int d=0;d<4;d++){
                        int nextr=r+dr[d];
                        int nextc=c+dc[d];
                        if(nextr>=0&&nextr<m&&nextc>=0&&nextc<n
                          &&picture[nextr][nextc]==num&&!visited[nextr][nextc]
                          ){
                            visited[nextr][nextc]=true;
                            q.push({nextr,nextc});
                        }
                    }
                }
                answer[1]=max(answer[1],cnt);
            }
        }
    }
    // answer[0]=s.size();
    return answer;
}