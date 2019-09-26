package tasks.codes.CF_Practice;

import JCodes.Maths.MathTools;
import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

public class DSwords {
    public void solve(int testNumber, InputReader in, OutputWriter out) {

        int n = in.nextInt();
        int [] a = in.nextIntArray(n);
        long sum = 0;

        for(int j : a) sum += j;

        int maxi = -1;

        for(int j : a) {
            if(j > maxi) maxi = j;
        }

        int g = maxi - a[0];
        for(int i = 1 ; i < n ; i++) {
            g = MathTools.gcd(g , maxi - a[i]);
        }

        long ans = 0;
        ans = maxi;
        ans *= n;
        ans -= sum;
        ans /= g;

        out.println(ans + " " + g);
    }
}
