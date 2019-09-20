package JCodes.DP;

public class ncr {

    public static long ncr(long n, long r) {
        long [][] dp = new long [(int) n + 1][(int) r + 1];
         for(int i = 0 ; i <= n ; i++) {
             for(int j = 0 ; j <= r ; j++) {
                 if(i == 0 || i < j) {
                     dp[i][j] = 0;
                     continue;
                 }
                 if(j == 0 || j == i) {
                     dp[i][j] = 1;
                 }
                 else {
                     dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                 }
             }
         }

         return dp[(int) n][(int) r];
    }

    public static void main(String[] args) {
        System.out.println(ncr(10 , 2));
    }
}
