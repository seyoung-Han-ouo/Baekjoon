import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt();

        for (int i = 0; i < N; i++){
            String num = in.next();

            // 비밀번호는 6자리 이상 9자리 이하
            if (num.length() >= 6 & num.length() <= 9)
                System.out.println("yes");
            else
                System.out.println("no");
        }
    }
}