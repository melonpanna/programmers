#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string,int> m;
    int i=0;
    for(string s:players){
       m[s]=i++;
    }
    vector<int> order;
    for(int j=0;j<players.size();j++){
        order.push_back(j);
    }
    for(string s:callings){
        int temp=m[s];
        int index;
        for(int j=1;j<players.size();j++){
            if(order[j]==temp){
                index=j;break;
            }
        }
        int t=order[index-1];
        order[index-1]=temp;
        order[index]=t;
    }
    for(int e:order){
        answer.push_back(players[e]);
    }
    return answer;
}