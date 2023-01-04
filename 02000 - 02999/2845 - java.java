import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int L = in.nextInt(); // 1m^2당 사람의 수
        int P = in.nextInt(); // 파티가 열렸던 곳의 넓이
        int arr[] = new int[5]; // 각 기사에 실려있는 참가자의 수

        // 입력
        for (int i = 0; i < 5; i++)
            arr[i] = in.nextInt();

        // 출력
        for (int i = 0; i < 5; i++)
            System.out.printf("%d ", arr[i] - (L * P));
    }
}