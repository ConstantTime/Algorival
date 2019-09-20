package tasks.codes.ABC125;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

public class DFlippingSigns {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();

        int [] a = in.nextIntArray(n);

        long sum = 0;

        int cnt = 0;
        int mini = Integer.MAX_VALUE;
        for(int i : a) {
            if(i < 0) cnt++;
            sum += Math.abs(i);
            mini = Math.min(mini , Math.abs(i));
        }

        if(cnt % 2 == 0) {
            out.println(sum);
        }
        else {
            out.println(sum - 2 * mini);
        }

    }
}
