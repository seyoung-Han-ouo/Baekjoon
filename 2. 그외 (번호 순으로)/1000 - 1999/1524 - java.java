import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine()); // 테스트 케이스의 개수 T

        for (int i = 0; i < T; i++) {
            br.readLine(); // 테스트 케이스 다음의 공백
            StringTokenizer st = new StringTokenizer(br.readLine());

            int N = Integer.parseInt(st.nextToken()); // 세준이의 병사 수
            int M = Integer.parseInt(st.nextToken()); // 세비의 병사 수

            // 세준이의 병사들 중 가장 강한 병사의 힘
            int sejun = 0;
            st = new StringTokenizer(br.readLine());

            for (int j = 0; j < N; j++) {
                if (st.hasMoreTokens()) {
                    int power = Integer.parseInt(st.nextToken());

                    if (power > sejun) sejun = power;
                }
            }

            // 세비의 병사들 중 가장 강한 병사의 힘
            int sebi = 0;
            st = new StringTokenizer(br.readLine());

            for (int j = 0; j < M; j++) {
                if (st.hasMoreTokens()) {
                    int power = Integer.parseInt(st.nextToken());

                    if (power > sebi) sebi = power;
                }
            }

            // 출력
            if (sejun < sebi)
                System.out.println("B");
            else
                System.out.println("S");
        }
    }
}
