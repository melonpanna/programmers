#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> v=vector<vector<int>>(501,vector<int>());
    vector<bool> used=vector<bool>(100001,false);
    int last=1;
    int cnt=0;
    vector<int> temp;
    for(int i=2;i<s.size()-1;i++){
        if(!(s[i]>='0'&&s[i]<='9')){
            if(s[i]==','&&s[i-1]!='}'){
                temp.push_back(stoi(s.substr(last+1,i-last-1)));
                cnt++;
            }
            if(s[i]=='}'){
                temp.push_back(stoi(s.substr(last+1,i-last-1)));
                cnt++;
                v[cnt]=vector<int>(temp.begin(),temp.end());
                temp.clear();
                cnt=0;
            }
            last=i;
        }
    }
    for(int i=1;i<=500;i++){
        if(v[i].empty())break;
        for(int j=0;j<i;j++){
            if(!used[v[i][j]]){
                answer.push_back(v[i][j]);
                used[v[i][j]]=true;
            }
        }
    }
    return answer;
}