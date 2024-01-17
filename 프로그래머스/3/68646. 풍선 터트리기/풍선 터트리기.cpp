#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(vector<int> a) {
    int answer = 0;
    int n=a.size();
    if(n<=2)return n;
    vector<int> leftmin=vector<int>(n,0);
    vector<int> rightmin=vector<int>(n,0);
    leftmin[0]=a[0];
    rightmin[n-1]=a[n-1];
    for(int i=1;i<n-1;i++){
        leftmin[i]=min(leftmin[i-1],a[i]);
        rightmin[n-i-1]=min(rightmin[n-i],a[n-i-1]);
    }
    for(int i=1;i<n-1;i++){
        if(leftmin[i]>=a[i]||rightmin[i]>=a[i])answer++;
    }
    return answer+2;
}