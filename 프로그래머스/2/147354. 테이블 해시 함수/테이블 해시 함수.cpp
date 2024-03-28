#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer;
    sort(data.begin(),data.end(),[&](vector<int> v1,vector<int>v2){
        if(v1[col-1]==v2[col-1])return v1[0]>v2[0];
        return v1[col-1]<v2[col-1];
    });
    vector<long long> s;
    for(int i=row_begin;i<=row_end;i++){
        long long temp=0;
        for(int j=0;j<data[0].size();j++){
            temp+=data[i-1][j]%i;
        }
        s.push_back(temp);
    }
    if(row_begin==row_end)return s[0];
    answer=s[0]^s[1];
    for(int i=2;i<s.size();i++){
        answer^=s[i];
    }
    return answer;
}