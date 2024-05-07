#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(),phone_book.end(),[](string s1,string s2){
        // if(s1.size()==s2.size())return s1<s2;
        // return s1.size()<s2.size();
        return s1<s2;
    });
    for(int i=0;i<phone_book.size()-1;i++){
        for(int j=i+1;j<phone_book.size();j++){
            // if(phone_book[i][0]!=phone_book[j][0])continue;
            // if(phone_book[j].find(phone_book[i])==0)return false;
            string temp=phone_book[j].substr(0,phone_book[i].size());
            if(temp==phone_book[i])return false;
            else if(temp>phone_book[i])break;
        }
    }
    return answer;
}