package codeforces;

import org.w3c.dom.ls.LSInput;

import java.math.BigInteger;
import java.security.Key;
import java.security.PrivilegedExceptionAction;
import java.util.*;
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.Semaphore;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.stream.Collectors;

public class CP {
    static Boolean isSorted(List<Integer> a) {
        List<Integer> temp = a;
        Collections.sort(temp);
        return a.equals(temp);
    }

    static String nonDecreasing(List<Integer> a, Integer k) {
        if (k == 1 && !isSorted(a))
            return "NO";
        else
            return "True";
    }

    int getDigit(int a) {
        int ans = 0;
        while (a > 0) {
            ans += a % 10;
            a = a / 10;
        }
        return ans;
    }

    public String largestNumber(int[] nums) {
        Map<Integer, List<Integer>> mp = new TreeMap<>(Comparator.reverseOrder());
        String ans = "";
        for (int a : nums) {
            int msb = Integer.parseInt(String.valueOf(a).substring(0, 1));
            if (mp.containsKey(msb)) {
                mp.get(msb).add(a);
            } else {
                mp.put(msb, new ArrayList<>());
                mp.get(msb).add(a);
            }
        }
        for (Map.Entry<Integer, List<Integer>> entry : mp.entrySet()) {
            Collections.sort(entry.getValue(), (a, b) -> {
                int one = getDigit(a);
                int two = getDigit(b);
                if (one != two) {
                    return Integer.compare(two, one);
                } else {
                    return Integer.compare(String.valueOf(a).length(), String.valueOf(b).length());
                }
            });
        }
        for (Map.Entry<Integer, List<Integer>> entry : mp.entrySet()) {
            for (Integer ele : entry.getValue()) {
                ans += String.valueOf(ele);
            }
        }
        return ans;
    }

    public String longestCommonPrefix(String[] strs) {
        Arrays.sort(strs);
        List<String> list = new ArrayList<>(Arrays.asList(strs));
        list.sort(Collections.reverseOrder());
        int mini = Integer.MAX_VALUE;
        if (list.size() == 1) return list.get(0);
        for (int i = 0; i < list.size() - 1; i++) {
            int j = 0;
            String s = list.get(i);
            String t = list.get(i + 1);
            int len = Math.min(s.length(), t.length());
            while (j < len) {
                if (s.charAt(j) != t.charAt(j)) break;
                j++;
            }
            mini = Math.min(mini, j);
        }
        return strs[0].substring(0, mini);
    }

    class Pair {
        Integer i;

        public Pair(Integer i, Integer j) {
            this.i = i;
            this.j = j;
        }

        Integer j;

        @Override
        public String toString() {
            return "Pair{" +
                    "i=" + i +
                    ", j=" + j +
                    '}';
        }
    }

    class PairStruct<T, U> {
        T i;
        U j;

        public PairStruct(T i, U j) {
            this.i = i;
            this.j = j;
        }


        public String toString() {
            return "Pair{" +
                    "i=" + i +
                    ", j=" + j +
                    '}';
        }
    }

    class Triplet {
        Integer i;

        Integer j;
        Integer k;

        @Override
        public String toString() {
            return i + " " + j + " " + k;
        }

        public Triplet(Integer i, Integer j, Integer k) {
            this.i = i;
            this.j = j;
            this.k = k;
        }
    }

    public int minExtraChar(String s, String[] dictionary) {
        Set<String> dictio = new HashSet<>();
        for (String str : dictionary)
            dictio.add(str);
        StringBuilder sb = new StringBuilder(s);
        List<Pair> list = new ArrayList<>();
        int ans = s.length();

        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j <= s.length(); j++) {
                String sub = s.substring(i, j);
                if (dictio.contains(sub)) {
                    ans -= j - i;
                }
            }
        }
        return ans;
    }

    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        int n = arr1.length;
        int m = arr2.length;
        int ans = 0;
//        Map<Character,List<String>>mp=new HashMap<>();
        Set<String> hashSet = new HashSet<>();
        for (int i = 0; i < m; i++) {
            String s = String.valueOf(arr2[i]);
            for (int j = 1; j <= s.length(); j++) {
                hashSet.add(s.substring(0, j));
            }
        }
        for (int i = 0; i < n; i++) {
            String s = String.valueOf(arr1[i]);
            String t = "";
            for (int j = 0; j < s.length(); j++) {
                if (hashSet.contains(s.substring(0, j))) {
                    ans = Math.max(ans, j);
                } else break;
            }
        }
        return ans;
    }

    public boolean check(int[] nums) {
        boolean acesding = false;
        int peak = -1;
        for (int i = 0; i < nums.length - 1; i++) {
            if (acesding) {
                if (nums[i] > nums[i + 1])
                    return false;
                else {
                    if (nums[i] >= peak)
                        return false;
                    if (i == nums.length - 2) {
                        return nums[i + 1] < peak;
                    }
                }
            } else {
                if (nums[i] >= nums[i + 1]) {
                    acesding = true;
                    peak = nums[i];
                }

            }
        }
        return true;
    }

    class MyCalendar {
        class Meeting {
            public int start, end;

            public Meeting(int start, int end) {
                this.start = start;
                this.end = end;
            }
        }

        List<Meeting> meetings;

        public MyCalendar() {
            meetings = new ArrayList<>();
        }

        public boolean book(int start, int end) {
            for (Meeting meeting : meetings) {
                if (meeting.end > start && end > meeting.start) {
                    return false;
                }
            }
            meetings.add(new Meeting(start, end));
            return true;
        }
    }

    private Integer getIntegerEvent(String s) {
        String[] t = s.split(":");
        int hour = Integer.parseInt(t[0]);
        int minutes = Integer.parseInt(t[1]);
        return (hour * 60) + minutes;
    }

    public boolean haveConflict(String[] event1, String[] event2) {
        Integer firststart = getIntegerEvent(event1[0]);
        Integer firstend = getIntegerEvent(event1[1]);
        Integer secondstart = getIntegerEvent(event2[0]);
        Integer secondend = getIntegerEvent(event2[1]);


        if (firstend >= secondstart && secondend >= firststart) {
            return true;
        } else {
            return false;
        }

    }

    class MyCalendarTwo {

        class Meeting {
            public int start, end;

            public Meeting(int start, int end) {
                this.start = start;
                this.end = end;
            }
        }

        List<Meeting> meetings;

        public MyCalendarTwo() {
            meetings = new ArrayList<>();
        }

        public boolean book(int start, int end) {
            int cnt = 0;
            for (Meeting meeting : meetings) {
                if (meeting.end > start && end > meeting.start) {
                    cnt++;
                }
            }
            if (cnt >= 2) return false;
            meetings.add(new Meeting(start, end));
            return true;
        }
    }

    /**
     * Your MyCalendarTwo object will be instantiated and called as such:
     * MyCalendarTwo obj = new MyCalendarTwo();
     * boolean param_1 = obj.book(start,end);
     */
    static class MyCalendarTwo1 {

        class Meeting {
            public int start, end;

            public Meeting(int start, int end) {
                this.start = start;
                this.end = end;
            }
        }

        List<Meeting> meetings;

        public MyCalendarTwo1() {
            meetings = new ArrayList<>();
        }

        public boolean book(int start, int end) {
            int cnt = 0;
            for (Meeting meeting : meetings) {
                if (meeting.end > start && end > meeting.start) {
                    cnt++;
                }
            }
            if (cnt >= 2) return false;
            meetings.add(new Meeting(start, end));
            return true;
        }
    }

    public int[] arrayRankTransform(int[] arr) {
        int n = arr.length;
        int[] ans = new int[n];
        TreeSet<Integer> set = new TreeSet<>();

        for (int i = 0; i < n; i++) {
            set.add(arr[i]);
        }

        for (int i = 0; i < n; i++) {
            if (set.contains(arr[i])) {
                ans[i] = set.headSet(arr[i]).size() + 1;
            }
        }
        return ans;
    }

    int dpcoins(int[] nums, int idx, int sum, int[][] dp) {
        if (sum == 0) return 0;
        if (idx == 0) {
            if (sum == nums[idx]) return 0;
            return (int) 1e9;
        }
        if (dp[idx][sum] != -1) return dp[idx][sum];
        int nottake = dpcoins(nums, idx - 1, sum, dp);
        int take = (int) 1e9;
        if (sum >= nums[idx])
            take = 1 + dpcoins(nums, idx - 1, sum - nums[idx], dp);
        return dp[idx][sum] = Math.min(nottake, take);
    }


    public int minSubarray(int[] nums, int p) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (sum % p == 0) return 0;
        int extra = sum % p;
        int[][] dp = new int[nums.length + 1][sum + 1];
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[0].length; j++) {
                dp[i][j] = -1;
            }
        }
        int dpcoins = dpcoins(nums, nums.length - 1, extra, dp);

        if (dpcoins >= 1e9) return -1;
        else return dpcoins;
    }

    void temp() {
//        int[] nums = {3, 1, 4, 2};
//        int dpcoins = dpcoins(nums, nums.length - 1, 4);
//        if (dpcoins >= 1e9) System.out.println(-1);
//        else System.out.println(dpcoins);
//        System.out.println(16 % 9);
//        BigInteger i = 1000000000 + 1000000000 + 1000000000;
//        System.out.println(i % new BigInteger((int) 3));
    }

    public long dividePlayers(int[] skill) {
        int n = skill.length;
        int pairs = skill.length / 2;
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += skill[i];
        }
        if (sum % pairs != 0) return -1;
        int pairsum = (int) sum / pairs;
        Map<Integer, Integer> mp = new HashMap<>();
        long ans = 0;
        for (int i = 0; i < n; i++) {
            int rem = pairsum - skill[i];
            if (mp.containsKey(rem)) {
                mp.put(rem, mp.get(rem) - 1);
                ans += ((long) rem * skill[i]);
                if (mp.get(rem) == 0) mp.remove(rem);
            } else {
                mp.put(skill[i], mp.getOrDefault(skill[i], 0) + 1);
            }
        }
        return mp.isEmpty() ? ans : -1;
    }

    public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length()) return false;
        HashSet<String> sts = new HashSet<>();
        boolean ans = false;
        int s1len = s1.length();
        for (int i = 0; i < s2.length() - s1len; i++) {
            String ss = s2.substring(i, i + s1len);
            char[] temparr = ss.toCharArray();
            Arrays.sort(temparr);
            ss = new String(temparr);
            System.out.println(ss);
            sts.add(ss);
        }
        char[] temparr = s1.toCharArray();
        Arrays.sort(temparr);
        s1 = new String(temparr);
        ans = sts.contains(s1);
        return ans;
    }

    public boolean areSentencesSimilar(String s1, String s2) {
        String[] s1arr = s1.split(" ");
        String[] s2arr = s2.split(" ");
        String[] sarr;
        String[] larr;
        String ss, ls;
        if (s1arr.length > s2arr.length) {
            sarr = s2arr;
            larr = s1arr;
            ss = s2;
            ls = s1;
        } else if (s1arr.length < s2arr.length) {
            sarr = s1arr;
            larr = s2arr;
            ss = s1;
            ls = s2;
        } else {
            return s1.equals(s2);
        }
        int le = larr.length - 1;
        int se = sarr.length - 1;
        if (sarr.length == 1) {
            return sarr[0].equals(larr[0]) || sarr[se].equals(larr[le]);
        }
        if (!sarr[0].equals(larr[0]) && sarr[se].equals(larr[le])) {
            int ind = ls.indexOf(ss);
            if (ind == -1)
                return false;
            String temp = ls.substring(ind);
            return temp.equals(ss);
        } else if (sarr[0].equals(larr[0]) && !sarr[se].equals(larr[le])) {
            int ind = ls.indexOf(ss);

            if (ind == -1)
                return false;
            return ls.charAt((ind + ss.length())) == ' ';
        } else if (!sarr[0].equals(larr[0]) || !sarr[se].equals(larr[le])) {
            return false;
        }
        int l = 0;
        while (sarr[l].equals(larr[l]) && l <= se) {
            l++;
        }
        while (sarr[se].equals(larr[le]) && le > 0 && se > 0) {
            se--;
            le--;
        }
        return l > se;
    }

    public int minLength(String s) {
        int ab = 0;
        int cd = 0;
        while (ab != -1 || cd != -1) {
            ab = s.indexOf("AB");
            if (ab != -1) {
                String resstr = s.substring(0, ab);
                resstr += s.substring(ab + 2);
                s = resstr;
            }

            cd = s.indexOf("CD");
            if (cd != -1) {
                String resstr = s.substring(0, cd);
                resstr += s.substring(cd + 2);
                s = resstr;
            }
        }
        return s.length();
    }

    public int minSwaps(String s) {
        int n = s.length();
        int cnt = 0;
        int ans = Integer.MAX_VALUE;
        for (char c : s.toCharArray()) {
            if (c == ']') {
                cnt--;
                ans = Math.min(ans, cnt);
            } else cnt++;
        }
        if (ans == n / 2) return Math.abs(ans + 1);
        else return Math.abs(ans);
    }

    public int minAddToMakeValid(String s) {
        Stack<Character> st = new Stack<>();
        int ans = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') st.push('(');
            else {
                if (st.empty()) {
                    ans++;
                } else if (st.peek() != '(') {
                    ans++;
                } else {
                    st.pop();
                }
            }
        }
        return st.size();
    }

    public String kthLargestNumber(String[] nums, int k) {
        Queue<String> queue = new PriorityQueue<>((a, b) -> a.length() == b.length() ? a.compareTo(b) : Integer.compare(a.length(), b.length()));
        queue.addAll(Arrays.asList(nums));
        for (String s : nums) {
            if (queue.size() > k) queue.poll();
            queue.add(s);
        }
        return queue.poll();
    }

    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        int j = 1;
        int i = 0;
        int last = nums[0];
        for (i = 1; i < n; i++) {
            if (nums[i] > last) {
                last = nums[i];
                nums[j++] = nums[i];
            }
        }
        return j;
    }

    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n;
        int[] save = new int[k];
        int l = 0;
        //1,2,3,4,5,6,7
        //5,6,7,1,2,3,4
        for (int i = n - k; i < n; i++) {
            save[l++] = nums[i];
        }
        l = 0;
        for (int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }
        for (int i = 0; i < k; i++) {
            nums[i] = save[i];
        }
    }

    public void moveZeroes(int[] nums) {
        int l = 0;
        int zc = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                nums[l++] = nums[i];
            } else {
                zc++;
            }
        }
        for (int i = l; i < nums.length; i++) {
            nums[i] = 0;
        }
    }

    public int missingNumber(int[] nums) {
        int n = 0;
        for (int i = 0; i < nums.length; i++) {
            n = i ^ nums[i];
        }
        return n;
    }

    public int maxWidthRamp(int[] nums) {
//        int n = nums.length;
//        int ans = 0;
//        int least = 0;
//        if (nums.length <= 1) return 0;
//        Stack<Integer> st = new Stack<>();
//        st.push(0);
//        for (int i = 1; i < nums.length; i++) {
//            while (!st.empty() && nums[i] <= nums[st.peek()]) {
//                st.pop();
//            }
//            if (!st.empty())
//                ans = Math.max(i - st.peek(), ans);
//            st.push(i);
//        }
//        return ans;
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] <= nums[j]) {
                    ans = Math.max(ans, (j - i));
                }
            }
        }
        return ans;
    }

    public int[] twoSum(int[] nums, int target) {
        int[] ans = new int[2];
        List<Pair> list = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            list.add(new Pair(nums[i], i));
        }
        Collections.sort(list, (a, b) -> Integer.compare(a.i, b.i));
        int i = 0;
        int j = nums.length - 1;
        while (i < j) {
            if (list.get(i).i + list.get(j).i == target) {
                ans[0] = list.get(i).j;
                ans[1] = list.get(i).j;
            }
            int sum = list.get(i).i + list.get(j).i;
            if (sum < target) i++;
            else j--;
        }
        return ans;
    }

    public int[] rearrangeArray(int[] nums) {
        int[] pos = new int[nums.length];
        int[] neg = new int[nums.length];
        int p = 0;
        int n = 0;
        for (int num : nums) {
            if (num > 0) pos[p++] = num;
            else neg[n++] = num;
        }
        boolean pflag = true;
        p = 0;
        n = 0;
        for (int i = 0; i < nums.length; i++) {
            if (pflag) {
                nums[i] = pos[p++];
            } else {
                nums[i] = neg[n++];
            }
            pflag = !pflag;
        }
        return nums;
    }

    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        List<List<Integer>> list = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    list.add(Arrays.asList(i, j, k));
                    j++;
                    k--;
                    while (j > 0 && j < n && nums[j] == nums[j - 1]) j++;
                    while (k > 0 && k < n && nums[k] == nums[k + 1]) k--;
                } else if (sum < 0) j++;
                else k--;
            }
        }
        return list;
    }

    public int maxProduct(int[] nums) {
        int ans = Integer.MIN_VALUE;
//        int curprod = 1;
//        //2,3,-2,4
//        for (int i = 0; i < nums.length; i++) {
//            curprod *= nums[i];
//            ans = Math.max(curprod, ans);
//            if (curprod <= 0) curprod = 1;
//        }
//        return ans;
        for (int i = 0; i < nums.length; i++) {
            int curprod = nums[i];
            for (int j = i + 1; j < nums.length; j++) {
                curprod *= nums[j];
                ans = Math.max(ans, curprod);
            }
        }
        return ans;
    }

    public int smallestChair(int[][] times, int targetFriend) {
        List<Triplet> list = new ArrayList<>();
        for (int i = 0; i < times.length; i++) {
            list.add(new Triplet(i, times[i][0], times[i][1]));
        }
        Collections.sort(list, Comparator.comparingInt(a -> a.j));
        int max = 0;
        Map<Integer, Triplet> mp = new HashMap<>();
        for (Triplet triplet : list) {
            Integer chair = max;
            for (Map.Entry<Integer, Triplet> entry : mp.entrySet()) {
                if (entry.getValue().k < triplet.j) {
                    mp.put(entry.getKey(), triplet);
                    chair = entry.getKey();

                }
            }
            if (chair == max) {
                mp.put(max, triplet);
                max++;
            }
            if (triplet.i == targetFriend) {
                return chair;
            }
        }
        return max;
    }

    boolean intersect(Pair p1, Pair p2) {
        if (p1.i == p2.i) return true;
        if (p1.j < p2.i) {
            return false;
        } else {
            return p1.i < p2.j;
        }
    }

    public int minGroups(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);

        PriorityQueue<Integer> endTimeQueue = new PriorityQueue<>();

        for (int[] interval : intervals) {
            if (!endTimeQueue.isEmpty() && endTimeQueue.peek() < interval[0]) {
                endTimeQueue.poll();
            }

            endTimeQueue.offer(interval[1]);
        }
        return endTimeQueue.size();
    }

    public long maxKelements(int[] nums, int k) {
        Queue<Integer> queue = new PriorityQueue<>(Comparator.reverseOrder());
        for (int ele : nums) {
            queue.offer(ele);
        }
        long ans = 0;
        for (int i = 0; i < k; i++) {
            if (!queue.isEmpty()) {
                int val = queue.poll();
                ans += val;
                queue.offer((int) Math.ceil(val / 3.0));
            }
        }
        return ans;
    }

    boolean caneat(int[] arr, int cur, int h) {
        int ans = 0;
        for (int ele : arr) {
            int ceiled = (int) Math.ceil(ele / (double) cur);
            ans += ceiled;
            if (ans > h) return false;
        }

        return ans <= h;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int max = piles[0];
        for (int ele : piles) {
            max = Math.max(max, ele);
        }
        int low = 0;
        int high = max;
        int ans = Integer.MAX_VALUE;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (caneat(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return (ans == Integer.MAX_VALUE) ? -1 : ans;
    }

    boolean getbockes(int[] nums, int days, int m, int k) {
        int cur = 0;
        int ans = 0;
        for (int ele : nums) {
            if (ele <= days) {
                cur++;
                if (cur == k) {
                    cur = 0;
                    ans++;
                }
                if (ans >= m) return true;
            } else cur = 0;
        }
        return ans >= m;
    }

    public int minDays(int[] bloomDay, int m, int k) {
        BigInteger temp = BigInteger.valueOf(m * k);
        if (m * k > bloomDay.length) return -1;
        int low = bloomDay[0];
        int high = bloomDay[0];
        for (int ele : bloomDay) {
            low = Math.min(low, ele);
            high = Math.max(high, ele);
        }
        int ans = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (getbockes(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    boolean canwedivide(int[] nums, int thr, int mid) {
        int ans = 0;
        for (int ele : nums) {
            ans += (int) Math.ceil(ele / (double) mid);
            if (ans > thr) return false;
        }
        return ans <= thr;
    }

    public int smallestDivisor(int[] nums, int threshold) {
        int low = nums[0];
        int high = nums[0];
        for (int ele : nums) {
            low = Math.min(low, ele);
            high = Math.max(high, ele);
        }
        int ans = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canwedivide(nums, threshold, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    public String removeOuterParentheses(String s) {
        int cnt = 0;
//        StringBuilder ans = new StringBuilder(s);
//        for (int i = 0; i < s.length(); i++) {
//            char cur = s.charAt(i);
//            if (cnt == 0) {
//                ans.replace(i, i + 1, "");
//            }
//            if (cur == '(') {
//                if (cnt == 0) {
//                    ans.replace(i, i + 1, "");
//                }
//                cnt++;
//            } else {
//                if (cnt == 1) {
//                    ans.replace(i - 1, i, "");
//                }
//                cnt--;
//            }
//
//        }
        char[] chararr = s.toCharArray();
        for (int i = 0; i < chararr.length; i++) {
            char cur = chararr[i];
            if (cnt == 0) {
                chararr[i] = '1';
            }
            if (cur == '(') {
                if (cnt == 0) {
                    chararr[i] = '1';
                }
                cnt++;
            } else {
                if (cnt == 1) {
                    chararr[i] = '1';
                }
                cnt--;
            }
        }
        String ans = "";
        for (char c : chararr) {
            if (c != '1') {
                ans += c;
            }
        }
        return ans.toString();
    }

    public String largestOddNumber(String num) {
        String ans = "";
        long max = Long.MIN_VALUE;
        for (int i = 0; i < num.length(); i++) {
            for (int j = i + 1; j < num.length(); j++) {
                String cur = num.substring(i, j);
                long number = Long.parseLong(cur);
                if (number % 2 != 0) {
                    if (number > max) {
                        max = number;
                        ans = cur;
                    }
                }
            }
        }
        return ans;
    }

    public long minimumSteps(String s) {
        long ans = 0;
        int l = 0;
        int r = s.length() - 1;
        char[] chararr = s.toCharArray();
        while (l < r) {
            if (chararr[l] == '0') l++;
            else {
                if (chararr[r] != '1') {
                    ans += r - l;
                    char temp = chararr[l];
                    chararr[l] = chararr[r];
                    chararr[r] = temp;
                    r--;
                } else r--;

            }
        }
        return ans;
    }

    public String longestDiverseString(int a, int b, int c) {
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((x, y) -> y[1] - x[1]);

        if (a > 0) {
            maxHeap.offer(new int[]{'a', a});
        }
        if (b > 0) {
            maxHeap.offer(new int[]{'b', b});
        }
        if (c > 0) {
            maxHeap.offer(new int[]{'c', c});
        }
        StringBuilder result = new StringBuilder();

        while (!maxHeap.isEmpty()) {
            int[] current = maxHeap.poll();
            int length = result.length();
            if (length >= 2 && result.charAt(length - 1) == current[0] && result.charAt(length - 2) == current[0]) {
                if (maxHeap.isEmpty()) {
                    break;
                }
                int[] next = maxHeap.poll();
                result.append((char) next[0]);
                if (next[1] > 1) {
                    next[1]--;
                    maxHeap.offer(next);
                }
                maxHeap.offer(current);
            } else {
                result.append((char) current[0]);
                if (current[1] > 1) {
                    current[1]--;
                    maxHeap.offer(current);
                }
            }
        }

        return result.toString();
    }

    boolean canweship(int[] nums, int weight, int days) {
        int cur = 0;
        int ans = 1;
        for (int i = 0; i < nums.length; i++) {
            if (cur + nums[i] > weight) {
                ans++;
                cur = nums[i];
            } else {
                cur += nums[i];
            }

            if (ans > days) return false;
        }
        return ans <= days;
    }

    public int shipWithinDays(int[] nums, int days) {
        int low = 1;
        int high = 0;
        for (int ele : nums) {
            high += ele;
        }
        int maxi = high;
        int ans = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canweship(nums, mid, days)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    public int findKthPositive(int[] arr, int k) {
        int maxi = arr[0];
        HashSet<Integer> set = new HashSet<>();
        for (int i = 0; i < arr.length; i++) {
            maxi = Math.max(maxi, arr[i]);
            set.add(arr[i]);
        }
        int cur = 0;
        for (int i = 1; i <= maxi; i++) {
            if (!set.contains(i)) {
                cur++;
                if (cur == k) return i;
            }
        }
        return maxi + 1;
    }

    public int maximumSwap(int num) {
        char[] nums = String.valueOf(num).toCharArray();
        int n = nums.length;
        int postfix[] = new int[n];
        postfix[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[postfix[i + 1]]) postfix[i] = i;
            else postfix[i] = postfix[i + 1];
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[postfix[i]]) {
                char temp = nums[postfix[i]];
                nums[postfix[i]] = nums[i];
                nums[i] = temp;
                break;
            }
        }
        return Integer.parseInt(new String(nums));
    }

    public boolean rotateString(String s, String goal) {
        int n = s.length();
        if (s.equals(goal)) return true;
        for (int i = 1; i < n; i++) {
            String one = s.substring(0, i);
            String two = s.substring(i);
            String rotated = two + one;
            if (rotated.equals(goal)) return true;
        }
        return false;
    }

    public boolean isAnagram(String s, String t) {
        char[] sarr = s.toCharArray();
        char[] tarr = t.toCharArray();
        Arrays.sort(sarr);
        Arrays.sort(tarr);
        return new String(sarr).equals(new String(tarr));
    }

    public long kthLargestLevelSum(TreeNode root, int k) {
        Queue<TreeNode> queue = new LinkedList<>();
        Queue<Long> heap = new PriorityQueue<>(Collections.reverseOrder());
        queue.offer(root);
        while (!queue.isEmpty()) {
            long cursum = 0;
            int n = queue.size();
            for (int i = 0; i < n; i++) {
                TreeNode node = queue.poll();
                System.out.print(node.val + " ");
                cursum += node.val;
                if (node.left != null) queue.offer(node.left);
                if (node.right != null) queue.offer(node.right);
            }
            heap.offer(cursum);
            System.out.println();
        }
        while (k > 0) {
            heap.poll();
            k--;
        }
        return heap.isEmpty() ? -1 : heap.poll();
    }

    public int longestSquareStreak(int[] nums) {
        Arrays.sort(nums);
        int ans = 0;
        for (int ele : nums) {
            long pow = ele * (long) ele;
            if (pow > Integer.MAX_VALUE) continue;
            if (Arrays.binarySearch(nums, (int) pow) >= 0) {
                int len = 1;
                while (Arrays.binarySearch(nums, (int) pow) >= 0) {
                    len++;
                    pow = pow * pow;
                    if (pow > Integer.MAX_VALUE) break;

                }
                ans = Math.max(ans, len);
            }
        }
        return ans;
    }

    public String makeFancyString(String s) {
        String ans = "";
        long len = s.length();
        int count = 1;
        char last = '1';
        char[] schar = s.toCharArray();
        int i = 0;
        while (i < s.length()) {
            if (schar[i] == last) {
                count++;
                if (count <= 2) {
                    ans += String.valueOf(schar[i]);
                    i++;
                } else {
                    last = schar[i];
                    while (schar[i] == last) {
                        i++;
                    }
                }
            } else {
                count = 1;
                last = schar[i];
                ans += String.valueOf(schar[i]);
                i++;
            }
        }
        return ans;
    }

    boolean candistribute(int k, int n, int[] quantities) {
        int idx = 0;
        int i = 0;
        int stores = 0;
        for (int prod : quantities) {
            stores += (prod + 1) / k;
        }
        return stores <= n;
    }

    public int minimizedMaximum(int n, int[] quantities) {
        int l = 0;
        int r = Arrays.stream(quantities).max().getAsInt();
        int ans = r;
        while (l < r) {
            int mid = (l + r) / 2;
            if (candistribute(mid, n, quantities)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    public int[] decrypt(int[] code, int k) {
        int[] ans = new int[code.length];
        if (k >= 0) {
            for (int i = 0; i < code.length; i++) {
                int sum = 0;
                for (int j = i + 1; j <= i + k; j++) {

                    sum += code[j % (code.length)];
                }
                ans[i] = sum;
            }
            return ans;
        } else {
            for (int i = 0; i < code.length; i++) {
                int sum = 0;
                int idx = i - 1;
                for (int j = 0; j < Math.abs(k); j++) {
                    if (idx < 0) idx = code.length - 1;
                    sum += code[idx--];
                }
                ans[i] = sum;
            }
            return ans;
        }
    }

    int maximumLength(String s) {
        HashMap<String, Integer> mp = new HashMap<>();
        int ans = -1;
        for (int i = 0; i < s.length(); i++) {
            int maxi = 0;
            for (int j = 0; j <= s.length() - (i + 1); j++) {
                String substr = s.substring(j, j + (i + 1));
                if (mp.containsKey(substr)) {
                    mp.put(substr, mp.get(substr) + 1);
                    maxi = Math.max(maxi, mp.get(substr));
                } else {
                    mp.put(substr, 1);
                }
            }
            if (maxi >= 3) ans = Math.max(ans, i + 1);
        }
        return ans;
    }

    public int maximumBeauty(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        int ans = 1;
        for (int num : nums) {
            int minus = num - k;
            int plus = num + k;
            for (int i = minus + 1; i < plus; i++) {
                if (mp.containsKey(i)) {
                    mp.put(i, mp.get(i) + 1);
                    ans = Math.max(ans, mp.get(i));
                } else {
                    mp.put(i, 1);
                }
            }

            if (mp.containsKey(num)) {
                mp.put(num, mp.get(num) + 1);
                ans = Math.max(ans, mp.get(num));
            } else {
                mp.put(num, 1);
            }

        }
        return ans;
    }

    public long maximumSubarraySum(int[] nums, int k) {
        Set<Integer> set = new HashSet<>();
        if (nums.length < k) return 0;
        long ans = 0;
        long sum = 0;
        for (int i = 0; i < k; i++) {
            set.add(nums[i]);
            sum += nums[i];
        }
        if (set.size() < k) {
            ans = 0;
        } else {
            ans = sum;
        }

        int start = 0;
        int end = k;
        while (end < nums.length) {
            sum -= nums[start];
            sum += nums[end];
            if (set.contains(nums[start])) {
                set.remove(nums[start]);
            } else {
                set.add(nums[start]);
            }
            if (nums[start + 1] == nums[start]) set.add(nums[start]);
            set.add(nums[end]);
            if (set.size() == k) ans = Math.max(sum, ans);

            start++;
            end++;
        }
        return ans;
    }

    public static void main(String[] args) {

        CP cp = new CP();
        cp.temp();
        int[] nums = {1, 1, 1, 1};
        int[][] twod = {{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}};
        String s1 = "abcdef";
        String s2 = "";
        int k = 10;
//        System.out.println(cp.largestNumber(nums));
//        String[] strings = {"leet", "code", "leetcode"};
//        System.out.println(cp.longestCommonPrefix(strings));
//        System.out.println(cp.minExtraChar("leetscode", strings));
//        int []arr1={1,10,100};
//        int []arr2={1000};
//        String[]starr1={"01:15","02:00"};
//        String[]starr2={"02:00","03:00"};
//        System.out.println(cp.haveConflict(starr1,starr2));
//        MyCalendarTwo1 mcal = new MyCalendarTwo1();
//        int[][] mat = {{10, 20}, {50, 60}, {10, 40}, {5, 15}, {5, 10}, {25, 55}};
//        for (int i = 0; i < mat.length; i++) {
//            System.out.println(mcal.book(mat[i][0], mat[i][1]));
//        }
//        System.out.println(cp.minSubarray(nums, 3));

//        System.out.println(cp.checkInclusion(s1, s2));
//        System.out.println(cp.areSentencesSimilar(s1, s2));
//        System.out.println(cp.minLength(s1));
//        System.out.println(cp.minSwaps(s1));
//        System.out.println(cp.removeDuplicates(nums));
//        cp.rotate(nums, 3);
//        cp.moveZeroes(nums);
//        System.out.println(cp.missingNumber(nums));
//        System.out.println(cp.maxWidthRamp(nums));
//        cp.twoSum(nums, 6);
//        cp.rearrangeArray(nums);
//        System.out.println(cp.smallestChair(twod, 6));
//        System.out.println(cp.minGroups(twod));
//        System.out.println(cp.minEatingSpeed(nums, 8));
//        System.out.println(cp.minDays(nums, 3, 1));
//        System.out.println(cp.smallestDivisor(nums, 1000000));
//        System.out.println(cp.removeOuterParentheses(s1));
//        System.out.println(cp.minimumSteps(s1));
//        System.out.println(cp.shipWithinDays(nums, 1));
//        System.out.println(cp.maximumSwap(98368));
//        System.out.println(cp.rotateString(s1, s2));
//        System.out.println(cp.makeFancyString(s1));
//        cp.decrypt(nums, 3);
//        System.out.println(cp.maximumSubarraySum(nums, 2));
//        System.out.println(cp.maximumLength(s1));
        System.out.println(cp.maximumBeauty(nums, k));
    }
}
