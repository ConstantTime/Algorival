package JCodes.Maths;

import java.util.Random;

public class MathTools {
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

    public boolean isPrime(int n , int k) {
        if(n <= 1 || n == 4) return false;
        if(n <= 3) return true;

        int d = n - 1;

        while(d % 2 == 0) {
            d = d / 2;
        }

        // k iterations for perfection
        for(int i = 0 ; i < k ; i++) {
            if(!millerTest(d , n)) {
                return false;
            }
        }

        return true;
    }

    public boolean millerTest(int d, int n) {
        Random r = new Random();

        int a = r.nextInt(n - 4) + 2;
        int x = (int) MathTools.modular_power(a , d , n);
        if(x == 1 || x == n - 1) return true;

        while(d != n - 1) {
            x = (x * x) % n;
            d *= 2;
            if(x == 1) return false;
            if(x == n - 1) return true;
        }

        return false;
    }

    public static long modular_power(long fi, long l, long mod) {
        if(l == 0) return 1;
        long ans = modular_power(fi , l / 2 , mod);
        ans *= ans;
        ans %= mod;
        if(l % 2 != 0) {
            ans *= fi;
            ans %= mod;
        }
        return ans;
    }


    public static long inverse_mod(long fi , long mod) {
        return modular_power(fi , mod - 2 , mod);
    }

    public static long ncr(long n, long r, long mod) {
        long ans = 1;

        long [] fac = MathTools.factorial(n , mod);

        ans *= fac[(int) n];
        ans %= mod;

        ans *= MathTools.inverse_mod(fac[(int) r] , mod);
        ans %= mod;
        ans *= MathTools.inverse_mod(fac[(int) (n - r)] , mod);
        ans %= mod;

        return ans;
    }

    public static long npr(long n , long r , long mod) {
        long ans = 1;

        long [] fac = MathTools.factorial(n , mod);

        ans *= fac[(int) n];
        ans %= mod;
        ans *= MathTools.inverse_mod(fac[(int) (n - r)] , mod);
        ans %= mod;

        return ans;
    }

}
