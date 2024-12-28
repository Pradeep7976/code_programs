package leetcode;

import java.net.ServerSocket;
import java.util.*;

public class Graph {
    class Pair {
        public int i;
        public int j;
        public int dist;

        public Pair(int i, int j, int dist) {
            this.i = i;
            this.j = j;
            this.dist = dist;
        }
    }

    private void bfs(int[][] mat, int[][] ans) {
        Queue<Pair> q = new LinkedList();
        q.offer(new Pair(0, 0, 0));
        int n = mat.length;
        int m = mat[0].length;
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[0].length; j++) {
                if (mat[i][j] == 0) {
                    q.add(new Pair(i, j, 0));
                }
            }
        }
        while (!q.isEmpty()) {
            int ni = q.peek().i;
            int nj = q.peek().j;
            int ndist = q.peek().dist;
            ans[ni][nj] = ndist;
            q.remove();
            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int nrow = ni + delrow[i];
                int ncol = nj + delcol[i];
                int dist = ndist + 1;
                if (nrow >= 0 && nrow < n && ncol >= 0 && nrow < m && mat[nrow][ncol] == 1) {
                    q.add(new Pair(nrow, ncol, dist));
                }
            }
        }

    }

    //    public int[][] updateMatrix(int[][] mat) {
//        int[][] ans = new int[mat.length][mat[0].length];
//        int[][] vis = new int[mat.length][mat[0].length];
//        bfs(mat, ans, vis);
//        return ans;
//    }
    public String[] uncommonFromSentences(String s1, String s2) {
        Map<String, Integer> mp = new HashMap<>();
        String[] s1arr = s1.split(" ");
        String[] s2arr = s2.split(" ");
        int len = Math.max(s1.length(), s2.length());
        String[] sarr = new String[len];
        int i = 0;
        for (String s : s1arr) {
            if (mp.containsKey(s)) {
                mp.put(s, mp.get(s) + 1);
            } else {
                mp.put(s, 0);
            }
        }
        for (String s : s2arr) {
            if (mp.containsKey(s)) {
                mp.put(s, mp.get(s) + 1);
            } else {
                mp.put(s, 0);
            }
        }
        for (Map.Entry<String, Integer> entry : mp.entrySet()) {
            if (entry.getValue() == 1)
                sarr[i++] = entry.getKey();
        }
        return sarr;
    }


    public static void main(String[] args) {
        Graph graph = new Graph();
//        graph.uncommonFromSentences();
    }
}
