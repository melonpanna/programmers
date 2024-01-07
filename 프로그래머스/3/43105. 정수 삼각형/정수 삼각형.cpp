#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> sum;
    for(int i=0;i<triangle.size();i++){
        vector<int> temp=vector<int>(i+1,0);
        sum.push_back(temp);
    }
    sum[0][0]=triangle[0][0];
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<i+1;j++){
            if(j==0)sum[i][j]=triangle[i][j]+sum[i-1][j];
            else if(j==i)sum[i][j]=triangle[i][j]+sum[i-1][j-1];
            else sum[i][j]=triangle[i][j]+max(sum[i-1][j-1],sum[i-1][j]);
        }
    }
    answer=*max_element(sum[triangle.size()-1].begin(),sum[triangle.size()-1].end());
    return answer;
}