void mx_printchar(char c);
int mx_strlen(const char *s);
void mx_printstr(const char *s);

void mx_print_args(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        mx_printstr(argv[i]);
        mx_printchar('\n');
    }
}

int main(int argc, char *argv[]) {
    mx_print_args(argc, argv);
}
