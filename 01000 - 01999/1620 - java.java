import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] s = br.readLine().split(" ");
        int N = Integer.parseInt(s[0]); // 포켓몬의 개수
        int M = Integer.parseInt(s[1]); // 문제의 개수

        Map<String, Integer> poketmon1 = new HashMap<String, Integer>(); // key : 이름
        Map<Integer, String> poketmon2 = new HashMap<Integer, String>(); // key : 번호

        for (int i = 1; i <= N; i++) {
            String name = br.readLine();
            poketmon1.put(name, i);
            poketmon2.put(i, name);
        }

        // 입력으로 숫자가 들어왔다면 포켓몬의 이름을, 문자가 들어왔으면 번호를 출력
        for (int j = 0; j < M; j++) {
            String question = br.readLine();
            boolean isNumber = Character.isDigit(question.charAt(0));

            if (isNumber)
                System.out.println(poketmon2.get(Integer.parseInt(question)));
            else
                System.out.println(poketmon1.get(question));
        }
    }
}