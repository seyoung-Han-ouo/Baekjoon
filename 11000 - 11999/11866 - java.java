import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Queue queue = new Queue();

        queue.max = in.nextInt(); // 사람의 수
        int K = in.nextInt(); // 양의 정수 K

        queue.init(); // 큐 초기화
        queue.print(K); // 형식에 맞게 출력
    }
}

class Queue {
    int max;

    int front;
    int rear;
    int[] data;

    // 큐 초기화
    void init() {
        front = 0;
        rear = 0;

        data = new int[max + 1];

        for (int i = 1; i <= max; i++)
            enqueue(i);
    }

    // 큐에 데이터 입력
    void enqueue(int n) {
        data[++rear % (max + 1)] = n;
    }

    // 큐에서 데이터 삭제
    int dequeue() {
        return data[++front % (max + 1)];
    }

    // 공백 여부 확인
    Boolean isEmpty() {
        return (front == rear);
    }

    // 형식에 맞게 출력
   void print(int k) {
        System.out.print("<");
        while(true) {
            for (int i = 1; i < k; i++)
                enqueue(dequeue());

            System.out.printf("%d", dequeue());

            if (!isEmpty())
                System.out.print(", ");
            else
                break;
        }
        System.out.println(">");
    }
}