package JCodes.DP;

import java.util.Arrays;
import java.util.List;

public class MaxLenChainOfPairs {

    public static int maxlength(List < pair> a) {
        int n = a.size();
        int maxi = 0;

        int [] lcs = new int[n];
        Arrays.fill(lcs , 1);

        for(int i = 1 ; i < n ; i++) {
            for(int j = 0 ; j < i ; j++) {
                if(a.get(i).first > a.get(i).second && lcs[i] < lcs[j] + 1) {
                    lcs[i] = lcs[j] + 1;
                }
            }
        }

        for(int i = 0 ; i < n ; i++) {
            maxi = Math.max(maxi , lcs[i]);
        }

        return maxi;
    }
}

class pair{
    public long first;
    public long second;
    pair() {

    }
    pair(long a , long b) {
        this.first = a;
        this.second = b;
    }
}
