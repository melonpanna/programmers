#include <string>
#include <vector>
#include <set>

using namespace std;

int answer = 0;
vector<int> unique;
vector<int> common;
vector<vector<int>> answerset;
void backtracking(int index,vector<vector<string>> relation,vector<int> selected){
    selected.push_back(index);
    set<string> s;
    if(selected.size()>1){
        for(int i=0;i<relation.size();i++){
            string temp;
            for(int j=0;j<selected.size();j++){
                temp+=relation[i][common[selected[j]]];
                temp+="_";
            }
            s.insert(temp);
        }
    }
    if(s.size()==relation.size()){
        vector<int> tempset;
        for(int e:selected){
            tempset.push_back(e);
        }
        answerset.push_back(tempset);
        return;
    }
    else{
        int lastindex=selected[selected.size()-1];
        for(int i=lastindex+1;i<common.size();i++){
            backtracking(i,relation,selected);
        }
    }
    return;
}
int solution(vector<vector<string>> relation) {
    for(int i=0;i<relation[0].size();i++){
        set<string> s;
        for(int j=0;j<relation.size();j++){
            s.insert(relation[j][i]);
        }
        if(s.size()==relation.size())unique.push_back(i);
        else common.push_back(i);
    }
    answer+=unique.size();
    for(int i=0;i<common.size();i++){
        vector<int> selected;
        backtracking(i,relation,selected);
    }
    //answerset 정리
    for(int i=0;i<answerset.size();i++){
        for(int j=i+1;j<answerset.size();j++){
            set<int> s1;
            for(int e:answerset[i]){
                s1.insert(e);
            }
            int s1size=s1.size();
            set<int> s2;
            for(int e2:answerset[j]){
                s1.insert(e2);
                s2.insert(e2);
            }
            if(s1size==s1.size()){
                answerset.erase(answerset.begin()+i);
                i--;
                break;
            }
            else if(s1.size()==s2.size()){
                answerset.erase(answerset.begin()+j);
            }
        }
    }
    answer+=answerset.size();
    return answer;
}