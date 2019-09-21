package tasks.codes.ABC135;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

import java.util.Arrays;

public class B0Or1Swap {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int [] a = in.nextIntArray(n);
        int [] b = a.clone();
        int [] c = a.clone();

        Arrays.sort(c);

        boolean flag = false;
        for(int i = 0 ; i < n ; i++) {
            for(int j = i + 1 ; j < n ; j++) {

                int temp = b[i];
                b[i] = b[j];
                b[j] = temp;
                boolean res = true;

                for(int k = 0 ; k < n ; k++) {
                    if(c[k] != b[k]) {
                        res = false;
                        break;
                    }
                }

                temp = b[i];
                b[i] = b[j];
                b[j] = temp;

                if(res == true) {
                    //out.println(second);
                    flag = true;
                    break;
                }

            }
        }

        boolean same = true;
        for(int i = 0 ; i < n ; i++) {
            if(b[i] != c[i]) {
                same = false;
                break;
            }
        }

        if(flag || same) {
            out.println("YES");
        }
        else {
            out.println("NO");
        }
    }
}
