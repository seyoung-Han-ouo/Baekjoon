import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt(); // 수열의 크기
        int K = in.nextInt(); // 횟수

        String s = in.nextLine(); // 엔터
        s = in.nextLine(); // 입력

        String arr[] = s.split(",");
        int nArr[] = new int[N];

        // 배열에 숫자 저장
        for (int i = 0; i < N; i++)
            nArr[i] = Integer.parseInt(arr[i]);

        // 인접한 두 원소의 차이를 이용해서 크기가 N-1인 수열 만들기
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < N - i - 1; j++) {
                nArr[j] = nArr[j + 1] - nArr[j];
            }
        }

        // 출력
        System.out.print(nArr[0]);
        for (int i = 1; i < N - K; i++)
            System.out.print("," + nArr[i]);
    }
}