import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt(); // 길이

        int[] A = new int[N]; // 길이가 N인 정수 배열 A
        int[] B = new int[N]; // 길이가 N인 정수 배열 B

        // 입력
        for (int i = 0; i < N; i++)
            A[i] = in.nextInt();

        for (int i = 0; i < N; i++)
            B[i] = in.nextInt();

        // 정렬
        Arrays.sort(A);
        Arrays.sort(B);

        int S = 0;
        for (int i = 0; i < N; i++)
            S += (A[i] * B[N - i - 1]);

        // 출력
        System.out.println(S);
    }
}