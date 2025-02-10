public class s34_FirstandLastPosition {
    public static void main(String[] args) {
        int[] nums = {1,1,2,2,3,3,4,4,4,6};
        int target = 4;
        System.out.println(searchRange(nums,target));
    }
    public static int[] searchRange(int[] nums, int target){
        int[] ans = {-1,-1};
        int start = search(nums,target,true);
        int end = search(nums,target,false);
        ans[0]=start;
        ans[1]=end;
        return ans;
    }
    static int search(int[] nums,int target,boolean findStartIndex){
        int ans = -1;
        int start = 0;
        int end = nums.length-1;

        while (start<=end){
            //mid = (start+end)/2 this may exceed the range of int
            int mid = start+(end-start)/2;

            if (target<nums[mid]){
                end =mid-1;
            } else if (target>nums[mid]) {
                start = mid+1;
            }else {
                ans = mid;
                if (findStartIndex==true){
                    end = mid-1;
                }else {
                    start=mid+1;
                }
            }
        }
        return ans;
    }
}
