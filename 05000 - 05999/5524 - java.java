import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt(); // 줄의 수
        String s[] = new String[N]; // 각 줄의 내용

        s[0] = in.nextLine(); // 공백 제거
        for (int i = 0; i < N; i++)
            s[i] = in.nextLine();

        // 입실자의 이름을 소문자로 출력
        for (int i = 0; i < N; i++)
            System.out.println(s[i].toLowerCase());
    }
}