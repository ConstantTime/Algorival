package JCodes.BinarySearch;

import java.util.Arrays;

public class upper_bound {

    public static int upper_bound(long a[] , long value) {
        int n = a.length;

        if(value >= a[n - 1]) return n;
        int l = 0;
        int r = n - 1;

        while(l < r) {
            final int mid = (l + r) / 2;
            if(value < a[mid]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }
    public static int upper_bound(int a[] , int value) {
        int n = a.length;

        if(value >= a[n - 1]) return n;
        int l = 0;
        int r = n - 1;

        while(l < r) {
            final int mid = (l + r) / 2;
            if(value < a[mid]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }

    public static int upper_bound(double a[] , double value) {
        int n = a.length;

        if(value >= a[n - 1]) return n;

        int l = 0;
        int r = n - 1;

        while(l < r) {
            final int mid = (l + r) / 2;
            if(value < a[mid]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }


    public static void main(String[] args) {

        //Testing the algortihm
        int [] a = new int [] {1 , 2 , 1287 , 12487 , 684 , 9 , 10 , 2136 , 12 , 6};
        Arrays.sort(a);
        for(int j : a) System.out.print(j + " ");
        System.out.println();
        System.out.println(upper_bound(a , 1276236));
    }
}
