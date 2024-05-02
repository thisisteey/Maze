#ifndef FILE_UTILITIES_H
#define FILE_UTILITIES_H

/*
 * Description:
 * Header file for file parsing functions and utilities
 */

/* File Opeartion functions */
FILE *open_file(char *filenm);
MazeMap_t read_file(FILE *fileptr);
void close_file(FILE *fileptr);

/* File Info Validation functions */
int count_lines(FILE *fileptr);
void authz_line(int maxln_cnt, char *line, FILE *fileptr, int curr_ln);
MazeMap_t handle_file(char *filenm);

/* Utility functions */
int check_arr(char arr_val, char *arr, unsigned int arr_lent);
char *str_concat(const char *dest_str, const char *src_str);
int slope_region(int angle, int *exp_angle);

#endif
