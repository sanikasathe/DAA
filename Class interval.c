

#include <stdio.h>

#include <stdlib.h>



// Define the structure for an interval

typedef struct Interval {

    int start;

    int end;

} Interval;



// Function to swap two intervals

void swap(Interval *a, Interval *b) {

    Interval temp = *a;

    *a = *b;

    *b = temp;

}



// Function to sort intervals based on their end times

void sortIntervals(Interval intervals[], int n) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (intervals[i].end > intervals[j].end) {

                swap(&intervals[i], &intervals[j]);

            }

        }

    }

}



// Function to erase overlapping intervals

void eraseOverlapIntervals(Interval intervals[], int n) {

    if (n < 2) {

        return;

    }



    sortIntervals(intervals, n);



    int end = intervals[0].end;

    printf("Remaining intervals:\n");

    printf("(%d, %d)\n", intervals[0].start, intervals[0].end);



    for (int i = 1; i < n; i++) {

        if (intervals[i].start < end) {

            continue;

        } else {

            end = intervals[i].end;

            printf("(%d, %d)\n", intervals[i].start, intervals[i].end);

        }

    }

}



int main() {

    int n;

    printf("Enter the number of intervals: ");

    scanf("%d", &n);



    Interval intervals[n];

    printf("Enter the intervals:\n");

    for (int i = 0; i < n; i++) {

        scanf("%d %d", &intervals[i].start, &intervals[i].end);

    }



    eraseOverlapIntervals(intervals, n);



    return 0;

}
