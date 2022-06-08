import java.util.Scanner;

public class baekjoon1408 {
    // 입력한 시간을 초로 바꾼다.
    public static int second(String s) {
        String[] array = s.split(":");

        int num = 0; // 초

        // 시간을 초 단위로 변환
        for (int i = 0; i < 3; i++) {
            int n = Integer.parseInt(array[i]);

            for (int j = i; j < 2; j++) n *= 60;

            num += n;
        }

        return num;
    }

    // 임수 수행에 남은 시간을 입력한 형태로 변환해서 출력한다.
    public static void print(int n) {
        if (n < 0) {
            int day = second("24:00:00");
            n += day;
        }

        int t = n / 3600;           // 시간
        int m = (n % 3600) / 60;    // 분
        int s = (n % 3600) % 60;    // 초

        // 출력
        System.out.printf("%02d:%02d:%02d\n", t, m, s);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String now = in.next(); // 현재 시간
        String start = in.next(); // 도현이가 임무를 시작한 시간

        int time = second(start) - second(now); // 남은 시간간

       print(time);
    }
}
