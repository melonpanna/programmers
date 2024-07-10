#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string,string> nickname; //uid-nickname
    vector<pair<string,bool>> msg; //uid-행동
    //record 처리
    for(int i=0;i<record.size();i++){
        // int uid=stoi(record[i].substr(find(record[i],'u')+2,4));
        // string command=record[i].substr(0,5);
        istringstream ss(record[i]);
        string stringBuffer;
        vector<string> v;
        while(getline(ss,stringBuffer,' ')){
            v.push_back(stringBuffer);
        }
        if(v[0]=="Enter"){
            msg.push_back({v[1],false});
            nickname[v[1]]=v[2];
        }
        else if(v[0]=="Leave"){
            msg.push_back({v[1],true});
            // nickname[v[1]]=v[2];
        }
        else nickname[v[1]]=v[2];
    }
    //answer 처리
    for(int i=0;i<msg.size();i++){
        string temp=nickname[msg[i].first]+"님이 ";
        if(msg[i].second)temp+="나갔습니다.";
        else temp+="들어왔습니다.";
        answer.push_back(temp);
    }
    return answer;
}