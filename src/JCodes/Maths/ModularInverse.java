package JCodes.Maths;

import static JCodes.Maths.ModularPower.modular_power;

public class ModularInverse {
    public static long inverse_mod(long fi , long mod) {
        return modular_power(fi , mod - 2 , mod);
    }
}
