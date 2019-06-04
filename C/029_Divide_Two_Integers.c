int divide(int dividend, int divisor) {
    
    // Divide two integers without using multiplication, division and mod operator.
    // If it is overflow, return MAX_INT.
    
    int s,ans,k;
    long d1,d2,s1[35],s2[35];
    
    d1=dividend;
    d2=divisor;
    
    if (d2==0) {
        return INT_MAX;
    }
    else if (d2==1) {
        return dividend;
    }
    else if (d2==-1) {
        if (d1==INT_MIN) {
            return INT_MAX;
        }
        else {
            return -d1;
        }
    }
    
    if (d1==0) {
        return 0;
    }
    
    if (d2>0) {
        if (d1>0) {
            s=1;
        }
        else {
            d1=-d1;
            s=-1;
        }
    }
    else {
        d2=-d2;
        if (d1>0) {
            s=-1;
        }
        else {
            d1=-d1;
            s=1;
        }
    }
    
    if (d1<d2) {
        return 0;
    }

    k=0;
    s1[0]=d2;
    s1[1]=s1[0]+s1[0];
    s2[0]=1;
    s2[1]=2;

    while (s1[k+1]<=d1) {
        k++;

        s1[k+1]=s1[k]+s1[k];
        s2[k+1]=s2[k]+s2[k];
    }
    
    ans=0;
    for (int i=k;i>=0;i--) {
        if (s1[i]<=d1) {
            d1-=s1[i];
            ans+=s2[i];
            
            if (d1<d2) {
                break;
            }
        }
    }
    
    return s*ans;
}
