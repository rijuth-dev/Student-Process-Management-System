#include <stdio.h>
#include <stdbool.h>

#define P 4
#define R 4

int main() {

    // Resources: LabKey, Projector, Textbook, Laptop

    // Allocation Matrix
    int allocation[P][R] = {
        {1, 0, 0, 0},   // Student 1 has LabKey
        {0, 1, 0, 0},   // Student 2 has Projector
        {0, 0, 1, 0},   // Student 3 has Textbook
        {0, 0, 0, 0}    // Student 4 has none
    };

    // Maximum resources each student may need (2 resources)
    int max[P][R] = {
        {1, 1, 0, 0},   // S1 needs LabKey + Projector
        {0, 1, 1, 0},   // S2 needs Projector + Textbook
        {0, 0, 1, 1},   // S3 needs Textbook + Laptop
        {1, 0, 0, 1}    // S4 needs LabKey + Laptop
    };

    // Available resources
    int available[R] = {0, 0, 0, 1};

    int need[P][R];
    int work[R];
    bool finish[P] = {false};

    int safeSequence[P];
    int count = 0;

    // Step 1: Calculate Need Matrix
    for(int i=0;i<P;i++)
    {
        for(int j=0;j<R;j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Print Resource Names
    printf("\nResources:\n");
    printf("R1: LabKey  R2: Projector  R3: Textbook  R4: Laptop\n");

    // Print Allocation Matrix
    printf("\nAllocation Matrix:\n");
    for(int i=0;i<P;i++)
    {
        printf("Student %d : ",i+1);
        for(int j=0;j<R;j++)
            printf("%d ",allocation[i][j]);
        printf("\n");
    }

    // Print Max Matrix
    printf("\nMaximum Requirement Matrix:\n");
    for(int i=0;i<P;i++)
    {
        printf("Student %d : ",i+1);
        for(int j=0;j<R;j++)
            printf("%d ",max[i][j]);
        printf("\n");
    }

    // Print Need Matrix
    printf("\nNeed Matrix:\n");
    for(int i=0;i<P;i++)
    {
        printf("Student %d : ",i+1);
        for(int j=0;j<R;j++)
            printf("%d ",need[i][j]);
        printf("\n");
    }

    // Print Available Resources
    printf("\nAvailable Resources:\n");
    for(int i=0;i<R;i++)
        printf("%d ",available[i]);
    printf("\n");

    // Work = Available
    for(int i=0;i<R;i++)
        work[i] = available[i];

    // Banker's Safety Algorithm
    while(count < P)
    {
        bool found = false;

        for(int i=0;i<P;i++)
        {
            if(finish[i] == false)
            {
                bool possible = true;

                for(int j=0;j<R;j++)
                {
                    if(need[i][j] > work[j])
                    {
                        possible = false;
                        break;
                    }
                }

                if(possible)
                {
                    for(int j=0;j<R;j++)
                        work[j] += allocation[i][j];

                    safeSequence[count] = i;
                    finish[i] = true;
                    count++;
                    found = true;
                }
            }
        }

        if(found == false)
        {
            printf("\nSystem is UNSAFE (Deadlock possible)\n");
            return 0;
        }
    }

    // Safe sequence
    printf("\nSystem is SAFE\n");
    printf("Safe Sequence:\n");

    for(int i=0;i<P;i++)
    {
        printf("Student%d",safeSequence[i]+1);
        if(i != P-1)
            printf(" -> ");
    }

    printf("\n");

    return 0;
}
