#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(),routes.end(),[](vector<int> r1,vector<int> r2){
        return r1[1]<r2[1];
    });
    int end=routes[0][1];
    answer++;
    for(int i=1;i<routes.size();i++){
        if(routes[i][0]<=end)continue;
        end=routes[i][1];
        answer++;
    }
    return answer;
}