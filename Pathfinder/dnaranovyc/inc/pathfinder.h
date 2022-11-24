#pragma once

#include "../libmx/inc/libmx.h"

#define SOME_BIG_INT 2000000

typedef struct s_map {
    char **file_lines;
    int nbr_of_islands;
    char **islands;
    int **bridge_matrix;
    int **matrix_of_paths;
    int *way_to_island;
}   t_map;

int **algoritm(t_map map);
void check_all_errors(char *file, char *argv[]);
void check_number_of_islands(char **temp, int lines, int nbr_of_islands);
void error_broken_string(int n);
int **find_bridge_matrix(t_map map);
char** find_islands(char *str, int isl_nbr);
char **find_path(char *line);
void print_one(t_map map, int number_of_steps);
void print_all(t_map map);
