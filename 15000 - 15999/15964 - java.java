import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        BigInteger A = new BigInteger(in.next());
        BigInteger B = new BigInteger(in.next());

        // A＠B = (A+B)×(A-B) = A^2 - B^2
        A = A.multiply(A);
        B = B.multiply(B);

        System.out.println(A.subtract(B));
    }
}