#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(),times.end());
    long long low=times[0];
    //최대 1e18
    long long high=(long long)n*times[times.size()-1];
    long long mid,temp;
    answer=high;
    while(low<=high){
        temp=0;
        mid=low+(high-low)/2;
        for(int e:times){
            temp+=mid/e;
            if(temp>=n)break;
        }
        if(temp>=n){
            answer=min(answer,mid);
            high=mid-1;
        }
        else low=mid+1;
    }
    return answer;
}
