package leetcode;

import java.util.*;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	public TreeNode() {
	}

	public TreeNode(int val) {
		this.val = val;
	}

	public TreeNode(int val, TreeNode left, TreeNode right) {
		this.val = val;
		this.left = left;
		this.right = right;
	}

}

class ListNode {
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

public class Tree {
	public List<Integer> largestValues(TreeNode root) {
		List<Integer> result = new ArrayList<>();
		Queue<TreeNode> queue = new LinkedList<>();
		queue.add(root);
		while (!queue.isEmpty()) {
			int n = queue.size();
			int ans = queue.peek().val;
			for (int i = 0; i < n; i++) {
				ans = Math.max(queue.peek().val, ans);
				TreeNode node = queue.poll();
				if (node.left != null)
					queue.add(node.left);
				if (node.right != null)
					queue.add(node.right);

			}
			result.add(ans);
		}
		return result;
	}

	public int minimumOperations(int[] nums) {
		int ans = 0;
		Set<Integer> set = new HashSet<>();
		int n = nums.length;
		int i = n - 1;
		for (; i >= 0; i--) {
			if (set.contains(nums[i])) {
				break;
			}
			set.add(nums[i]);
		}
		return Math.ceilDiv((i + 1), 3);
	}

	

	public static TreeNode createTreeFromArray(Integer[] arr) {
		if (arr == null || arr.length == 0)
			return null;

		TreeNode root = new TreeNode(arr[0]);
		Queue<TreeNode> queue = new LinkedList<>();
		queue.offer(root);
		int i = 1;

		while (i < arr.length) {
			TreeNode current = queue.poll();

			// Process left child
			if (i < arr.length && arr[i] != null) {
				current.left = new TreeNode(arr[i]);
				queue.offer(current.left);
			}
			i++;

			// Process right child
			if (i < arr.length && arr[i] != null) {
				current.right = new TreeNode(arr[i]);
				queue.offer(current.right);
			}
			i++;
		}

		return root;
	}

	public static ListNode createListFromArray(Integer[] arr) {
		ListNode head = null;
		ListNode prev = null;
		for (Integer ele : arr) {
			ListNode node = new ListNode(ele);
			if (head == null) {
				head = node;
				prev = head;
			}
			prev.next = node;
			prev = node;
		}
		return head;
	}

	public static void printList(ListNode head) {
		if (head == null) {
			System.out.println("Null");
		}
		while (head != null) {
			System.out.print(head.val + " ");
			head = head.next;
		}
		System.out.println();
	}

	public static void printTree(TreeNode root) {
		if (root == null)
			return;

		Queue<TreeNode> queue = new LinkedList<>();
		queue.offer(root);

		while (!queue.isEmpty()) {
			TreeNode current = queue.poll();
			if (current != null) {
				System.out.print(current.val + " ");
				queue.offer(current.left);
				queue.offer(current.right);
			} else {
				System.out.print("null ");
			}
		}
	}

	private static boolean func(ListNode head, TreeNode root) {
		if (head == null)
			return true;
		else if (root == null) {
			if (head == null)
				return true;
			else
				return false;
		}
		if (head.next == null) {
			if (head.val == root.val) {
				return true;
			} else {
				return false;
			}
		}

		if (head.val != root.val) {
			return false;
		}
		boolean ans = false;
		if (root.left != null && head.next.val == root.left.val) {
			ans = func(head.next, root.left);
		}
		if (ans) {
			return ans;
		}
		if (root.right != null && head.next.val == root.right.val) {
			ans = func(head.next, root.right);
		}
		return ans;
	}

	public static boolean isSubPath(ListNode head, TreeNode root) {
		if (root == null || head == null) {
			return false;
		}
		if (root.val == head.val) {
			if (func(head, root)) {
				return true;
			}
		}
		return isSubPath(head, root.left) || isSubPath(head, root.right);
	}

	public ListNode[] splitListToParts(ListNode head, int k) {
		int n = 0;
		ListNode cur = head;
		while (cur != null) {
			n++;
			cur = cur.next;
		}
		System.out.println("List Size = " + n);
		List<ListNode> list = new ArrayList<>();
		int len = 0, rem = 0;
		if (n < k) {
			len = 1;
		} else {
			len = n / k;
			rem = n % k;
		}
		System.out.println("Len is " + len);
		System.out.println("Rem is " + rem);
		int cnt = len;

		if (rem != 0) {
			cnt = cnt + 1;
			rem--;
		}
		cur = head;
		ListNode start = head;
		while (cur != null) {
			int value = cur.val;
			if (cnt == 1) {
				list.add(start);
				cnt = len;
				if (rem != 0) {
					cnt++;
					rem--;
				}
				ListNode prev = cur;
				cur = cur.next;
				start = cur;
				if (cur != null)
					prev.next = null;
			} else {
				cnt--;
				cur = cur.next;
			}
		}
		ListNode listNode[] = new ListNode[k];
		int i = 0;
		for (i = 0; i < list.size(); i++) {
			listNode[i] = list.get(i);
		}
		while (i < k) {
			listNode[i] = null;
			i++;
		}
		return listNode;
	}

	public static void main(String[] args) {
		Integer[] arr = { 1, 4, 4, null, 2, 2, null, 1, null, 6, 8, null, null, null, null, 1, 3 };
		Integer[] arr2 = { 1, 2, 3 };

		TreeNode root = createTreeFromArray(arr);
		ListNode head = createListFromArray(arr2);
		Tree tree = new Tree();
		ListNode[] listarray = tree.splitListToParts(head, 5);
		for (ListNode node : listarray) {
			System.out.println();
			printList(node);
		}
//        System.out.println(isSubPath(head, root));
	}
}
