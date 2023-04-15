import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int big = 0; // 최댓값
        int sero = 0; // 행 번호
        int garo = 0; // 열 번호

        for (int i = 0; i < 9; i++) {
            String[] s = br.readLine().split(" ");

            // 최댓값을 찾기
            for (int j = 0; j < 9; j++) {
                int n = Integer.parseInt(s[j]);

                if (n > big) {
                    big = n;
                    sero = i;
                    garo = j;
                }
            }
        }

        // 출력
        System.out.println(big + "\n" + ++sero + " " + ++garo);

    }
}