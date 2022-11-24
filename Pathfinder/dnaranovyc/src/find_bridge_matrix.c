#include "../inc/pathfinder.h"

int **find_bridge_matrix(t_map map) {

  int x;
  int y;
  int sum = 0;

  int **bridge_matrix = (int **)malloc(map.nbr_of_islands * sizeof(int *));
  for (int i = 0; i < map.nbr_of_islands; i++)
    bridge_matrix[i] = (int *)malloc(map.nbr_of_islands * sizeof(int));

  for (int i = 0; i < map.nbr_of_islands; i++)
    for (int j = 0; j < map.nbr_of_islands; j++)
      bridge_matrix[i][j] = SOME_BIG_INT;

  for (int i = 1; map.file_lines[i]; i++) {

    char **temp = find_path(map.file_lines[i]);

    if (mx_atoi(temp[2]) >= __INT_MAX__) {
      mx_printerr("error: sum of bridges lengths is too big\n");
      exit(0);
    }

    x = mx_get_strarr_index(map.islands, temp[0]);
    y = mx_get_strarr_index(map.islands, temp[1]);

    bridge_matrix[x][y] = mx_atoi(temp[2]);
    bridge_matrix[y][x] = mx_atoi(temp[2]);

    mx_del_strarr(&temp);
  }

  for (int i = 1; map.file_lines[i]; i++) {
    char **temp = find_path(map.file_lines[i]);

    sum += mx_atoi(temp[2]);

    if (sum >= __INT_MAX__) {
      mx_printerr("error: sum of bridges lengths is too big\n");
      exit(0);
    }

    mx_del_strarr(&temp);
  }

  return bridge_matrix;
}
