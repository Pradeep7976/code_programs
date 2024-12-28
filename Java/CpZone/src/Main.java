import java.util.PriorityQueue;
import java.util.Queue;

public class Main {
    public static long pickGifts(int[] gifts, int k) {
        Queue<Integer> queue = new PriorityQueue<>((a, b) -> b - a);
        for (int gift : gifts) {
            queue.add(gift);
        }
        for (int i = 0; i < k; i++) {
            int n = queue.poll();
            queue.add((int) Math.floor(Math.sqrt(n)));
        }
        long ans = 0;
        while (!queue.isEmpty()) {
            ans += queue.poll();
        }
        return ans;
    }

    public static void main(String[] args) {
        int arr[] = { 25, 64, 9, 4, 100 };
        System.out.println(pickGifts(arr, 4));
    }
}