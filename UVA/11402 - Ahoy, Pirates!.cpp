#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;
 
#define IOS std::ios_base::sync_with_stdio(false)
//funciones
ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
 
int lt[1<<21], rt[1<<21], t[1<<21], s[1<<21], c[1<<21], vec[1<<20];
//lt y rt son para los rangos
//lt->rango izquierdo
//rt->rango derecho
//t->Segment tree
//s->Segment tree estados
//c->Segment tree completo (todos 1, no se modifica)
//vec->vector inicial de numeros
int n;
 
void init()
{
    int temp;
    for(int i = 0; i < 23; i++)//log2(n) +1 (entero)
        if(n >> i == 0)
        {
            temp = 1 << i;
            break;
        }
        
   /* if(n - 1 << (temp-1) <= 0)
        temp = 1 << (temp-1);
    else
        temp = 1 << temp;
    temp = 8;*/
    //printf("temp: %d\n", temp);
 
    for(int i = temp; i < ( temp << 1 ); i++)
    {
        lt[i] = i-temp;
        rt[i] = i-temp;
        c[i] = (i - temp < n) ? 1 : 0;
        s[i] = 0;
        t[i] = (i - temp < n) ? vec[i-temp] : 0;
        //printf("lt[%d] = %d - rt[%d] = %d - c[%d] = %d\n", i, lt[i], i, rt[i], i, c[i]);
    }
    for(int i = temp-1; i > 0; i--)
    {
        lt[i] = lt[i<<1];
 
        rt[i] = rt[(i<<1) | 1];
        c[i] = c[i<<1] + c[(i<<1) | 1];
        s[i] = 0;
        t[i] = t[i<<1] + t[(i<<1) | 1];
        //printf("lt[%d] = %d - rt[%d] = %d - c[%d] = %d\n", i, lt[i], i, rt[i], i, c[i]);
    }
}
void upN(int a)
{
    //1-> todos 0
    //2-> todos 1
    //3-> todos volteados
    if(s[a] == 0)
        return;
    if(s[a] == 1)
        t[a] = 0;
    if(s[a] == 2)
        t[a] = c[a];
    if(s[a] == 3)
        t[a] = c[a] - t[a];
 
    if(lt[a] == rt[a])//si es ultimo nodo
    {
        s[a] = 0;//procesado, ahora no hacer nada
        return;
    }
    if(s[a] != 3)//si no es voltear
        s[a<<1] = s[(a<<1) | 1] = s[a];
    else
    {
        //si es voltear, da 0 (hacer nada)
        //si es todos 0, da todos 1
        //si es todos 1, da todos 0
        s[a<<1] = 3 - s[a<<1];
        s[(a<<1) | 1] = 3 - s[(a<<1) | 1];
    }
 
    s[a] = 0;//procesado, ahora no hacer nada
}
int query(int a, int b, int v)
{
   
    if(lt[v] > b || rt[v] < a)//si esta fuera del rango
        return 0;
    upN(v);
    if(lt[v] >= a && rt[v] <= b)//si esta totalmente dentro del rango
    {
        //printf("ENTRO ACA\n");
        return t[v];
    }
    //printf("SE FUE POR ACA\n");
    return query(a, b, v<<1) + query(a, b, (v<<1) | 1);//ver los hijos
}
 
//void total()
//{
//  printf("total: %d\n", query(0,n,1));
//}
 
void update(int a, int b, int v, int va)
{
    upN(v);
    //printf("NODO : %d - ", v);
    //total();
    if(lt[v] > b || rt[v] < a)//si no esta en el rango
        return;
    if(lt[v] >= a && rt[v] <= b)//si esta totalmente dentro del rango
    {
        s[v] = va;
        upN(v);
        return;
    }
    //actualizar hijos
    update(a,b, v<<1, va);
    update(a,b, (v<<1) | 1, va);
    //actualizar este nodo
    t[v] = t[v<<1] + t[(v<<1) | 1];
}
 
int main()
{
    //IOS;
    int casos;
    char pala[1<<20+1];
    scanf("%d\n", &casos);
    for(int ca = 0; ca < casos; ca++)
    {
        //LECTURA
        int tem;
        n=0;
        scanf("%d\n", &tem);
        for(int i = 0; i < tem; i++)
        {
            int veces;
 
            scanf("%d\n", &veces);
            scanf("%s", &pala);
            int sz = strlen(pala);
            for(int z = 0; z < veces; z++)
                for(int j = 0; j < sz; j++)
                    vec[n++] = pala[j] == '1' ? 1 : 0;
        }
 
        //INICIALIZACION DEL SEGMENT TREE
        init();
        //printf("rt[1] = %d - lt[1] = %d\n", rt[1], lt[1]);
        //LECTURA
        int qu;
        scanf("%d\n", &qu);
        char t1;
        int t2, t3;
 
        printf("Case %d:\n", ca+1);
 
        int contador=1;//para el "Q" (solo imprimir)
        for(int i = 0; i < qu; i++)
        {
            scanf("%c %d %d\n", &t1, &t2, &t3);
            if(t1 == 'E')
                update(t2, t3, 1, 1);
            else if(t1 == 'F')
                update(t2, t3, 1, 2);
            else if(t1 == 'I')
                update(t2, t3, 1, 3);
            else
                printf("Q%d: %d\n", contador++, query(t2, t3, 1));
                //->UPDATE
                //F->2 (todos a 1)
                //E->1 (todos a 0)
                //I->3 (todos volteados)
                //S->QUERY
            //printf("FIN QUERY\n");
        }
    }
    return 0;
}