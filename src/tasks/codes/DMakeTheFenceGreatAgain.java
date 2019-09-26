package tasks.codes;

import JCodes.generics.IntPair;
import JCodes.generics.LongPair;
import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

public class DMakeTheFenceGreatAgain {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int q = in.nextInt();
        while(q != 0) {
            q--;
            int n = in.nextInt();
            LongPair[] pair = new LongPair[n];
            for(int i = 0 ; i < n ; i++) {
                pair[i] = new LongPair(in.nextInt() , in.nextInt());
                
            }
        }
    }
}
