import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt();

        // 첫째 줄부터 N번째 줄까지 차례대로 별을 출력
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < N - i; j++) // 공백 출력
                System.out.printf(" ");

            for (int j = 0; j < 2 * i - 1; j++) // 별 출력
                System.out.printf("*");

            System.out.println();
        }

        // N번째 줄부터 2 * N - 1번째 줄까지 차례대로 별을 출력
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) // 공백 출력
                System.out.printf(" ");

            for (int j = 0; j < 2 * (N - i) - 1; j++) // 별 출력
                System.out.printf("*");

            System.out.println();
        }
    }
}