package tasks.codes;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class EWhoSaysAPun {
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
    public void solve(int testNumber, InputReader in, OutputWriter out) {

        int n = in.nextInt();
        String s = in.next();

        int maxi = 0;

        int [][] dp = new int[n][n];

        for(int i = 0 ; i < n ; i++) Arrays.fill(dp[i] , 0);

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(s.charAt(i) == s.charAt(j)) {
                    if(i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = Math.max(1 + dp[i - 1][j - 1] , dp[i][j]);
                    }
                }
                dp[i][j] = Math.min(dp[i][j] , j - i);
                maxi = Math.max(maxi , dp[i][j]);
            }
        }

        out.println(maxi);
    }


}
