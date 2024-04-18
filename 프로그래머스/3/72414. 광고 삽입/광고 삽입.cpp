#include <string>
#include <vector>

using namespace std;

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int maxstart=0;
    long long maxsum=0;
    int ptime=stoi(play_time.substr(0,2))*3600+stoi(play_time.substr(3,2))*60+stoi(play_time.substr(6));
    vector<int> cnt=vector<int>(ptime+1,0);
    for(string l:logs){
        int start=stoi(l.substr(0,2))*3600+stoi(l.substr(3,2))*60+stoi(l.substr(6));
        int end=stoi(l.substr(9,2))*3600+stoi(l.substr(12,2))*60+stoi(l.substr(15));
        for(int i=start;i<end;i++)cnt[i]++;
    }
    //슬라이딩 윈도우
    int atime=stoi(adv_time.substr(0,2))*3600+stoi(adv_time.substr(3,2))*60+stoi(adv_time.substr(6));
    long long sum=0;
    for(int i=1;i<=atime;i++)sum+=cnt[i];
    maxsum=sum;
    for(int i=2;i<=ptime-atime;i++){
        sum-=cnt[i-1];
        sum+=cnt[i+atime-1];
        if(maxsum<sum){
            maxsum=sum;
            maxstart=i;
        }
    }
    int hour=maxstart/3600;
    if(hour<10)answer+=('0'+to_string(hour));
    else answer+=to_string(hour);
    maxstart%=3600;
    answer+=':';
    int minute=maxstart/60;
    if(minute<10)answer+=('0'+to_string(minute));
    else answer+=to_string(minute);
    answer+=':';
    int second=maxstart%60;
    if(second<10)answer+=('0'+to_string(second));
    else answer+=to_string(second);
    return answer;
}