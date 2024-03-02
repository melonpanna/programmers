#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    int low=0;
    //최대 인용 횟수
    int high=1000;
    int mid=(low+high)/2;
    while(low<=high){
        //검증
        int index=-1;
        for(int i=citations.size()-1;i>=0;i--){
            if(citations[i]>=mid)index=i;
            else break;
        }
        //조건 충족 x
        if((index==-1)||mid>(citations.size()-index)){
            high=mid-1;
        }
        else{
            if(mid>(citations.size()-index)){
                high=mid-1;
            }
            else{
                answer=max(answer,mid);
                low=mid+1;
            }
        }
        mid=(low+high)/2;
    }
    return answer;
}