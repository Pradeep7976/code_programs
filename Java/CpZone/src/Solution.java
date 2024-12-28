import java.io.*;
import java.util.*;


class Solution {
    public static int solution(int[] nums) {
        Set<Integer> set = new HashSet<>();

        for (int num : nums) {
            if (num > 0) {
                set.add(num);
            }
        }
        int missing = 1;
        while (set.contains(missing)) {
            missing++;
        }

        return missing;
    }

    public static int solution1(int[] arr) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            if (mp.containsKey(arr[i])) {
                mp.put(arr[i], 0);
            } else {
                mp.put(arr[i], mp.get(arr[i]) + 1);
            }
        }
        int missing = 1;
        while (mp.containsKey(missing))
            missing++;
        return missing;
    }

    static void one(int[] arr) {
//        int o = 0;
//        boolean h = true;
//        int change1 = 0;
//        int change2 = 0;
//        for (int i = 0; i < arr.length; i++) {
//            if (h) {
//                if (arr[i] == 0) {
//                    h = false;
//                    continue;
//                }
//                change1++;
//            } else {
//                if (arr[i] == 1) {
//                    h = true;
//                    continue;
//                }
//                change1++;
//            }
//        }
//        h = false;
//        for (int i = 0; i < arr.length; i++) {
//            if (!h) {
//                if (arr[i] == 0) {
//                    h = true;
//                    continue;
//                }
//                change2++;
//            } else {
//                if (arr[i] == 1) {
//                    h = false;
//                    continue;
//                }
//                change2++;
//            }
//        }
        int n = arr.length;
        int[] arr1 = new int[arr.length];
        int[] arr2 = new int[arr.length];
        int i = 0;
        boolean h = true;
        while (i != n) {
            if (h) {
                arr1[i] = 1;
                arr2[i] = 0;
                h = false;
            } else {
                arr1[i] = 0;
                arr2[i] = 1;
                h = true;
            }
            i++;
        }
        int ans1 = 0;
        int ans2 = 0;
        for (i = 0; i < n; i++) {
            if (arr1[i] != arr[i])
                ans1++;
            else if (arr2[i] != arr[i])
                ans2++;
        }
        System.out.println(Math.min(ans1, ans2));
    }

    static int subarray(int[] arr, int n) {
//        int ans = Integer.MIN_VALUE;
//        for (int i = 0; i < n; i++) {
//            for (int j = i; j < n; j++) {
//                int sum = 0;
//                for (int k = i; k <= j; k++) {
//                    sum += arr[k];
//                }
//                ans = Math.max(ans, sum);
//            }
//        }
        int ans = Integer.MIN_VALUE;
        List<Integer> list = new ArrayList<>();
        List<Integer> anslist = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int sum = Integer.MIN_VALUE;
            sum = sum + arr[i];
            if (ans < sum)
                ans = sum;
            if (sum < 0)
                sum = 0;

        }
        if (ans < 0)
            return 0;
        return ans;
//        System.out.println(anslist);
//        return ans;
    }

    public static int maxSubarraySum(int[] arr, int n) {
        int maxi = Integer.MIN_VALUE; // maximum sum

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += arr[k];
                }

                maxi = Math.max(maxi, sum);
            }
        }

        return maxi;
    }

    public List<Integer> sort012(List<Integer> list) {
        int zero = 0;
        int one = 0;
        int two = 0;
        for (int i = 0; i < list.size(); i++) {
            int ele = list.get(i);
            if (ele == 0) {
                Collections.swap(list, zero, i);
                zero++;
            } else if (ele == 1) {
                if (one == 0) {
                    one = i;
                }
                one++;
                Collections.swap(list, two, i);
            } else {
                if (two == 0) {
                    two = i;
                }

            }
        }
        return list;
    }

    public static List<Integer> sort(List<Integer> l1, List<Integer> l2) {
        int i = 0;
        int j = 0;
        while (i < l1.size() && j < l2.size()) {
            if (l1.get(i) > l2.get(j)) {
                l1.add(i, l2.get(j));
                l2.remove(l2.get(j));
            }
            i++;
        }
        if (l2.size() != 0) {
            l1.addAll(l2);
        }
        return l1;
    }

    static void subarray2(int[][] arr) {

    }

    public void writeFile(String fileName) {
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter("G:\\Code Programs\\Java\\CpZone\\src\\one.txt"));
            List<String> string = List.of("one", "two", "three");
            writer.write(String.join(",", string));
            String s = "onosdfnosndofnsdf";
            System.out.println(s.substring(1));
            writer.close();
        } catch (Exception e) {
            System.out.println("error reading file");
            System.out.println("Reason: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int n = 97;
        char c = (char) n;
        System.out.println(c);
    }

    private void readFile(String fileName) {

        try {
            BufferedReader reader = new BufferedReader(new FileReader("G:\\Code Programs\\Java\\CpZone\\src\\one.txt"));
            String line;
            while ((line = reader.readLine()) != null)
                System.out.println(line);
            System.out.println("threads" + Runtime.getRuntime().availableProcessors());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
