import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String s = in.next();

        for (int i = 0; i < s.length(); i++)
            System.out.printf(s.charAt(s.length() - 1 - i) + "");
    }
}