#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    //뒤에 있는 기능은 앞 기능 배포될 때 함께 배포됨
    //맨 앞에 있는 애 배포될 때 다 털어버리기
    queue<int> q;
    for(int e:progresses)q.push(e);
    int day=1;
    int index=0;
    while(!q.empty()){
        int cnt=0;
        while(!q.empty()&&speeds[index]*day+q.front()>=100){
            q.pop();
            cnt++;
            index++;
        }
        if(cnt>0)answer.push_back(cnt);
        day++;
    }
    return answer;
}