package JCodes.DP;

import java.util.ArrayList;
import java.util.List;

public class ZAlgorithm {
    public int [] zCalculation(String s) {
        int n = s.length();
        int left = 0;
        int right = 0;
        int [] Z = new int[n];
        Z[0] = 0;
        for(int k = 1; k < s.length() ; k++) {
            if(k > right) {
                left = right = k;
                while(right < s.length() && s.charAt(right)== s.charAt(right - left)) {
                    right++;
                }
                Z[k] = (right - left);
                right--;
            } else {
                int k1 = k - left;
                if(Z[k1] < right - k + 1) {
                    Z[k] = Z[k1];
                } else {
                    left = k;
                    while(right < s.length() && s.charAt(right)== s.charAt(right - left)) {
                        right++;
                    }
                    Z[k] = (right - left);
                    right--;
                }
            }
        }

        return Z;
    }

    // here a is our pattern that will be matched with string b which is our main text
    public List< Integer > patternMatching(String a, String b) {
        String res = a;
        res.concat("$");
        res.concat(b);
        int [] z = zCalculation(res);

        List < Integer > ans = new ArrayList<>();

        for(int i = 0 ; i < z.length ; i++) {
            if(z[i] == a.length()) {
                ans.add(i - a.length() - 1);
            }
        }

        return ans;
    }

}
