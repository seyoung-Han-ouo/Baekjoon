import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt(); // N개의 물병
        int K = in.nextInt(); // 한 번에 옮길 수 있는 물병 K개

        int shop = 0; // 구매해야 하는 물병의 수

        while (true) {
            String solo = Integer.toBinaryString(N); // N을 2진수로 변환
            int bottle = 0; // 물병의 수
            int idx = -1;

            // 현재 옮겨야하는 물병의 수
            for (int i = 0; i < solo.length(); i++)
                if (solo.charAt(i) == '1') {
                    bottle++;

                    if (idx == -1) idx = i;
                }

            // 상점에서 사야하는 물병의 최솟값 찾기
            if (bottle <= K) break;
            else {
                N += ((int)Math.pow(2, idx));
                shop += ((int)Math.pow(2, idx));
            }
        }

        // 출력
        System.out.println(shop);
    }
}