#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> road;
    for(int i=0;i<n;i++)road.push_back(vector<int>(m,0));
    for(vector<int> e:puddles){
        road[e[1]-1][e[0]-1]=-1;
    }
    road[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0&&j==0)||road[i][j]==-1)continue;
            //위가 막힘
            if(i==0||road[i-1][j]==-1){
                road[i][j]=(road[i][j-1]==-1?0:road[i][j-1])%1000000007;
            }
            //왼쪽이 막힘
            else if(j==0||road[i][j-1]==-1){
                road[i][j]=(road[i-1][j]==-1?0:road[i-1][j])%1000000007;
            }
            else{
                int a=(road[i-1][j]==-1)?0:road[i-1][j];
                int b=(road[i][j-1]==-1)?0:road[i][j-1];
                road[i][j]=(a+b)%1000000007;
            }
        }
    }
    answer=road[n-1][m-1];
    return answer;
}