#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

using namespace std;

struct Nodo
{
    string respuesta;
    struct Nodo * izq;
    struct Nodo * der;
};

Nodo * head, * inicio;

void pregunta(Nodo * inicio, Nodo * prev);
void actualiza_archivo(Nodo *& head, fstream & archivo);
void actualizacion_arbol(Nodo * fin, Nodo *& prefin);
void pregunta_final(Nodo * head, Nodo * prev);
void interpretacion_bc(Nodo *& inicio, fstream & archivo);

void actualiza_archivo(Nodo *& head, fstream & archivo)
{
    if(head == NULL)
    {
        archivo << "%" << endl;
    }
    else
	{
        archivo << head->respuesta << endl;
        actualiza_archivo(head->izq, archivo);
        actualiza_archivo(head->der, archivo);
    }
}

void actualizacion_arbol(Nodo * fin, Nodo *& prefin)
{
    string res, preg;
    cout << "\n\nNo se :(" << endl;
    cout << "\nCual es el elemento?\t";
    cin.ignore();
    getline(cin, res);
    cout << "Escribe una pregunta que cuya respuesta para " << res << " sea SI, y para " << fin->respuesta << " sea NO" << endl;
    getline(cin, preg);
    Nodo * resNodo, * pregNodo;
    resNodo = new Nodo;
    resNodo->respuesta = res;
    resNodo->izq = NULL;
    resNodo->der = NULL;

    pregNodo = new Nodo;
    pregNodo->respuesta = preg;
    pregNodo->izq = resNodo;
    pregNodo->der = fin;
    
    if(prefin->izq == fin)
    {
        prefin->izq = pregNodo;
    }
    else if(prefin->der == fin)
    {
        prefin->der = pregNodo;
    }
    
		fstream archivo;
    archivo.open("bc.txt", ios::out);
    actualiza_archivo(inicio, archivo);
    string respuesta_ad;
    cout << "Continuar?\t";
    cin >> respuesta_ad;
    
    while(true)
    {
	    if(respuesta_ad == "si" || respuesta_ad == "Si" || respuesta_ad == "SI" || respuesta_ad == "y" || respuesta_ad == "Y")
		{
			pregunta(inicio, NULL);
			return;
	    }
	    else if(respuesta_ad == "no" || respuesta_ad == "NO" || respuesta_ad == "No" || respuesta_ad == "n" || respuesta_ad == "N")
	    {
			return;
	    }
	    else
		{
	        cout << "Repuesta invalida." << endl << "Intente de nuevo..." << endl;
	    }
	}
	           
}

void pregunta_final(Nodo * head, Nodo * prev)
{
    string respuesta_ad;
    cout << "El elemento es " << head->respuesta << "?" << "\n";
    cin >> respuesta_ad;
    if(respuesta_ad == "si" || respuesta_ad == "SI" || respuesta_ad == "Si" || respuesta_ad == "y" || respuesta_ad == "Y")
	{
        cout << "Elemento identificado correctamente." << endl;
        cout << "\n\n Continuar?:";
        cin >> respuesta_ad;
        if(respuesta_ad == "si" || respuesta_ad == "SI" || respuesta_ad == "Si" || respuesta_ad == "y" || respuesta_ad == "Y")
		{
            pregunta(inicio, prev);
        }
        else if(respuesta_ad == "no" || respuesta_ad == "NO" || respuesta_ad == "No" || respuesta_ad == "n" || respuesta_ad == "N")
		{
            return;
    	}
    }
    else if(respuesta_ad == "no" || respuesta_ad == "NO" || respuesta_ad == "No" || respuesta_ad == "n" || respuesta_ad == "N")//en caso de que no encontremos en nuestro arbol, al animal en cuestion 
    {
		actualizacion_arbol(head, prev);
	}
    else
	{
        cout << "Repuesta invalida." << endl << "Intente de nuevo..." << endl;
        pregunta_final(head, prev);
    }
}

void pregunta(Nodo * inicio, Nodo * prev)
{
    string respuesta_ad;
    if(inicio->izq != NULL && inicio->der != NULL)
	{
        cout << inicio->respuesta << endl;
        cin >> respuesta_ad;
        if(respuesta_ad == "si" || respuesta_ad == "SI" || respuesta_ad == "Si" || respuesta_ad == "y" || respuesta_ad == "Y")
        {
            pregunta(inicio->izq, inicio);
        }
        else if(respuesta_ad == "no" || respuesta_ad == "NO" || respuesta_ad == "No" || respuesta_ad == "n" || respuesta_ad == "N")
        {
			pregunta(inicio->der, inicio);
		}
        else
		{
            cout << "Repuesta invalida." << endl << "Intente de nuevo..." << endl;
            pregunta(inicio, prev);
        }
    }
    else
    {
        pregunta_final(inicio, prev);
    }
}

void interpretacion_bc(Nodo *& inicio,fstream & archivo)
{
	string str;
	if(!archivo.eof())
	{
        getline(archivo, str);
        //cout<<str<<" ";
        cin.clear();
    }
   	else
   	{
    	return;
    }
    if(str != "%")
	{
        inicio = new Nodo;
        inicio->respuesta = str;
        interpretacion_bc(inicio->izq, archivo);
        interpretacion_bc(inicio->der, archivo);
    }
    else
    {
        inicio = NULL;
    }
}

int main()
{
    fstream archivo;
    archivo.open("bc.txt", ios::in);
    interpretacion_bc(inicio, archivo);
    archivo.close();
    //for(Nodo * it=inicio;it!=NULL;it=it->izq)
    //	cout<<it->respuesta<<" ";
    pregunta(inicio, NULL);
    //archivo.open("bc.txt",ios::out);
    //actualiza_archivo(inicio,archivo);
    //archivo.close();
    
    return 69;
}