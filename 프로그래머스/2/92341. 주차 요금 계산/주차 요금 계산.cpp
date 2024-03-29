#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<int,int>> v;//차량번호,주차요금
    map<int,int> sum;
    map<int,int> m;
    int temp;
    for(string s:records){
        int time=stoi(s.substr(0,2))*60+stoi(s.substr(3,2));
        int num=stoi(s.substr(6,4));
        string command=s.substr(11);
        if(command=="IN"){
            m[num]=time;
        }
        else{
            temp=time-m[num];
            m.erase(num);
            if(sum.find(num)!=sum.end())sum[num]+=temp;
            else sum[num]=temp;
        }
    }
    int time=23*60+59;
    for(auto it=m.begin();it!=m.end();it++){
        temp=time-(it->second);
        if(sum.find(it->first)!=sum.end())sum[it->first]+=temp;
        else sum[it->first]=temp;
    }
    for(auto it=sum.begin();it!=sum.end();it++){
        int fee=fees[1];
        if(it->second>fees[0]){
            fee+=(((it->second)-fees[0])/fees[2])*fees[3];
            if(((it->second)-fees[0])%fees[2]>0)fee+=fees[3];
        }
        v.push_back({it->first,fee});
    }
    sort(v.begin(),v.end());
    for(pair<int,int> p:v)answer.push_back(p.second);
    return answer;
}