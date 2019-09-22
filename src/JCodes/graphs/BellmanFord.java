package JCodes.graphs;

import JCodes.graphs.BaseObjects.BellmanGraph;

import java.util.Arrays;

public class BellmanFord {

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
