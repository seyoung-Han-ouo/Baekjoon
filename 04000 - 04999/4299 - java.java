import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int sum = in.nextInt(); // 두 팀 점수의 합
        int sub = in.nextInt(); // 두 팀 점수의 차

        int team1 = (sum + sub) / 2; // 득점을 많이 한 쪽
        int team2 = sum - team1;

        // 두 팀의 경기 결과를 출력
        if (team1 - team2 == sub && team1 >= 0 && team2 >= 0)
            System.out.println(team1 + " " + team2);
        else
            System.out.println("-1");
    }
}