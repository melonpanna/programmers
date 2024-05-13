#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    vector<int> s1;
    vector<int> s2;
    vector<long long> dp=vector<long long>(sequence.size(),0);
    for(int i=0;i<sequence.size();i++){
        if(i%2==0){
            s1.push_back(sequence[i]);
            s2.push_back(-sequence[i]);
        }
        else{
            s1.push_back(-sequence[i]);
            s2.push_back(sequence[i]);
        }
    }
    //이전 애들이 도움이 되면 포함하고 아니면 0
    dp[0]=s1[0];
    answer=max((long long)s1[0],answer);
    for(int i=1;i<sequence.size();i++){
        if(dp[i-1]>0)dp[i]=dp[i-1]+s1[i];
        else dp[i]=s1[i];
        answer=max(dp[i],answer);
    }
    dp[0]=s2[0];
    answer=max((long long)s2[0],answer);
    for(int i=1;i<sequence.size();i++){
        if(dp[i-1]>0)dp[i]=dp[i-1]+s2[i];
        else dp[i]=s2[i];
        answer=max(dp[i],answer);
    }
    return answer;
}