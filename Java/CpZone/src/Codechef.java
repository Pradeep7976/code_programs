//import java.util.*;
//
//class Codechef {
//    public static void main(String[] args) {
//        int t;
//        Scanner sc = new Scanner(System.in);
//        t = sc.nextInt();
//        while (t-- > 0) {
//            int a, b;
//            a = sc.nextInt();
//            b = sc.nextInt();
//            int ans = 0;
//            while (a != b) {
//                if (a > b) {
//                    int c = Math.ceilDiv(a, 2);
//                    a = a - c;
//                    ans += c;
//                } else {
//                    int c = Math.ceilDiv(b, 2);
//                    b = b - c;
//                    ans += c;
//                }
//            }
//            System.out.println(ans);
//        }
//    }
//}
