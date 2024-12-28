import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        // t = 1;
        while (t-- > 0) {
            BigInteger n = scanner.nextBigInteger();
            BigInteger ans = n % 20;
            System.out.println(ans);
        }
    }
}