import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String s = in.next();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) < 'a')
                System.out.printf((char)(s.charAt(i) + 32) + ""); // 대문자 > 소문자
            else
                System.out.printf((char)(s.charAt(i) - 32) + ""); // 소문자 > 대문자
        }
    }
}