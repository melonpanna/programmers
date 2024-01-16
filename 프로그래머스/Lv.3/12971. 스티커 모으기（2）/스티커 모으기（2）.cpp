#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX_N 100005
using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    // 현재 인덱스는
    // i-2에서 왔을 수도 있고
    // i-3에서 왔을 수도 있음
    // i==n-1이면, 0번 인덱스에서 출발한 애는 업데이트 불가
    // i==2에서도 출발할 수 있지 않아?세 가지 고르고
    int dp[MAX_N][3];
    int n=sticker.size();
    memset(dp,0,sizeof(dp));
    if(n==1)return sticker[0];
    else if(n==2)return max(sticker[0],sticker[1]);
    else if(n==3)return max(sticker[0],max(sticker[1],sticker[2]));
    dp[0][0]=sticker[0];
    dp[1][1]=sticker[1];
    dp[2][2]=sticker[2];
    for(int i=0;i<3;i++){
        if(i==n)break;
        for(int j=i+2;j<sticker.size();j++){
            if(i==0&&j==sticker.size()-1)dp[j][i]=max(dp[j-2][i],dp[j-3][i]);
            else if(j==i+2)dp[j][i]=dp[j-2][i]+sticker[j];//2/3/4
            else dp[j][i]=max(dp[j-2][i],dp[j-3][i])+sticker[j];
            if(j>=sticker.size()-2)answer=max(answer,dp[j][i]);
        }
    }
    return answer;
}