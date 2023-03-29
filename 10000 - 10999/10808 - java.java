import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String S = br.readLine();
        int[] arr = new int[26];

        Arrays.fill(arr, 0);

        for (int i = 0; i < S.length(); i++)
            arr[S.charAt(i) - 'a']++;

        // 단어에 포함되어 있는 단어의 개수를 공백으로 구분해서 출력
        for (int i = 0; i < 26; i++)
            System.out.print(arr[i] + " ");
    }
}