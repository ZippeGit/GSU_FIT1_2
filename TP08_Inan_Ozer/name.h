/*
 * name.h
 *
 *  Created on: Mar 28, 2019
 *      Author: Merve Unlu
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 50
#define DBSIZE 20000

#ifndef NAME_H_
#define NAME_H_

struct Name{
	char name[MAXSIZE];
    int value;
};

struct dbName{
    struct Name db[DBSIZE];
    int currentSize;
};


void print_db(struct dbName d);
void read_name_file(struct dbName* d,char* filename);
void read_value_file(struct dbName* d,char* filename);
int search_uniform(struct dbName d,char* name);
int search_binary(struct dbName d,char* name);

void split_names(struct dbName* dAll,struct dbName* dGood,struct dbName* dBad);
int search_good_bad(struct dbName dGood, struct dbName dBad,char* name);

#endif /* NAME_H_ */
