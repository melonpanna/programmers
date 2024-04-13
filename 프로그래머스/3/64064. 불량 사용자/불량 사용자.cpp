#include <string>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
string s;
set<string> answerset;
int answer = 0;
void dfs(int order,int idx){
    s+=to_string(idx);
    if(order==v.size()-1){
        string temp=s;
        sort(temp.begin(),temp.end());
        if(answerset.find(temp)==answerset.end()){
            answer++;
            answerset.insert(temp);
        }
        s=s.substr(0,s.size()-1);
        return;
    }
    for(int i=0;i<v[order+1].size();i++){
        if(s.find(to_string(v[order+1][i]))==-1){
            dfs(order+1,v[order+1][i]);
        }
    }
    s=s.substr(0,s.size()-1);
    return;
}
int solution(vector<string> user_id, vector<string> banned_id) {
    for(int i=0;i<banned_id.size();i++)v.push_back(vector<int>());
    for(int i=0;i<user_id.size();i++){
        for(int j=0;j<banned_id.size();j++){
            if(user_id[i].size()!=banned_id[j].size())continue;
            bool check=true;
            for(int k=0;k<user_id.size();k++){
                if(banned_id[j][k]=='*')continue;
                if(banned_id[j][k]!=user_id[i][k]){
                    check=false;
                    break;
                }
            }
            if(check)v[j].push_back(i);
        }
    }
    for(int i=0;i<v[0].size();i++){
        dfs(0,v[0][i]);
    }
    return answer;
}