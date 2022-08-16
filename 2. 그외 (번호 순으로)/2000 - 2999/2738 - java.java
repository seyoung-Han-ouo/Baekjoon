import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt(); // 행렬의 크기 N
        int M = in.nextInt(); // 행렬의 크기 M

        int[][] A = new int[N][M]; // 행렬 A

        // 행렬 A의 원소
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                A[i][j] = in.nextInt();
            }
        }

        // 행렬 A와 B를 더하기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int num = in.nextInt(); // 행렬 B의 원소
                A[i][j] += num;
            }
        }

        // 행렬 A와 B를 더한 행렬 출력
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                System.out.printf("%d ", A[i][j]);
            }
            System.out.println();
        }
    }
}