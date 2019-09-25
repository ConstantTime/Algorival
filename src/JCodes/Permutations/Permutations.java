package JCodes.Permutations;

import JCodes.Maths.MathTools;

import java.util.*;

import static java.lang.Math.abs;

public class Permutations {

    final public static long mod = (long) (1e18 + 7);
    public static long totalPermutations(long n) {
        long [] fac = MathTools.factorial(n, mod);
        return fac[(int) n];
    }

    public static int nextGreaterNumber(int n) {
        // TODO -  resolve error
        String res = String.valueOf(n);
        char [] s = new char[res.length()];
        for(int i = 0 ; i < res.length() ; i++) {
            s[i] = res.charAt(i);
        }

        NavigableMap< Integer , Integer > a = new TreeMap<>();

        for(int i = s.length - 1 ; i >= 0 ; i--) {
            int c = s[i];
            Map.Entry < Integer , Integer > entry = a.ceilingEntry(c);
            a.put(c , i);
            if(entry == null || entry.getKey() < s[i]) continue;
            char cc = '0';
            cc += entry.getKey();
            System.out.println(i +  " " + entry.getKey() != null ? (char)(cc) :  -1);
            char temp = s[i];
            s[i] = s[entry.getValue()];
            s[entry.getValue()] = temp;
            Arrays.sort(s , i + 1 , s.length);

            if(Long.valueOf(String.valueOf(s)) == n) continue;
            return Long.valueOf(String.valueOf(s)) > Integer.MAX_VALUE ? -1 : Integer.valueOf(String.valueOf(s));
        }

        return -1;
    }

    public static List<Integer> findClosestElements(int[] arr, int k, int x) {
        PriorityQueue < pair > a = new PriorityQueue<>((o1, o2) -> {
            if((o1.first) != (o2.first)) return (o1.first) - (o2.first);
            return abs(o1.second) - abs(o2.second);
        });

        List < Integer > ans = new ArrayList<>();

        for(int i = 0 ; i < arr.length ; i++) {
            a.add(new pair(abs(x - arr[i]) , x - arr[i] >= 0 ? i + 1 : -i - 1));
        }

//        PriorityQueue < pair > temp = new PriorityQueue<>(a);
//
//        while(temp.size() != 0) {
//            System.out.println(temp.peek().toString());
//            temp.poll();
//        }


        while(ans.size() != k) {
            pair p = a.peek();
            if(p.second >= 0) {
                ans.add(x - p.first);
            }
            else {
                ans.add(x + p.first);
            }
            a.poll();
        }

        Collections.sort(ans);

        return ans;
    }
    // TODO - more codes to be added in this file

    public static void main(String[] args) {
        int [] a = new int []{1 , 2 , 3 , 4 , 5};
        System.out.println(findClosestElements(a , 4 , 3));
    }
}

class pair {
    public int first;
    public int second;

    pair() {

    }

    pair(int first , int second) {
        this.first = first;
        this.second = second;
    }

    public String toString() {
        return new String(String.valueOf(first) +  " " + String.valueOf(second));
    }

}
