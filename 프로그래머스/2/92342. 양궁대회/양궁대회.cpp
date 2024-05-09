#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool selected[11];
vector<int> answer;
vector<int> realanswer;
bool found=false;
int maxv=-1;
int lastindex=-1;
void dfs(int index,int n,vector<int>& info){
    int rest=n-(info[10-index]+1);//쳐냈음
    if(rest<0)return;
    answer[10-index]=info[10-index]+1;
    int temp=0;
    if(rest>0&&index==10){
        temp=rest;
        answer[10]+=rest;
        rest=0;
    }
    if(rest==0){
        int apeach=0;
        int me=0;
        for(int i=0;i<=10;i++){
            if(info[i]<answer[i])me+=10-i;
            else if(info[i]==0&&answer[i]==0)continue;
            else apeach+=10-i;
        }
        if(apeach<me){
            if(maxv<me-apeach){
                found=true;
                maxv=me-apeach;
                realanswer=vector<int>(answer.begin(),answer.end());
            }
            if(maxv==me-apeach){
                for(int i=10;i>=0;i--){
                    if(answer[i]<realanswer[i]){
                        break;
                    }
                    if(i==0){
                        realanswer=vector<int>(answer.begin(),answer.end());
                    }
                }
            }
        }
        answer[10-index]=0;
        answer[10]-=temp;
        return;
    }
    for(int i=index+1;i<=10;i++){
        dfs(i,rest,info);
    }
    answer[10-index]=0;
    return;
}
vector<int> solution(int n, vector<int> info) {
    answer=vector<int>(11,0);
    for(int i=0;i<=10;i++){
        dfs(i,n,info);
    }
    if(!found)return vector<int>(1,-1);
    return realanswer;
}