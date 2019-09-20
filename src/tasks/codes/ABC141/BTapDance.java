package tasks.codes.ABC141;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

public class BTapDance {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        String s = in.next();

        boolean flag = true;

        int n = s.length();
        for(int j = 1 ; j <= n ; j++) {
            int i = j - 1;

            if(i % 2 == 0)  {
                if(s.charAt(i) == 'R' || s.charAt(i) == 'U' || s.charAt(i) == 'D') {
                    continue;
                }
                else {
                    flag = false;
                    break;
                }
            }
            else {
                if(s.charAt(i) == 'L' || s.charAt(i) == 'U' || s.charAt(i) == 'D') {
                    continue;
                }
                else {
                    flag = false;
                    break;
                }
            }
        }

        out.println(flag == true ? "Yes" : "No");
    }
}
