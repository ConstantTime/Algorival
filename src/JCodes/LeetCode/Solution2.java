package JCodes.LeetCode;

import JCodes.graphs.BaseObjects.Graph;
import JCodes.graphs.BaseObjects.Node;

import java.util.*;

class CustomComp implements Comparator< int[] > {

    public int compare(int[] a , int [] b) {
        return a[0] - b[0];
    }
}
public class Solution2 {

    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {

        Graph graph = new Graph();

        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            List <Node> item = new ArrayList<>();
            graph.list.add(item);
        }

        for(int [] flight : flights) {
            graph.list.get(flight[0]).add(new Node(flight[1] , flight[2]));
        }

        PriorityQueue < int[] > pq = new PriorityQueue<>(new CustomComp());
        pq.add(new int[]{0 , src , K + 1});
        while(!pq.isEmpty()) {
            int [] cur = pq.poll();
            if(cur[1] == dst) return cur[0];
            if(cur[2] > 0) {

                for(Node node : graph.list.get(cur[1])) {
                    pq.add(new int[] {
                        cur[0] + node.cost , node.node , cur[2] - 1
                    });
                }
            }
        }

        return -1;
    }

    public static String reorganizeString(String S) {
        int[] count = new int[26];
        for(int i = 0; i < S.length(); i++) {
            count[S.charAt(i) - 'a']++;
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            return b[1] - a[1];
        });
        for (int i = 0; i < count.length; i++) {
            if (count[i] > 0) {
                pq.offer(new int[]{i, count[i]});
            }
        }
        StringBuilder sb = new StringBuilder();
        while (!pq.isEmpty()) {
            int[] first = pq.poll();
            if (first[1] > 1 && pq.isEmpty()) return "";
            if (first[1] == 1 && pq.isEmpty()) {
                sb.append((char)('a'+first[0]));
                break;
            }
            int[] second = pq.poll();

            int pairs = Math.min(first[1], second[1]);
            while(pairs > 0) {
                sb.append((char)('a'+first[0]));
                sb.append((char)('a'+second[0]));
                pairs--;
            }
            if (first[1] > second[1]) pq.offer(new int[]{first[0], first[1]-second[1]});
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        Solution2 s = new Solution2();
        System.out.println(reorganizeString("aab"));
    }
}

class pairP implements Comparable <pairP> {
    public char fi;
    public int se;

    public pairP(int b , char a) {
        fi = a;
        se = b;
    }

    @Override
    public int compareTo(pairP o) {
        return se - o.se;
    }
}
