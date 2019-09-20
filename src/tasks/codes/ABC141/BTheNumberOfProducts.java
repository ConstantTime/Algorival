package tasks.codes.ABC141;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

import java.util.Arrays;

public class BTheNumberOfProducts {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int [] a = in.nextIntArray(n);

        int [] l = new int[n + 1];
        int [] r = new int[n + 1];
        Arrays.fill(l , 0);
        Arrays.fill(r , 0);

        for(int i = 1 ; i <= n ; i++) {
            if(a[i - 1] > 0) {
                r[i]++;
            }
            else {
                l[i]++;
            }
        }

        for(int i = 1 ; i <= n ; i++) {
            l[i] += l[i - 1];
            r[i] += r[i - 1];
        }

        long j = n;
        long cnt = (n * (n + 1)) / 2;



    }

}
