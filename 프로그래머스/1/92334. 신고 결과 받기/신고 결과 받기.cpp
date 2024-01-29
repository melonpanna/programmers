#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    vector<string> penalty;
    map<string,int> sum;
    map<string,vector<string>> m;//얘 정지되면 메일보내야하는 애들
    map<string,int> mail;
    for(string r:report){
        //a가 b를 신고
        string a=r.substr(0,r.find(' '));
        string b=r.substr(r.find(' ')+1,r.size());
        if(sum.find(b)!=sum.end()){
            if(m.find(b)!=m.end()
               &&find(m[b].begin(),m[b].end(),a)!=m[b].end())
                continue;
            sum[b]++;
        }
        else{
            sum[b]=1;
        }
        if(sum[b]==k)penalty.push_back(b);
        if(m.find(b)!=m.end()){
            m[b].push_back(a);
        }
        else{
            vector<string> temp={a};
            m[b]=temp;
        }
    }
    for(string p:penalty){
        for(string s:m[p]){
            if(mail.find(s)!=mail.end())mail[s]++;
            else mail[s]=1;
        }
    }
    for(string id:id_list){
        if(mail.find(id)!=mail.end())answer.push_back(mail[id]);
        else answer.push_back(0);
    }
    return answer;
}