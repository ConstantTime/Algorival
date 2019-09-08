package JCodes.LeetCode;

import JCodes.generics.PairGenericWithComparator;

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
