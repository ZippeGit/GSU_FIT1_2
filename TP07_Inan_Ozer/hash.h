#ifndef _HASH_H
#define _HASH_H

#define MAXBUCKETS 10000

typedef struct key {
  char* word;
  unsigned long count;
  struct key *next;
} Key;

unsigned long hash_compute(const char *str);
Key* hash_lookup(Key **table, const char *str, int create);
void hash_free(Key **table);
void hash_dump(Key **table,int n);
int hash_count_word(Key **table,const char *str); 
void hash_same_code(Key **table,const char *str);

#endif
