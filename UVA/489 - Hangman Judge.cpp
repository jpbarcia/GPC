#include <stdio.h>
#include <vector>
#include <string.h>


using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w+", stdout);

	int round;
	int buenas, malas;
	char juez[500] = { 0 }, jugador[500] = { 0 };
	char registro[500] = { 0 };
	while (scanf("%d\n", &round) != EOF && round != -1)
	{

		buenas = 0;
		malas = 0;
		gets(juez);
		gets(jugador);
		printf("Round %d\n", round);
		bool buenaMala = false;
		int size1 = strlen(jugador);
		int size2 = strlen(juez);

		for (int i = 0; i < size1; i++)
		{
			char letra = jugador[i];
			bool estaEnArreglo = false;
			int sizeArr = strlen(registro);
			for (int j = 0; j < sizeArr; j++)
				if (letra == registro[j])
				{
					estaEnArreglo = true;
					break;
				}
			if (!estaEnArreglo)
			{
				registro[sizeArr] = letra;
				for (int j = 0; j < size2; j++)
					if (letra == juez[j])
					{
						buenas++;
						estaEnArreglo = true;
					}
				if (estaEnArreglo)
				{
					if (buenas == size2)
					{
						printf("You win.\n");
						buenaMala = true;
						break;
					}
				}
				else
				{
					malas++;
					if (malas == 7)
					{
						printf("You lose.\n");
						buenaMala = true;
						break;
					}
				}
			}
		}
		if (!buenaMala)
			printf("You chickened out.\n");
		int sizetemp = strlen(registro);
		for (int i = 0; i < sizetemp; i++)
			registro[i] = 0;

	}
	return 0;
}