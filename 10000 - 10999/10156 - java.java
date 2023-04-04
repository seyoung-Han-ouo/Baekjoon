import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] s = br.readLine().split(" ");
        int K = Integer.parseInt(s[0]); // 과자 한 개의 가격
        int N = Integer.parseInt(s[1]); // 사려고 하는 과자의 개수
        int M = Integer.parseInt(s[2]); // 현재 동수가 가진 돈

        // 동수가 부모님께 받아야 하는 돈의 액수
        int money = (K * N - M) > 0 ? (K * N - M) : 0;

        System.out.println(money);
    }
}