package tasks.codes.ABC125;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

public class CGCDOnBlackboard {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int [] a = in.nextIntArray(n);

        int []l = new int[n];
        int [] r = new int [n];
        l[0] = a[0];

        for(int i = 1 ; i < n ; i++) {
            l[i] = gcd(l[i - 1] , a[i]);
        }

        r[n - 1] = a[n - 1];
        for(int i = n - 2 ; i >= 0 ; i--) {
            r[i] = gcd(r[i + 1] , a[i]);
        }

        int maxi = Integer.MIN_VALUE;

        for(int i = 1 ; i < n - 1 ; i++) {
            maxi = Math.max( maxi , gcd(l[i - 1] , r[i + 1]));
        }

        out.println(Math.max(maxi , Math.max(l[n - 2] , r[1])));
    }
    public int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);

    }

}
