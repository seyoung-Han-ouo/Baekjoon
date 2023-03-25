import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static int[][] arr; // 간선이 연결하는 두 정점의 번호
    static Boolean[] check; // 방문 체크

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] s = br.readLine().split(" ");
        int N = Integer.parseInt(s[0]); // 정점의 개수
        int M = Integer.parseInt(s[1]); // 간선의 개수
        int V = Integer.parseInt(s[2]); // 탐색을 시작할 정점의 번호

        arr = new int[N + 1][N + 1];
        check = new Boolean[N + 1];

        // 간선이 연결하는 두 정점의 번호 입력 받기
        for (int i = 0; i < M; i++) {
            String[] ss = br.readLine().split(" ");
            int a = Integer.parseInt(ss[0]);
            int b = Integer.parseInt(ss[1]);

            arr[a][b] = 1;
            arr[b][a] = 1;
        }

        // DFS를 수행한 결과 출력
        Arrays.fill(check, false);
        DFS(V, N);
        System.out.println();

        // BFS를 수행한 결과 출력
        Arrays.fill(check, false);
        BFS(V, N);
        System.out.println();

        br.close();
    }

    // 깊이우선탐색
    public static void DFS(int start, int N) {
        check[start] = true; // 방문 체크
        System.out.printf("%d ", start);

        // 다음 노드 방문
        for (int i = 1; i <= N; i++)
            if(arr[start][i] == 1 && !check[i]) DFS(i, N);
    }

    // 너비우선탐색
    public static void BFS(int start, int N) {
        Queue<Integer> q = new LinkedList<Integer>();

        q.add(start);
        check[start] = true; // 방문 체크

        while(!q.isEmpty()) {
            start = q.poll();
            System.out.printf("%d ", start);

            for (int i = 1; i <= N; i++) {
                if(arr[start][i] == 1 && !check[i]) {
                    q.add(i);
                    check[i] = true; // 방문 체크
                }
            }
        }

        q.clear();
    }
}