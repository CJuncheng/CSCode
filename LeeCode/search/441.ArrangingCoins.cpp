int arrangeCoins(int n) {
        /*
        int lo = 1, hi = n;
        while(hi>lo) {
            int mid  = lo + ((hi-lo)>>1);
            long res = mid * 1L * (mid + 1) / 2;
            res <= n ? lo=mid+1 : hi = mid;
        }
        return lo==1?1:lo-1;
        */
    int lo = 1, hi = n;
    while(hi>lo) {
        int mid  = lo + ((hi-lo+1)>>1); // 向上取整
        (long) mid * (mid + 1) / 2 <= n ? lo=mid : hi = mid-1;
    }
    return lo;
}