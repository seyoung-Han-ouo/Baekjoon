import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        BigInteger P = new BigInteger(in.next()); // 두 소수의 곱으로 이루어진 암호
        int K = in.nextInt(); // 두 소수의 크기 제한
        boolean check[] = new boolean[K + 1];

        int prim; // 소수
        boolean bad = false; // K보다 작은 소수로 P가 나누어 떨어지는가?

        // 소수를 찾고, 그 소수로 P를 나눠본다.
        for (prim = 2; prim < K; prim++) {
            if (check[prim]) continue;

            // prim으로 암호가 나누어지는 지 확인
            BigInteger num = new BigInteger(prim + "");
            bad = (P.mod(num).compareTo(BigInteger.ZERO) == 0);

            if (bad) break;

            // 소수가 아닌 것들을 지운다.
            for (int i = prim * 2; i < K; i += prim)
                check[i] = true;
        }

        // 출력
        if (bad)
            System.out.printf("BAD %d\n", prim);
        else
            System.out.println("GOOD");
    }
}