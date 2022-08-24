import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n1 = in.nextInt(); // 열 수
        int k1 = in.nextInt(); // 열 당 좌석의 수

        int n2 = in.nextInt();
        int k2 = in.nextInt();

        System.out.println(n1 * k1 + n2 * k2);
    }
}