package tasks.codes.ABC125;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

public class ABiscuitGenerator {
    public void solve(int testNumber, InputReader in, OutputWriter out) {

        int a = in.nextInt();
        int b = in.nextInt();
        int t = in.nextInt();

        int ans = 0;
        for(int i = 1 ; i <= t ; i++) {
            if(i % a == 0) {
                ans += b;
            }
        }

        out.println(ans);
    }
}
