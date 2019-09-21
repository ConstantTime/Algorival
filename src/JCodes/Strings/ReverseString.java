package JCodes.Strings;

public class ReverseString {

    public static String reverseString(String s) {
        int l = 0;
        int r = s.length() - 1;

        StringBuilder a = new StringBuilder();

        for(int i = r ; i >= 0 ; i--) {
            a.append(s.charAt(i));
        }

        return a.toString();
    }
}
