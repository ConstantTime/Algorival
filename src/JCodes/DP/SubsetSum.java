package JCodes.DP;

public class SubsetSum {

    // determine if subset has sum equalt to SUM

    public static boolean IfSumIsThereOrNot(long [] a , int n , long sum) {
        boolean subset[][] = new boolean[2][(int) (sum + 1)];

        for(int i = 0 ; i <= n ; i++) {
            for(long j = 0 ; j <= sum ; j++) {
                if(j == 0) {
                    subset[i % 2][(int) j] = true;
                }
                else if(i == 0) {
                    subset[i % 2][(int) j] = false;
                }
                else if(a[i - 1] <= j) {
                    subset[i % 2][(int) j] = subset[(i + 1) % 2][(int) (j - a[i - 1])] || subset[(i + 1) % 2][(int) j];
                }
                else {
                    subset[i % 2][(int) j] = subset[(i + 1) % 2][(int) j];
                }
            }
        }

        return subset[n % 2][(int) sum];
    }
}
