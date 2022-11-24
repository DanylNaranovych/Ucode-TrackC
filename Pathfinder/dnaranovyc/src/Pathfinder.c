#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return -1;
    }
    if (open(argv[1], O_RDONLY) < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        return -1;
    }

    char *file = mx_file_to_str(argv[1]);
    check_all_errors(file, argv);
    t_map map;
    map.file_lines = mx_strsplit(file, '\n');
    map.nbr_of_islands = mx_atoi(map.file_lines[0]);
    map.islands = find_islands(file, map.nbr_of_islands);
    map.bridge_matrix = find_bridge_matrix(map);
    map.matrix_of_paths = algoritm(map);
    print_all(map);

    mx_strdel(&file);
    mx_del_strarr(&map.file_lines);
    mx_del_strarr(&map.islands);
    mx_del_2dintarr(&map.bridge_matrix, map.nbr_of_islands);
    mx_del_2dintarr(&map.matrix_of_paths, map.nbr_of_islands);

    return 0;
}
