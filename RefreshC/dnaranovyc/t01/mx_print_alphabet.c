#include <unistd.h>

void mx_printchar(char c);

void mx_print_alphabet(void) {
    int lower_temp = 98;
    for (int upper_temp = 65; upper_temp <= 90; upper_temp += 2){
        mx_printchar((char)upper_temp);
        mx_printchar((char)lower_temp);
        lower_temp++;
        lower_temp++;
    }
    mx_printchar('\n');
}

// int main() {
//     mx_print_alphabet();
// }
