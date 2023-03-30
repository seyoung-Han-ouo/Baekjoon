import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Map<String, String> school = new HashMap<String, String>() {{
            put("NLCS","North London Collegiate School");
            put("BHA","Branksome Hall Asia");
            put("KIS","Korea International School");
            put("SJA","St. Johnsbury Academy");
        }};

        String s = br.readLine();

        System.out.println(school.get(s));
    }
}