package JCodes.graphs.BaseObjects;

public class Node implements Comparable<Node> {

    public int node;
    public int cost;

    public Node(int node , int cost) {
        this.node = node;
        this.cost = cost;
    }

    @Override
    public int compareTo(Node node1) {
        if(cost < node1.cost) return -1;
        if(cost > node1.cost) return 1;
        return 0;
    }
}
