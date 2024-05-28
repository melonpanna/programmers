#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i=0;i<skill_trees.size();i++){//20
        int last=0;
        bool success=true;
        for(int j=0;j<skill_trees[i].size();j++){//26
            int t=skill.find(skill_trees[i][j]);
            if(t>=0){
                if(last!=t){
                    success=false;
                    break;
                }
                last++;
            }
        }
        if(success)answer++;
    }
    return answer;
}