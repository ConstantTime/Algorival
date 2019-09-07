package tasks.codes;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

import java.util.Arrays;
import java.util.Vector;

public class DColoringEdges {

    Vector < Integer > [] a = new Vector[5456];
    public void solve(int testNumber, InputReader in, OutputWriter out) {

        int n = in.nextInt();

        int m = in.nextInt();

        for(int i = 1 ; i <= n ; i++) {
            a[i] = new Vector<>();
        }

        pair<Integer , Integer , Integer>[] ans = new pair[m];

        for(int i = 0 ; i < m ; i++) {
            int x , y;
            x = in.nextInt();
            y = in.nextInt();

            ans[i] = new pair(x , y , i);

            a[x].add(y);
        }

        boolean flag = cycle(n);

       // out.println(flag);
        int [] res = new int[m];
        Arrays.fill(res , 1);

        if(flag == false) {
            out.println(1);
            for(int i : res) {
                out.print(i + " ");
            }
            return ;
        }

        for(int i = 0 ; i < m ; i++) {
            if(ans[i].getFi() > ans[i].getSe()) {
                res[ans[i].getTh()] = 2;
            }
        }
        out.println(2);
        for(int i : res) {
            out.print(i + " ");
        }


    }

    private boolean dfs(int s , int [] color) {
        color[s] = 1;

        for(int j : a[s]) {
            if(color[j] == 1) {
                return true;
            }

            if(color[j] == 0 && dfs(j , color)) {
                return true;
            }
        }

        color[s] = 2;
        return false;
    }
    private boolean cycle(int n) {

        int [] color = new int [n + 1];

        Arrays.fill(color , 0);

        for(int i = 1 ; i <= n ; i++) {
            if(color[i] == 0) {
                if(dfs(i , color)) {
                    return true;
                }
            }
        }
        return false;
    }

    class pair<T, W , X> implements Comparable<pair>{
        private T fi;
        private W se;
        private X th;

        public pair() {

        }
        public pair(T fi , W se, X th) {
            this.fi = fi;
            this.th = th;
            this.se = se;
        }

        public T getFi() {
            return fi;
        }

        public W getSe() {
            return se;
        }

        public X getTh () {
            return th;
        }

        @Override
        public int compareTo(pair o) {
            return 0;
        }
    }

}
