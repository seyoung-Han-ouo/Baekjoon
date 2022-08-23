import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt(); // n개의 스코어 라운드

        System.out.println((n + 1) * 2 + " " + (n + 1) * 3);
    }
}