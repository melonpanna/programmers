#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> nums) {
    int answer=0;
    vector<int> v;
    int maxn=-1;
    for(int i=0;i<nums.size()-2;i++){
        for(int j=i+1;j<nums.size()-1;j++){
            for(int k=j+1;k<nums.size();k++){
                v.push_back(nums[i]+nums[j]+nums[k]);
                maxn=max(maxn,nums[i]+nums[j]+nums[k]);
            }
        }
    }
    vector<bool> isprime=vector<bool>(maxn+1,true);
    isprime[0]=false;
    for(int i=2;i*i<=maxn;i++){
        for(int j=i+1;j<=maxn;j++){
            if((j%i)==0)isprime[j]=false;
        }
    }
    for(int e:v){
        if(isprime[e])answer++;
    }
    return answer;
}