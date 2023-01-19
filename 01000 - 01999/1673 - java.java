import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        while (in.hasNextInt()) {
            int n = in.nextInt(); // 치킨 한 마리를 주문할 수 있는 치킨 쿠폰의 수
            int k = in.nextInt(); // 도장을 k개 모으면 치킨 쿠폰 한 장

            int count = 0; // 치킨의 수
            int stamp = 0; // 도장의 수

            while (true) {
                count += n;
                stamp += n;

                n = stamp / k;
                stamp %= k;

                if (n == 0) break;
            }

            // 출력
            System.out.println(count);
        }
    }
}