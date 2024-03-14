#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> dp=vector<int>(numbers.size(),-1);
    vector<int> idx=vector<int>(numbers.size(),-1);
    for(int i=numbers.size()-2;i>=0;i--){
        for(int j=i+1;j<numbers.size();j++){
            if(numbers[i]<numbers[j]){
                dp[i]=numbers[j];
                idx[i]=j;
                break;
            }
            else{
                if(dp[j]==-1){
                    break;
                }
                if(numbers[i]>dp[j])continue;
                if(numbers[i]<dp[j]){
                    dp[i]=dp[j];
                    idx[i]=idx[j];
                    break;
                }
                else if(numbers[i]==dp[j]){
                    if(dp[idx[j]]!=-1){
                        dp[i]=dp[idx[j]];
                        idx[i]=idx[idx[j]];
                        break;
                    }
                }
            }
        }
        
    }
    return dp;
}