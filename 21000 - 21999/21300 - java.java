import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int sum = 0; // 환급 보증금의 값

        for (int i = 0; i < 6; i++) {
            int n = in.nextInt();
            sum += n * 5;
        }

        System.out.println(sum);
    }
}