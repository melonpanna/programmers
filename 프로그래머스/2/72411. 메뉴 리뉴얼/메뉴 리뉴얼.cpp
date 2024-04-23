#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
map<string,int> m;

void dfs(int index,string temp,string origin){
    temp+=origin[index];
    sort(temp.begin(),temp.end());
    if(m.find(temp)!=m.end())m[temp]++;
    else m[temp]=1;
    for(int i=index+1;i<origin.size();i++){
        dfs(i,temp,origin);
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i=0;i<orders.size();i++){
        for(int j=0;j<orders[i].size();j++){
            dfs(j,"",orders[i]);
        }
    }
    vector<pair<int,string>> v;
    for(auto it=m.begin();it!=m.end();it++){
        v.push_back({it->second,it->first});
    }
    sort(v.rbegin(),v.rend());
    map<int,int> m2;
    for(int i=0;i<v.size();i++){
        if(v[i].first>1){
            if(find(course.begin(),course.end(),v[i].second.size())!=course.end()){
                if(m2.find(v[i].second.size())!=m2.end()){
                    if(m2[v[i].second.size()]==v[i].first)answer.push_back(v[i].second);
                }
                else{
                    m2[v[i].second.size()]=v[i].first;
                    answer.push_back(v[i].second);
                }
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}