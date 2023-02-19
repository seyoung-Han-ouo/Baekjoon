import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt();

        System.out.println("int a;");
        System.out.println("int *ptr = &a;");

        for (int i = 2; i <= N; i++) {
            System.out.printf("int ");

            for (int j = 0; j < i; j++)
                System.out.print("*");

            if (i == 2)
                System.out.printf("ptr%d = &ptr;", i);
            else
                System.out.printf("ptr%d = &ptr%d;", i, i - 1);

            System.out.println();
        }
    }
}