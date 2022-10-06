import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Stack stack = new Stack();

        int n = in.nextInt();
        int j = 1;
        boolean isNo = false; // 불가능 여부

        for (int i = 0; i < n; i++) {
            int num = in.nextInt();

            // num이 스택에 포함될 때까지 push
            if (stack.peek() < num) {
                int m = 0;
                for (; j <= num; j++) {
                    stack.push(j);
                    m++;
                }

                stack.pop();
                stack.arrSet(i, true, m + 1);
            }
            // 가장 위에 있는 숫자기 num과 같을 때
            else if (stack.peek() == num) {
                stack.pop();
                stack.arrSet(i, false, 1);
            }
            else {
                isNo = true;
                break;
            }
        }

        // 출력력
        if(isNo)
            System.out.println("NO");
        else {
            for (int i = 0; i < n; i++)
                stack.print(i);
        }
    }
}

class Stack {
    private int top = -1;
    private int[] data = new int[100001];
    public int[] count = new int[100001];
    public boolean[] isPlus = new boolean[100001];

    // 삽입 함수
    public void push(int n) {
        data[++top] = n;
    }

    // 삭제 함수
    public int pop() {
        if (isEmpty())
            return 0;
        else
            return data[top--];
    }

    // 스택이 비어있는지 확인
    public boolean isEmpty() {
        return top == -1;
    }

    // 맨 위의 데이터 가져오기
    public int peek() {
        if (isEmpty())
            return 0;
        else
            return data[top];
    }

    // 배열에 값 입력
    public void arrSet(int i, boolean b, int n) {
        isPlus[i] = b;
        count[i] = n;
    }

    // 출력
    public void print(int num) {
        for (int i = 0; i < count[num]; i++) {
            if (isPlus[num] && i != count[num] - 1)
                System.out.println("+");
            else
                System.out.println("-");
        }
    }
}