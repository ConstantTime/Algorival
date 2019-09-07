package tasks.codes.ABC140;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

public class BBuffet {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();

        int [] a = in.nextIntArray(n);
        int [] b = in.nextIntArray(n);
        int [] c = in.nextIntArray(n - 1);

        int prev = -1;

        int sum = 0;
        for(int i = 0 ; i < n ; i++) {
            int index = a[i] - 1;


            sum += b[index];

          //  out.print(sum + "\n");
            if(index == prev + 1 && prev >= 0) {
                sum += c[prev];
//                out.print(sum + "sajda \n");
            }

            prev = index;
        }

        out.println(sum);
    }
}
