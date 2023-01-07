import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt(); // 줄의 수
        String s[] = new String[N]; // 각 줄의 내용

        s[0] = in.nextLine(); // 공백 제거
        for (int i = 0; i < N; i++)
            s[i] = in.nextLine();

        // 각 문장의 앞에 줄 번호를 추가한 뒤 출력
        for (int i = 0; i < N; i++) {
            System.out.printf("%d. ", i + 1);
            System.out.println(s[i]);
        }
    }
}