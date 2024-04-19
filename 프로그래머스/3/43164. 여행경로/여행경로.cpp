#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,int> m;
map<int,string> name;
vector<vector<int>> remain;
vector<string> answer;
vector<string> temp;
int n;

void dfs(int v,vector<vector<int>>& adj,int c){
    if(c==n){
        if(answer.empty())answer=vector<string>(temp.begin(),temp.end());
        else{
            for(int i=1;i<n;i++){
                if(temp[i]<answer[i]){
                    answer=vector<string>(temp.begin(),temp.end());
                    break;
                }
                else if(temp[i]>answer[i])break;
            }
        }
        return;
    }
    for(int next:adj[v]){
        if(remain[v][next]>0){
            remain[v][next]--;
            temp.push_back(name[next]);
            dfs(next,adj,c+1);
            remain[v][next]++;
            temp.pop_back();
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    n=tickets.size();
    int cnt=0;
    //단방향 인접리스트
    vector<vector<int>> adj=vector<vector<int>>(10001,vector<int>());
    remain=vector<vector<int>>(10001,vector<int>(10001,0));
    //인접리스트 만들면서 번호 할당
    for(vector<string> t:tickets){
        if(m.find(t[0])==m.end()){
            m[t[0]]=cnt++;
            name[m[t[0]]]=t[0];
        }
        if(m.find(t[1])==m.end()){
            m[t[1]]=cnt++;
            name[m[t[1]]]=t[1];
        }
        adj[m[t[0]]].push_back(m[t[1]]);
        remain[m[t[0]]][m[t[1]]]++;
    }
    for(int e:adj[m["ICN"]]){
        remain[m["ICN"]][e]--;
        temp.push_back("ICN");
        temp.push_back(name[e]);
        dfs(e,adj,1);
        remain[m["ICN"]][e]++;
        temp.pop_back();
        temp.pop_back();
    }
    return answer;
}