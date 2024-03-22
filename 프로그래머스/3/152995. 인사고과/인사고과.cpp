#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> s1,vector<int> s2){
    if(s1[0]==s2[0])return s1[1]<s2[1];
    else return s1[0]>s2[0];
}

int solution(vector<vector<int>> scores) {
    vector<int> sums;
    int s1=scores[0][0],s2=scores[0][1];
    sort(scores.begin(),scores.end(),cmp);
    int maxs=scores[0][1];
    sums.push_back(scores[0][0]+scores[0][1]);
    for(int i=1;i<scores.size();i++){
        if(scores[i][1]<maxs){
            if(scores[i][0]==s1&&scores[i][1]==s2)return -1;
            continue;
        }
        maxs=scores[i][1];
        sums.push_back(scores[i][0]+scores[i][1]);
    }
    sort(sums.rbegin(),sums.rend());
    int answer=find(sums.begin(),sums.end(),s1+s2)-sums.begin()+1;
    return answer;
}