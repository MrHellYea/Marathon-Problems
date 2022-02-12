#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;


struct ponto {
	double x, y, comp;
};

double pit(struct ponto, struct ponto);


int main() {
	int i, flag = 0;
	double dist;
	struct ponto maria, jogo;
	
	scanf("%lf %lf %lf", &maria.x, &maria.y, &maria.comp);
	
	for (i = 1; i <= maria.comp; i++) {
		scanf("%lf %lf %lf", &jogo.x, &jogo.y, &jogo.comp);
		dist = pit(maria, jogo);
		
		if (dist < jogo.comp * jogo.comp) {
			if (flag)
				printf(" ");
			else
				flag = 1;
			
			printf("%i", i);
		}
	}
		
	if (!flag)
		printf("%i", -1);
	printf("\n");
		
	return 0;
}


double pit(struct ponto maria, struct ponto jogo) {
	return ((maria.x - jogo.x) * (maria.x - jogo.x)) + ((maria.y - jogo.y) * (maria.y - jogo.y));
}
