import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int arr[] = new int[3];

        for (int i = 0; i < 3; i++)
            arr[i] = in.nextInt();

        sort(arr);
    }

    // 오름차순으로 정렬
    public static void sort(int arr[]) {
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 3; j++) {
                if (arr[i] > arr[j]) {
                    int num = arr[i];
                    arr[i] = arr[j];
                    arr[j] = num;
                }
            }
        }

        // 제일 작은 수, 그 다음 수, 제일 큰 수를 차례대로 출력
        for (int i = 0; i < 3; i++)
            System.out.printf("%d ", arr[i]);
    }
}