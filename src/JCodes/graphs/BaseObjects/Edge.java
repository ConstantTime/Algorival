package JCodes.graphs.BaseObjects;

public class Edge {
    public int source;
    public int destination;
    public int weight;

    Edge() {

    }

    Edge(int source , int destination , int weight) {
        this.source = source;
        this.destination = destination;
        this.weight = weight;
    }
}
