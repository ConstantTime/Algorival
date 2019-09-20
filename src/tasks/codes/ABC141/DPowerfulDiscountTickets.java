package tasks.codes.ABC141;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

import java.util.Collections;
import java.util.PriorityQueue;

public class DPowerfulDiscountTickets {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();

        long [] a = in.nextLongArray(n);
        PriorityQueue < Long > res = new PriorityQueue<>(Collections.reverseOrder());

        long sum = 0;
        long total = 0;
        for(long j : a) {
            res.add(j);
            total += j;
        }
        while(m != 0) {
            m--;
            long x = res.peek();
            res.poll();
            sum += x - x / 2;
            res.add(x / 2);
        }

        out.println(total - sum);
    }
}
