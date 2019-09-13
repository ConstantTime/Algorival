package JCodes.Maths;

import java.util.Random;

public class MillerRabin {

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
        int x = (int) ModularPowerAndInverse.modular_power(a , d , n);
        if(x == 1 || x == n - 1) return true;

        while(d != n - 1) {
            x = (x * x) % n;
            d *= 2;
            if(x == 1) return false;
            if(x == n - 1) return true;
        }

        return false;
    }
}
