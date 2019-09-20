package JCodes.DP;

import java.util.Arrays;

public class lcs {
    public int lcs(String a , String b) {
        int n = a.length();
        int m = b.length();

        int [][] dp = new int[n][m];
        for(int i = 0 ; i < n ; i++) Arrays.fill(dp[i] , 0);

        int ans = 0;
        for(int i = 1 ; i < n ; i++) {
            for(int j = 1 ; j < m ; j++) {
                if(a.charAt(i) == b.charAt(j)) {
                    dp[i][j] = dp[i - 1][j - 1];
                    ans = Math.max(ans , dp[i][j]);
                }
            }
        }
        return ans;
    }
}
