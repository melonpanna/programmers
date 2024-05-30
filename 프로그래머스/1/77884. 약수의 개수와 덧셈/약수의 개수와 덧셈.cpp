#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    vector<int> cnt=vector<int>(right+1,1);
    
    for(int j=left;j<=right;j++){
        for(int i=2;i<=right;i++){
            if(i>j)break;
            if((j%i)==0)cnt[j]++;
        }
    }
    for(int j=left;j<=right;j++){
        if((cnt[j]%2)==0)answer+=j;
        else answer-=j;
    }
    return answer;
}