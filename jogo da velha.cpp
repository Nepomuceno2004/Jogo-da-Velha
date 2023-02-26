#include <iostream>
#include <string.h>
using namespace std;

void exibir_coordenadas();
void exibir_matriz(char matriz[3][3]);

int main() {
	setlocale(LC_ALL, "Portuguese");
	system("COLOR 0B");

	bool vencedor = false;
	char matriz[3][3] = {' '};
	int contador_linha = 0;

	while(vencedor!=true) {

		system("cls");
		exibir_coordenadas();
		exibir_matriz(matriz);


		if(contador_linha%2==0) {

			int c1, c2;
			bool verif;
			string cord;
			cout << "\n\n\nDigite a posição do X do JOGADOR 1(valores de 1 a 3)(ex: 2x2): ";

			do {

				cin >> cord;
				if(cord.length() == 3) {


					c1 = stoi(cord.substr(0,1));
					c2 = stoi(cord.substr(2,1));


					if(c1 > 3 || c2 > 3 || c1 < 1 || c2 < 1) {
						verif = false;
						cout << "Valores Inválidos. Insira coordenadas X,Y com valores de 1 a 3(ex: 1x2): ";
					}
					else {
						verif = true;
					}

					if(matriz[c1-1][c2-1] == 'X' || matriz[c1-1][c2-1] == 'O') {
						verif = false;
						cout << "Posição já ocupada. Escolha outra coordenada: ";
					}

				}
				else {
					verif = false;
					cout << "Valores Inválidos. Insira coordenadas X,Y com valores de 1 a 3(ex: 3x1): ";
				}

			} while(verif == false);

			matriz[c1-1][c2-1] = 'X';
			contador_linha++;

		}
		else {
			int c1, c2;
			bool verif;
			string cord;

			cout << "\n\nDigite a posição do O do JOGADOR 2(ex: 3x1): ";

			do {

				cin >> cord;
				if(cord.length() == 3) {


					c1 = stoi(cord.substr(0,1));
					c2 = stoi(cord.substr(2,1));


					if(c1 > 3 || c2 > 3 || c1 < 1 || c2 < 1) {
						verif = false;
						cout << "Valores Inválidos. Insira coordenadas X,Y com valores de 1 a 3(ex: 1x2): ";
					}
					else {
						verif = true;
					}

					if(matriz[c1-1][c2-1] == 'X' || matriz[c1-1][c2-1] == 'O') {
						verif = false;
						cout << "Posição já ocupada. Escolha outra coordenada: ";
					}

				}
				else {
					verif = false;
					cout << "Valores Inválidos. Insira coordenadas X,Y com valores de 1 a 3(ex: 3x1): ";
				}

			} while(verif == false);

			matriz[c1-1][c2-1] = 'O';
			contador_linha++;
		}


		//verificar linhas e colunas
		for(int i = 0; i<3; i++) {
			char a;
			char b;
			char c;

			a=matriz[i][0];
			b=matriz[i][1];
			c=matriz[i][2];

			if((a=='X' || a== 'O') && (a==b && b==c)) {
				system("cls");
				cout << "\nVencedor: " << a << '\n';
				vencedor = true;
				break;
			}

			a=matriz[0][i];
			b=matriz[1][i];
			c=matriz[2][i];

			if((a=='X' || a== 'O') && (a==b && b==c)) {
				system("cls");
				cout << "\nVencedor: " << a << '\n';
				vencedor = true;
				break;
			}
		}

		//verifica diagonais e empate se necessário
		
		if(vencedor==false) {
			int principal = 0;
			int secundaria = 0;
			char vetP[3];
			char vetS[3];

			for(int i = 0; i<3; i++) {
				for(int j = 0; j<3; j++) {

					if(i==j) {
						vetP[principal] = matriz[i][j];
						principal++;
					}
					if(i+j==2) {
						vetS[secundaria] = matriz[i][j];
						secundaria++;
					}
				}
			}

			if((vetP[0]==vetP[1] && vetP[1]==vetP[2]) && (vetP[0] == 'X' || vetP[0]=='O')) {
				system("cls");
				cout << "\nVencedor: " << vetP[0] << '\n';
				vencedor = true;
				break;
			} else if((vetS[0]==vetS[1] && vetS[1]==vetS[2]) && (vetS[0] == 'X' || vetS[0]=='O')) {
				system("cls");
				cout << "\nVencedor: " << vetS[0] << '\n';
				vencedor = true;
				break;
			} else if(contador_linha == 9) {
				system("cls");
				cout << "\nEmpate!\n";
				break;
			}
		}
	}//fim do while

	cout << "\n\n";
	exibir_matriz(matriz);
	cout << "\n\n\n\n";
	system("pause");


	return 0;
}

void exibir_matriz(char x[3][3]) {

	for(int i = 0; i<3; i++) {
		for(int j = 0; j<3; j++) {
			cout << " " << x[i][j];

			if(j<2)
				cout << " | ";
		}
		if(i<2)
			cout << "\n ____________\n\n";
	}
}

void exibir_coordenadas() {

	cout << "  COORDENADAS:\n\n";
	cout << " 1    2   3\n";
	cout << "\n   |    |     1\n";
	cout << " ___________\n";
	cout << "\n   |    |     2\n";
	cout << " ___________\n";
	cout << "\n   |    |     3\n\n\n    JOGO:\n\n";
}
