import java.util.*;
class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        int w=0;
        Queue<Integer> q=new LinkedList<>();
        for(int i=0;i<truck_weights.length;i++){
            answer++;
            if(!q.isEmpty()&&q.size()==bridge_length){
                w-=q.poll();
            }
            if(w+truck_weights[i]<=weight){
                q.offer(truck_weights[i]);
                w+=truck_weights[i];
            }
            else{
                q.offer(0);
                i--;
            }
        }
        //마지막 원소 통과할 시간 더함
        answer+=bridge_length;
        return answer;
    }
}