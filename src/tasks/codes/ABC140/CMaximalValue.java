package tasks.codes.ABC140;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

import java.util.Arrays;

public class CMaximalValue {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();

        int [] b = in.nextIntArray(n - 1);

        int sum = 0;

        int [] a = new int[n];

        Arrays.fill(a , 1000000000);

        for(int i = 0 ; i < n - 1 ; i += 2) {
            a[i] = b[i];
            a[i + 1] = b[i];
        }

        for(int i = 1 ; i < n - 1 ; i += 2) {
            a[i] = Math.min(a[i] , b[i]);
            a[i + 1] = Math.min(a[i + 1] , b[i]);
        }

        for(int i : a) sum += i;
        out.println(sum);
    }
}
