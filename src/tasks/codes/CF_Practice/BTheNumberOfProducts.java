package tasks.codes.CF_Practice;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

public class BTheNumberOfProducts {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int [] a = in.nextIntArray(n);

        for(int i = 0 ; i < n ; i++) {
            a[i] = (a[i] > 0 ? 1 : -1);
        }

        long total = ((long)n * (long)(n + 1)) / 2;

        long pos = 0;

        long bal = 0;
        long cnt1 = 0;
        long cnt2 = 0;
        for(int i = 0 ; i < n ; i++) {
            if (bal % 2 == 0) {
                cnt1++;
            } else {
                cnt2++;
            }
            if (a[i] < 0) {
                bal++;
            }
            if (bal % 2 == 0) {
                pos += cnt1;
            } else {
                pos += cnt2;
            }
        }

        out.println((total - pos) + " " + (pos));
    }
}
