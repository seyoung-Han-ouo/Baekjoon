import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int M = 1234567891;

        int L = in.nextInt(); // 문자열의 길이
        String s = in.next(); // 영문 소문자로만 이루어진 문자열

        long r = 1;
        long hash = 0;

        for (int i = 0; i < L; i++) {
            long num = (s.charAt(i) - 'a' + 1) * r % M;

            hash = (hash + num) % M;

            r *= 31;
            r %= M;
        }

        // 출력
        System.out.println(hash % M);
    }
}