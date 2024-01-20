#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> p1,pair<int,int> p2){
    if(p1.first==p2.first)return p1.second<p2.second;
    else return p1.first>p2.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> popular;
    map<string,vector<pair<int,int>>> m;
    for(int i=0;i<genres.size();i++){
        if(popular.empty()||popular.find(genres[i])==popular.end()){
            popular[genres[i]]=plays[i];
            vector<pair<int,int>> temp;
            temp.push_back({plays[i],i});
            m[genres[i]]=temp;
        }
        else{
            popular[genres[i]]+=plays[i];
            m[genres[i]].push_back({plays[i],i});
        } 
    }
    vector<pair<int,string>> v;
    for(auto it=popular.begin();it!=popular.end();it++){
        v.push_back({it->second,it->first});
    }
    sort(v.rbegin(),v.rend());
    for(pair<int,string> e:v){
        if(m[e.second].size()==1){
            answer.push_back(m[e.second][0].second);
            continue;
        }
        sort(m[e.second].begin(),m[e.second].end(),cmp);
        for(int i=0;i<2;i++){
            answer.push_back(m[e.second][i].second);
        }
    }
    return answer;
}