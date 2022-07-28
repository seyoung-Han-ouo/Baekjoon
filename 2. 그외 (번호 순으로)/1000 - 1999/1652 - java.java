import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt(); // 방의 크기 N
        String[] room = new String[101];

        // 입력
        for (int i = 0; i < N; i++)
            room[i] = in.next();

        int garo = garoSero(N, room, false); // 가로로 누울 수 있는 자리의 개수
        int sero = garoSero(N, room, true); // 세로로 누울 수 있는 자리의 개수

        // 출력
        System.out.println(garo + " " + sero);
    }

    // 누울 수 있는 자리의 개수
    public static int garoSero(int N, String[] room, boolean isSero) {
        int num = 0;

        for (int i = 0; i < N; i++) {
            int count = 0; // 연속해서 비어있는 칸

            for (int j = 0; j < N; j++) {
                char c = room[i].charAt(j);

                if (isSero) // 세로칸을 탐색할 때
                    c = room[j].charAt(i);

                // 해당 칸이 비어있는가?
                if (c == '.') count++;
                else if (c == 'X') {
                    // 2칸 이상의 빈칸이 존재할 때
                    if (count >= 2) num++;

                    count = 0;
                }
            }

            // 2칸 이상의 빈칸이 존재할 때
            if (count >= 2) num++;
        }

        return num;
    }
}