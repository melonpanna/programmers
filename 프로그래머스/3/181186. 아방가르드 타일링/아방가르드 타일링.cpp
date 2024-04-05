#include <string>
#include <vector>
#define MOD 1000000007
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n) {
    vector<int> dp=vector<int>(max(4,n+1),0);
    vector<long long> sum=vector<long long>(max(4,n+1),0);
    dp[0]=1;
    dp[1]=1;
    dp[2]=3;
    dp[3]=10;
    sum[0]=1;
    sum[1]=1;
    sum[2]=3;
    sum[3]=11;
    int a;
    for(int i=4;i<=n;i++){
        dp[i]=((long long)dp[i-1]+(long long)dp[i-2]*2+(long long)dp[i-3]*5)%MOD;
        dp[i]=((long long)dp[i]+sum[i-4]*2)%MOD;
        if(i>=5)dp[i]=((long long)dp[i]+sum[i-5]*2)%MOD;
        if(i>=6)dp[i]=((long long)dp[i]+sum[i-6]*4)%MOD;
        sum[i]=(sum[i-3]+dp[i])%MOD;
    }
    return dp[n];
}