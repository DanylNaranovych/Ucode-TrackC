#include "../inc/pathfinder.h"

int find_min(int a, int b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}

int **algoritm(t_map map) {

  int **temp = (int **)malloc(map.nbr_of_islands * map.nbr_of_islands * sizeof(int *));
  for (int i = 0; i < map.nbr_of_islands; i++) 
    temp[i] = (int *)malloc(map.nbr_of_islands * sizeof(int));
  
  for (int i = 0; i < map.nbr_of_islands; i++) 
    for (int j = 0; j < map.nbr_of_islands; j++)
      temp[i][j] = map.bridge_matrix[i][j];

  for (int i = 0; i < map.nbr_of_islands; i++)
    for (int j = 0; j < map.nbr_of_islands; j++)
      for (int k = 0; k < map.nbr_of_islands; k++)
        if (temp[j][i] != SOME_BIG_INT && temp[i][k] != SOME_BIG_INT &&
            j != k && temp[j][k] == SOME_BIG_INT)
          temp[j][k] = temp[j][i] + temp[i][k];

  for (int i = 0; i < map.nbr_of_islands; i++)
    for (int j = 0; j < map.nbr_of_islands; j++)
      for (int k = 0; k < map.nbr_of_islands; k++)
        if (temp[j][i] != SOME_BIG_INT && temp[i][k] != SOME_BIG_INT &&
            j != k && temp[j][k] != SOME_BIG_INT)
          temp[j][k] = find_min(temp[j][k], temp[j][i] + temp[i][k]);

  // temp[0] = 0;
  // for (int k = 1; k < map.nbr_of_islands; ++k)
  //     for (int i = 0; i < map.nbr_of_islands; ++i)
  //          for (int j = 0; j < map.nbr_of_islands; ++j)
  //              if (temp[k - 1][j] + map.bridge_matrix[j][i] < temp[k][i])
  //                  temp[k][i] = temp[k - 1][j] + map.bridge_matrix[j][i];

  for (int i = 0; i < map.nbr_of_islands; i++)
    for (int j = 0; j < map.nbr_of_islands; j++)
      if (temp[i][j] >= SOME_BIG_INT)
        temp[i][j] = 0;

  return temp;
}
