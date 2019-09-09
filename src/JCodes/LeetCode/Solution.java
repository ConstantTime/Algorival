package JCodes.LeetCode;

import JCodes.generics.PairGenericWithComparator;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Stack;
import java.util.Vector;

public class Solution {
    public static Vector< Integer > nextGreaterDistance(int[] T) {
        Vector < Integer > ans = new Vector<>();

        int n = T.length;

        if(n == 0) return ans;

        ans.setSize(n);

        Stack<PairGenericWithComparator.pair<Integer , Integer>> s = new Stack<>();
        PairGenericWithComparator.pair<Integer , Integer> temp;

        temp = new PairGenericWithComparator.pair<>(T[0] , 0);
        s.add(temp);

        for(int i = 1 ; i < n ; i++) {
            if(s.empty()) {
                temp = new PairGenericWithComparator.pair<>(T[i] , i);
                s.push(temp);
                continue;
            }

            while(s.empty() == false && s.peek().getFi() < T[i]) {
                ans.set(s.peek().getSe(),  i - s.peek().getSe());
                s.pop();
            }

            temp = new PairGenericWithComparator.pair<>(T[i] , i);
            s.push(temp);
        }

        while(s.empty() == false) {
            ans.set(s.peek().getSe() , 0);
            s.pop();
        }
        return ans;
    }

    public int mincostTickets(int[] days, int[] costs) {
        int n = days.length;

        int m = costs.length;

        if(n == 0) return 0;

        int [] dp = new int[366];

        for(int i = 1 ; i < 366 ; i++) {
            dp[i] = Integer.MAX_VALUE;
        }
        dp[0] = 0;
        int didx = 0;

        for(int i = 1 ; i < 366  ; i++){

            if(didx >= days.length) break;
            if(i < days[didx]) {
                dp[i] = dp[i - 1];
            }
            else {
                dp[i] = dp[i - 1] + costs[0];
                int mindp = dp[i - 1];

                for(int j = 1; j <= 7 ; j++) {
                    if(i - j < 0) {
                        break;
                    }

                    mindp = Math.min(mindp, dp[i - j]);
                }

                dp[i] = Math.min(dp[i], mindp + costs[1]);

                for(int j = 7 ; j <= 30 ; j++) {
                    if(i - j < 0) break;
                    mindp = Math.min(mindp , dp[i - j]);
                }

                dp[i] = Math.min(dp[i] , mindp + costs[2]);
                didx++;
            }
        }

        return dp[days[days.length - 1]];
    }

    public int wiggleMaxLength(int[] nums) {
        int n = nums.length;

        if(n == 0) return 0;

        boolean[] inc = new boolean[n];
        Arrays.fill(inc , false);

        int [] dp = new int[n];
        Arrays.fill(dp , 1);

        for(int i = 1 ; i < n ; i++) {
            for(int j = 0 ; j < i ; j++) {
                if(j == 0) {
                    if(nums[i] == nums[j]) continue;
                    dp[i] = Math.max(dp[i] , dp[j] + 1);
                    if(nums[i] > nums[j]) {
                        inc[i] = true;
                    }
                    continue;
                }
                if(nums[j] < nums[i]) {
                    if(inc[j] == false) {
                        if(dp[j] + 1 > dp[i]) {
                            dp[i] = dp[j] + 1;
                            inc[i] = true;
                        }

                    }
                }
                else if(nums[j] > nums[i]) {
                    if(inc[j] == true) {
                        if(dp[j] + 1 > dp[i]) {
                            dp[i] = dp[j] + 1;
                            inc[i] = false;
                        }
                    }
                }
            }
        }

        return dp[n - 1];
    }


    public static void main(String[] args) {
        int [] T = new int[4];

        T[0] = 11;
        T[1] = 13;
        T[2] = 21;
        T[3] = 3;

        Vector < Integer > ans = nextGreaterDistance(T);

        for(int i : ans) {
            System.out.print(i +  " ");
        }
    }

}
