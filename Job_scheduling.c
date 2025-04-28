#include <stdio.h>

// Define a structure for Job
typedef struct {
    char name[10];
    int resources;
    int profit;
    float ratio;  // Profit-to-resource ratio
} Job;

// Function to sort jobs based on the ratio (descending)
void sortJobs(Job jobs[], int n) {
	int i,j;
    for ( i = 0; i < n - 1; i++) {
        for ( j = i + 1; j < n; j++) {
            if (jobs[i].ratio < jobs[j].ratio) {
                Job temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }
}

// Function to allocate resources and calculate total profit
void allocateResources(Job jobs[], int n, int totalResources) {
    int resourcesUsed = 0;
    int totalProfit = 0;

    printf("Allocated Jobs: ");
    	int i;
    for ( i = 0; i < n; i++) {
        if (resourcesUsed + jobs[i].resources <= totalResources) {
            resourcesUsed += jobs[i].resources;
            totalProfit += jobs[i].profit;
            printf("%s ", jobs[i].name);
        }
    }

    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    // List of jobs
    Job jobs[] = {
        {"Job1", 2, 50, 50.0 / 2},
        {"Job2", 3, 60, 60.0 / 3},
        {"Job3", 4, 70, 70.0 / 4},
        {"Job4", 5, 100, 100.0 / 5}
    };
    
    int totalResources = 10;  // Total available resources
    int numJobs = sizeof(jobs) / sizeof(jobs[0]);

    // Sort the jobs based on the profit-to-resource ratio
    sortJobs(jobs, numJobs);

    // Allocate resources and print the result
    allocateResources(jobs, numJobs, totalResources);

    return 0;
}
