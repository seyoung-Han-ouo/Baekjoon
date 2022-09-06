import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int X = in.nextInt(); // 영수증에 적힌 총 금액
        int N = in.nextInt(); // 영수증에 적힌 구매한 물건의 종류의 수

        int sum = 0;
        for (int i = 0; i < N; i++) {
            int a = in.nextInt(); // 물건의 가격
            int b = in.nextInt(); // 물건의 개수

            sum += (a * b);
        }

        if (sum == X)
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}