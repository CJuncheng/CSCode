int guessNumber(int n) {
    int lo = 1, hi = n;
    while(lo<hi){
        int mid = lo + ((hi-lo)>>1);
        //guess(mid)<=0 ? hi = mid: lo = mid+1;
    }
    return lo; 
}