import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 컴퓨터공학과의 등급에 따른 과목평점
        Map<String, Double> grade = Map.of(
                "A+", 4.5,
                "A0", 4.0,
                "B+", 3.5,
                "B0", 3.0,
                "C+", 2.5,
                "C0", 2.0,
                "D+", 1.5,
                "D0", 1.0,
                "F", 0.0
        );

        double hak = 0; // 학점의 합
        double sum = 0; // 등급의 합

        for (int i = 0; i < 20; i++) {
            String[] s = br.readLine().split(" ");
            double d = Double.parseDouble(s[1]);

            // 등급이 P인 과목은 계산에서 제외
            if (!s[2].equals("P")) {
                sum += (grade.get(s[2]) * d);
                hak += d;
            }
        }

        // 치훈이의 전공평점을 출력
        System.out.println(String.format("%.6f", sum / hak));
    }
}