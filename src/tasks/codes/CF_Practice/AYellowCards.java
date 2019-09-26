package tasks.codes.CF_Practice;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

public class AYellowCards {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int a1 = in.nextInt();
        int a2 = in.nextInt();
        int k1 = in.nextInt();
        int k2 = in.nextInt();
        int n = in.nextInt();

        if(k1 > k2) {
            int temp;
            temp = a1;
            a1 = a2;
            a2 = temp;
            temp = k1;
            k1 = k2;
            k2 = temp;
        }

        int maxi = 0;
        int mini = 0;

        int prev = n;
        int num = 0;
        num = n / k1;
        
        n -= Math.min(num * k1 , a1 * k1);
        maxi += Math.min(num , a1);
        
        num = n / k2;
        n -= Math.min(num * k2  , a2 * k2);
        maxi += Math.min(num  , a2 );
        
        int total = a1 * k1 + a2 * k2;

      //ma  out.println(total , prev , n);
        if(total < prev) {
            mini = a1 + a2;
        } else {
            mini = (a1 + a2) - (total - prev);
            if(mini < 0)
                mini = 0;

        }
        out.println(mini + " " + maxi);
    }
}
