import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int UR = in.nextInt();
        int TR = in.nextInt();
        int UO = in.nextInt();
        int TO = in.nextInt();

        System.out.println(56 * UR + 24 * TR + 14 * UO + 6 * TO);
    }
}