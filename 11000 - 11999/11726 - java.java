import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[1001];

        // 직사각형을 채우는 방법의 수 구하기
        for (int i = 0; i <= n; i++) {
            if (i < 4)
                arr[i] = i;
            else
                arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
        }

        // 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지 출력
        System.out.println(arr[n] % 10007);

        br.close();
    }
}