import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] s = br.readLine().split(" ");
        int N = Integer.parseInt(s[0]); // 폭죽을 터뜨리는 학생의 수
        int C = Integer.parseInt(s[1]); // 폭죽쇼가 끝나는 시간

        int arr[] = new int[N]; // 학생들이 폭죽을 터뜨리는 주기
        int count = 0;

        for (int i = 0; i < N; i++)
            arr[i] = Integer.parseInt(br.readLine());

        // 폭죽쇼가 시작되고 끝날 때까지 밤하늘에 폭죽을 볼 수 있는 총 시간
        for (int i = 1; i <= C; i++) {
            for (int j = 0; j < N; j++) {
                if (i % arr[j] == 0) {
                    count++;
                    break;
                }
            }
        }

        System.out.println(count);
    }
}