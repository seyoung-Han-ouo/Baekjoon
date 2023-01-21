import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String s = in.nextLine(); // 평문
        String code = in.next(); // 암호화 키

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ')
                System.out.printf(" ");
            else {
                // 변형된 문자의 순서
                int n = s.charAt(i) - code.charAt(i % code.length()) - 1;

                if (n < 0) n += 26; // 변형된 문자가 a 이전의 문자일 경우

                System.out.printf((char)(n % 26 + 'a') + "");
            }
        }
    }
}