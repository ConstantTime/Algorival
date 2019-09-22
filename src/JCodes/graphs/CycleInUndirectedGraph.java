package JCodes.graphs;

import JCodes.graphs.BaseObjects.Graph;
import JCodes.graphs.BaseObjects.Node;

import java.util.Arrays;

public class CycleInUndirectedGraph {

    private static boolean isCyclic(Graph graph , int vertices) {
        boolean [] visited = new boolean[vertices + 1];

        Arrays.fill(visited , false);

        for(int i = 1 ; i <= vertices ; i++) {
            if(!visited[i]) {
                if(UtilFunction(graph , visited , i , -1)) return true;
            }
        }

        return false;
    }

    private static boolean UtilFunction(Graph graph, boolean[] visited, int s, int parent) {

        visited[s] = true;
        for(Node node : graph.list.get(s)) {
            int v = node.node;
            if(!visited[v]) {
                if(UtilFunction(graph , visited , v , s)) return true;
            }
            else if (v != parent) {
                return true;
            }
        }
        return false;
    }
}
