package tasks.codes.CF_Practice;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

public class CPerfectTeam {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int q = in.nextInt();
        for(int pp = 1 ; pp <= q ; pp++) {
            int c , m , x;
            c = in.nextInt();
            m = in.nextInt();
            x = in.nextInt();
            if(c > m) {
                int temp = c;
                c = m;
                m = temp;
            }
            int lef = m - c;
            int people = lef + x;
            int teams = Math.min(c , (people + 2 * c) / 3);
            out.println(teams);
        }
    }
}
