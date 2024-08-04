import java.io.*;
import java.util.*;

public class Main {
	static int n;
	public static void main(String[] args) throws IOException {
		HashMap<Character,Integer> hm=new HashMap<>();
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb=new StringBuilder();
		StringTokenizer st=new StringTokenizer(br.readLine());
		n=Integer.parseInt(st.nextToken());
		String[] arr=new String[n];
		int[] pos=new int[n];
		for(int i=0;i<n;i++)pos[i]=-1;
		String temp;
		for(int i=0;i<n;i++) {
			temp=br.readLine();
			arr[i]=temp;
			boolean check=false;
			for(int j=0;j<temp.length();j++) {
				if(temp.charAt(j)==' ')continue;
				if(j==0||(j>0&&temp.charAt(j-1)==' ')) {
					if(hm.containsKey(temp.charAt(j)))continue;
					pos[i]=j;
					hm.put(Character.toUpperCase(temp.charAt(j)),i);
					hm.put(Character.toLowerCase(temp.charAt(j)),i);
					check=true;break;
				}
			}
			if(check)continue;
			for(int j=0;j<temp.length();j++) {
				if(temp.charAt(j)==' ')continue;
				if(hm.containsKey(temp.charAt(j)))continue;
				pos[i]=j;
				hm.put(Character.toUpperCase(temp.charAt(j)),i);
				hm.put(Character.toLowerCase(temp.charAt(j)),i);break;
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<arr[i].length();j++) {
				if(pos[i]==j) {
					sb.append('[');
					sb.append(arr[i].charAt(j));
					sb.append(']');
				}
				else sb.append(arr[i].charAt(j));
			}
			sb.append('\n');
		}
		System.out.println(sb);
	}
}
