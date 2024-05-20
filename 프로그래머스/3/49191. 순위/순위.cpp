#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> beat=vector<vector<int>>(n+1,vector<int>(n+1,0));
    for(vector<int> e:results){
        beat[e[0]][e[1]]=1;
        beat[e[1]][e[0]]=-1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(beat[i][k]==1&&beat[k][j]==1){
                    beat[i][j]=1;
                    beat[j][i]=-1;
                }
                else if(beat[i][k]==-1&&beat[k][j]==-1){
                    beat[j][i]=1;
                    beat[i][j]=-1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(beat[i][j]!=0)cnt++;
        }
        if(cnt==n-1)answer++;
    }
    return answer;
}