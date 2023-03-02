import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine()); // 테스트 케이스의 개수

        for (int i = 0; i < T; i++) {
            String[] s = br.readLine().split(",");
            int A = Integer.parseInt(s[0]);
            int B = Integer.parseInt(s[1]);

            System.out.println(A + B);
        }
    }
}