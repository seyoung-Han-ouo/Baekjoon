import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int K = in.nextInt(); // 열의 개수
        String s = in.next(); // 암호화 된 문자열

        char arr[][] = new char[s.length() / K + 1][K]; // K개의 열을 가진 문자표

        // 문자표에 문자열 채우기
        for (int i = 0; i < s.length() ; i++) {
            int idx1 = i / K;
            int idx2 = i % K;

            // 문자열은 왼쪽 → 오른쪽, 오른쪽 → 왼쪽로 읽은 결과이기에
            if (idx1 % 2 == 1)
                idx2 = K - 1 - idx2;

            arr[idx1][idx2] = s.charAt(i);
        }

        // 출력
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < s.length() / K; j++)
                System.out.print(arr[j][i]);
        }
    }
}