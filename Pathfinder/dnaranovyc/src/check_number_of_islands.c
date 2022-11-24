#include "../inc/pathfinder.h"

void check_number_of_islands(char **islands, int lines, int nbr_of_islands) {
    int count = 0;
    
    for (int i = 0; i < lines; i++) 
        if (islands[i][0] != ' ') 
            count++;

    if (count != nbr_of_islands) {
        mx_del_strarr(&islands);
        mx_printerr("error: invalid number of islands\n");
        exit(0);
    }
}
