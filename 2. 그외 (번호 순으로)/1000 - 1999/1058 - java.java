import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt(); // 사람의 수 N
        String friend[] = new String[N]; // 각 사람들의 친구 리스트

        // 입력
        for (int i = 0; i < N; i++)
            friend[i] = in.next();

        // 출력
        System.out.println(friendCnt(friend, N));
    }

    // 가장 유명한 사람의 2-친구의 수 찾기
    public static int friendCnt(String[] friend, int N) {
        int f = 0; // 가장 유명한 사람의 2-친구의 수

        for (int i = 0; i < N; i++) {
            boolean check[] = new boolean[N]; // 이미 세아린 친구를 또 세지 않기 위함
            check[i] = true; // 자기 자신을 미리 체크

            int num = 0; // i번째 사람의 친구의 수

            for (int j = 0; j < N; j++) {
                // 서로 친구인 경우 찾기
                if (friend[i].charAt(j) == 'Y' && !check[j]) {
                    check[j] = true;
                    num++;

                    // 한다리 건너서 친구인 사람 찾기
                    for (int k = 0; k < N; k++) {
                        // 마지막 조건은 방문해야 하는데 이미 방문처리되어 방문하지 못하게 되는 것을 막기 위해 추가
                        if (friend[j].charAt(k) == 'Y' && !check[k] && friend[i].charAt(k) != 'Y') {
                            check[k] = true;
                            num++;
                        }
                    }
                }
            }

            // 가장 유명한 사람의 친구 수 저장
            if (num > f) f = num;

            // 한 사람이 가질 수 있는 최대 친구 수는 N - 1이다.
            if (f == N - 1) break;
        }

        return f;
    }
}