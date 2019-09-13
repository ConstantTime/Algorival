package tasks.codes.ABC135;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

public class AHarmony {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int a = in.nextInt();
        int b = in.nextInt();
        if((a + b) % 2 == 0) {
            out.println((a + b) / 2);
        }
        else {
            out.println("IMPOSSIBLE");
        }
    }
}
