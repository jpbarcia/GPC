
//************************DE AQUI SE EMPIEZA A COPIAR ****************************
//*********Librerias*************
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
//********Using********
using namespace std;

//********Defines******
#define FOR(variable, ini, fin) for(int variable = ini ; variable < fin ; variable++)
#define INF 100000

//#define N 8


//*********TypeDefs*********
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair <int, int> ii;
typedef pair <int, bool> ib;
typedef vector<ib> vib;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef queue<int> qi;

//**********Variables*globales*******

map<int, vi> grafo;
map<int, int> visitado;
int cant;
int n, m;
int vez = 0;
//int nodosNoVisitados = 0;
int ini, TTL;
//**********Funciones*************


void AlgoritmoDFS()
{
	qi cola;
	int temp;
	int temp2;
	//int ttl = TTL;
	cola.push(ini);
	visitado[ini] = 0;
	while (!cola.empty())
	{
		temp = cola.front();
		cola.pop();
		int size = grafo[temp].size();
		for (int i = 0; i < size; i++)
		{
			temp2 = grafo[temp][i];
			if (visitado.find(temp2) == visitado.end())
			{
				
				if (visitado[temp]+1 <= TTL)
				{
					cola.push(temp2);
					visitado[temp2] = visitado[temp] + 1;
				}
				else
				{
					//nodosNoVisitados = ContarVisitados();
					return;
				}
			}
		}
	}
	map<int, int>::iterator it;
	for (it = visitado.begin(); it != visitado.end(); it++)
	{
		it->second = INF;
	}
}



//**********MAIN*************
int main()
{

	while (true)
	{
		grafo = map<int, vi>();
		visitado = map<int, int>();
		scanf("%d", &cant);
		if (!cant)
			return 0;
		for (int i = 0; i < cant; i++)
		{
			scanf("%d %d", &n, &m);
			grafo[n].push_back(m);
			grafo[m].push_back(n);
			//visitado[n] = INF;
			//visitado[m] = INF;
		}
		while (true)
		{
			scanf("%d %d", &ini, &TTL);
			if (!ini && !TTL)
				break;
			vez++;
			//nodosNoVisitados = 0;
			AlgoritmoDFS();

			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", vez, grafo.size()-visitado.size(), ini, TTL);
			visitado.clear();

		}
	}

	return 0;
}
