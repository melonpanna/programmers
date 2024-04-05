#include <string>
#include <vector>
#define MOD 1000000007
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> dp=vector<int>(n+1,0);
    dp[0]=1;
    dp[1]=1;
    dp[2]=3;
    for(int i=3;i<=n;i++){
        dp[i]+=dp[i-3]*5%MOD;
        dp[i]+=dp[i-1];
        dp[i]+=dp[i-2]*2%MOD;
        if(i>=4)dp[i]+=dp[i-4]*2%MOD;
        if(i>=6)dp[i]+=dp[i-6]*4%MOD;
        int a=1;
        while(3*a+2<=i){
            dp[i]+=dp[i-(3*a+2)]*2%MOD;
            a++;
        }
        dp[i]%=MOD;
        cout<<i<<' '<<dp[i]<<'\n';
    }
    return dp[n];
}