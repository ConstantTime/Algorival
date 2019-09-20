package JCodes.DP;

public class CountWaysToReachNthStep {

    public static long countWays(long n , long k) {
        long [] dp = new long [(int) (n + 1)];

        dp[0] = 1;

        for(int i = 1 ; i <= k ; i++) {
            for(int j = 0 ; j <= n ; j++) {
                if(j >= i) {
                    dp[j] += dp[j - i];
                }
            }
        }
        return dp[(int) n];
    }
}
