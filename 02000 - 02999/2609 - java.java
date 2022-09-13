import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int num1 = in.nextInt();
        int num2 = in.nextInt();

        int i = 2;
        int multi = 1;

        // 최대공약수 구하기
        while(true) {
            if (num1 < i || num2 < i) break;

            if (num1 % i == 0 && num2 % i == 0) {
                num1 /= i;
                num2 /= i;
                multi *= i;
            }
            else i++;
        }

        // 출력
        System.out.println(multi);
        System.out.println(multi * num1 * num2);
    }
}