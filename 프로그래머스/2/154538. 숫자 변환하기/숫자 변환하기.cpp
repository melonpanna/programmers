#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int x, int y, int n) {
    int k=max(y+1,3*x+1);
    vector<int> dp=vector<int>(k,0);
    dp[x+n]=1;
    dp[2*x]=1;
    dp[3*x]=1;
    for(int i=x;i<=y;i++){
        if(i-n>0&&dp[i-n]!=0){
            if(dp[i]==0)dp[i]=dp[i-n]+1;
            else dp[i]=min(dp[i-n]+1,dp[i]);
        }
        if(i%2==0&&dp[i/2]!=0){
            if(dp[i]==0)dp[i]=dp[i/2]+1;
            else dp[i]=min(dp[i/2]+1,dp[i]);
        }
        if(i%3==0&&dp[i/3]!=0){
            if(dp[i]==0)dp[i]=dp[i/3]+1;
            else dp[i]=min(dp[i/3]+1,dp[i]);
        }
    }
    if(x!=y&&dp[y]==0)return -1;
    return dp[y];
}