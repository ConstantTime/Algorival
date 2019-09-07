package tasks.codes.ABC140;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

import java.util.Vector;

// Number of max same facing boys
public class DFaceProducesUnhappiness {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();

        String s = in.next();

        int[] a = new int[n];

        for(int i = 0 ; i < n ; i++) {
            if(s.charAt(i) == 'L') a[i] = 1;
            else a[i] = -1;
        }

        Vector < Integer > res = new Vector<>();

        int sum = 0;
        int cur = 1;

        for(int i = 1 ; i < n ; i++) {
            if(a[i] == a[i - 1]) {
                cur++;
            }
            else {
                res.add(cur);
                cur = 1;
            }
        }

        res.add(cur);

        for(int i : res) sum += i - 1;

        while(k != 0) {
            k--;
            sum += 2;
        }

        out.println(Math.min(sum , n - 1));
    }
}
