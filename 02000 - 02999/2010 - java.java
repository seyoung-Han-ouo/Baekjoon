import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt(); // 멀티탭의 개수
        int count = 1; // 연결될 수 있는 컴퓨터의 수

        for (int i = 0; i < N; i++) {
            int plug = in.nextInt(); // 플러그를 꽂을 수 있는 수

            count += (plug - 1);
        }

        // 출력
        System.out.println(count);
    }
}