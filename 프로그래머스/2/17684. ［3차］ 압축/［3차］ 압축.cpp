#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int> dict;
    int maxlength=1;
    //사전 초기화
    for(int i=0;i<='Z'-'A';i++){
        char c='A'+i;
        string str="";
        str+=c;
        dict[str]=i+1;
    }
    for(int i=0;i<msg.size();){
        string temp;
        for(int j=maxlength;j>0;j--){
            temp=msg.substr(i,j);
            if(dict.find(temp)!=dict.end()){
                answer.push_back(dict[temp]);
                break;
            }
        }
        dict[msg.substr(i,temp.size()+1)]=dict.size()+1;
        maxlength=max(maxlength,(int)temp.size()+1);
        //i 이동
        i+=temp.size();
    }
    return answer;
}