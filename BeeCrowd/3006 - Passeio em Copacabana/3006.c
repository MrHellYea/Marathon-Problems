#include <stdio.h>


int find_r(char *, int);


int main() {
	int casos, i, rp, menor, atual, aux, auxaux, atualaux;
	char map[1000024], found;
	
	scanf("%i", &casos);	
	for (i = 0; i < casos; i++) {
		scanf("%s", map);
		rp = find_r(map, 0);
		menor = -1;
		
		while (rp != -1) {
			aux = 0;
			atual = 0;
			while (map[rp - aux] != 'C' && map[rp - aux] != 'F' && rp - aux >= 0) { 
				aux++;
				atual++;
			}
			
			if (rp - aux >= 0) {
				found = map[rp - aux];
				auxaux = aux;
				atualaux = atual;
				while ((map[rp - aux] == found || map[rp - aux] == '.' || map[rp - aux] == 'R') && rp - aux >= 0) {
					aux++;
					atual++;
				}	
				if (rp - aux < 0)
					atual--;
				
				if ((menor == -1 || atual < menor) && rp - aux >= 0)
					menor = atual;
	
				aux = auxaux;
				atual = atualaux;
				while ((map[rp - aux] == found || map[rp - aux] == '.' || map[rp - aux] == 'R') && map[rp - aux] != '\0') { 
					aux--; 
					atual++;
				}

				if (rp - aux == '\0')
					atual--;

				if ((menor == -1 || atual < menor) && map[rp - aux] != '\0') 
					menor = atual;
			} 

			aux = 0;
			atual = 0;
			while (map[rp + aux] != 'C' && map[rp + aux] != 'F' && map[rp + aux] != '\0') {
				aux++;
				atual++;
			} 

			if (map[rp + aux] != '\0') {
				found = map[rp + aux];
				auxaux = aux;
				atualaux = atual;
				while ((map[rp + aux] == found || map[rp + aux] == '.' || map[rp + aux] == 'R') && map[rp + aux] != '\0') {
					aux++;
					atual++;
				}	
		
				if (rp + aux == '\0')
					atual--;
		
				if ((menor == -1 || atual < menor) && map[rp + aux] != '\0')
					menor = atual;

				aux = auxaux;
				atual = atualaux;
				while ((map[rp + aux] == found || map[rp + aux] == '.' || map[rp + aux] == 'R') && rp + aux >= 0) { 
					aux--; 
					atual++;
				}

				if (rp + aux < 0)
					atual--;
			
				if ((menor == -1 || atual < menor) && rp + aux >= 0)
					menor = atual;
			}
			rp = find_r(map, rp + 1);
		}
		printf("%i\n", menor);
	}
	
	return 0;
}


int find_r(char *map, int offset) {
	int i;
	
	for (i = 0; i < offset; i++) {
		map++;
	}
	
	while (*map != 'R' && *map != '\0') {
		offset++;
		map++;
		if (*map == '\0') 
			offset = -1;
	}
	
	return offset;
}
