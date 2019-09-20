package JCodes.Maths;

public class nprWithoutDp {

    public static long npr(long n , long r , long mod) {
        long ans = 1;

        long [] fac = factorial.factorial(n , mod);

        ans *= fac[(int) n];
        ans %= mod;
        ans *= ModularInverse.inverse_mod(fac[(int) (n - r)] , mod);
        ans %= mod;

        return ans;
    }
}
