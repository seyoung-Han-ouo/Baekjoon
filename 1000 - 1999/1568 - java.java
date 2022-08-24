import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt(); // N 마리의 새
        int sec = 0; // 모든 새가 날아가기까지 걸리는 시간
        int num = 1; // 지금 불러야 하는 수

        while(N != 0) {
            // 현재 나무에 앉아있는 새의 수가 지금 불러야 하는 수 보다 작을 때
            if (N < num) num = 1;

            sec++;
            N -= num++;
        }

        // 출력
        System.out.println(sec);
    }
}