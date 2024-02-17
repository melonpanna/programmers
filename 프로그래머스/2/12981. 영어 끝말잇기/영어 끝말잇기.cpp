#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string,int> m;
    string lastWord;
    for(int i=0;i<words.size();i++){
        if(i==0&&words[i].size()>=1){
            lastWord=words[i];
            m[words[i]]=1;
        }
        else if(m.find(words[i])==m.end()&&words[i].size()>=1&&words[i][0]==lastWord[lastWord.size()-1]){
            lastWord=words[i];
            m[words[i]]=1;
        }
        //탈락
        else{
            answer.push_back(i%n+1);
            answer.push_back(i/n+1);
            return answer;
        }
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}