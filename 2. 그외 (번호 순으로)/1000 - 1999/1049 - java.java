import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt(); // 끊어진 기타줄의 개수 N
        int M = in.nextInt(); // 기타줄 브랜드 M개

        int pack = 1000; // 가장 싼 6줄 패키지 가격
        int one = 1000; // 가장 싼 낱개 가격

        for (int i = 0; i < M; i++) {
            int p = in.nextInt(); // 패키지 가격
            int o = in.nextInt(); // 낱개의 가격

            // 가장 싼 제품의 가격 찾기
            if (p < pack) pack = p;
            if (o < one) one = o;
        }

        // 출력
        System.out.println(needMoney(pack, one, N));
    }

    // 기타줄을 적어도 N개 사기 위해 필요한 돈의 최솟값찾기
    public static int needMoney(int pack, int one, int N) {
        int sum = 0;

        // 6개를 구매할 때
        if (N / 6 > 0) {
            if (pack < one * 6)
                sum += pack * (N / 6);
            else
                sum += ((one * 6) * (N / 6));
        }

        // 6개 미만을 구매할 때
        if (N % 6 != 0) {
            if (pack < one * (N % 6))
                sum += pack;
            else
                sum += (one * (N % 6));
        }

        return sum;
    }
}