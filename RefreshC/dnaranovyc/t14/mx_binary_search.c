int mx_strcmp(const char *s1, const char *s2);

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int bottom= 0;
    int mid;
    int top = size - 1;
    while(bottom <= top){
        mid = (bottom + top)/2;
        *count += 1;
        if (mx_strcmp(arr[mid], s) == 0){
            return mid;
        } else if (mx_strcmp(arr[mid], s) > 0){
            top = mid - 1;
        } else if (mx_strcmp(arr[mid], s) < 0){
            bottom = mid + 1;
        }
    }
    *count = 0;
    return -1;
}
