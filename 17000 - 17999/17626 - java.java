import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n + 1];
        arr[0] = 0;
        arr[1] = 1;

        for (int i = 2; i <= n; i++) {
            arr[i] = 4;

            // 사용하는 최소 제곱수의 수
            for (int j = 1; j * j <= i; j++)
                arr[i] = Math.min(arr[i - j * j] + 1, arr[i]);
        }

        System.out.println(arr[n]);

        br.close();
    }
}