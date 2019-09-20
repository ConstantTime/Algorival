package tasks.codes.ABC141;

import tasks.fastIO.InputReader;
import tasks.fastIO.OutputWriter;

import java.util.HashMap;
import java.util.Map;

public class AWeatherPrediction {
    public void solve(int testNumber, InputReader in, OutputWriter out) {

        String s = in.next();

        Map< String , String > a = new HashMap<>();
        a.put("Sunny" , "Cloudy");
        a.put("Cloudy" , "Rainy");
        a.put("Rainy" , "Sunny");

        out.println(a.get(s));
    }
}
