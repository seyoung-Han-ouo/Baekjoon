import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        BigInteger apple = new BigInteger(in.next()); // 총 사과의 수
        BigInteger klaudia = new BigInteger(in.next()); // Klaudia가 더 가진 사과의 수

        // Natalia의 사과의 수
        BigInteger natalia = apple.subtract(klaudia).divide(new BigInteger("2"));

        // 출력
        System.out.println(natalia.add(klaudia) + "\n" + natalia);
    }
}