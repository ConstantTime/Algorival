package tasks.codes;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

public class BYYMMOrMMYY {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        String s = in.next();

        String amb = "AMBIGUOUS";
        String y = "YYMM";
        String m = "MMYY";

        String first = s.substring(0  , 2);
        String second = s.substring(2 , 4);

        boolean year = false;
        boolean month = false;
        if(Integer.valueOf(first) > 0 && Integer.valueOf(second) <= 12 && Integer.valueOf(second) > 0) {
            year = true;
        }

        if(Integer.valueOf(first) <= 12 && Integer.valueOf(first) > 0 && Integer.valueOf(second) > 0) {
            month = true;
        }

        if(year && month) {
            out.println(amb);
        }
        else if(year) {
            out.print(y);
        }
        else if(month) {
            out.print(m);
        }
        else {
            out.println("NA");
        }
    }
}
