double myPow(double x, int n) {
    if (n==0) {
        return 1.0;
    }
    else if (n>0){
      return (n%2==0) ? myPow(x*x,n/2) : myPow(x*x,n/2)*x;
    }
    else {
      return (n%2==0) ? myPow(x*x,n/2) : myPow(x*x,n/2)/x;
    }
}
