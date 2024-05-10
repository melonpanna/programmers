#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int solution(string s)
{
    int answer=1;
    for(int i=1;i<s.size()-1;i++){
        int left=i-1;
        int right=i+1;
        int cnt=1;
        while(left>=0&&right<s.size()){
            if(s[left]==s[right])cnt+=2;
            else break;
            left--;right++;
        }
        answer=max(answer,cnt);
    }
    for(int i=0;i<s.size()-1;i++){
        //s[0]~s[1]이 답인 상황도 고려
        int j=i+1;
        if(s[i]!=s[j])continue;
        int left=i-1;
        int right=j+1;
        int cnt=2;
        while(left>=0&&right<s.size()){
            if(s[left]==s[right])cnt+=2;
            else break;
            left--;right++;
        }
        answer=max(answer,cnt);
    }
    return answer;
}