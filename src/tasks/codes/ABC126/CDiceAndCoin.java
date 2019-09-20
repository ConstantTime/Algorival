package tasks.codes.ABC126;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

import java.util.Formatter;

public class CDiceAndCoin {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();

        double ans = 0.0;

        for(int i = 1 ; i <= n ; i++) {
            double f = 1.0 / Double.valueOf(n);

            int cnt = 0;
            int score = i;
            while(true) {
                if(score >= k) {
                    break;
                }
                cnt++;
                score = score * 2;
            }

          //  if(cnt == 0) continue;
        //    if(cnt > 0)
         //      out.println(i , cnt);
            ans += f * Math.pow(0.5 , Double.valueOf(cnt));
        }

        Formatter fmt = new Formatter();
        fmt.format("%.15f" , ans);

        out.println(fmt);
    }
}
