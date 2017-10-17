int mySqrt(int x) {

    // Implement int sqrt(int x).
    // Compute and return the square root of x.
    
    long c1=1,c2=x,a,c;
    
    if (x==0) {
        return 0;
    }
    else if (x<4) {
        return 1;
    }
    else {
        while (c2-c1>1) {
            c=(c1+c2)/2;
            a=c*c;

            if (a==x) {
                return c;
            }
            else if (a>x) {
                c2=c;
            }
            else {
                c1=c;
            }
        }
        
        if (c2*c2<x) {
            return c2;
        }
        else {
            return c1;
        }
    }
}
