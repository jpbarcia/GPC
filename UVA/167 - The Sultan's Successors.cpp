
//DE AQUI SE EMPIEZA A COPIAR ****************************

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
//+++++++

using namespace std;

//**TYPO DEFINE

#define N 8

typedef vector<int> vi;
//typedef pair <int, int> ii;
//typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef queue<int> qi;

//GLOBAL********
vvi respuestas;
vi reinas(8);

int mapa[8][8];

void guardarRespuesta()
{
	vi temp(8);
	for (int i = 0; i < N; i++)
	{
		temp[i] = reinas[i];
	}
	respuestas.push_back(temp);
}

bool sePuede(int fila, int col)
{
	for (int i = 0; i < fila; i++)
	{
		if (col == reinas[i])
			return false;
		if (fila - i + reinas[i] == col || reinas[i] - (fila - i) == col)
			return false;
	}
	return true;
}

void backtrack(int fila)
{
	if (fila == N)
	{		
		guardarRespuesta();
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (sePuede(fila, i))
		{
			reinas[fila] = i;
			backtrack(fila + 1);
		}
	}
}

int verEnRespuestas()
{
	int mayor;
	int suma = 0;
	for (int i = 0; i < respuestas.size(); i++)
	{
		suma = 0;
		for (int j = 0; j < N; j++)
		{
			suma += mapa[j][respuestas[i][j]];
		}
		if (suma > mayor)
			mayor = suma;
	}
	return mayor;
}

int main()
{
	for (int i = 0; i < N; i++)
	{
		reinas[i] = 0;
	}
	backtrack(0);

	int cant;
	scanf("%d", &cant);
	for (int i = 0; i < cant; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				scanf("%d", &mapa[j][k]);
			}
		}
		printf("%5d\n", verEnRespuestas());
	}
	

	return 0;
}