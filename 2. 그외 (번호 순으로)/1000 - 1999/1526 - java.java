import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String N = in.next(); // 입력

        int idx = N.length() - 1; // 숫자의 길이
        int result = 0; // 결과

        // N보다 작거나 같은 금민수 중 가장 큰 것 찾기
        for (int i = 0; i <= idx; i++) {
            int num1 = 7;
            int num2 = 4;

            for (int j = i; j < idx; j++) {
                num1 *= 10;
                num2 *= 10;
            }

            result += num1;

            // 현재 구하고 있는 자릿수에 4를 넣을지 7을 넣을 지 결정한다.
            if (result > Integer.parseInt(N)) {
                result -= num1 - num2;

                // 해당 자리에 4를 넣어도 N보다 큰 수가 만들어질 때
                if (result > Integer.parseInt(N)) {
                    result -= num2;

                    if (i != 0) {
                        result += num1;

                        if (result / (num1 * 10 / 7) == 4)
                            result %= (num1 * 10 / 7);
                        else
                            result -= (num1 - num2) * 10;
                    }
                }
            }
        }

        // 출력
        System.out.println(result);
    }
}