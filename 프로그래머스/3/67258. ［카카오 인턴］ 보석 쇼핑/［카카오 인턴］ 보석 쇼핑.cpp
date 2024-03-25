#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer={1,(int)gems.size()};
    int minl=gems.size();
    set<string> kind;
    for(int i=0;i<gems.size();i++)kind.insert(gems[i]);
    int left=0,right=0;
    map<string,int> m;
    m[gems[0]]=1;
    while(left<=right){
        if(m.size()<kind.size()){
            if(right<gems.size()-1){
                if(m.find(gems[right+1])!=m.end())m[gems[++right]]++;
                else m[gems[++right]]=1;
            }
            else break;
        }
        else{
            if(minl>right-left){
                minl=right-left;
                answer={left+1,right+1};
            }
            //left만 이동
            if(left<gems.size()-1){
                m[gems[left]]--;
                if(m[gems[left]]==0)m.erase(gems[left]);
                left++;
            }
        }
    }
    return answer;
}