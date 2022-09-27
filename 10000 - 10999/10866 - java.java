import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Deque<Integer> deque = new ArrayDeque<>();

        int N = Integer.parseInt(br.readLine()); // 명령의 수

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            String s = st.nextToken(); // 명령
            int x = 0;

            switch (s) {
                case "push_front": // 정수 X를 덱의 앞에 넣는다
                    x = Integer.parseInt(st.nextToken());
                    deque.addFirst(x);

                    break;
                case "push_back": // 정수 X를 덱의 뒤에 넣는다
                    x = Integer.parseInt(st.nextToken());
                    deque.addLast(x);

                    break;
                case "pop_front": // 덱의 가장 앞에 있는 수를 뺀다
                    if (deque.size() == 0) x = -1;
                    else x = deque.removeFirst();

                    break;
                case "pop_back": // 덱의 가장 뒤에 있는 수를 뺀다
                    if (deque.size() == 0) x = -1;
                    else x = deque.removeLast();

                    break;
                case "size": // 덱에 들어있는 정수의 개수
                    x = deque.size();

                    break;
                case "empty": // 덱이 비어있는가
                    if (deque.size() == 0) x = 1;
                    else x = 0;

                    break;
                case "front": // 덱의 가장 앞에 있는 정수
                    if (deque.size() == 0) x = -1;
                    else x = deque.getFirst();

                    break;
                case "back": // 덱의 가장 뒤에 있는 정수
                    if (deque.size() == 0) x = -1;
                    else x = deque.getLast();

                    break;
            }

            // 출력
            if (!s.equals("push_front") && !s.equals("push_back"))
                System.out.println(x);
        }
    }
}