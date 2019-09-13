package tasks.codes;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

public class AChangingACharacter {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        String s = in.next();

        String temp = "";

        String a , b , c;
        if(k - 1 >= 1)
            a = s.substring(0 , k - 1);
        else
            a = temp;

        if(k + 1 <= n)
            b = s.substring(k , n);
        else
            b = temp;

        c = s.substring(k - 1, k);

        out.println(a + c.toLowerCase() + b);
    }
}
