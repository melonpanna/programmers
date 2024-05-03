import java.util.*;
class Solution {
    public static class Node{
        int r;
        int c;
        int dist;
        
        public Node(int r,int c,int dist){
            this.r=r;
            this.c=c;
            this.dist=dist;
        }
    }
    public int solution(int[][] maps) {
        int answer = 0;
        //bfs해서 도달했을 때의 cnt를 반환하면 됨
        boolean[][] visited=new boolean[maps.length][maps[0].length];
        for(int i=0;i<maps.length;i++)Arrays.fill(visited[i],false);
        Queue<Node> q=new LinkedList<>();
        q.offer(new Node(0,0,1));
        visited[0][0]=true;
        int[] dr={-1,0,1,0};
        int[] dc={0,-1,0,1};
        int w=maps[0].length;
        int h=maps.length;
        while(!q.isEmpty()){
            Node v=q.poll();
            for(int d=0;d<4;d++){
                int nextr=v.r+dr[d];
                int nextc=v.c+dc[d];
                if(nextr>=0&&nextr<h&&nextc>=0&&nextc<w&&!visited[nextr][nextc]&&maps[nextr][nextc]!=0){
                    if(nextr==h-1&&nextc==w-1)return v.dist+1;
                    q.offer(new Node(nextr,nextc,v.dist+1));
                    visited[nextr][nextc]=true;
                }
            }
        }
        return -1;
    }
}
