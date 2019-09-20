package JCodes.Maths;

public class factorial {

    final long mod = (long) (1e18 + 7);
    public static long [] factorial(long n, long mod) {

        long [] fac = new long [(int) n + 1];

        fac[0] = 1;
        for(long i = 1 ; i <= n ; i++) {
            fac[(int) i] = i * fac[(int) (i - 1)];
            fac[(int) i] %= mod;
        }

        return fac;
    }
}
