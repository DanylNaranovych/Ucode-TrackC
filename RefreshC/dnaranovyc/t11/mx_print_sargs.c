void mx_printchar(char c);
int mx_strlen(const char *s);
void mx_printstr(const char *s);
int mx_strcmp(const char *s1, const char *s2);

void mx_print_sargs(int argc, char *argv[]) {
    for(int i = 1; i < argc; i++){
        for(int j = i+1; j < argc; j++) {
            if(mx_strcmp(argv[i], argv[j]) > 0){
                char* tmp = argv[i];
                argv[i] = argv[j];
                argv[j] = tmp;
            }
        }
    }
    for (int i = 1; i < argc; i++) {
        mx_printstr(argv[i]);
        mx_printchar('\n');
    }
}

int main(int argc, char *argv[]) {
    mx_print_sargs(argc, argv);
}
