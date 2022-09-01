import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt();

        System.out.println((N / 100 * 78) + " " + (N - (N / 100 * 20) / 100 * 22));
    }
}