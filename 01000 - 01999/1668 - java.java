import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt(); // 트로피의 개수
        int arr[] = new int[N]; // 트로피의 높이

        for (int i = 0; i < N; i++)
            arr[i] = in.nextInt();

        // 출력
        System.out.println(lookLeft(arr));
        System.out.println(lookRight(N, arr));
    }

    // 왼쪽에서 봤을 때 보이는 개수
    public static int lookLeft(int arr[]) {
        int big = 0;
        int count = 0;

        for (int n: arr) {
            if (n > big) {
                big = n;
                count++;
            }
        }

        return count;
    }

    // 오른쪽에서 봤을 때 보이는 개수
    public static int lookRight(int N, int arr[]) {
        int big = 0;
        int count = 0;

        for (int i = N - 1; i >= 0; i--) {
            if (arr[i] > big) {
                big = arr[i];
                count++;
            }
        }

        return count;
    }
}