package JCodes.Maths;

public class ncrWithoutDp {

    public static long ncr(long n, long r, long mod) {
        long ans = 1;

        long [] fac = factorial.factorial(n , mod);

        ans *= fac[(int) n];
        ans %= mod;

        ans *= ModularInverse.inverse_mod(fac[(int) r] , mod);
        ans %= mod;
        ans *= ModularInverse.inverse_mod(fac[(int) (n - r)] , mod);
        ans %= mod;

        return ans;
    }
}
