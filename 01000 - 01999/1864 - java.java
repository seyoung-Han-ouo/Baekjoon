import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 문어가 쓰는 숫자와 그를 표현하는 잔물결 무늬
        Map<Character, Integer> arr = Map.of(
                '-', 0,
                '\\', 1,
                '(', 2,
                '@', 3,
                '?', 4,
                '>', 5,
                '&', 6,
                '%', 7,
                '/', -1
        );

        while (true) {
            String s = br.readLine(); // 문어 숫자
            int num = 0; // 문어 숫자에 대응하는 십진수

            // '#'이 들어오면 입력을 종료
            if (s.equals("#")) break;

            // 입력 받은 문어 숫자를 십진수로
            for (int i = 0; i < s.length(); i++)
                num += (arr.get(s.charAt(i)) * Math.pow(8, s.length() - i - 1));

            // 출력
            System.out.println(num);
        }
    }
}