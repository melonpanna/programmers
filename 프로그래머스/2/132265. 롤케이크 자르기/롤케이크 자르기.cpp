#include <string>
#include <vector>
#include <cstring>
#define MAX_N 10005
//슬라이딩 윈도우?
//0->1 될 때랑 n->0 될 때만 가짓수 변동
using namespace std;
int solution(vector<int> topping) {
    int answer = 0;
    int cnt1[MAX_N];
    int cnt2[MAX_N];
    int n1=0;
    int n2=0;
    memset(cnt1,0,sizeof(cnt1));
    memset(cnt2,0,sizeof(cnt2));
    //초기화
    cnt1[topping[0]]++;n1++;
    for(int i=1;i<topping.size();i++){
        if(cnt2[topping[i]]==0){
            n2++;
        }
        cnt2[topping[i]]++;
    }
    if(n1==n2)answer++;
    for(int i=1;i<topping.size()-1;i++){
        //1번이 i번째까지 획득
        if(cnt1[topping[i]]==0){
            n1++;
        }
        cnt1[topping[i]]++;
        cnt2[topping[i]]--;
        if(cnt2[topping[i]]==0){
            n2--;
        }
        if(n1==n2)answer++;
    }
    return answer;
}