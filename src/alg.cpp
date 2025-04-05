// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            } else if (arr[i] + arr[j] > value) {
                break;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0, right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            int l = 1, r = 1;
            while (left + l < right && arr[left + l] == arr[left]) l++;
            while (right - r > left && arr[right - r] == arr[right]) r++;
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += (n * (n - 1)) / 2;
                break;
            } else {
                count += l * r;
                left += l;
                right -= r;
            }
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];
        if (target < arr[i]) continue;

        int left = i + 1, right = len - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        int start = left;
        int countTarget = 0;
        while (start < len && arr[start] == target) {
            countTarget++;
            start++;
        }
        count += countTarget;
    }
    return count;
}
