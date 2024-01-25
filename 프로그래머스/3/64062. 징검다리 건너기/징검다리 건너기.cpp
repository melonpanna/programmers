#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    //조건 충족하는 수 중 가장 큰 수
    int answer = 0;
    int high=*max_element(stones.begin(),stones.end());
    int low=1;
    int mid;
    while(low<=high){
        int retire=0;
        int mid=low+(high-low)/2;
        for(int e:stones){
            if(e-mid<0)retire++;
            else retire=0;
            if(retire>=k){
                break;
            }
        }
        if(retire>=k)high=mid-1;
        else{
            answer=max(mid,answer);
            low=mid+1;
        }
    }
    return answer;
}