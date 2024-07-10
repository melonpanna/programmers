#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<long long> dp=vector<long long>(n+1,0);
    if(n==1)return 1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-2]+dp[i-1])%1000000007;
    }
    return dp[n];
}