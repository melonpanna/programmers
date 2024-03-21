#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string,int> m;
bool cmp(vector<int> v1,vector<int> v2,int k){
    return v1[k]<v2[k];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    m["code"]=0;
    m["date"]=1;
    m["maximum"]=2;
    m["remain"]=3;
    for(int i=0;i<data.size();i++){
        if(data[i][m[ext]]<val_ext)answer.push_back(data[i]);
    }
    sort(answer.begin(), answer.end(), [&](const auto& a, const auto& b) {
        return cmp(a, b, m[sort_by]);
    });
    return answer;
}