#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int storey) {
    int answer=0;
    while(storey>0){
        int num=storey%10;
        if(num>5){
            answer+=10-num;
            storey+=10-num;
        }else if(num<5){
            answer+=num;
            storey-=num;
        }else{
            int num2=(storey/10)%10;
            if(num2>=5){
                answer+=5;
                storey+=5;
            }else{
                answer+=5;
                storey-=5;
            }
        }
        storey/=10;
    }
    return answer;
}
//455 460
//455 (내림)450 (내림)400 0 ->5+5+4
//455 (내림)450 (올림)500 0
//455 (올림)460 (올림)500 0 ->5+4+5
//445 455 