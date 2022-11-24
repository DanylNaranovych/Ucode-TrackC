#include "../inc/pathfinder.h"

char **find_path(char *line) {

    char **path = (char **)malloc(4 * sizeof(char *));
    for (int i = 0; i <= 3; i++)
        path[i] = NULL;
    
    path[0] = mx_strndup(line, mx_get_char_index(line, '-'));
    line += mx_get_char_index(line, '-') + 1;
    path[1] = mx_strndup(line, mx_get_char_index(line, ','));
    line += mx_get_char_index(line, ',') + 1;
    path[2] = mx_strndup(line, mx_get_char_index(line, '\n'));
     
    return path;
}
