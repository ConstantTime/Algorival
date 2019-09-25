package JCodes.misc;

import java.util.Iterator;
import java.util.Map;
import java.util.NavigableMap;
import java.util.TreeMap;

public class NavMap {

    public static void main(String[] args) {
        NavigableMap < Integer , Integer > a = new TreeMap<>();

        int n = 10;
//        for(Map.Entry entry : a.entrySet()) {
//
//            System.out.println(entry.getKey() + " " + entry.getValue());
//        }

        NavigableMap < Integer , Integer > b = new TreeMap<>();
        b.put(1 , 5);
        b.put(10 , 55);
        b.put(2 , 10);
        b.put(3 , 15);
        b.put(6 , 8);
        b.put(7 , 9);
        b.put(4 , 67);



        for(Map.Entry entry : b.entrySet()) {
            System.out.println(entry.getKey() + " " + entry.getValue());
        }
        for(int i = 0 ; i < n ; i++) {

        }
    }
}
