import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[1001];

        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 3;

        // 직사각형을 채우는 방법의 수 구하기
        for (int i = 3; i <= n; i++)
            arr[i] = (arr[i - 1] + arr[i - 2] * 2) % 10007;

        // 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지 출력
        System.out.println(arr[n] % 10007);

        br.close();
    }
}