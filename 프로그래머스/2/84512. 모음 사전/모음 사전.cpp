#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//완탐-이분탐색 x
char arr[5]={'A','E','I','O','U'};
string temp;
vector<string> dictionary;
bool found=false;
int answer = 0;
//6*6*6*6*6-1 가지 경우 10^5
//sort해도 10^5번 연산
void dfs(int index,int cnt,int length,string word){
    // if(found)return;
    temp+=arr[index];
    if(cnt==length){
        dictionary.push_back(temp);
        // if(temp==word){
        //     found=true;
        //     return;
        // }
    }
    else{
        for(int i=0;i<5;i++){
            dfs(i,cnt+1,length,word);
        }
    }
    temp=temp.substr(0,cnt-1);
    return;
}
int solution(string word) {
    for(int length=1;length<=5;length++){
        for(int i=0;i<5;i++){
            dfs(i,1,length,word);
        }
    }
    sort(dictionary.begin(),dictionary.end());
    return find(dictionary.begin(),dictionary.end(),word)-dictionary.begin()+1;
}