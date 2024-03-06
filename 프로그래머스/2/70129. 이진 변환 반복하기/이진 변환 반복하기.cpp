#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt=0;
    int zeros=0;
    if(s=="1"){
        answer=vector<int>({0,0});
        return answer;
    }
    while(s!="1"){
        cnt++;
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')c++;
        }
        zeros+=(s.size()-c);
        string temp="";
        for(int i=18;i>=0;i--){
            if(c&(1<<i))temp+='1';
            else temp+='0';
        }
        int index=temp.find('1');
        s=temp.substr(index,18);
    }
    answer.push_back(cnt);
    answer.push_back(zeros);
    return answer;
}