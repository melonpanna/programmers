import java.util.*;
class Solution {
    public int solution(int[] arr) {
        int answer = 0;
        int max=Arrays.stream(arr).max().getAsInt();
        for(int i=2;;i++){
            int temp=max*i;
            for(int j=0;j<arr.length;j++){
                if(temp%arr[j]!=0)break;
                if(j==arr.length-1)return temp;
            }
        }
        // return answer;
    }
}