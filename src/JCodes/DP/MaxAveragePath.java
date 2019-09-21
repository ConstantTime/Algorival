package JCodes.DP;

public class MaxAveragePath {

    public static double maxAveragePath(double cost[][]) {
        int n = cost.length;
        int m = cost[0].length;

        double [][] dp = new double[n][m];
        dp[0][0] = cost[0][0];
        for(int i = 1 ; i < n ; i++) {
            dp[i][0] = dp[i - 1][0] + cost[i][0];
        }

        for(int i = 0 ; i < m ; i++) {
            dp[0][i] = dp[0][i - 1] + cost[0][i];
        }

        for(int i = 1 ; i < n ; i++) {
            for(int j = 1 ; j < m ; j++) {
                dp[i][j] = Math.max(dp[i - 1][j] , dp[i][j - 1]) + cost[i][j];
            }
        }

        // can be changes to double for finding the accurate value
        return dp[n][m] / (n + m - 1);
    }
}
