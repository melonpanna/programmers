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
        int index=find(order.begin(),order.end(),temp)-order.begin();
        swap(order[index-1],order[index]);
    }
    for(int e:order){
        answer.push_back(players[e]);
    }
    return answer;
}