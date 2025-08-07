#ifndef FUNC_H
#define FUNC_H

#define MAX_LINE_LENGTH 1024
#define HARD_HANDS 11
#define SOFT_HANDS  8
#define PAIR_HANDS  10
#define DEALER_UPCARD 10

char ***allocate_dealer_arr(int n_rows, int size_of_data);

void free_dealer_arr( char*** array, int n_rows, int n_cols);

char*** file_process( char* file_name, int n_rows, int size_of_data);

int rand_card(int min, int max);

void print_card(char value);

void print_2_cards(char value1 , char value2);

#endif