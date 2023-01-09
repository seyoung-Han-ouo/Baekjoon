import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        while (true) {
            int a = in.nextInt(); // 나무의 나이
            int leaf = 1; // 나뭇잎의 수

            if (a == 0) break;

            for (int i = 0; i < a; i++) {
                int sF = in.nextInt(); // splitting factor
                int cut = in.nextInt(); // 가지치기 한 가지의 수

                leaf = leaf * sF - cut;
            }

            // 출력
            System.out.println(leaf);
        }
    }
}