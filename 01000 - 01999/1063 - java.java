import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String k = in.next();
        String d = in.next();

        int N = in.nextInt(); // 움직이는 횟수 N

        int[] king = {k.charAt(0) - 'A', k.charAt(1) - '1' + 1}; // 킹의 위치
        int[] doll = {d.charAt(0) - 'A', d.charAt(1) - '1' + 1}; // 돌의 위치

        for (int i = 0; i < N ; i++) {
            String s = in.next();

            move(s, king, doll);
        }

        print(king); // 킹의 마지막 위치 출력
        print(doll); // 돌의 마지막 위치 출력
    }

    public static void move(String s, int[] king, int[] doll) {
        String[] RLBT = {"R", "L", "B", "T", "RT", "LT", "RB", "LB"};
        int[][] m = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

        int garo = 0, sero = 0;

        // 가로/세로로 어느 정도 움직여야 하는지 찾는다.
        for (int i = 0; i < 8; i++) {
            if (RLBT[i].equals(s)) {
                garo = m[i][0];
                sero = m[i][1];

                break;
            }
        }

        int kGaro = king[0] + garo;
        int kSero = king[1] + sero;

        // 킹이 움직이고서도 체스판 위에 있을 때
        if ((kGaro >= 0 && kGaro < 8) && (kSero > 0 && kSero <= 8)) {
            // 킹이 움직이는 위치에 돌이 있을 때
            if (kGaro == doll[0] && kSero == doll[1]) {
                int dGaro = doll[0] + garo;
                int dSero = doll[1] + sero;

                // 돌이 움직이고서도 체스판 위에 있을 때
                if ((dGaro >= 0 && dGaro < 8) && (dSero > 0 && dSero <= 8)) {
                    king[0] = kGaro;
                    king[1] = kSero;

                    doll[0] = dGaro;
                    doll[1] = dSero;
                }
            }
            else {
                king[0] = kGaro;
                king[1] = kSero;
            }
        }
    }

    // 출력
    public static void print(int[] arr) {
        System.out.print((char)(arr[0] + 'A'));
        System.out.println(arr[1]);
    }
}