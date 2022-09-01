import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int m = in.nextInt();

        BigInteger A = new BigInteger(in.next());
        BigInteger B = new BigInteger(in.next());

        System.out.println(A.multiply(B));
    }
}