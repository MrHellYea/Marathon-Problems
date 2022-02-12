#include <bits/stdc++.h>

#define lli long long int;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);

using namespace std;

void rotate(int x);
void F();
void FB();
void B();
void BB();
void R();
void RB();
void L();
void LB();
void U();
void UB();
void D();
void DB();

char cube[6][3][3];

int main() {
    ibs; cti;
    int n, rot;
    char aux;
    cin >> n;

    while (n--) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> aux;
                cube[0][i][j] = aux;
            }
        }

        for (int k = 0; k < 3; k++) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    cin >> aux;
                    cube[i + 1][k][j] = aux;
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> aux;
                cube[5][i][j] = aux;
            }
        }

        do {
            cin >> rot;
            if (rot == 1) {L();}
            else if (rot == -1) {LB();}
            else if (rot == 2) {F();}
            else if (rot == -2) {FB();}
            else if (rot == 3) {R();}
            else if (rot == -3) {RB();}
            else if (rot == 4) {B();}
            else if (rot == -4) {BB();}
            else if (rot == 5) {U();}
            else if (rot == -5) {UB();}
            else if (rot == 6) {D();}
            else if (rot == -6) {DB();}
        } while (rot);

        bool fixed = true;
        for (int k = 0; k < 6; k++) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (cube[k][i][j] != cube[k][0][0]) {
                        cout << "No, you are wrong!\n";
                        fixed = false; i = 3; k = 6; break;
                    }
                }
            }
        }
        if (fixed) cout << "Yes, grandpa!\n";
    }

    return 0;
}

void rotate(int x) {
    char aux = cube[x][0][2];

	cube[x][0][2] = cube[x][0][0];
	cube[x][0][0] = cube[x][2][0];
	cube[x][2][0] = cube[x][2][2];
	cube[x][2][2] = aux;

	char aux2 = cube[x][1][2];

	cube[x][1][2] = cube[x][0][1];
	cube[x][0][1] = cube[x][1][0];
	cube[x][1][0] = cube[x][2][1];
	cube[x][2][1] = aux2;
}

void F() {
    char aux = cube[3][0][0];
	char aux2 = cube[3][1][0];
	char aux3 = cube[3][2][0];

	cube[3][0][0] = cube[0][2][0];
	cube[3][1][0] = cube[0][2][1];
	cube[3][2][0] = cube[0][2][2];

	cube[0][2][0] = cube[1][2][2];
	cube[0][2][1] = cube[1][1][2];
	cube[0][2][2] = cube[1][0][2];

	cube[1][2][2] = cube[5][0][2];
	cube[1][1][2] = cube[5][0][1];
	cube[1][0][2] = cube[5][0][0];

	cube[5][0][2] = aux;
	cube[5][0][1] = aux2;
	cube[5][0][0] = aux3;

	rotate(2);
}

void FB() {
    char aux = cube[3][0][0];
	char aux2 = cube[3][1][0];
	char aux3 = cube[3][2][0];

	cube[3][0][0] = cube[5][0][2];
	cube[3][1][0] = cube[5][0][1];
	cube[3][2][0] = cube[5][0][0];

	cube[5][0][2] = cube[1][2][2];
	cube[5][0][1] = cube[1][1][2];
	cube[5][0][0] = cube[1][0][2];

	cube[1][2][2] = cube[0][2][0];
	cube[1][1][2] = cube[0][2][1];
	cube[1][0][2] = cube[0][2][2];

	cube[0][2][0] = aux;
	cube[0][2][1] = aux2;
	cube[0][2][2] = aux3;

	rotate(2); rotate(2); rotate(2);
}

void B() {
    char aux = cube[3][0][2];
	char aux2 = cube[3][1][2];
	char aux3 = cube[3][2][2];

	cube[3][0][2] = cube[5][2][2];
	cube[3][1][2] = cube[5][2][1];
	cube[3][2][2] = cube[5][2][0];

	cube[5][2][2] = cube[1][2][0];
	cube[5][2][1] = cube[1][1][0];
	cube[5][2][0] = cube[1][0][0];

	cube[1][2][0] = cube[0][0][0];
	cube[1][1][0] = cube[0][0][1];
	cube[1][0][0] = cube[0][0][2];

	cube[0][0][0] = aux;
	cube[0][0][1] = aux2;
	cube[0][0][2] = aux3;

	rotate(4);
}

void BB() {
    char aux = cube[3][0][2];
	char aux2 = cube[3][1][2];
	char aux3 = cube[3][2][2];

	cube[3][0][2] = cube[0][0][0];
	cube[3][1][2] = cube[0][0][1];
	cube[3][2][2] = cube[0][0][2];

	cube[0][0][0] = cube[1][2][0];
	cube[0][0][1] = cube[1][1][0];
	cube[0][0][2] = cube[1][0][0];

	cube[1][2][0] = cube[5][2][2];
	cube[1][1][0] = cube[5][2][1];
	cube[1][0][0] = cube[5][2][0];

	cube[5][2][2] = aux;
	cube[5][2][1] = aux2;
	cube[5][2][0] = aux3;

	rotate(4); rotate(4); rotate(4);
}

void L() {
    char aux = cube[0][0][0];
	char aux2 = cube[0][1][0];
	char aux3 = cube[0][2][0];

	cube[0][0][0] = cube[4][2][2];
	cube[0][1][0] = cube[4][1][2];
	cube[0][2][0] = cube[4][0][2];

	cube[4][2][2] = cube[5][0][0];
	cube[4][1][2] = cube[5][1][0];
	cube[4][0][2] = cube[5][2][0];

	cube[5][0][0] = cube[2][0][0];
	cube[5][1][0] = cube[2][1][0];
	cube[5][2][0] = cube[2][2][0];

	cube[2][0][0] = aux;
	cube[2][1][0] = aux2;
	cube[2][2][0] = aux3;

	rotate(1);

}

void LB() {
    char aux = cube[0][0][0];
	char aux2 = cube[0][1][0];
	char aux3 = cube[0][2][0];

	cube[0][0][0] = cube[2][0][0];
	cube[0][1][0] = cube[2][1][0];
	cube[0][2][0] = cube[2][2][0];

	cube[2][0][0] = cube[5][0][0];
	cube[2][1][0] = cube[5][1][0];
	cube[2][2][0] = cube[5][2][0];

	cube[5][0][0] = cube[4][2][2];
	cube[5][1][0] = cube[4][1][2];
	cube[5][2][0] = cube[4][0][2];

	cube[4][2][2] = aux;
	cube[4][1][2] = aux2;
	cube[4][0][2] = aux3;

	rotate(1); rotate(1); rotate(1);
}

void R() {
    char aux = cube[0][0][2];
	char aux2 = cube[0][1][2];
	char aux3 = cube[0][2][2];

	cube[0][0][2] = cube[2][0][2];
	cube[0][1][2] = cube[2][1][2];
	cube[0][2][2] = cube[2][2][2];

	cube[2][0][2] = cube[5][0][2];
	cube[2][1][2] = cube[5][1][2];
	cube[2][2][2] = cube[5][2][2];

	cube[5][0][2] = cube[4][2][0];
	cube[5][1][2] = cube[4][1][0];
	cube[5][2][2] = cube[4][0][0];

	cube[4][2][0] = aux;
	cube[4][1][0] = aux2;
	cube[4][0][0] = aux3;
	
	rotate(3);
}

void RB() {
    char aux = cube[0][0][2];
	char aux2 = cube[0][1][2];
	char aux3 = cube[0][2][2];

	cube[0][0][2] = cube[4][2][0];
	cube[0][1][2] = cube[4][1][0];
	cube[0][2][2] = cube[4][0][0];

	cube[4][2][0] = cube[5][0][2];
	cube[4][1][0] = cube[5][1][2];
	cube[4][0][0] = cube[5][2][2];

	cube[5][0][2] = cube[2][0][2];
	cube[5][1][2] = cube[2][1][2];
	cube[5][2][2] = cube[2][2][2];

	cube[2][0][2] = aux;
	cube[2][1][2] = aux2;
	cube[2][2][2] = aux3;
	
	rotate(3); rotate(3); rotate(3);
}

void U() {
    char aux = cube[1][0][0];
    char aux2 = cube[1][0][1];
    char aux3 = cube[1][0][2];

	cube[1][0][0] = cube[2][0][0];
    cube[1][0][1] = cube[2][0][1];
    cube[1][0][2] = cube[2][0][2];
	cube[2][0][0] = cube[3][0][0];
    cube[2][0][1] = cube[3][0][1];
    cube[2][0][2] = cube[3][0][2];
	cube[3][0][0] = cube[4][0][0];
    cube[3][0][1] = cube[4][0][1];
    cube[3][0][2] = cube[4][0][2];
	cube[4][0][0] = aux;
    cube[4][0][1] = aux2;
    cube[4][0][2] = aux3;

	rotate(0);
}

void UB() {
	char aux = cube[1][0][0];
    char aux2 = cube[1][0][1];
    char aux3 = cube[1][0][2];

	cube[1][0][0] = cube[4][0][0];
    cube[1][0][1] = cube[4][0][1];
    cube[1][0][2] = cube[4][0][2];
	cube[4][0][0] = cube[3][0][0];
    cube[4][0][1] = cube[3][0][1];
    cube[4][0][2] = cube[3][0][2];
	cube[3][0][0] = cube[2][0][0];
    cube[3][0][1] = cube[2][0][1];
    cube[3][0][2] = cube[2][0][2];
	cube[2][0][0] = aux;
    cube[2][0][1] = aux2;
    cube[2][0][2] = aux3;

	rotate(0); rotate(0); rotate(0);
}

void D() {
	char aux = cube[1][2][0];
    char aux2 = cube[1][2][1];
    char aux3 = cube[1][2][2];

	cube[1][2][0] = cube[4][2][0];
    cube[1][2][1] = cube[4][2][1];
    cube[1][2][2] = cube[4][2][2];
	cube[4][2][0] = cube[3][2][0];
    cube[4][2][1] = cube[3][2][1];
    cube[4][2][2] = cube[3][2][2];
	cube[3][2][0] = cube[2][2][0];
    cube[3][2][1] = cube[2][2][1];
    cube[3][2][2] = cube[2][2][2];
	cube[2][2][0] = aux;
    cube[2][2][1] = aux2;
    cube[2][2][2] = aux3;

	rotate(5);
}

void DB() {
    char aux = cube[1][2][0];
    char aux2 = cube[1][2][1];
    char aux3 = cube[1][2][2];

	cube[1][2][0] = cube[2][2][0];
    cube[1][2][1] = cube[2][2][1];
    cube[1][2][2] = cube[2][2][2];
	cube[2][2][0] = cube[3][2][0];
    cube[2][2][1] = cube[3][2][1];
    cube[2][2][2] = cube[3][2][2];
	cube[3][2][0] = cube[4][2][0];
    cube[3][2][1] = cube[4][2][1];
    cube[3][2][2] = cube[4][2][2];
	cube[4][2][0] = aux;
    cube[4][2][1] = aux2;
    cube[4][2][2] = aux3;

	rotate(5); rotate(5); rotate(5);
}
