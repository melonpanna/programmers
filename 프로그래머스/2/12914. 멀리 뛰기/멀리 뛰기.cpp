#include <vector>

using namespace std;

long long solution(int n) {
    vector<long long> dp=vector<long long>(n+1,0);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=(long long)dp[i-1]+dp[i-2];
        dp[i]%=1234567;
    }
    return dp[n];
}