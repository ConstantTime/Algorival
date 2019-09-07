package tasks.codes;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

import java.util.*;

public class DVariousSushi {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();

        long[] t = new long[n + 1];

        long[] d = new long[n + 1];

        for (int i = 1; i <= n; i++) {
            t[i] = in.nextLong();
            d[i] = in.nextLong();
        }

        pair<Long, Long>[] a = new pair[n];

        for (int i = 1; i <= n; i++) {
            a[i - 1] = new pair(d[i], t[i]);
        }

        Arrays.sort(a);
//        Collections.reverse(Arrays.asList(a));

        int l = 0;
        int r = n - 1;

        while (l < r) {
            pair<Long, Long> temp = a[l];
            a[l] = a[r];
            a[r] = temp;
            l++;
            r--;
        }
        long sum = 0;

        Queue<Long> q = new PriorityQueue<>();

        Set<Long> res = new TreeSet<>();

        for (int i = 0; i < k; i++) {
            sum += a[i].fi;

            if (res.contains(a[i].se)) {
                q.add(a[i].fi);
            } else {
                res.add(a[i].se);
            }
        }

        long sz = res.size();

        long ans = sum + sz * sz;

        //out.println(ans);

        for (int i = k; i < n; i++) {
            if (!res.contains(a[i].se) && res.size() != k) {
                if(q.peek() == null) continue;
                long front = q.peek();

                //out.println(front);

                q.poll();

                res.add(a[i].se);

                sum -= front;
                sum += a[i].fi;

                long tt = res.size();

                ans = Math.max(ans, sum + tt * tt);
            }
        }

        out.println(ans);
    }

    class pair<T, W> implements Comparable<pair> {
        private T fi;
        private W se;

        public pair() {

        }

        public pair(T fi, W se) {
            this.fi = fi;
            this.se = se;
        }

        public int compareTo(pair o) {
            if (fi != o.fi) return Long.valueOf((Long) fi).compareTo(Long.valueOf((Long) o.fi));
            return Long.valueOf((Long) se).compareTo((Long.valueOf((Long) o.fi)));
        }

    }

}
