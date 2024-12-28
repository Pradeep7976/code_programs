import java.util.*;

class Solution {
    public static int solution(int[] arr) {
        int N = arr.length;
        int ans = 0;
        // for(int i=N/2-1;i>=0;i--){
        // heapify(arr,N,i);
        // }
        // for(int i=N-1;i>0;i--){
        // int temp=arr[0];
        // arr[0]=arr[i];
        // arr[i]=temp;
        // heapify(arr, i, 0);
        // }
        Arrays.sort(arr);
        for (int i = 0; i < N; i++) {
            if (i == 0) {
                if (arr[i] != i + 1) {
                    ans = i + 1;
                    break;
                }
            } else if (arr[i] != arr[i - 1] || arr[i] == i + 1) {
                continue;
            } else {
                ans = i + 1;
                break;
            }

        }
        System.out.println(arr[arr.length - 1] + 1);
        return arr[arr.length - 1] + 1;
    }

    static void heapify(int arr[], int N, int i) {
        int lar = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < N && arr[l] > arr[lar]) {
            lar = l;
        } else if (r < N && arr[r] > arr[lar]) {
            lar = r;
        }

        if (lar != i) {
            heapify(arr, N, lar);
        }
    }

    public static void main(String[] args) throws java.lang.Exception {
        

    }
}
