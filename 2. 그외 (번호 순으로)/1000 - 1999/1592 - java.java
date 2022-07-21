import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt(); // 사람 수
        int M = in.nextInt(); // 어느 한 사람이 받아야하는 공의 횟수
        int L = in.nextInt(); // 공의 현재 위치에서 L번째 있는 사람

        // 각각 공을 받은 횟수
        int[] people = new int[N];
        for (int i = 0; i < N; i++)
            people[i] = 0;

        int num = 0; // 현재 공을 가지고 있는 사람
        int count = 0; // 공을 던진 횟수

        while (true) {
            people[num]++;

            // 한 사람이 공을 M번 받았으면 게임은 끝
            if (people[num] >= M) break;

            // 현재 공을 받은 횟수가 홀수번 : 현재 위치에서 시계 방향으로 L번째
            // 현재 공을 받은 횟수가 짝수번 : 현재 위치에서 반시계 방향으로 L번째
            if (people[num] % 2 == 0)
                num = (num + L) % N;
            else if (people[num] % 2 == 1)
                num = (num - L + N) % N;

            count++;
        }

        System.out.println(count);
    }
}