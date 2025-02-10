public class s704_BinarySearch {
    public static void main(String[] args) {

    }
    static int binarySearch(int[] arr, int target){
        int start = 0;
        int end = arr.length -1;

        while (start<=end){
            int mid = start +(end-start)/2;

            if (target<arr[mid]){
                end = mid-1;
            } else if (target>arr[mid]) {
                start = start+1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }

    static int binary_search(int[] arr, int target){
        int start = 0;
        int end = arr.length-1;
        int mid = (start+end)/2;
        while (start<end){
            if (target<arr[mid]){
                end = mid-1;
            } else if (target>arr[mid]) {
                start=start+1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
}
