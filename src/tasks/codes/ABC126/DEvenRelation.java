package tasks.codes.ABC126;

import JCodes.graphs.Graph;
import JCodes.graphs.Node;
import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class DEvenRelation {
    private int[] color;
    private boolean[] vis;
    Graph graph;
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        graph = new Graph();
        int n = in.nextInt();

        for(int i = 1 ; i <= n + 1 ; i++) {
            List<Node> item = new ArrayList<>();
            graph.a.add(item);
        }

        for(int i = 0 ; i < n - 1; i++) {
            int u , v , w;
            u = in.nextInt();
            v = in.nextInt();
            w = in.nextInt();

            graph.a.get(u).add(new Node(v , w));
            graph.a.get(v).add(new Node(u , w));
        }

        color = new int[n + 1];
        vis = new boolean[n + 1];

        Arrays.fill(color , -1);
        Arrays.fill(vis , false);

        color[1] = 0;
        dfs(1);

        for(int i = 1 ; i <= n ; i++) {
            out.println(color[i]);
        }
    }

    private void dfs(int i) {
        vis[i] = true;

        for(Node node : graph.a.get(i)) {
            if(vis[node.node] == false) {
                color[node.node] = (color[i] + node.cost) % 2;
                dfs(node.node);
            }
        }
    }
}
