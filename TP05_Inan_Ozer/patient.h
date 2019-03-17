#ifndef PATIENT_H_
#define PATIENT_H_

/* Aciliyetine gore hastalik seviyeleri */
enum Priority {
    PRIO_HEART_ATTACK,  // 0
    PRIO_FRACTURE,      // 1
    PRIO_NAUSEA,        // 2
    PRIO_FEVER,         // 3
    PRIO_HEADACHE,   // 4
    MAX_PRIO,           // 5
};

struct patientInfo {
    /* Aciliyet bilgisi */
    enum Priority prio;
    /* Sosyal guvenlik numarasi */
    int ssn;

    struct patientInfo *next;
};

extern const char *priority_strings[];

struct patientInfo* enqueue(struct patientInfo *head, enum Priority prio, int ssn);
struct patientInfo* dequeue(struct patientInfo **head);
void print_queue(struct patientInfo *head);
int is_empty(struct patientInfo *head);

#endif /* PATIENT_H_ */
