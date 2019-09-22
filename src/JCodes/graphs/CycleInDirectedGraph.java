package JCodes.graphs;

import JCodes.graphs.BaseObjects.Color;
import JCodes.graphs.BaseObjects.Graph;
import JCodes.graphs.BaseObjects.Node;

import java.util.Arrays;

public class CycleInDirectedGraph {

    public static boolean isCyclic(Graph graph, int vertices) {

        Color[] colors = new Color[vertices + 1];
        Arrays.fill(colors , Color.WHITE);

        for(int i = 1 ; i <= vertices ; i++) {
            if(colors[i].equals(Color.WHITE)) {
                if(dfs(graph , i , colors)) {
                    return true;
                }
            }
        }

        return false;
    }

    private static boolean dfs(Graph graph, int i, Color[] colors) {

        colors[i] = Color.GRAY;

        for(Node node : graph.list.get(i)) {
            int v = node.node;
            if(colors[v].equals(Color.GRAY)) {
                return true;
            }

            if(colors[v].equals(Color.WHITE) && dfs(graph , i , colors)) {
                return true;
            }
        }

        colors[i] = Color.BLACK;
        return false;
    }
}
