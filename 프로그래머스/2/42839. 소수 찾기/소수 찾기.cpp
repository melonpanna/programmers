#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;
set<int> s;
void perm(string numbers,int index,string temp,int visited){
    temp+=numbers[index];
    s.insert(stoi(temp));
    visited|=(1<<index);
    for(int i=0;i<numbers.size();i++){
        if(visited&(1<<i))continue;
        perm(numbers,i,temp,visited);
    }
    visited-=(1<<index);
}

int solution(string numbers) {
    int answer = 0;
    for(int i=0;i<numbers.size();i++){
        perm(numbers,i,"",0);
    }
    vector<int> v=vector<int>(s.begin(),s.end());
    int maxn=*max_element(v.begin(),v.end());
    vector<bool> isprime=vector<bool>(maxn+1,true);
    isprime[0]=false;
    isprime[1]=false;
    for(int i=2;i<=(maxn/2);i++){
        if(!isprime[i])continue;
        int cnt=2;
        while(i*cnt<=maxn){
            isprime[i*cnt]=false;
            cnt++;
        }
    }
    for(int i=0;i<v.size();i++){
        if(isprime[v[i]])answer++;
    }
    return answer;
}