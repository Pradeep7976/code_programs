//import java.util.Arrays;
//
//public class Interview {
//    static int maxProfit(int arr[]) {
//        int n = arr.length;
//        int profit = 0;
//        int maxind = arr[n - 1];
//        for (int i = n - 1; i >= 0; i--) {
//            int currProfit = maxind - arr[i];
//            profit = Math.max(currProfit, profit);
//            maxind = Math.max(maxind, arr[i]);
//        }
//        return profit;
//    }
//
//    //[10, 9, 2, 5, 3, 7, 101, 18]
//    static int maxSubseques(int[] arr) {
//        if (arr.length == 0)
//            return 0;
//        int[] dp = new int[arr.length];
//        int lenth = 0;
//        for (int num : arr) {
//            int index = Arrays.binarySearch(dp, 0, lenth, num);
//
//            if (index < 0) {
//                index = -(index + 1);
//            }
//            dp[index] = num;
//            if (index == lenth) {
//                lenth++;
//            }
//        }
//        return lenth;
//    }
//
//    public static void main(String[] args) {
//        int arr[] = {0, 1, 0, 3, 2, 3};
//        System.out.println(maxSubseques(arr));
//    }
//}
