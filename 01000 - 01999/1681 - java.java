import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt(); // N명의 학생들
        int L = in.nextInt(); // 사용하지 않는 수

        int count = 0; // 라벨이 붙은 학생의 수
        int i; // 현재 라벨의 번호

        for (i = 1; ; i++) {
            boolean notWant = false; // 학생들이 해당 숫자를 원하는가?

            // 숫자 검사
            for (int j = i; j > 0; j /= 10) {
                if (j % 10 == L) {
                    notWant = true;
                    break;
                }
            }

            if (!notWant) count++;

            if (count == N) break;
        }

        // 출력
        System.out.println(i);
    }
}