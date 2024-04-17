#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> answer;
int dfs(int r,int c,int n,vector<vector<int>>& arr){
    if(n==1){
        return arr[r][c];
    }
    int num[4];
    num[0]=dfs(r,c,n/2,arr);
    num[1]=dfs(r+n/2,c,n/2,arr);
    num[2]=dfs(r,c+n/2,n/2,arr);
    num[3]=dfs(r+n/2,c+n/2,n/2,arr);
    if(num[0]==num[1]&&num[0]==num[2]&&num[0]==num[3]){
        return num[0];
    }
    else{
        for(int i=0;i<4;i++){
            if(num[i]!=-1)answer[num[i]]++;
        }
        return -1;
    }
}
vector<int> solution(vector<vector<int>> arr) {
    answer=vector<int>(2,0);
    int temp=dfs(0,0,arr[0].size(),arr);
    if(temp!=-1)answer[temp]++;
    return answer;
}