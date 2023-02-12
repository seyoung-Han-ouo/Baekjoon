import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int bus = 0; // 현재 승객의 수
        int big = 0; // 기차에 사람이 가장 많을 때의 사람 수

        for (int i = 0; i < 4; i++) {
            int a = in.nextInt();
            int b = in.nextInt();

            bus = bus - a + b;

            // 기차에 사람이 가장 많을 때
            if (bus > big) big = bus;
        }

        // 최대 사람 수를 출력
        System.out.println(big);
    }
}