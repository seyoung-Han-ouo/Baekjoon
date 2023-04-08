import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine()); // 입력의 크기

        System.out.println(MenOfPassion(n) + "\n1");
    }

    //  코드1의 수행 횟수
    public static int MenOfPassion(int n) {
        int count = 0;
        for (int i = 0; i < n; i++) count++; // 코드1

        return count;
    }
}