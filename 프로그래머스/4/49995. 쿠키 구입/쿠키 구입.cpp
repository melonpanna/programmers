#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> cookie) {
    int answer=0;
    int sum1=0;
    int sum2=0;
    for(int e:cookie)sum2+=e;
    for(int m=0;m<cookie.size()-1;m++){
        sum1+=cookie[m];
        sum2-=cookie[m];
        int s1=sum1;
        int s2=sum2;
        int l=0,r=cookie.size()-1;
        while(l<=m&&m<r){
            if(s1<s2){
                if(m<r-1)s2-=cookie[r--];
                else break;
            }
            else if(s1==s2){
                answer=max(s1,answer);
                break;
            }
            else{
                if(l+1<=m)s1-=cookie[l++];
                else break;
            }
        }
    }
    return answer;
}