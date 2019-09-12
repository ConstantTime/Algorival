package JCodes.Maths;

public class ModularPowerAndInverse {
    private long modular_power(long fi, long l, long mod) {
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

    private long inverse_mod(long fi , long mod) {
        return modular_power(fi , mod - 2 , mod);
    }
}
