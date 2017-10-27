/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool overlap(struct Interval interval1, struct Interval interval2) {
    return !(interval1.start > interval2.end || interval1.end < interval2.start);
}

struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
    struct Interval* newIntervals = (struct Interval*) malloc((intervalsSize+1)*sizeof(struct Interval));

    if (intervals[0].start > newInterval.end) {
        *returnSize=intervalsSize+1;
        newIntervals[0]=newInterval;
        for (int i=0;i<intervalsSize;i++) {
            newIntervals[i+1]=intervals[i];
        }
        
        return newIntervals;
    }
    else if (intervals[intervalsSize-1].end < newInterval.start) {
        *returnSize=intervalsSize+1;
        newIntervals[intervalsSize]=newInterval;
        for (int i=0;i<intervalsSize;i++) {
            newIntervals[i]=intervals[i];
        }
        
        return newIntervals;
    }
    
    int i1=-1;
    int i2;
    
    while (!overlap(intervals[i1+1],newInterval) && intervals[i1+1].end < newInterval.start) {
        i1++;
        newIntervals[i1] = intervals[i1];
    }
    
    i2=i1+1;
    
    newIntervals[i1+1] = newInterval;
    while (overlap(intervals[i2],newInterval)) {
        
        if (intervals[i2].start < newIntervals[i1+1].start) {
            newIntervals[i1+1].start = intervals[i2].start;
        }
        
        if (intervals[i2].end > newIntervals[i1+1].end) {
            newIntervals[i1+1].end = intervals[i2].end;
        }
        
        i2++;
        if (i2==intervalsSize) {
            break;
        }
    }
    
    // 0 ~ i1 and i2 ~ intervalsSize-1 are not overlaping with newInterval
    // i1+1 ~ i2-1 overlap with newInterval
    *returnSize = intervalsSize-i2+i1+2;
    
    if (i2<intervalsSize) {
        for (int i=i2;i<intervalsSize;i++) {
            newIntervals[i1+2-i2+i] = intervals[i];
        }
    }
    
    return newIntervals;
}
