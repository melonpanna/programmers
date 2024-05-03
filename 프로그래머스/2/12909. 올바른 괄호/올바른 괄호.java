import java.util.*;
class Solution {
    boolean solution(String s) {
        Stack<Character> st=new Stack<>();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='('){
                st.push('(');
            }
            else{
                if(st.isEmpty()||st.peek()==')')return false;
                else{
                    st.pop();
                }
            }
        }
        if(st.isEmpty())return true;
        else return false;
    }
}