void mx_printchar(char c);

void mx_printint(int n) {
	char buffer[12];
	int i = 0;
	if (n == 0)
		mx_printchar('0'); 
	else if (n < 0) {
		if (n == -2147483648) {
			mx_printint(-214748364);
			mx_printchar('8');
			mx_printchar('\n');
		} else {
			mx_printchar('-');
			mx_printint(-n);
		}
	} else {
		for (; n != 0; n /= 10) 
			buffer[i++] = '0' + n % 10;
		for (int j = i - 1; j >= 0; j--)
			mx_printchar(buffer[j]);
		mx_printchar('\n');
	}
	if (n > 0) {
		mx_printchar('\n');
	}
}

// int main() {
// 	mx_printint(-2147483647); 
// }
