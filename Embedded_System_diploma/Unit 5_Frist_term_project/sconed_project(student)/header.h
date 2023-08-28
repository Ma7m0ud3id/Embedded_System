/*
 * header.h
 *
 *  Created on: Aug 22, 2023
 *      Author: mahmo
 */

#ifndef HEADER_H_
#define HEADER_H_
#include<stdio.h>
#define DPRINTF(_stats_) printf(_stats_)
#define DPRINTFV(_stats_1,_stats_2) printf(_stats_1,_stats_2)
#define DSCANF(_stats_1,_stats_2) scanf(_stats_1,_stats_2)
#define SS fflush(stdout);fflush(stdin);

void add_student_file();
void add_student_manually();
void find_rl();
void find_fn();
void find_c();
void tot_s();
void del_s();
void up_s();
void show_s();

#endif /* HEADER_H_ */
