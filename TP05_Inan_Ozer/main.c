#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdio.h>

#include "patient.h"

int main(int argc, const char *argv[])
{

    srand(time(NULL));
    struct patientInfo *queue = NULL;
    int i;
   // struct patientInfo *queue= malloc(sizeof(struct patientInfo));

    for (i = 0; i < 10; i++) {
        int ssn = (rand() % 1001) + 1000;
        int sickness = (rand() % MAX_PRIO);
        queue = enqueue(queue, sickness, ssn);
        printf("\n> New patient arrived: %s (priority: %d)] SSN: %d", priority_strings[sickness], sickness, ssn);
        print_queue(queue);

        sleep(1);
        
        if ((rand() % 2) && (rand() % 2)) {
            //Dequeue 
            struct patientInfo *out = dequeue(&queue);
            printf(">>> Patient [%12s (priority: %d) | (SSN: %d)] is now out of the queue!\n",
                    priority_strings[out->prio], out->prio, out->ssn);
        } 
    }

    return 0;
}
