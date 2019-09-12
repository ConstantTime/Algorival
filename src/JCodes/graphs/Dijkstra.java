package JCodes.graphs;

import java.util.*;

public class Dijkstra {

    PriorityQueue < Node > pq = new PriorityQueue<>();
    Set < Integer > settled = new HashSet<>();
    int [] dist;
    public int [] dijkstra(int n , List <List< Node >> a , int src) {

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

    private void neighbours(List < List < Node > > a, int u) {
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
}
