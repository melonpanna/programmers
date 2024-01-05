#include <string>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define MAX_N 51

using namespace std;
int table[MAX_N][MAX_N];
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    vector<int> present=vector<int>(friends.size(),0);
    //선물 지수
    map<string,int> level;
    map<string,int> order;
    for(int i=0;i<friends.size();i++){
        level.insert({friends[i],0});
        order.insert({friends[i],i});
    }
    for(string e:gifts){
        int blank=e.find(' ');
        //준 친구
        string a=e.substr(0,blank);
        //받은 친구
        string b=e.substr(blank+1,e.size()-1);
        level[a]++;level[b]--;
        int anum=order[a];
        int bnum=order[b];
        table[anum][bnum]++;
    }
    //선물 예측
    for(int i=0;i<friends.size()-1;i++){
        for(int j=i+1;j<friends.size();j++){
            int anum=order[friends[i]];
            int bnum=order[friends[j]];
            string a=friends[i];
            string b=friends[j];
            if(table[anum][bnum]==table[bnum][anum]){
                //주고받은 기록 없을 때도 포함
                if(level[a]>level[b])present[anum]++;
                else if(level[a]<level[b])present[bnum]++;
            }
            else if(table[anum][bnum]>table[bnum][anum]){
                present[anum]++;
            }
            else present[bnum]++;
        }
    }
    sort(present.rbegin(),present.rend());
    answer=present[0];
    return answer;
}