#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

long long fac[21];
bool visited[21];
vector<int> solution(int n, long long k) {
    vector<int> answer;
    if(n==1){
        answer.push_back(1);
        return answer;
    }
    fac[0]=1;
    memset(visited,0,sizeof(visited));
    for(int i=1;i<=20;i++){
        fac[i]=fac[i-1]*i;
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++){
            if(visited[j])continue;
            cout<<i<<' '<<fac[n-i-1]<<"\n";
            if(k!=1&&fac[n-i-1]<k){
                k-=fac[n-i-1];
                continue;
            }
            visited[j]=true;
            answer.push_back(j);
            break;    
        }
    }
    return answer;
}