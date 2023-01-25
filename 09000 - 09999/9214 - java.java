import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int count = 1; // 테스트 케이스 번호

        while (true) {
            String n = in.next(); // 최대 100글자의 정수 n

            // 입력의 끝은 0
            if (n.equals("0")) break;

            // n의 첫 번째 항 알아내기
            while (true) {
                StringBuilder sb = new StringBuilder();

                // 정수의 길이가 홀수인 경우 이전 항이 존재하지 않는다.
                if (n.length() % 2 == 1) break;

                // 이전 항 알아내기
                for (int i = 0; i < n.length(); i += 2) {
                    int idx = Integer.parseInt(n.charAt(i) + "");

                    for (int j = 0; j < idx; j++)
                        sb.append(n.charAt(i + 1));
                }

                // 첫 번째 항을 찾음
                if (n.equals(sb.toString())) break;

                n = sb.toString();
            }

            // 출력
            System.out.println("Test " + count++ + ": " + n);
        }
    }
}