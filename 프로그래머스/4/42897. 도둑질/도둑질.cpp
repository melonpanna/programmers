#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int n=money.size();
    vector<int> dp1=vector<int>(n,0);
    vector<int> dp2=vector<int>(n,0);
    dp1[0]=money[0];
    dp1[1]=max(dp1[0],money[1]);
    dp2[0]=money[1];
    dp2[1]=max(dp2[0],money[2]);
    for(int i=2;i<n-1;i++){
        dp1[i]=max(dp1[i-2]+money[i],dp1[i-1]);
        dp2[i]=max(dp2[i-2]+money[i+1],dp2[i-1]);
    }
    return max(dp1[n-2],dp2[n-2]);
}