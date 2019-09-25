package JCodes.graphs.BaseObjects;

import java.util.*;

public class ShortestPath {

    public static PriorityQueue<Node> pq = new PriorityQueue<>();
    public static Set< Integer > settled = new HashSet<>();
    public static int [] dist;
    public static int [] dijkstra(int n, List<List<Node>> a, int src) {

        dist = new int[n];
        Arrays.fill(dist , Integer.MAX_VALUE);

        dist[src] = 0;
        pq.add(new Node(src , 0));

        while(settled.size() != n) {
            int u = pq.remove().node;
            settled.add(u);
            neighbours(a , u);
        }

        return dist;
    }

    public static void neighbours(List < List < Node > > a, int u) {
        int edgeDistance = -1;
        int newDistance = -1;

        for(int i = 0 ; i < a.get(u).size() ; i++) {
            Node v = a.get(u).get(i);
            if(!settled.contains(v.node)) {
                edgeDistance = v.cost;
                newDistance = v.cost + edgeDistance;

                if(newDistance < dist[v.node]) {
                    dist[v.node] = newDistance;
                }

                pq.add(new Node(v.node , dist[v.node]));
            }
        }
    }

    public static long [] bellman_ford(BellmanGraph a, int vertices , int edges) {

        long [] dist = new long[vertices + 1];

        Arrays.fill(dist , Integer.MAX_VALUE);

        dist[1] = 0;

        for(int i = 1 ; i <= vertices - 1 ; i++) {
            for(int j = 0 ; j < edges ; j++) {
                int source = a.edgeList.get(i).source;
                int destination = a.edgeList.get(i).destination;
                int weight = a.edgeList.get(i).weight;

                if(dist[source] != Integer.MAX_VALUE) {
                    dist[destination] = Math.min(dist[destination] ,
                            dist[source] + weight);
                }

            }
        }

        for(int i = 0 ; i < edges ; i++) {
            int source = a.edgeList.get(i).source;
            int destination = a.edgeList.get(i).destination;
            int weight = a.edgeList.get(i).weight;

            if(dist[destination] > dist[source] + weight) {
                Arrays.fill(dist , -1);
                return dist;
            }
        }

        return dist;

    }
}
