import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int R1 = in.nextInt();
        int S = in.nextInt(); // 두 수의 평균

        // R2 출력
        System.out.println(S * 2 - R1);
    }
}