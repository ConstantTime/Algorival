package JCodes.Permutations;

import JCodes.Maths.factorial;

public class Permutations {

    final public static long mod = (long) (1e18 + 7);
    public static long totalPermutations(long n) {
        factorial factorial = new factorial();
        long [] fac = factorial.factorial(n, mod);
        return fac[(int) n];
    }

    // TODO - more codes to be added in this file
}
