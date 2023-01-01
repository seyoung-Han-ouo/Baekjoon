import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        while(true) {
            String s = in.nextLine(); // 한 줄씩 입력 받기
            String member[] = s.split(" "); // 입력 받은 값 쪼개기

            // # 0 0 입력 시 종료
            if (s.equals("# 0 0")) break;

            // 이름과 분류를 출력
            if (Integer.parseInt(member[1]) > 17 || Integer.parseInt(member[2]) >= 80)
                System.out.println(member[0] + " Senior");
            else
                System.out.println(member[0] + " Junior");
        }
    }
}
