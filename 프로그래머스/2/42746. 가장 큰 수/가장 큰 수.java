import java.util.*;
class Solution {
    public String solution(int[] numbers) {
        List<Integer> list=new ArrayList<>();
        for(int e:numbers)list.add(e);
        Collections.sort(list,(n1,n2)->{
            String s1=Integer.toString(n1);
            String s2=Integer.toString(n2);
            // if((s2+s1).compareTo(s1+s2)==0){
            //     if(s1.length()>s2.length())return -1;
            //     else return 1;
            // }
            return (s2+s1).compareTo(s1+s2);
        });
        if(list.get(0)==0)return "0";
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<list.size();i++){
            sb.append(Integer.toString(list.get(i)));
        }
        return sb.toString();
    }
}