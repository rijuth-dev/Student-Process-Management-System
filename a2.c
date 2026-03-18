#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define STUDENTS 5
#define COURSES 3

// Seats available in each course
int seats[COURSES] = {10, 15, 8};

// Mutex for seat allocation
pthread_mutex_t lock;

// Semaphores for courses
sem_t course_sem[COURSES];

void* bookSeat(void* arg)
{
    int student_id = *(int*)arg;

    // Each student tries to book a random course
    int course = student_id % COURSES;

    printf("Student %d trying to book Course %d\n", student_id, course);

    // Wait if no seats available
    sem_wait(&course_sem[course]);

    // Lock critical section
    pthread_mutex_lock(&lock);

    if(seats[course] > 0)
    {
        seats[course]--;
        printf("Student %d successfully booked Course %d | Remaining seats: %d\n",
               student_id, course, seats[course]);
    }

    pthread_mutex_unlock(&lock);

    sleep(1);

    pthread_exit(NULL);
}

int main()
{
    pthread_t students[STUDENTS];
    int id[STUDENTS];

    pthread_mutex_init(&lock, NULL);

    // Initialize semaphores with seat count
    sem_init(&course_sem[0], 0, 10);
    sem_init(&course_sem[1], 0, 15);
    sem_init(&course_sem[2], 0, 8);

    for(int i = 0; i < STUDENTS; i++)
    {
        id[i] = i + 1;
        pthread_create(&students[i], NULL, bookSeat, &id[i]);
    }

    for(int i = 0; i < STUDENTS; i++)
    {
        pthread_join(students[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    for(int i = 0; i < COURSES; i++)
        sem_destroy(&course_sem[i]);

    return 0;
}
