// UVa ProblemS.cpp: archivo de proyecto principal.

#include "stdafx.h"


//************************DE AQUI SE EMPIEZA A COPIAR ****************************
//*********Librerias*************
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>

//********Using********
using namespace std;

//********Defines******
#define FOR(variable, ini, fin) for(int variable = ini ; variable < fin ; i++)
#define INF 100000

//*********TypeDefs*********
typedef vector<int> vi;
typedef pair <int, int> ii;
typedef pair <int, bool> ib;
typedef vector<ib> vib;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef queue<int> qi;

//**********Variables*globales*******
int tape, n;// tape -> maxima duracion ; n -> cantidad de pistas
vib tracks(20);//vector de int y bool de las pistas
int validos[20];//array de los validos
int nval, near;//nval -> numero de validos ; near -> numero más cercano a tape

//*********Funciones**********

void backtrack(int pos, int suma)
{
	if (suma > tape)
		return;
	if (pos)
		tracks[pos - 1].second = true;
	
	FOR(i, pos, n)
	{
		backtrack(i+1, tracks[i].first + suma);
	}

	if (suma > near)
	{
		near = suma;
		nval = 0;
		//pasar valores validos al arreglo validos
		FOR(i, 0, n)
		{
			if (tracks[i].second)
			{
				validos[nval] = tracks[i].first;
				nval++;
			}
		}
	}
	if (pos)
		tracks[pos - 1].second = false;
}


int main()
{
	while (scanf("%d %d",&tape, &n) != EOF)
	{
		FOR(i, 0, n)
		{
			scanf("%d", &tracks[i].first);
			tracks[i].second = false;
		}
		near = 0;
		backtrack(0, 0);

		FOR(i, 0, nval)
		{
			printf("%d ", validos[i]);
		}
		printf("sum:%d\n", near);

	}
    return 0;
}
