import java.util.Scanner;

public class Main {
    public static void main(String[] args)  {
        Scanner in = new Scanner(System.in);

        long N = in.nextLong();
        long sum = 0;

        // N으로 나누었을 때 나머지와 몫이 같은 모든 자연수 찾기
        for (int i = 1; i < N; i++)
            sum += (i * N + i);

        // 출력
        System.out.println(sum);
    }
}