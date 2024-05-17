import java.util.*;
class Solution {
    public int solution(int n, int k) {
        int answer = 0;
        StringBuilder sb=new StringBuilder();
        while(n>0){
            sb.append(Integer.toString(n%k));
            n/=k;
        }
        String temp=sb.toString();
        StringBuilder sb2=new StringBuilder();
        for(int i=temp.length()-1;i>=0;i--)sb2.append(temp.charAt(i));
        String s=sb2.toString();
        String[] arr=s.split("0");
        // string으로 변환 후 잘라내기
        long maxn=-1;
        ArrayList<Long> list=new ArrayList<>();
        for(String str:arr){
            if(str.length()==0)continue;
            long i=Long.parseLong(str);
            if(maxn<i)maxn=i;
            list.add(i);
        }
        if(maxn<=1)return 0;
        // HashMap<Long,Boolean> m=new HashMap<>();
        Set<Long> set=new HashSet<>();
        // for(long i=2;i<=maxn;i++){
        //     m.put(i,true);
        // }
        // m.put((long)1,false);
        set.add((long)1);
        //소수인지 판별
        // for(long i=2;i<=maxn/2;i++){
        //     for(long j=2;;j++){
        //         if(i*j>maxn)break;
        //         if(!list.contains(i*j))continue;
        //         set.add(i*j);
        //     }
        // }
        for(long e:list){
            if(e==2||e==3)answer++;
            else{
                long t=(long)Math.sqrt(e);
                for(long i=2;i<=t;i++){
                    if(e%i==0)break;
                    if(i==t)answer++;
                }
            } 
        }
        return answer;
    }
}