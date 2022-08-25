import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        BigInteger sum = new BigInteger("0"); // 합

        for (int i = 0; i < 3; i++) {
            String s = in.next(); // 숫자 입력

            sum = sum.add(new BigInteger(s));
        }

        // 출력
        System.out.println(sum);
    }
}