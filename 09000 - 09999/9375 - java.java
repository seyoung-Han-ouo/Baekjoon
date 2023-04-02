import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine()); // 테스트 케이스

        for (int i = 0; i < t; i++) {
            Map<String, Integer> clothes = new HashMap<String, Integer>();
            int n = Integer.parseInt(br.readLine()); // 해빈이가 가진 의상의 수

            // 해빈이가 가진 의상을 종류별로 몇 개 있는지 map에 저장
            for (int j = 0; j < n; j++) {
                String[] s  = br.readLine().split(" ");

                if(!clothes.containsKey(s[1]))
                    clothes.put(s[1], 1);
                else
                    clothes.put(s[1], clothes.get(s[1]) + 1);
            }

            int cnt = 1; // 의상을 입을 수 있는 경우의 수 구하기
            Set<String> keySet = clothes.keySet();

            for (String key : keySet) cnt *= (clothes.get(key) + 1);

            // 출력
            System.out.println(cnt - 1);
        }
    }
}