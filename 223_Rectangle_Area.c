// Find the total area covered by two rectilinear rectangles in a 2D plane.
// 
// Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
// 
// Assume that the total area is never beyond the maximum possible value of int.

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    return (C-A)*(D-B)+(G-E)*(H-F)-overlap(A,C,E,G)*overlap(B,D,F,H);
}

int overlap(int A, int C, int E, int G) {
    // overlap of interval [A,C] and [E,G]
    
    if (C<=E || A>=G) {
        return 0;
    }
    else if (A<=E) {
        if (C<=G) {
            return C-E;
        }
        else {
            return G-E;
        }
    }
    else {
        if (C>=G) {
            return G-A;
        }
        else {
            return C-A;
        }
    }
}
