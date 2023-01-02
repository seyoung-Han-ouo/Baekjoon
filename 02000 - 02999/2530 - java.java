import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int A = in.nextInt(); // 시
        int B = in.nextInt(); // 분
        int C = in.nextInt(); // 초
        int D = in.nextInt(); // 요리하는 데 필요한 시간

        time(A, B, C, D);
    }

    // 오븐구이가 끝나는 시간을 계산한다.
    public static void time(int A, int B, int C, int D) {
        C += (A * 3600) + (B * 60) + D;

        // 디지털 시계는 23시 59분 59초에서 1초가 지나면 0시 0분 0초가 된다.
        while (C >= 24 * 3600)
            C -= 24 * 3600;

        // 시, 분, 초 구하기
        A = C / 3600;
        B = (C - (A * 3600)) / 60;
        C = C % 60;

        // 종료되는 시각의 시, 분, 초을 공백을 사이에 두고 출력
        System.out.println(A + " " + B + " " + C);
    }
}
