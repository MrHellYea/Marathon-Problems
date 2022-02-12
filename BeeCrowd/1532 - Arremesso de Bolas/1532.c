#include <stdio.h>
#include <math.h>


int check(int, int);


int main() {
	int dis, vel, i;
	
	scanf("%i %i", &dis, &vel);
	while (dis != 0 && vel != 0) {
		for (i = vel; i > 0; i--) {
			if (check(dis, i)) {
				printf("possivel\n");
				i = 0;
			}
		}
		
		if (i == 0)
			printf("impossivel\n");
		
		scanf("%i %i", &dis, &vel);
	}

	return 0;
}


int check(int distance, int velocity) {
	int result = 0, ran = 0, i;
	
	while (velocity > 0) {
		for (i = 0; i < velocity; i++) {
			ran += velocity;
			if (ran == distance) {
				result = 1;
				i = velocity;
				velocity = 0;
			}
		}
		velocity--;
	}

	return result;
}
