#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int cnt=0;//지금 보고 있는 상자의 번호
    int idx=0;//order[idx]를 넣어야 함
    stack<int> temp;
    while(idx<order.size()&&cnt<order.size()){
        if(cnt==order[idx]-1){
            answer++;idx++;
            while(idx<order.size()&&!temp.empty()){
                if(temp.top()==order[idx]-1){
                    answer++;
                    idx++;
                    temp.pop();
                }
                else break;
            }
        }
        else{
            temp.push(cnt);
        }
        cnt++;
    }
    return answer;
}