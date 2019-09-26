package JCodes.Strings;

public class ValidIPOrNot {

    private static boolean isIPAddressValid(String ip) {
        boolean result = true;
        int i = 0;
        int [] val = new int[4];

        if ((ip == null) || (ip.trim().length() == 0)) {
            result = false;
        }
        else {
            if (!(ip.contains("."))) {
                result = false;
            }
            else {
                // important learning
                String [] parts = ip.split("\\.");
                if (!(parts.length == 4)) {
                    result = false;
                }
                else {
                    for (String s : parts) {
                        try {
                            val[i] = Integer.parseInt(s);
                            if ((val[i] < 0) || (val[i] > 255)) {
                                result = false;
                            }
                            i++;
                        } catch (Exception e) {
                            result = false;
                        }
                    }
                }
            }
        }
        return result;
    }

}
