import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int T = in.nextInt(); // 테스트 케이스의 개수

        for (int i = 0; i < T; i++) {
            int A = in.nextInt(); // 자연수 A
            int B = in.nextInt(); // 자연수 B

            int num = 1; // A와 B의 공약수

            // 공약수 구하기
            for (int j = 2; j <= A; ) {
                if (A % j == 0 && B % j == 0) {
                    num *= j;
                    A /= j;
                    B /= j;
                }
                else j++;
            }

            // 출력
            System.out.println(num * A * B);
        }
    }
}