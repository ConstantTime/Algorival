package tasks.codes.ABC125;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

public class BResale {
    public void solve(int testNumber, InputReader in, OutputWriter out) {

        int n = in.nextInt();
        pair[] a = new pair[n];

        int [] v = in.nextIntArray(n);
        int [] c = in.nextIntArray(n);
        int maxi = 0;

        for(int i = 0 ; i < n ; i++) {
            maxi += (v[i] - c[i] > 0 ? v[i] - c[i] : 0);
        }
        out.println(maxi);
    }
}

class pair implements Comparable < pair > {

    public int first;
    public int second;

    public pair(int i, int i1) {
        first = i;
        second = i1;
    }

    @Override
    public int compareTo(pair o) {
        if(first < o.first) return -1;
        else if(first > o.first) return 1;
        else if(second < o.second) return -1;
        return 1;
    }
}