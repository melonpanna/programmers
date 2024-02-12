#include <string>
#include <vector>

using namespace std;
int cnt=0;
void cal(int sum,int index,vector<int> numbers,int target){
    if(index==numbers.size()){
        if(sum==target)cnt++;
        return;
    }
    //양수
    cal(sum+numbers[index],index+1,numbers,target);
    //음수
    cal(sum-numbers[index],index+1,numbers,target);
    return;
}
int solution(vector<int> numbers, int target) {
    //+한 경우, -한 경우로 분기하기
    cal(0,0,numbers,target);
    return cnt;
}