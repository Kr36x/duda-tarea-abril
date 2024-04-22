#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class Item{
	private:
		
	public:
		string producto;
		string tipoProducto;
		int	cantidad;
		float precio;
		string fabricante;
		
		Item *next; //apuntador al siguiente Nodo

	
	Item(string producto, string tipoProducto, string fabricante, int	cantidad, float precio){
		this->producto = producto;
		this->tipoProducto = tipoProducto;
		this->cantidad = cantidad;
		this->precio = precio;
		this->fabricante = fabricante;
		this->next = NULL; //de forma predeterminada el siguiente Nodo es NULL
		
	}
};

#endif
