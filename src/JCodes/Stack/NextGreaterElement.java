package JCodes.Stack;

import java.util.Stack;

public class NextGreaterElement {

    public static int [] ForNormalArray(int a[]) {
        Stack < Integer > s = new Stack<>();
        int n = a.length;
        int [] ans = new int[n];

         for(int i = n - 1 ; i >= 0 ; i--) {
             while(!s.empty() && s.peek() <= a[i]) {
                 s.pop();
             }

             if(s.empty()) {
                 ans[i] = -1;
             }
             else {
                 ans[i] = s.peek();
                 s.pop();
             }

             s.push(a[i]);
         }

        return ans;
    }

    public static int [] ForCircularArray(int a[]) {
        Stack < Integer > s = new Stack<>();
        int n = a.length;
        int [] ans = new int[n];

        for(int i = n - 1 ; i >= 0 ; i--) {
            s.push(a[i]);
        }

        for(int i = n - 1 ; i >= 0 ; i--) {
            while(!s.empty() && s.peek() <= a[i]) {
                s.pop();
            }

            if(s.empty()) {
                ans[i] = -1;
            }
            else {
                ans[i] = s.peek();
                s.pop();
            }

            s.push(a[i]);
        }

        return ans;
    }
}
