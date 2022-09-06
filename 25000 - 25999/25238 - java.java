import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int a = in.nextInt(); // 몬스터의 방어율 수치
        int b = in.nextInt(); // 유저의 방무

        if (a * (100 - b) < 10000)
            System.out.println("1");
        else
            System.out.println("0");
    }
}