#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int right=0;
    for(int e:stations){
        int cleft=max(1,e-w);
        int cright=min(n,e+w);
        if(right>cleft||cleft==1){
            right=cright;
            continue;
        }
        answer+=(cleft-right-1)/(2*w+1);
        if((cleft-right-1)%(2*w+1)>0)answer++;
        right=cright;
    }
    if(right<n){
        answer+=(n-right)/(2*w+1);
        if((n-right)%(2*w+1)>0)answer++;
    }
    return answer;
}