#include "../inc/pathfinder.h"

void print_all(t_map map) {
    map.way_to_island = (int *)malloc((map.nbr_of_islands + 1) * sizeof(int));
    for (int i = 0; i < map.nbr_of_islands; i++) {
        for (int j = i + 1; j < map.nbr_of_islands; j++) {
            map.way_to_island[0] = j;
            map.way_to_island[1] = i;
            print_one(map, 1);
        }
    }
    free(map.way_to_island);
}

void print_one(t_map map, int number_of_steps) {

    int start_island = map.way_to_island[0];
    int end_island = map.way_to_island[number_of_steps];

    for (int i = 0; i < map.nbr_of_islands; i++) {
        if((map.bridge_matrix[end_island][i] == map.matrix_of_paths[end_island][start_island] - map.matrix_of_paths[i][start_island])
        && i != map.way_to_island[number_of_steps]) {

            number_of_steps++;
            map.way_to_island[number_of_steps] = i;

            print_one(map, number_of_steps);

            number_of_steps--;
        }
    }

    if (map.way_to_island[number_of_steps] != start_island) {
        return;
    } 

    mx_printstr("========================================\nPath: ");
    mx_printstr(map.islands[map.way_to_island[1]]);
    mx_printstr(" -> ");
    mx_printstr(map.islands[map.way_to_island[0]]);
    mx_printstr("\nRoute: ");
    if (number_of_steps > 2) {
        for (int i = 1; i < number_of_steps + 1; i++) {
            mx_printstr(map.islands[map.way_to_island[i]]);
            if (i < number_of_steps)
                mx_printstr(" -> ");

        }
    } else {
        mx_printstr(map.islands[map.way_to_island[1]]);
        mx_printstr(" -> ");
        mx_printstr(map.islands[map.way_to_island[0]]);
    }
    mx_printstr("\nDistance: ");
    if (number_of_steps > 2) {
       for (int i = 1; i < number_of_steps; i++) {
            int temp = map.bridge_matrix[map.way_to_island[i]][map.way_to_island[i + 1]];

            mx_printint(temp);

            if (i < number_of_steps - 1)
                mx_printstr(" + ");
        }
        mx_printstr(" = ");
        mx_printint(map.matrix_of_paths[map.way_to_island[0]][map.way_to_island[1]]);
    } else {
        mx_printint(map.matrix_of_paths[map.way_to_island[0]][map.way_to_island[1]]);
    }
    mx_printstr("\n========================================\n");

}
