#include stdio.h
#include stdlib.h
#include string.h


int main() {
	char k = malloc(50), msg = malloc(100024), pch, temp;
	int n, i, j, aux, flag;

	int mat = malloc(sizeof(int)  26);
	for (i = 0; i  26; i++) {
		mat[i] = malloc(sizeof(int)  26);
		aux = 0;
		for (j = 0; j  26; j++) {
			if ('a' + j + i  122)
				aux = 26;
			mat[i][j] = 'a' + j + i - aux;
		}
	}

	scanf(%s %i, k, &n);
	for (i = 0; i  n; i++) {
		j = 0;
		flag = 0;
		scanf(%c, &temp);
		scanf(%[^n], msg);
		pch = strtok(msg,  );
		while (pch != NULL) {
			aux = 0;
			if (pch[aux] == 97  pch[aux] == 101  pch[aux] == 105  pch[aux] == 111  pch[aux] == 117) {
				if (!flag) {
					printf(%s, pch);
					flag = 1;
				} else 
					printf( %s, pch);
			} else {
				while (pch[aux] != '0') {
					pch[aux] = mat[k[j % strlen(k)] - 97][pch[aux] - 97];
					aux++;
					j++;
				}
				if (!flag) {
					printf(%s, pch);
					flag = 1;
				} else 
					printf( %s, pch);
			}
			
			pch = strtok(NULL,  );
		}
		printf(n);
	}

	return 0;
}
