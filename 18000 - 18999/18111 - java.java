import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] s = br.readLine().split(" ");

        int N = Integer.parseInt(s[0]); // 세로 N
        int M = Integer.parseInt(s[1]); // 가로 M
        int B = Integer.parseInt(s[2]); // 블록 B개

        int[][] ground = new int[N][M];

        int high = 0; // 입력값 중 가장 높은 땅
        int low = 256; // 입력값 중 가장 낮은 땅

        for (int i = 0; i < N; i++) {
            s = br.readLine().split(" ");

            for (int j = 0; j < M; j++) {
                ground[i][j] = Integer.parseInt(s[j]);

                if (ground[i][j] > high) high = ground[i][j];
                if (ground[i][j] < low) low = ground[i][j];
            }
        }

        int time = 0; // 땅을 고르는 데 걸리는 시간
        int gh = 0; // 땅의 높이

        for (int i = low; i <= high; i++) {
            int t = 0; // 땅을 i 높이로 만드는데 걸리는 시간
            int useB = 0; // 사용한 블록의 수

            // 땅 고르기
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < M; k++) {
                    if (ground[j][k] > i) { // 블록 제거
                        t += ((ground[j][k] - i) * 2);
                        useB -= (ground[j][k] - i);
                    }
                    else if (ground[j][k] < i) { // 블록 쌓기
                        t += (i - ground[j][k]);
                        useB += (i - ground[j][k]);
                    }
                }
            }

            // 작업에 걸리는 최소 시간
            if ((t <= time || i == low) && useB <= B) {
                time = t;
                gh = i;
            }
        }

        // 출력
        System.out.println(time + " " + gh);
    }
}