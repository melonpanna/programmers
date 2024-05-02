import java.util.*;
class Solution {
    boolean[] visited;
    int answer=0;
    String[] d;
    String[] f={"A","C","F","J","M","N","R","T"};
    public int solution(int n, String[] data) {
        visited=new boolean[8];
        d=data;
        for(int i=0;i<8;i++){
            dfs(i,"");
        }
        return answer;
    }
    void dfs(int idx,String name){
        visited[idx]=true;
        //idx번째 붙임
        name+=f[idx];
        //name 길이 8이면 검증 들어감
        if(name.length()==8){
            // if(name.charAt(0)=='A')System.out.print(name+" ");
            if(check(name))answer++;
        }
        else{
            for(int i=0;i<8;i++){
                if(!visited[i]){
                    dfs(i,name);
                }
            }
        }
        visited[idx]=false;
        return;
    }
    boolean check(String name){
        for(String s:d){
            char a=s.charAt(0);
            char b=s.charAt(2);
            int i1=name.indexOf(a);
            int i2=name.indexOf(b);
            int d=Math.abs(i1-i2)-1;
            int dist=s.charAt(4)-'0';
            // if(name.charAt(0)=='A'){
            //     System.out.println(i1+" "+i2+" "+d+" "+dist);
            // }
            switch(s.charAt(3)){
                case '=':if(d!=dist)return false;break;
                case '<':if(d>=dist)return false;break;
                case '>':if(d<=dist)return false;
            }
        }
        return true;
    }
}