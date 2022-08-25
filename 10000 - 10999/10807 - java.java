import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt(); // 정수의 개수 N
        int arr[] = new int[101];

        for (int i = 0; i < N; i++)
            arr[i] = in.nextInt();

        int V = in.nextInt(); // 찾으려고 하는 정수 v

        int count = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] == V) count++;
        }

        // 출력
        System.out.println(count);
    }
}