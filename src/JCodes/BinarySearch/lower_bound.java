package JCodes.BinarySearch;

public class lower_bound {

    public static int lower_bound(long [] a , long value) {
        int n = a.length;

        if(value > a[n - 1]) return n;
        int l = 0;
        int r = n - 1;

        while(l < r) {
            final int mid = (l + r) / 2;
            if(value <= a[mid]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }

    public static int lower_bound(int [] a , int value) {
        int n = a.length;

        if(value > a[n - 1]) return n;
        int l = 0;
        int r = n - 1;

        while(l < r) {
            final int mid = (l + r) / 2;
            if(value <= a[mid]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }

    public static int lower_bound(double [] a , double value) {
        int n = a.length;

        if(value > a[n - 1]) return n;
        int l = 0;
        int r = n - 1;

        while(l < r) {
            final int mid = (l + r) / 2;
            if(value <= a[mid]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }
}
