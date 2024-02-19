#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
bool cmp_head(string s1,string s2){
    string temp1=s1;
    string temp2=s2;
    transform(temp1.begin(),temp1.end(),temp1.begin(),::toupper);
    transform(temp2.begin(),temp2.end(),temp2.begin(),::toupper);
    if(s1<s2)return true;
    else return false;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    string head,number,tail;
    //숫자가 다섯 자 이상 되면, 숫자여도 tail에 속함
    //자체 compare 하는 거 만들어야겠다 upper해서 비교하는 것
    vector<string> order;
    map<string,vector<int>> indices;//(head+number)-index //중복 가능하므로
    map<string,vector<int>> heads;//head별 numbers
    for(int i=0;i<files.size();i++){
        string s=files[i];
        int numberindex;
        for(int j=0;j<s.size();j++){
            if(s[j]>='0'&&s[j]<='9'){
                numberindex=j;
                break;
            }
        }
        string head=s.substr(0,numberindex);
        transform(head.begin(),head.end(),head.begin(),::toupper);
        //number 추출
        int tailindex=s.size();
        for(int j=numberindex+1;j<s.size();j++){
            if(!(s[j]>='0'&&s[j]<='9')){
                tailindex=j;
                break;
            }
            else if(j-numberindex>=5){
                tailindex=j;
                break;
            }
        }
        string number=s.substr(numberindex,tailindex-numberindex);
        int n=stoi(number);
        number=to_string(n);
        if(heads.find(head)!=heads.end()){//이미 존재
            if(find(heads[head].begin(),heads[head].end(),n)==heads[head].end())heads[head].push_back(n);
        }
        else{
            order.push_back(head);
            vector<int> temp=vector<int>();
            temp.push_back(n);
            heads[head]=temp;
        }
        if(indices.find(head+number)!=indices.end()){
            indices[head+number].push_back(i);
        }
        else{
            vector<int> temp2=vector<int>();
            temp2.push_back(i);
            indices[head+number]=temp2;
        }
    }
    //파일명끼리 정렬한 후
    sort(order.begin(),order.end(),cmp_head);
    //그 파일명에 속한 애들끼리 정렬 하는 식으로?
    for(auto it=heads.begin();it!=heads.end();it++){
        sort((it->second).begin(),(it->second).end());
    }
    for(string head:order){
        // cout<<head<<" ";
        for(int number:heads[head]){
            // cout<<number<<' ';
            for(int e:indices[head+to_string(number)]){
                answer.push_back(files[e]);
            }
        }
        cout<<'\n';
    }
    return answer;
}