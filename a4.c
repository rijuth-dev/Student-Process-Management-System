#include <stdio.h>

#define MAX 50

int main() {
    int frames[MAX], time[MAX], pages[MAX];
    int n, f;
    int pageFaults = 0, clock = 0,replPage;

    // Input
    printf("Enter number of student registrations (page access): ");
    scanf("%d", &n);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("Enter registration order (page reference sequence):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames
    for (int i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\n--- LRU Page Replacement ---\n");

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        // Check if page is already in memory (Page Hit)
        for (int j = 0; j < f; j++) {
            if (frames[j] == page) {
                found = 1;
                time[j] = ++clock;
                printf("\nPage %d → HIT", page);
                break;
            }
        }

        // If not found → Page Fault
        if (!found) {
            int pos = 0;

            // Find LRU page (minimum time)
            for (int j = 1; j < f; j++) {
                if (time[j] < time[pos]) {
                    pos = j;
                }
            }
            replPage=frames[pos];
            printf(time[pos]>0?"\nPage %d → FAULT (Loaded into Frame %d by replacing page %d )":"\nPage %d → FAULT (Loaded into Frame %d )", page, pos , replPage);
            frames[pos] = page;
            time[pos] = ++clock;
            pageFaults++;

        }

        // Display current frame status
        printf("\nFrames: ");
        for (int j = 0; j < f; j++) {
            if (frames[j] != -1)
                printf(" %3d ", frames[j]);
            else
                printf("  -  ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}



// required input
// 20
// 16
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
