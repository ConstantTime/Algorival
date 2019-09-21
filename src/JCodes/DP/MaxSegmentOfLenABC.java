package JCodes.DP;

import java.util.Arrays;

public class MaxSegmentOfLenABC {

    public static long maxLengthOfSegmentABC(long n , long a , long b , long c) {
        long [] dp = new long[(int) n + 1];

        Arrays.fill(dp , -1);
        dp[0] = 0;
        for(int i = 0 ; i < n ; i++) {
            if(dp[i] == -1) continue;
            if(i + a <= n)
                dp[(int) (i + a)] = Math.max(dp[(int) (i + a)] , dp[i] + 1);
            if(i + b <= n)
                dp[(int) (i + b)] = Math.max(dp[(int) (i + b)] , dp[i] + 1);
            if(i + c <= n)
                dp[(int) (i + c)] = Math.max(dp[(int) (i + c)] , dp[i] + 1);
        }

        return dp[(int) n];

    }
}
