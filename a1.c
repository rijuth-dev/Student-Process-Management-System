#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int year;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int completion_time;
} Student;

void simulate_rr(Student* queue[], int count, int quantum, int *current_time, char* q_name) {
    if (count == 0) return;
    
    int completed = 0;
    printf("\n>>> Starting %s (Count: %d) <<<\n", q_name, count);
    
    while (completed < count) {
        for (int i = 0; i < count; i++) {
            if (queue[i]->remaining_time > 0) {
                int execute = (queue[i]->remaining_time > quantum) ? quantum : queue[i]->remaining_time;
                
                printf("[Time %03d] Student ID %02d (Year %d) runs for %d units\n", *current_time, queue[i]->id, queue[i]->year, execute);
                
                *current_time += execute;
                queue[i]->remaining_time -= execute;
                
                if (queue[i]->remaining_time == 0) {
                    completed++;
                    queue[i]->completion_time = *current_time;
                    // Waiting Time = Finish Time - Burst Time
                    queue[i]->waiting_time = queue[i]->completion_time - queue[i]->burst_time;
                    printf("          ** Student ID %02d Finished at %d **\n", queue[i]->id, *current_time);
                }
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Seed for random values
    Student students[20];
    Student *q1[20], *q2[20], *q3[20];
    int c1 = 0, c2 = 0, c3 = 0;
    int current_time = 0;

    // 1. GENERATE AND SHOW INPUTS
    printf("================= REGISTRATION INPUT DATA =================\n");
    printf("%-12s | %-12s | %-15s\n", "Student ID", "Year Level", "Reg Time Reqd");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < 20; i++) {
        students[i].id = i + 1;
        students[i].year = (rand() % 3) + 2; // Randomly assign Year 2, 3, or 4
        students[i].burst_time = (rand() % 10) + 1; // 1-10 units
        students[i].remaining_time = students[i].burst_time;
        students[i].waiting_time = 0;

        printf("ID: %-8d | Year: %-7d | Time: %-2d units\n", 
                students[i].id, students[i].year, students[i].burst_time);

        // Sort into priority queues
        if (students[i].year == 4) q1[c1++] = &students[i];
        else if (students[i].year == 3) q2[c2++] = &students[i];
        else q3[c3++] = &students[i];
    }
    printf("===========================================================\n\n");

    // 2. PROCESS QUEUES
    simulate_rr(q1, c1, 2, &current_time, "Queue 1: SENIORS (Year 4)");
    simulate_rr(q2, c2, 2, &current_time, "Queue 2: JUNIORS (Year 3)");
    simulate_rr(q3, c3, 2, &current_time, "Queue 3: SOPHOMORES (Year 2)");

    // 3. CALCULATE AND SHOW AVERAGES
    float avg_w1 = 0, avg_w2 = 0, avg_w3 = 0;
    for(int i=0; i<c1; i++) avg_w1 += q1[i]->waiting_time;
    for(int i=0; i<c2; i++) avg_w2 += q2[i]->waiting_time;
    for(int i=0; i<c3; i++) avg_w3 += q3[i]->waiting_time;

    printf("\n==================== FINAL STATISTICS =====================\n");
    printf("Year 4 (Seniors)    - Avg Waiting Time: %6.2f units\n", c1 ? avg_w1/c1 : 0);
    printf("Year 3 (Juniors)    - Avg Waiting Time: %6.2f units\n", c2 ? avg_w2/c2 : 0);
    printf("Year 2 (Sophomores) - Avg Waiting Time: %6.2f units\n", c3 ? avg_w3/c3 : 0);
    printf("===========================================================\n");

    return 0;
}
