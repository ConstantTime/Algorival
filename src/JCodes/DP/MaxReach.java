package JCodes.DP;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

import java.io.*;

public class MaxReach {

    public static int maxReach(int []a) {
        int n = a.length;

        int jumps = 1;
        int maxi = 0;

        if(n <= 1) return 0;
        if(a[0] == 0) {
            return -1;
        }
        maxi = a[0];
        int steps = a[0];
        for(int i = 1 ; i < n ; i++) {
            if(i == n - 1) return jumps;
            maxi = Math.max(maxi , i + a[i]);
            steps--;
            if(steps == 0) {
                jumps++;
                if(i >= maxi) return -1;
                steps = maxi - i;
            }
        }

        return -1;
    }

    public static void main(String[] args) {

        int [] a = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
        System.out.println(maxReach(a));
    }
}
