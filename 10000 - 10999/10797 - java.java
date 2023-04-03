import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int day = Integer.parseInt(br.readLine());
        int count = 0;

        String[] s = br.readLine().split(" ");

        for (int i = 0; i < 5; i++)
            if (Integer.parseInt(s[i]) == day) count++;

        System.out.println(count);
    }
}