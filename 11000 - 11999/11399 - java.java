import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine()); // 사람의 수
        int[] num = new int[N]; // 각 사람이 돈을 인출하는데 걸리는 시간

        String[] s = br.readLine().split(" ");

        for (int i = 0; i < N; i++)
            num[i] = Integer.parseInt(s[i]);

        Arrays.sort(num); // 오름차순 정렬

        System.out.println(needTime(num, N));
    }

    // 각 사람이 돈을 인출하는데 필요한 시간의 합 구하기
    public static int needTime(int[] num, int N) {
        int sum = num[0];

        for (int i = 1; i < N; i++) {
            num[i] += num[i - 1];
            sum += num[i];
        }

        return sum;
    }
}