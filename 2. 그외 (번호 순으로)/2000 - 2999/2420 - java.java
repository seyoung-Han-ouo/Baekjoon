import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        long N = in.nextInt(); // 유명도 N
        long M = in.nextInt(); // 유명도 M

        // 두 유명도의 차이
        long nm = (N - M < 0) ? ((N - M) * -1) : (N - M);

        // 출력
        System.out.println(nm);
    }
}