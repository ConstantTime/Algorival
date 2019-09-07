package tasks.codes.ABC140;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

public class APassword {
    public void solve(int testNumber, InputReader in, OutputWriter out) {

        long ans = 1;

        long n = in.nextLong();
        for(int i = 1 ; i <= 3 ; i++) {
            ans = ans * n;
        }

        out.println(ans);
    }
}
