void reverseBinaryArray(int arr[], int n) {
    int l = 0, r = n - 1;
    while (l < r) {
        arr[l] ^= arr[r];
        arr[r] ^= arr[l];
        arr[l] ^= arr[r];
        l++;
        r--;
    }
}
