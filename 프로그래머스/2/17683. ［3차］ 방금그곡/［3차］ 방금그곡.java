import java.util.*;
class Solution {
    public String solution(String m, String[] musicinfos) {
        String answer = "(None)";
        int maxlength=-1;
        m=m.replaceAll("A#","a")
            .replaceAll("B#","b")
            .replaceAll("C#","c")
            .replaceAll("D#","d")
            .replaceAll("E#","e")
            .replaceAll("F#","f")
            .replaceAll("G#","g");
        for(int i=0;i<musicinfos.length;i++){
            int length=
                Integer.valueOf(musicinfos[i].substring(6,8))*60
                +Integer.valueOf(musicinfos[i].substring(9,11))
                -Integer.valueOf(musicinfos[i].substring(0,2))*60
                -Integer.valueOf(musicinfos[i].substring(3,5));
            String[] temp=musicinfos[i].split(",");
            String title=temp[2];
            String melody=temp[3];
            melody=melody.replaceAll("A#","a")
                .replaceAll("B#","b")
                .replaceAll("C#","c")
                .replaceAll("D#","d")
                .replaceAll("E#","e")
                .replaceAll("F#","f")
                .replaceAll("G#","g");
            int originlength=melody.length();
            if(length>originlength){
                int repeat=length/originlength;
                String s=(melody.substring(0,originlength%length));
                StringBuilder sb=new StringBuilder();
                for(int j=0;j<repeat;j++){
                    sb.append(melody);
                }
                sb.append(s);
                melody=sb.toString();
            }
            else if(length<originlength){
                melody=melody.substring(0,length);
            }
            if(melody.contains(m)){
                    if(maxlength==-1||(maxlength!=-1&&maxlength<length)){
                        answer=title;
                        maxlength=length;
                    }
                }
            }
        return answer;
    }
}