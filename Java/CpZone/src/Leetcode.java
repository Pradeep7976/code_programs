import java.util.*;
import java.util.stream.Collectors;

public class Leetcode {
	class Node {
		public int val;
		public List<Node> neighbors;

		public Node() {
			val = 0;
			neighbors = new ArrayList<Node>();
		}

		public Node(int _val) {
			val = _val;
			neighbors = new ArrayList<Node>();
		}

		public Node(int _val, ArrayList<Node> _neighbors) {
			val = _val;
			neighbors = _neighbors;
		}
	}

	public class ListNode {
		int val;
		ListNode next;

		ListNode() {
		}

		ListNode(int val) {
			this.val = val;
		}

		ListNode(int val, ListNode next) {
			this.val = val;
			this.next = next;
		}
	}

	static long helper(int n, int ans, int copy) {
		if (n == 1 || ans == n) {
			return 0;
		}
		if (ans == 0)
			return Integer.MAX_VALUE;
		if (ans > n)
			return Integer.MAX_VALUE;
		long copy1 = helper(n, ans + copy, copy);
		long copy2 = 1 + helper(n, ans + copy, ans + copy);
		return 1 + Math.min(copy1, copy2);
	}

	static int minSteps(int n) {
		if (n == 1)
			return 0;
		long ans = helper(n, 1, 1);
		if (ans == Integer.MAX_VALUE)
			return 0;
		return (int) ans + 1;
	}

	public static int mySqrt(int x) {
		System.out.println(Integer.toBinaryString(x));
		for (int i = 0; i < 32; i++) {
			System.out.print(1 & (x >> i));
			System.out.print(" ");
		}
		return 0;
	}

	// public static List<Integer> mostVisited(int n, int[] rounds) {
	// if (n == 1)
	// return List.of(n);
	// int s = 0, e = 1;
	// Map<Integer, Integer> mp = new HashMap<>();
	// for (int i = 0; i < n - 1; i++) {
	// s = i;
	// e = i + 1;
	// while (s != e) {
	// if (mp.containsKey(s)) {
	// mp.put(s, mp.get(s));
	// } else {
	// mp.put(s, 1);
	// }
	// s = (s % n) + 1;
	// }
	// }
	// Collections.sort(mp., new Comparator<Map.Entry<Integer, Integer>>() {

	// @Override
	// public int compare(Entry<Integer, Integer> o1, Entry<Integer, Integer> o2) {

	// return o1.getValue().compareTo(o2.getValue());
	// }

	// });

	// }
	static Map<Character, Integer> freq(String s) {
		Map<Character, Integer> mp = new HashMap<>();
		for (int i = 0; i < s.length(); i++) {
			mp.put(s.charAt(i), mp.getOrDefault(s.charAt(i), 0) + 1);
		}
		return mp;
	}

	public static int minSteps(String s, String t) {
		Map<Character, Integer> freqs = freq(s);
		Map<Character, Integer> freqt = freq(t);

		int count = 0;

		for (Map.Entry<Character, Integer> entry : freqs.entrySet()) {
			char c = entry.getKey();
			int freqInS = entry.getValue();
			int freqInT = freqt.getOrDefault(c, 0);
			count += Math.abs(freqInS - freqInT);

			freqt.remove(c);
		}

		for (int freq : freqt.values()) {
			count += freq;
		}

		return count;
	}

	public List<Integer> intToBin(int num) {
		List<Integer> l = new ArrayList<>();
		while (num != 0) {
			if (num % 2 == 0) {
				l.add(1);
			} else {
				l.add(0);
			}
			num = num / 2;
		}
		// System.out.println(l);
		Collections.reverse(l);
		return l;
	}

	public int binToInt(List<Integer> list) {
		int i = 1;
		int ans = 0;
		Collections.reverse(list);
		for (Integer ele : list) {
			ans += ele * i;
			i *= 2;
		}
		return ans;
	}

	public int findComplement(int num) {
		// String s = Integer.toBinaryString(num);
		// String ans = "";
		// for (int i = 0; i < s.length(); i++) {
		// if (s.charAt(i) == '1')
		// ans += '0';
		// else {
		// ans += '1';
		// }
		// }
		// return Integer.parseInt(ans, 2);
		List<Integer> list = intToBin(num);
		return binToInt(list);
	}

	public int[] postfixsum(int[] a) {
		int ans[] = new int[a.length];
		if (a.length == 0)
			return ans;
		ans[a.length - 1] = a[a.length - 1];
		for (int i = a.length - 2; i >= 0; i++) {
			ans[i] = a[i + 1] + ans[i + 1];
		}
		return ans;
	}

	public int[] prefixSum(int[] a) {
		int n = a.length;
		int[] ans = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			ans[i] = ans[i - 1] + a[i - 1];
		}
		return ans;
	}

	public int maxSumMinProduct(int[] a) {
		int n = a.length;
		int[] prefixSum = prefixSum(a);
		int[] nsel = nsel(a);
		int[] nser = nser(a);
		long ans = 0;
		int MOD = 1_000_000_007;

		for (int i = 0; i < n; i++) {
			int left = nsel[i] + 1;
			int right = nser[i] - 1;

			long subSum = prefixSum[right + 1] - prefixSum[left];
			ans = Math.max(ans, subSum * a[i]);
		}

		return (int) (ans % MOD);
	}

	public int[] nser(int[] a) {
		int n = a.length;
		int[] ans = new int[n];
		Stack<Integer> st = new Stack<>();
		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() && a[st.peek()] >= a[i])
				st.pop();
			ans[i] = st.empty() ? n : st.peek();
			st.push(i);
		}
		return ans;
	}

	public int[] nsel(int[] a) {
		int n = a.length;
		int[] ans = new int[n];
		Stack<Integer> st = new Stack<>();
		for (int i = 0; i < n; i++) {
			while (!st.empty() && a[st.peek()] >= a[i])
				st.pop();
			ans[i] = st.empty() ? -1 : st.peek();
			st.push(i);
		}
		return ans;
	}

	public int maxSumMinProduct1(int[] nums) {
		int n = nums.length;
		long[] prefix = new long[n + 1];
		int MOD = 1_000_000_007;
		for (int i = 0; i < n; i++) {
			prefix[i + 1] = prefix[i] + nums[i];
		}

		int[] left = new int[n];
		int[] right = new int[n];
		Deque<Integer> stack = new ArrayDeque<>();

		for (int i = 0; i < n; i++) {
			while (!stack.isEmpty() && nums[stack.peek()] >= nums[i]) {
				stack.pop();
			}
			left[i] = stack.isEmpty() ? 0 : stack.peek() + 1;
			stack.push(i);
		}

		stack.clear();

		for (int i = n - 1; i >= 0; i--) {
			while (!stack.isEmpty() && nums[stack.peek()] >= nums[i]) {
				stack.pop();
			}
			right[i] = stack.isEmpty() ? n - 1 : stack.peek() - 1;
			stack.push(i);
		}

		long maxProduct = 0;

		for (int i = 0; i < n; i++) {
			long sum = prefix[right[i] + 1] - prefix[left[i]];
			maxProduct = Math.max(maxProduct, sum * nums[i]);
		}

		return (int) (maxProduct % MOD);
	}

	public int gcd(int a, int b) {
		while (b != 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}

	public String fractionAddition(String s) {
		Queue<Integer> qop = new LinkedList<>();
		Queue<Integer> qint = new LinkedList<>();
		int neg = 0;
		int i = 0;
		int curnum;
		while (i < s.length()) {
			if (s.charAt(i) == '-') {
				neg = 1;
				i++;
				continue;
			}
			if (s.charAt(i) == '+') {
				i++;
				continue;
			}
			if (s.charAt(i) == '/') {
				i++;
				continue;
			}
			int tens = 1;
			curnum = 0;
			int previ = i;
			while (i < s.length() && s.charAt(i) >= '0' && s.charAt(i) <= '9') {
				// int val = Character.getNumericValue(s.charAt(i));
				// curnum = curnum + (tens * val);
				// tens *= 10;
				i++;
			}
			curnum = Integer.parseInt(s.substring(previ, i));
			if (neg == 1) {
				int temp = curnum;
				curnum = 0;
				curnum = curnum - temp;
				qint.add(curnum);
				neg = 0;

			} else {
				qint.add(curnum);

			}
		}
		System.out.println(qint);
		Integer cnumerator = Integer.MIN_VALUE;
		Integer pnumerator = Integer.MIN_VALUE;
		Integer cdenominator = Integer.MIN_VALUE;
		Integer pdenominator = Integer.MIN_VALUE;
		if (qint.size() == 2) {
			cnumerator = qint.poll();
			cdenominator = qint.poll();

		} else {
			while (!qint.isEmpty()) {
				if (pnumerator == Integer.MIN_VALUE && pdenominator == Integer.MIN_VALUE) {
					pnumerator = qint.poll();
					pdenominator = qint.poll();
					continue;
				}
				cnumerator = qint.poll();
				cdenominator = qint.poll();
				cnumerator = (cnumerator * pdenominator) + (pnumerator * cdenominator);
				cdenominator = cdenominator * pdenominator;
				pdenominator = cdenominator;
				pnumerator = cnumerator;
			}
		}

		int gcd = gcd(cnumerator, cdenominator);
		while (gcd != 1) {
			gcd = gcd(cnumerator, cdenominator);
			cnumerator = cnumerator / gcd;
			cdenominator = cdenominator / gcd;
		}
		int one = 0;
		if (cnumerator < 0 || cdenominator < 0) {
			one = 1;
		}
		cnumerator = Math.abs(cnumerator);
		cdenominator = Math.abs(cdenominator);
		String ans = "";
		if (one == 1) {
			ans += "-";
		}
		ans += cnumerator.toString();
		ans += "/";
		ans += cdenominator.toString();
		return ans;
	}

	public void arrDisplay(int[] nums) {
		for (int j = 0; j < nums.length; j++) {
			System.out.print(nums[j] + " ");
		}
		System.out.println();
	}

	public int[] getFinalState(int[] nums, int k, int mul) {
		for (int i = 0; i < k; i++) {
			int min = 0;
			for (int j = 0; j < nums.length; j++) {
				if (nums[j] < nums[min]) {
					min = j;
				}
			}
			nums[min] *= mul;
		}
		return nums;
	}

	public boolean areAlmostEqual(int x, int y) {
		String sx = String.valueOf(x);
		String sy = String.valueOf(y);

		if (sx.length() != sy.length()) {
			return false;
		}

		if (sx.equals(sy)) {
			return true;
		}

		for (int i = 0; i < sx.length(); i++) {
			for (int j = i + 1; j < sx.length(); j++) {
				char[] arrX = sx.toCharArray();
				char temp = arrX[i];
				arrX[i] = arrX[j];
				arrX[j] = temp;

				int swappedX = Integer.parseInt(new String(arrX));

				if (swappedX == y) {
					return true;
				}
			}
		}

		return false;
	}

	public int countPairs(int[] nums) {
		int count = 0;

		for (int i = 0; i < nums.length; i++) {
			for (int j = i + 1; j < nums.length; j++) {
				if (areAlmostEqual(nums[i], nums[j])) {
					count++;
				}
			}
		}

		return count;
	}

	public int balancedStringSplit(String s) {
		int a = 0;
		int ans = 0;
		for (Character c : s.toCharArray()) {
			if (c == 'L') {
				a++;
			} else {
				a--;
			}

			if (a == 0) {
				ans += 1;
			}
		}
		return ans;
	}

	public String reverseWords(String s) {
		String[] words = s.split(" ");
		List<String> list = Arrays.asList(words);
		Collections.reverse(list);
		String ans = "";
		for (String ss : list) {
			if (ss != "")
				ans += ss + " ";
		}
		ans.trim();
		return ans;
	}

	public int[] productExceptSelf(int[] nums) {
		int prod = 1;
		int postfix[] = new int[nums.length];
		int prefix[] = new int[nums.length];
		int ans[] = new int[nums.length];
		int n = nums.length;
		postfix[n - 1] = nums[n - 1];
		for (int i = n - 2; i > 0; i--) {
			postfix[i] = postfix[i + 1] * nums[i];
		}
		prefix[0] = nums[0];
		for (int i = 1; i < n; i++) {
			prefix[i] = prefix[i - 1] * nums[i];
		}
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				ans[i] = postfix[i + 1];
			} else if (i == n - 1) {
				ans[i] = prefix[i - 1];
			} else {
				ans[i] = prefix[i - 1] * postfix[i + 1];
			}
		}
		return ans;
	}

	public void sectionSort(int[] arr) {
		int n = arr.length;
		for (int i = 0; i < n - 1; i++) {
			int mini = i;
			for (int j = i; j < n; j++) {
				if (arr[j] < arr[mini])
					mini = j;
			}
			int temp = arr[mini];
			arr[mini] = arr[i];
			arr[i] = temp;
		}
	}

	public void bubbleSort(int[] arr) {
		int n = arr.length;
		for (int i = 0; i < n - 1; i++) {
			boolean swap = false;
			for (int j = n - 1; j > i; j--) {
				if (arr[j] < arr[j - 1]) {
					int temp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = temp;
					swap = true;
				}
			}
			if (!swap)
				break;
		}
	}

	public void insertionSort(int[] arr) {
		int n = arr.length;
		if (n == 1)
			return;
		for (int i = 1; i <= n - 1; i++) {
			int j = i;
			while (j > 0 && (arr[j - 1] > arr[j])) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				j--;
			}
		}
	}

	public int pivotPos(int[] arr, int low, int high) {
		int i = low;
		int j = high;
		int pivot = arr[low];
		while (i < j) {
			while (i < high && arr[i] <= pivot) {
				i++;
			}
			while (j >= 0 && arr[j] > pivot) {
				j--;
			}
			if (i < j) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		int temp = arr[low];
		arr[low] = arr[j];
		arr[j] = temp;
		return j;
	}

	public void quickSort(int[] arr, int low, int high) {
		if (low < high) {
			int pivot = pivotPos(arr, low, high);
			quickSort(arr, low, pivot - 1);
			quickSort(arr, pivot + 1, high);
		}
		return;
	}

	public void mergeSort(int[] arr) {

	}

	public Node cloneGraph(Node node) {
		Queue<Node> que = new LinkedList<>();
		que.add(node);
		Set<Integer> visited = new HashSet();
		Node head = null;
		boolean first = true;
		while (!que.isEmpty()) {
			Node curNode = que.poll();
			if (visited.contains(curNode.val)) {
				continue;
			}
			Node node1 = new Node();
			node1.val = curNode.val;
			visited.add(curNode.val);
			List<Node> neighbours = new ArrayList<>();
			if (first) {
				head = node1;
			}
			for (Node no : curNode.neighbors) {
				Node tempnode = new Node(no.val);
				neighbours.add(tempnode);
				que.add(no);
			}
			node1.neighbors = neighbours;
		}
		return head;
	}

	public ListNode modifiedList(int[] nums, ListNode head) {
		ListNode cur = head;
		ListNode prev = null;
		Set<Integer> set = new HashSet<>();
		for (int i = 0; i < nums.length; i++) {
			set.add(nums[i]);
		}
		while (cur != null) {
			if (set.contains(cur.val)) {
				if (prev == null) {
					head = head.next;
				} else {
					prev.next = cur.next;
				}
			}
			prev = cur;
			cur = cur.next;
		}
		return head;
	}

	void temp() {
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		pq.add(3);
		pq.add(1);
		pq.add(44);
		System.out.println(pq);
		pq.remove();
		System.out.println(pq);
	}

//    public int[][] spiralMatrix(int m, int n, List<Integer> list) {
//        int[][] ans = new int[m][n];
//        int cnt = 0;
//        int l = 0;
//        int r = n;
//        int u = 0;
//        int d = m;
//        for (int i = 0; i < m - 1; i++) {
//            for (int j = 0; j < r; j++) {
//                ans[i][j] = list.get(cnt++);
//            }
//            r--;
//            for (int k = 0; k < d; k++)
//        }
//
//
//        return ans;
//    }

	public int maxDistinctElements(int[] nums, int k) {
		int range = k * -1;
		int ans = 0;
		Arrays.sort(nums);

		Set<Integer> set = Arrays.stream(nums).boxed().collect(Collectors.toSet());
		while (range <= k && ans < nums.length) {
			if (ans == 0) {
				ans++;
				continue;
			}
			if (nums[ans - 1] == nums[ans]) {
				range++;
			}
			ans++;
		}
		return ans;
	}

	int dpfindTargetSumWays(int[] nums, int[][] dp, int idx, int target) {

		if (dp[idx][target] != -1)
			return dp[idx][target];
		
		if (idx >= nums.length) {
			if (target == 0) {
				return 1;
			} else {
				return 0;
			}
		}

		int num = nums[idx];

		return dp[idx][target]= dpfindTargetSumWays(nums, dp, idx + 1, target - num)
				+ dpfindTargetSumWays(nums, dp, idx + 1, target + num);

	}

	public int findTargetSumWays(int[] nums, int target) {
		int dp[][] = new int[nums.length + 1][nums.length + 1];
		for (int[] d : dp) {
			Arrays.fill(d, -1);
		}
		int dpfindTargetSumWays = dpfindTargetSumWays(nums, dp, 0, target);
		return dpfindTargetSumWays;
	}

	public static void main(String[] args) {
		// String s = "leetcode";
		// String t = "coats";
		Leetcode lc = new Leetcode();
		int[] a = { 1, 1, 1, 1, 1 };
		int[] b = { 2, 3, 3, 1, 2 };
		// System.out.println(minSteps(s, t));
		// System.out.println(lc.findComplement(2));
//        String s = "-7/3";
		// System.out.println(lc.maxSumMinProduct(b));
		// List<Integer> list =new ArrayList<>(a);
		// lc.arrDisplay(lc.getFinalState(a, 5, 2));
//        System.out.println(Arrays.toString(lc.productExceptSelf(a)));
//        lc.quickSort(b, 0, b.length - 1);
//        System.out.println(Arrays.toString(b));
//        String st = "123";
//        System.out.println(st.toCharArray());
//        lc.temp();/
//		System.out.println(lc.maxDistinctElements(a, 1));
		System.out.println(lc.findTargetSumWays(a, 3));
	}
}