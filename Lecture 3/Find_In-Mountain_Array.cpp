/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int peak(MountainArray &a, int n) {
        int s = 0;
        int e = n - 1;
        int ans = -1;

        while (s <= e) {
            int mid = (s + e) / 2;
            if (a.get(mid) < a.get(mid + 1)) {
                s = mid + 1;
            } else {
                e = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }

    int BSAS(MountainArray a, int s, int e, int target) {
        int ans = -1;
        while (s <= e) {
            int mid = (s + e) / 2;
            int value = a.get(mid);
            if (value == target) {
                return mid;
            } else if (value < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
    int BSDS(MountainArray a, int s, int e, int target) {
        int ans = -1;
        while (s <= e) {
            int mid = (s + e) / 2;
            int value = a.get(mid);
            if (value == target) {
                return mid;
            } else if (value > target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArray.length();
        int k = peak(mountainArray, n);

        int ans = BSAS(mountainArray, 0, k, target);
        if (ans != -1) {
            return ans;
        }
        return BSDS(mountainArray, k + 1, n - 1, target);
    }
};