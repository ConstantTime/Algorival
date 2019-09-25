package tasks.codes;

import JCodes.graphs.BaseObjects.ShortestPath;
import JCodes.graphs.BaseObjects.Graph;
import JCodes.graphs.BaseObjects.Node;
import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

import java.util.*;

public class LeetCode {
    public void solve(int testNumber, InputReader in, OutputWriter out) {

    }

    int [][][] memo;
    int n;
    public int cherryPickup(int[][] grid) {
        n = grid.length;
        memo = new int[n][n][n];

        for(int [][] layer : memo) {
            for(int []row : layer) {
                Arrays.fill(row , Integer.MIN_VALUE);
            }
        }

        return Math.max(0 , dp(grid , 0 , 0 , 0));
    }

    private int dp(int [][] grid, int r1, int c1, int c2) {
        int r2 = r1 + c1 - c2;
        if(n == r1 || n == r2 || n == c1 || n == c2) {
            return -9999999;
        }
        else if(grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return -9999999;
        }
        else if(r1 == n - 1 || c1 == n - 1) {
            return grid[r1][c1];
        }
        else if(memo[r1][c1][c2] != Integer.MIN_VALUE) {
            return memo[r1][c1][c2];
        }
        else {
            int ans = grid[r1][c1];
            if(c1 != c2) {
                ans += grid[r2][c2];
            }

            ans += Math.max(Math.max(dp(grid , r1 , c1 + 1 , c2 + 1),
                    dp(grid , r1 + 1 , c1 , c2 + 1))
            , Math.max(dp(grid , r1 , c1 + 1 , c2) , dp(grid , r1 + 1 ,
                            c1 ,  c2)));
            memo[r1][c1][c2] = ans;
            return ans;
        }
    }

    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {

        Graph graph = new Graph();

        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            List<Node> item = new ArrayList<>();
            graph.list.add(item);
        }

        for(int [] flight : flights) {
            graph.list.get(flight[0]).add(new Node(flight[1] , flight[2]));
        }

        int [] dist = ShortestPath.dijkstra(n , graph.list, src);

        ans = dist[dst];
        return ans;
    }

    static class IntPair {
        public int first;
        public int second;

        IntPair() {

        }

        IntPair(int first , int second) {
            this.first = first;
            this.second = second;
        }
    }
}
