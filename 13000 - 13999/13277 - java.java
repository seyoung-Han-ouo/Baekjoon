import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        BigInteger A = new BigInteger(in.next());
        BigInteger B = new BigInteger(in.next());

        // 두 수의 곱 출력
        System.out.println(A.multiply(B));
    }
}