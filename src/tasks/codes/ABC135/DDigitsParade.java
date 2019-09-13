package tasks.codes.ABC135;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

import java.util.Arrays;

public class DDigitsParade {
    final long mod = (long) (1e9 + 7);
    final int N = (int) (1e5 + 5);
    long [][] dp = new long[N][15];
    int n;
    String s;
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        s = in.next();
        n = s.length();

        for(int i = 0 ; i < N ; i++) {
            Arrays.fill(dp[i] , -1);
        }

        out.println(DP(0 , 0));
    }

    private long DP(int i, int j) {
        long res = dp[i][j];
        if(res >= 0) return res;

        res = 0;
        if(i == n) {
            res = (j == 5 ? 1 : 0);
            dp[i][j] = res;
            return res;
        }
        if(s.charAt(i) == '?') {
            int temp;
            for(int dig = 0 ; dig < 10 ; dig++) {
                temp = (10 * j + dig) % 13;
                res += DP(i + 1 , temp);
                res %= mod;
            }
        }
        else {
            int dig = s.charAt(i) - '0';
            j = (10 * j + dig) % 13;
            res += DP(i + 1 , j);
            res %= mod;
        }

        dp[i][j] = res;
        return res;
    }
}
