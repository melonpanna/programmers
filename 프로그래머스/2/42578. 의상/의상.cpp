#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string,int> m;
    for(vector<string> e:clothes){
        //종류 있는지 확인-find
        //없음
        if(m.find(e[1])==m.end()){
            m.insert({e[1],1});
        }
        //있음
        else{
            m[e[1]]++;
        }
    }
    for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
        cout<<it->first<<' '<<it->second<<'\n';
        if(answer==0)answer=it->second+1;
        else answer*=(it->second+1);
        cout<<answer<<'\n';
    }
    return answer-1;
}