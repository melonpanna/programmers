#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable){
    string answer="";
    sort(timetable.begin(),timetable.end());
    int idx=0,cnt=0;
    while(cnt<n){
        int departure=9*60+cnt*t;
        if(departure>23*60+59)break;
        //그 안에 줄 세워놓기-수용 인원 차면 멈추기 or 시간 다 되면 멈추기
        int lasttime=-1;
        bool full=false;
        int cap=0;
        while(idx<timetable.size()){
            int time=stoi(timetable[idx].substr(0,2))*60+stoi(timetable[idx].substr(3,2));
            if(time<=departure){
                lasttime=time;
                cap++;
                if(cap==m){
                    full=true;
                    idx++;
                    break;
                }
            }
            else break;
            idx++;
        }
        //answer을 갱신함
        if(full){
            string hour=to_string((lasttime-1)/60);
            if(hour.size()<2)hour="0"+hour;
            string minute=to_string((lasttime-1)%60);
            if(minute.size()<2)minute="0"+minute;
            answer=hour+":"+minute;
        }
        else{
            if(departure==lasttime){
                string hour=to_string((lasttime-1)/60);
                if(hour.size()<2)hour="0"+hour;
                string minute=to_string((lasttime-1)%60);
                if(minute.size()<2)minute="0"+minute;
                answer=hour+":"+minute;
            }
            else{
                string hour=to_string((departure)/60);
                if(hour.size()<2)hour="0"+hour;
                string minute=to_string((departure)%60);
                if(minute.size()<2)minute="0"+minute;
                answer=hour+":"+minute;
            }
        }
        cnt++;
    }
    return answer;
}