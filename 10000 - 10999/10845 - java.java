import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st;
        queue queue = new queue();

        int N = Integer.parseInt(br.readLine()); // 명령의 수

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            String s = st.nextToken();
            int num = 0;

            switch (s) { // 명령 수행
                case "push":
                    num = Integer.parseInt(st.nextToken());
                    queue.push(num);
                    break;
                case "pop":
                    num = queue.pop();
                    break;
                case "size":
                    num = queue.size();
                    break;
                case "empty":
                    num = queue.empty();
                    break;
                case "front":
                    num = queue.front();
                    break;
                case "back":
                    num = queue.back();
                    break;
            }

            // 출력
            if (!s.equals("push"))
                System.out.println(num);
        }
    }
}

class queue {
    int f = -1; // 큐의 가장 앞
    int b = -1; // 큐의 가장 뒤
    int[] element = new int[10001];

    // 정수 X를 큐에 넣는 연산
    public void push(int x) {
        element[++b] = x;
    }

    // 큐에서 가장 앞에 있는 정수를 뺀다.
    public int pop() {
        if(empty() == 1)
            return -1;
        else
            return element[++f];
    }

    // 큐에 들어있는 정수의 개수
    public int size() {
        return b - f;
    }

    // 큐가 비어있으면 1, 아니면 0
    public int empty() {
        if (b <= f || b == -1)
            return 1;
        else
             return 0;
    }

    // 큐의 가장 앞에 있는 정수
    public int front() {
        if (empty() == 1)
            return -1;
        else
            return element[f + 1];
    }

    // 큐의 가장 뒤에 있는 정수
    public int back() {
        if(empty() == 1)
            return -1;
        else
            return element[b];
    }
}