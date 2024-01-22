#include <string>
#include <vector>
#include <algorithm>
#define N 1000000007
#include <iostream>

using namespace std;

int solution(int n, vector<int> money) {
    sort(money.begin(),money.end());
    vector<int> dp=vector<int>(n+1,0);
    dp[0]=1;
    for(int coin:money){
        for(int i=money[0];i<=n;i++){
            if(i>=coin){
                dp[i]+=dp[i-coin];
                dp[i]%=N;
            }
        }
    }
    return dp[n];
}