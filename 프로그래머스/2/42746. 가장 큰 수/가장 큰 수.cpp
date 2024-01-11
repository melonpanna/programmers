#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;
bool cmp(string s1,string s2){
    int lastindex=min(s1.length(),s2.length())-1;
    for(int i=0;i<=lastindex;i++){
        if(s1[i]==s2[i]){
            if(i==lastindex){
                if(s1.length()==s2.length()){
                    //아예 같은 문자열
                    return false;
                }
                else{
                    return s1 + s2 > s2 + s1;
                }
            }
            continue;
        }
        else return s1[i]>s2[i];     
    }
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(int n:numbers){
        stack<int> s;
        if(n==0){v.push_back("0");continue;}
        while(n>0){
            s.push(n%10);
            n/=10;
        }
        string temp;
        while(!s.empty()){
            temp+=s.top()+'0';
            s.pop();
        }
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),cmp);
    for(string str:v){
        answer+=str;
    }
    if(answer[0]=='0')return "0";
    cout<<cmp("566","56");
    return answer;
}