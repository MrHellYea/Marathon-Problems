#include <stdio.h>
#include <string.h>

struct nemsei {
	long long int d;
	long long int x;
	long long int y;
};

struct nemsei MDCE(long long int, long long int);

long long int InvMod(int, long long int);

long long int fat(int);

int check(char*, char);


int main() {
	char s[10024];
	int i;
	long long int total;
	
	scanf("%s", s);
	while (*s != 48) {
		total = fat(strlen(s));

		for (i = 0; i < 26; i++) {	
			total = ((total % 100000007) * InvMod(fat(check(s, 97 + i)), 100000007)%100000007)%100000007;
		}
		
		printf("%lli\n", total);
		scanf("%s", s);
	}

	return 0;
}


struct nemsei MDCE(long long int a, long long int b) {
	struct nemsei temp;
	long long int aux_x, aux_y;
	
	if (b == 0) {
		temp.d = a;
		temp.x = 1;
		temp.y = 0;
		
		return temp;
	} else {
		temp = MDCE(b, a % b);
		aux_x = temp.x;
		aux_y = temp.y;
		temp.x = aux_y;
		temp.y = aux_x - (a / b) * aux_y;
		
		return temp;
	}	
}


long long int InvMod(int b, long long int n) {
	struct nemsei temp;
	
	temp = MDCE(b, n);
	
	return (temp.x + n) % n;
}


long long int fat(int n) {
	int i;
	long long int total = 1;
	
	for (i = 2; i <= n; i++)
		total = (total%100000007 * i%100000007)%100000007;
	
	return total;
}


int check(char* string, char x) {
	int total = 0;

	while (*string != '\0') {
		if (*string == x)
			total++;
		string++;
	}
		
	return total;
}
