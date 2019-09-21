package JCodes.Strings;

public class IsPalindrome {

    public static boolean isPalindrome(String s) {
        int n = s.length() - 1;

        int l = 0;
        int r = n - 1;

        while(l < r) {
            if(s.charAt(l) != s.charAt(r)) return false;
            l++;
            r--;
        }

        return true;
    }
}
