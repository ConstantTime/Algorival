package tasks.codes.ABC135;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

public class CCitySavers {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        long [] a = in.nextLongArray(n + 1);
        long [] b = in.nextLongArray(n);

        long sum = 0;

        for(int i = 0 ; i < n ; i++) {
            long mini = Math.min(a[i] , b[i]);

            sum += mini;
            a[i] -= mini;
            b[i] -= mini;

            mini = Math.min(a[i + 1] , b[i]);
            sum += mini;
            a[i + 1] -= mini;
            b[i] -= mini;
        }

        out.println(sum);
    }
}
