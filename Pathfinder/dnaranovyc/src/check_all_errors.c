#include "../inc/pathfinder.h"

void check_all_errors(char *file, char *argv[]) {

    if (mx_strlen(file) == 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(0);
    }

    char **file_lines = mx_strsplit(file, '\n');
    int lines_count = 0;
    while (file_lines[lines_count])
        lines_count++;

    for (int i = 0; file_lines[0][i]; i++) {
        if(!mx_isdigit(file_lines[0][i])) {
            mx_printerr("error: line 1 is not valid\n");
            exit(0);
        }
    }
    
    if (file_lines[0][0] == '0' || file_lines[0][0] == '-') {
        mx_printerr("error: invalid number of islands\n");
        exit(0);
    }

    for (int i = 1, j, temp; i < lines_count; i++) {
        j = 0;
        temp = 0;
        
        while (mx_isalpha(file_lines[i][j]))
            j++;
        
        if (j == 0 || file_lines[i][j] != '-')
            error_broken_string(i + 1);
        
        j++;
        temp = j;

        while (mx_isalpha(file_lines[i][j])) 
            j++;
        
        if (j == temp || file_lines[i][j] != ',') 
            error_broken_string(i + 1);
        
        j++;
        temp = j;

        while (mx_isdigit(file_lines[i][j])) 
            j++;
        
        if (j == temp || file_lines[i][j] != '\0') 
            error_broken_string(i + 1);
    }

    char **temp = (char **)malloc((lines_count + 1) * sizeof(char *));
    for (int i = 0; i < lines_count; i++)
        temp[i] = mx_strndup(file_lines[i], mx_get_char_index(file_lines[i], ','));

    temp[lines_count] = NULL;
    
    for (int i = 0; i < lines_count; i++) {
        for (int j = 0; j < lines_count; j++) {
            if (temp[j][0] == '\0' || j == i) 
                continue;
            if (mx_strcmp(temp[i], temp[j]) == 0) {
                mx_printerr("error: duplicate bridges\n");
                exit(0);
            }    
        }
    }

    mx_del_strarr(&temp);
    
    mx_del_strarr(&file_lines);
}
