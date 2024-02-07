#include <string>
#include <cstring>
using namespace std;
//3차원 방문 배열?
bool visited[15][15][4];
int dr[4]={-1,1,0,0};
int dc[4]={0,0,1,-1};
int solution(string dirs) {
    //memset 제대로 되나 보기
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            for(int h=0;h<4;h++)
                visited[i][j][h]=false;
        }
    }
    int answer = 0;
    int r=5,c=5;
    int d;
    for(int i=0;i<dirs.size();i++){
        switch(dirs[i]){
            case 'U':d=0;break;
            case 'D':d=1;break;
            case 'R':d=2;break;
            case 'L':d=3;break;
        }
        if(!(r+dr[d]>=0&&r+dr[d]<=10&&c+dc[d]>=0&&c+dc[d]<=10))continue;
        if(!visited[r][c][d])answer++;
        visited[r][c][d]=true;
        r+=dr[d];c+=dc[d];
        if(d%2==0)d++;
        else d--;
        visited[r][c][d]=true;
    }
    return answer;
}