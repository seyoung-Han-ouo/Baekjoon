import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // 원숭이가 생각한 두 개의 자연수
        int num1 = in.nextInt();
        int num2 = in.nextInt();

        int garo = findGaro(num2) - findGaro(num1); // 동서방향거리
        int sero = findSero(num2) - findSero(num1); // 남북방향거리

        // 음수를 양수로 바꾸기
        if (garo < 0) garo *= -1;
        if (sero < 0) sero *= -1;

        // 출력
        System.out.println(garo + sero);
    }

    public static int findGaro(int n) {
        int garo = n / 4;

        // 4로 나누어 떨어지지 않는 수는 위에서 계산한 수에 1을 더한 칸에 위치한다.
        if (n % 4 != 0)
            garo++;

        return garo;
    }

    public static int findSero(int n) {
        int sero = n % 4;

        // 4로 나누어 떨어지는 수는 위에서 4번째 칸에 위치한다.
        if (sero == 0)
            sero = 4;

        return sero;
    }
}