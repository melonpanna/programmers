import java.util.*;
class Solution {
    public int solution(int n) {
        int answer = 0;
        //4 - 0 1 0 0 -> 1 0 0 0
        //9 - 1 1 0 0
        //완탐으로 맨날 2로 나누고 ㅇㅈㄹ 할수도
        //0 1 1 0 0 -> 1 0 1 0 0
        //1 0 1 0 -> 1 1 0 0
        //1 1 0 1 아니야 마지막으로 나온 1을 옮기는 거야
        // 1 1 0 -> 1 0 1 0
        //1 0 0 1 1 1 0
        //1 0 1 0 1 1 0 이 아니네ㅠㅠ 
        //1 0 1 0 0 1 1
        int index=0;
        boolean series=false;
        for(int i=0;;i++){
            if(((1<<i)&n)>0){
                series=true;
            }
            if(series&&((1<<i)&n)==0){
                index=i-1;
                break;
            }
        }
        for(int i=index+1;;i++){
            if(((1<<i)&n)==0){
                n+=(1<<i);
                n-=(1<<index);
                break;
            }
        }
        int j=0;
        for(int i=index-1;i>=0;i--){
            if(i<=j)break;
            if(((1<<i)&n)==0)continue;
            if(((1<<j)&n)==0){
                n-=(1<<i);
                n+=(1<<j);
            }
            j++;
        }
        return n;
    }
}