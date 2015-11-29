//DESDE AQUI SE COMIENZA A COPIAR

#include <stdio.h>
#include <vector>

#define INF 1000000

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;


/*
COLOR
-1 -> NO VISITADO
0 -> BLANCO
1 -> NEGRO
*/

vvi grafo(101);
int color[101];
int nodosNegros[101] = { 0 };
int nodosNegrosFinales[101] = { 0 };
int negros;
int maximo = 0;
int n, m;

bool cumple(int nodo)
{
	int size = grafo[nodo].size();
	for (int i = 0; i < size; i++)
	{
		if (color[grafo[nodo][i]] == 1)
		{
			return false;
		}
	}
	return true;
}

void Bactrack(int nodo)
{
	if (nodo == n + 1)
	{
		//comparar max con el actual
		if (negros > maximo)
		{
			maximo = negros;
			for (int i = 0; i < negros; i++)
				nodosNegrosFinales[i] = nodosNegros[i];
		}
		return;
	}
	if (n + 1 - nodo + negros < maximo)
		return;

	color[nodo] = 1;
	if (cumple(nodo))
	{
		nodosNegros[negros] = nodo;
		negros++;
		Bactrack(nodo + 1);
		negros--;
	}
	color[nodo] = 0;
	Bactrack(nodo + 1);
	return;
}

int main()
{
	//freopen("in.txt", "r", stdin);

	int cant;
	int u, v;
	for (int i = 0; i < 101; i++)
	{
		color[i] = -1;
	}

	scanf("%d", &cant);

	while (cant--)
	{

		scanf("%d %d", &n, &m);
		//nodos de 1 hasta n;
		negros = 0;
		maximo = 0;
		//LECUTRA
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &u, &v);
			grafo[u].push_back(v);
			grafo[v].push_back(u);
		}

		Bactrack(1);

		printf("%d\n", maximo);
		int maximo2 = maximo - 1;
		for (int i = 0; i < maximo; i++)
		{
			if (i < maximo2)
				printf("%d ", nodosNegrosFinales[i]);
			else
				printf("%d", nodosNegrosFinales[i]);
		}
		printf("\n");

		//reinicio de variables
		for (int i = 1; i <= n; i++)
		{
			grafo[i].clear();
		}
	}

	return 0;
}
