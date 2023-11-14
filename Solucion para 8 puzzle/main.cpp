 //author: Christopher Xavier Sanchez Duran
//UAMC

#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
// Definición de la estructura para representar un nodo en el árbol de búsqueda

class Node
{
	public:

	vector<vector<int>> x;// El estado actual del rompecabezas (representado como una permutación de números)

	int n;
	vector<int> vacio; // La acción que llevó al estado actual desde el padre (0 para arriba, 1 para abajo, 2 para izquierda, 3 para derecha)

	Node * padre; // Puntero al nodo padre
	vector<Node *> hijos;

	Node(vector<vector<int>> x)// Constructor para crear un nodo con un estado y un padre
   
	{
		this->x = x;
		this->n = x.size();
		this->padre = NULL;

		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				if(x[i][j] == 0)
				{
					this->vacio.push_back(i);
					this->vacio.push_back(j);
					break;
				}
			}
		}
	}

	Node(vector<vector<int>> x, Node & p, vector<int> vac)
	{
		this->x = x;
		this->n = x.size();
		this->padre = &p;
		this->vacio = vac;
	}
	
	void printNode()
	{
		if(this != NULL)
		{
			for(int i=0; i<n; ++i)
			{
				cout << endl;
				for(int j=0; j<n; ++j)
				{
					cout << "\t" << x[i][j];
				}
			}
		}
	}
};
// Función para imprimir el camino desde el nodo raíz hasta un nodo dado

class Tree
{
	public:

	int n;
	Node * raiz;

	Tree(vector<vector<int>> x)
	{
    	this->raiz = new Node(x);
		this->n = x.size();
	} // Rastrea el camino desde el nodo dado hasta el nodo raíz


	bool isSolved(vector<vector<int>> x)
	{
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				if(x[i][j] != n*i+j)
				{
					return false;
				}
			}
		}
		return true;
	}

	void addNode(vector<vector<int>> x, Node & p, vector<int> vac)
	{
		p.hijos.push_back(new Node(x,p,vac));
		
		return;
	}

	void copiar(vector<vector<int>> & original, vector<vector<int>> & copia)
	{	
		copia.resize(n);
		// Imprime el camino en orden inverso (desde la raíz hasta el nodo dado)
    
		for(int i=0; i<n; ++i)
		{
			copia[i].resize(n);
			for(int j=0; j<n; ++j)
			{
				copia[i][j] = original[i][j];
			}
		}
	// Aquí puedes agregar código para imprimir el estado del rompecabezas
      		return;
	}

	void addLevel(Node & p)
	{
		vector<vector<int>> copia;
		vector<int> vac{-1,-1};
		int aux;
		bool flag;
		
		if(p.vacio[0] > 0)
		{
			vac[0] = p.vacio[0]-1;
			vac[1] = p.vacio[1];
			flag = false;
				
			if(p.padre == NULL)
			{
				flag = true;
			}
			else
			{
				flag = (p.padre->vacio[0] != vac[0] || p.padre->vacio[1] != vac[1]);
			}
			
			if(flag)
			{
				copiar(p.x, copia);				
				aux = copia[vac[0]][vac[1]];
				copia[vac[0]][vac[1]] = copia[p.vacio[0]][p.vacio[1]];
				copia[p.vacio[0]][p.vacio[1]] = aux;
				addNode(copia, p, vac);
			}
		}
		
		if(p.vacio[0] < n-1)
		{
			vac[0] = p.vacio[0]+1;
			vac[1] = p.vacio[1];
			flag = false;
				
			if(p.padre == NULL)
			{
				flag = true;
			}
			else
			{
				flag = (p.padre->vacio[0] != vac[0] || p.padre->vacio[1] != vac[1]);
			}
			
			if(flag)
			{
				copiar(p.x, copia);
				aux = copia[vac[0]][vac[1]];
				copia[vac[0]][vac[1]] = copia[p.vacio[0]][p.vacio[1]];
				copia[p.vacio[0]][p.vacio[1]] = aux;
				addNode(copia, p, vac);
			}
		}
		
		if(p.vacio[1] > 0)
		{
			vac[0] = p.vacio[0];
			vac[1] = p.vacio[1]-1;
			flag = false;
				
			if(p.padre == NULL)
			{
				flag = true;
			}
			else
			{
				flag = (p.padre->vacio[0] != vac[0] || p.padre->vacio[1] != vac[1]);
			}
			
			if(flag)
			{
				copiar(p.x, copia);
				aux = copia[vac[0]][vac[1]];
				copia[vac[0]][vac[1]] = copia[p.vacio[0]][p.vacio[1]];
				copia[p.vacio[0]][p.vacio[1]] = aux;
				addNode(copia, p, vac);
			}
		}
		
		if(p.vacio[1] < n-1)
		{
			vac[0] = p.vacio[0];
			vac[1] = p.vacio[1]+1;
			flag = false;
				
			if(p.padre == NULL)
			{
				flag = true;
			}
			else
			{
				flag = (p.padre->vacio[0] != vac[0] || p.padre->vacio[1] != vac[1]);
			}
			
			if(flag)
			{
				copiar(p.x, copia);
				aux = copia[vac[0]][vac[1]];
				copia[vac[0]][vac[1]] = copia[p.vacio[0]][p.vacio[1]];
				copia[p.vacio[0]][p.vacio[1]] = aux;
				addNode(copia, p, vac);
			}
		}
	}
// Función para resolver el rompecabezas usando búsqueda en amplitud

  Node * BFS()
	{
		Node * p;
		queue<Node *> cola;
		cola.push(this->raiz);

		while(!cola.empty())
		{
			p = cola.front();
			cola.pop();
 			// Comprueba si el estado actual coincide con el estado objetivo
        
			if(isSolved(p->x))
			{
				return p;
			}
			
			addLevel(*p);
			for(Node * hijo : p->hijos)
			{
				//hijo->printNode();
				cola.push(hijo);
			}
			// el camino de solución
            return;
		}
		return NULL;
	}
};

int main()
{
	// Define el estado inicial del rompecabezas y el estado objetivo
   
	int n = 3, k = 0;
	vector<int> v {0,1,2,3,4,5,6,7,8}; 
	shuffle(v.begin(), v.end(), default_random_engine(69));
	vector<vector<int>> M = {{v[0], v[1], v[2]}, {v[3], v[4], v[5]}, {v[6], v[7], v[8]}};
	stack<Node*> camino;
	Tree t(M);
 	// Llama a la función para resolver el rompecabezas	
	Node * sol = t.BFS();
	Node * p = sol;
	camino.push(sol);

	cout << endl << "BFS" << endl;

    while(p->padre != NULL)
	{
		p = p->padre;
		camino.push(p);
	}
    while(!camino.empty())
	{
		cout << endl << "Movimiento " << k++ << ":"<< endl;
		camino.top()->printNode();
		camino.pop();
		cout << endl;
	}
	return 23;
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

