import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String day[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"}; // 요일
        int monthDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 각 달의 마지막 날

        int x = in.nextInt(); // x월
        int y = in.nextInt(); // y일

        int dayCount = y; // x월 y일이 1월 1일부터 며칠 뒤인가?
        for (int i = 0; i < x - 1; i++)
            dayCount += monthDay[i];

        // 출력
        System.out.println(day[dayCount % 7]);
    }
}