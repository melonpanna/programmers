#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
bool cmp(vector<string> v1,vector<string> v2){
    return v1[1]<v2[1];
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    sort(plans.begin(),plans.end(),cmp);
    stack<pair<string,int>> s;
    //시간 처리
    int hour=stoi(plans[0][1].substr(0,2));
    int minute=stoi(plans[0][1].substr(3,2));
    for(int i=0;i<plans.size()-1;i++){
        //과제 끝냈을 때 시각
        int minute1=minute+stoi(plans[i][2]);
        int hour1=hour+minute1/60;
        minute1%=60;
        //다음 과제 시작할 시간 
        hour=stoi(plans[i+1][1].substr(0,2));
        minute=stoi(plans[i+1][1].substr(3,2));
        if(hour<hour1||(hour==hour1&&minute1>minute)){
            //다 못 끝냄
            if(minute1<minute){
                minute1+=60;
                hour1-=1;
            }
            int rest=(hour1-hour)*60+minute1-minute;
            s.push({plans[i][0],rest});
        }
        else{
            //다 끝냄
            answer.push_back(plans[i][0]);
            //스택에 있는 애들 처리
            while(!s.empty()){
                int minute2=minute1+s.top().second;
                int hour2=hour1+minute2/60;
                minute2%=60;
                if(hour<hour2||(hour==hour2&&minute2>minute)){
                    if(minute2<minute){
                        minute2+=60;
                        hour2-=1;
                    }
                    //할 수 있는 양만큼만 함
                    int rest=(hour2-hour)*60+minute2-minute;
                    string t=s.top().first;
                    s.pop();
                    s.push({t,rest});
                    break;
                }
                else{
                    hour1=hour2;
                    minute1=minute2;
                    answer.push_back(s.top().first);
                    s.pop();
                }
            }
        }
    }
    //마지막으로 남은 과제 하고
    answer.push_back(plans[plans.size()-1][0]);
    //stack 털기
    while(!s.empty()){
        answer.push_back(s.top().first);
        s.pop();
    }
    return answer;
}