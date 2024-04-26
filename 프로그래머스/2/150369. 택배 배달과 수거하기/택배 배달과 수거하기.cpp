#include <string>
#include <vector>
#include <algorithm>

using namespace std;


long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int last=-1;
    for(int i=n;i>0;i--){
        if(deliveries[i-1]>0||pickups[i-1]>0){
            last=i;
            break;
        }
    }
    if(last==-1)return 0;
    int temp=0;
    int cap1=cap;
    int cap2=cap;
    bool flag1=false,flag2=false;
    for(int i=last;i>0;i--){
        if(deliveries[i-1]<=cap1){
            cap1-=deliveries[i-1];
            deliveries[i-1]=0;
        }
        else{
            deliveries[i-1]-=cap1;
            answer+=last*2;
            last=i;
            i=last+1;
            cap1=cap;
            cap2+=cap;
            continue;
        }
        if(pickups[i-1]<=cap2){
            cap2-=pickups[i-1];
            pickups[i-1]=0;
        }
        else{
            pickups[i-1]-=cap2;
            answer+=last*2;
            last=i;
            i=last+1;
            cap1+=cap;
            cap2=cap;
        }
    }
    answer+=last*2;
    return answer;
}