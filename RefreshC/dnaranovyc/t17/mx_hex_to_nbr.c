#include <stdbool.h>
#include <stdio.h>
bool mx_isalpha(int c);
bool mx_isdigit(int c);
bool mx_islower(int c);
bool mx_isupper(int c);

unsigned long mx_hex_to_nbr(const char *hex) {
    if (hex == NULL) return 0;
    int size = 0;
    unsigned long long int res = 0;
    while (hex[size] != '\0')
        size++;
    size--;
    unsigned long int hex_count = 1;
    for (int i = size; i >= 0; i--) {
        if (mx_isalpha(hex[i]) == 1) {
            if (mx_islower(hex[i]) == 1)
                res += (hex[i] - 87) * hex_count;
            if (mx_isupper(hex[i]) == 1)
                res += (hex[i] - 55) * hex_count;
        }
        if (mx_isdigit(hex[i]) == 1)
            res += (hex[i] - 48) * hex_count;
        hex_count *= 16;
    }
    return res;
}

// int main() {
//     printf("%lu\n", mx_hex_to_nbr("C4"));
//     printf("%lu\n", mx_hex_to_nbr("FADE"));
//     printf("%lu\n", mx_hex_to_nbr("ffffffffffff"));
//     return 0;
// }

bool mx_isalpha(int c) {
    return ((c >= 'a' 
    && c <= 'z') 
    || (c >= 'A' 
    && c <= 'Z') 
    ? 1 : 0);
}
bool mx_isdigit(int c) {
    return (c >= '0' 
            && c <= '9' 
            ? 1 : 0);
}
bool mx_islower(int c) {
   return (c >= 'a' 
            && c <= 'z' 
            ? 1 : 0);
}
bool mx_isupper(int c) {
    return (c >= 'A' 
    && c <= 'Z');
}
