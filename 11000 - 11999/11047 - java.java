import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] s = br.readLine().split(" ");
        int N = Integer.parseInt(s[0]); // N종류
        int K = Integer.parseInt(s[1]); // 가치의 합을 K

        int[] arr = new int[N]; // 동전의 가치
        for (int i = 0; i < N; i++)
            arr[i] = Integer.parseInt(br.readLine());

        System.out.println(coin(K, N, arr));
    }

    // K원을 만드는데 필요한 동전 개수의 최솟값 구하기
    public static int coin(int K, int N, int[] arr) {
        int count = 0;

        for (int i = N - 1; i >= 0; i--) {
            if (arr[i] <= K) {
                count += (K / arr[i]);
                K %= arr[i];
            }

            if (K == 0) break;
        }

        return count;
    }
}