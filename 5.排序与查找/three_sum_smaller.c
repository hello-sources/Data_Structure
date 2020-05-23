/*************************************************************************
    > File Name: three_sum_smaller.c
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sat 23 May 2020 07:44:22 PM CST
 ************************************************************************/




quick_sort(int *nums, int left, int right) {
    if (left > right) return ;
    int i = left, j = right;
    int key = nums[left];
    while (i < j) {
        while (i < j && key <= nums[j]) j--;
        nums[i] = nums[j];
        while (i < j && key >= nums[i]) i++;
        nums[j] = nums[i];
    }
    nums[i] = key;
    quick_sort(nums, left, i - 1);
    quick_sort(nums, i + 1, right);
}

int two_sum_smaller(int *nums, int n, int target) {
    if (n <= 1) return 0;
    int head = 0, tail = n - 1, ans = 0;
    while (head < tail) {
        while (head < tail && nums[head] + nums[tail] < target) head++;
        if (head == tail) break;
        ans += head;
        tail--;
    }
    ans += (head + 1) * head / 2;
    return ans;
}

int three_sum_smaller(int *nums, int length, int target) {
    quick_sort(nums, 0, length - 1);
    int cnt = 0;
    for (int i = 0; i < length; i++) {
        cnt += two_sum_smaller(nums + i + 1, length - i - 1, target - nums[i]);
    }
    return cnt;
}
