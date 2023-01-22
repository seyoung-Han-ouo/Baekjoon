import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt(); // 수열의 길이
        int arr[] = new int[N]; // 수열의 원소

        for (int i = 0; i < N; i++)
            arr[i] = in.nextInt();

        int n1 = arr[1] - arr[0]; // 다음수가 되기 위해 바로 전의 수에 더해야 하는 수
        int n2 = arr[1] / arr[0]; // 다음수가 되기 위해 바로 전의 수에 곱해야 하는 수

        // 수열의 다음 원소를 출력
        if (n1 == (arr[2] - arr[1]))
            System.out.println(arr[N - 1] + n1);
        else
            System.out.println(arr[N - 1] * n2);
    }
}