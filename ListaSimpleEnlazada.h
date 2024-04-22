#ifndef LISTASIMPLEENLAZADA_H
#define LISTASIMPLEENLAZADA_H

#include<iostream>
#include<stdexcept>
#include "Item.h"
using namespace std;

class ListaSimple{
	private:
		//atributos
		Item *first;
		Item *last;
		int length;
	public:
		//constructor
		ListaSimple(){
			//cuando una ListaSimple es nueva, no tiene Items
			//por lo tant primer y ultimo Item apuntan a NULL
			//y la longitud de la lista es CERO.
			this->first = NULL;
			this->last = NULL;
			this->length = 0;
		}
		//metodos
		Item *getFirst(){
			return this->first;
		}
		Item *getLast(){
			return this->last;
		}
		int getLength(){
			return this->length;
		}
		//metodo push: agrega un nuevo Item al final de la lista
		void push(string producto, string tipoProducto, string fabricante, int	cantidad, float precio){
			//primero crear un nuevo Item
			Item *nuevo = new Item(producto, tipoProducto, fabricante ,cantidad,precio);
			/*al hacer push se dan dos escenarios:
			* no hay Item
			* hay Item*/
			if( this->length == 0 ){
				//no hay Item: primer y ultimo Item apuntan al nuevo Item
				this->first = nuevo;
				this->last = nuevo;
				this->length++; //aumentar en 1 la longitud de la lista
			}
			else{
				//hay Items
				//el siguiente Item del Ultimo Item ahora apunta al nuevo Item
				this->last->next = nuevo;
				//ahora el ultimo Item es el nuevo Item
				this->last = nuevo;
				this->length++; //aumentar en 1 la longitud de la lista
			}
		}
		//metodo print: imprime la lista simple en una representacion en consola
		/*void print(){
			//crear un Nodo temporal para ir recorriendo la lista
			//este Nodo inicialmente apunta a first
			Item *tmp = this->first;
			while( tmp != NULL ){
				//mientras tmp sea distinto de NULL imprimir el valor
				///de dicho Nodo
				cout << tmp->producto << "->";
				//ahora tmp pasa a ser el next del tmp actual
				//o sea pasar al siguiente Item
				tmp = tmp->next;
			}
			//llegamos al final del recorrido
			cout << "NULL" << endl;
		}*/
		
		//Imprimir todos los Items de la lista con su respectivos valores de parametro.
		void printTodo(){
			int posicion = 0;
				Item *tmp = this->first;
			while( tmp != NULL ){
				//mientras tmp sea distinto de NULL imprimir el valor
				///de dicho Item
				cout << "Item #" << posicion << " Cantidad: " << tmp->cantidad << " " <<tmp->tipoProducto << " " << tmp->fabricante << " " << tmp->producto << " Precio: " << tmp->precio << " LPS"<<endl;
				
				//ahora tmp pasa a ser el next del tmp actual
				//o sea pasar al siguiente Item
				posicion++;
				tmp = tmp->next;
			}
			//llegamos al final del recorrido
			cout << posicion << " item encontrados." << endl;
		}
		
		//Imprimr el Item en un posicion especifica.
		void printItemPos(int pos){
			//primero validar que la posicion sea permitida
			if( pos < 0 || pos > this->length-1 )
				throw invalid_argument("posicion no valida");
			else{
				//recorrer la estructura hasta llegar a la posicion deseada
				Item *tmp = this->first;
				//variable de control para contar los saltos
				int actual = 0;
				while( tmp != NULL ){
					//si el salto actual es igual a la posicion solicitada
					//entonces retornamos el Item donde nos encontramos
					if( actual == pos )
						cout << "Item #" << actual << " Cantidad: " << tmp->cantidad << " " <<tmp->tipoProducto << " " << tmp->fabricante << " " << tmp->producto << " Precio: " << tmp->precio << " LPS"<<endl;
					
					tmp = tmp->next;
					actual++;
				}
			}
		}
		
		//metodo get: devuelve el Nodo en la posicion proporcionada
		Item *getItem(int pos){
			//primero validar que la posicion sea permitida
			if( pos < 0 || pos > this->length-1 )
				throw invalid_argument("posicion no valida");
			else{
				//recorrer la estructura hasta llegar a la posicion deseada
				Item *tmp = this->first;
				//variable de control para contar los saltos
				int actual = 0;
				while( tmp != NULL ){
					//si el salto actual es igual a la posicion solicitada
					//entonces retornamos el Item donde nos encontramos
					if( actual == pos )
						return tmp;
					
					tmp = tmp->next;
					actual++;
				}
			}
		}
		//?????
		//metodo get: devuelve el valor del Item en la posicion proporcionada
		void *get(int pos){
			return this->getItem(pos);
		}
		
		//metodo set: reemplaza la cantidad de la existencia del Item en la posicion proporcionada
		void set(int pos, int cantidad){
			this->getItem(pos)->cantidad = cantidad;
		}
		//metodo pop: saca un Item de la lista y lo retorna al interesado
		Item *pop(int pos){
			//recuperar el Item a eliminar
			Item *eliminar = this->getItem(pos);
			//si el Item a eliminar es el primer Item:
			if( eliminar == this->first ){
				//ahora first pasa a ser el siguiente Item de first
				this->first = this->first->next;
			}
			else{
				//Item a eliminar no es el primer Item
				//recuperar el Item anterior al Item a eliminar
				Item *anterior = this->getItem(pos-1);
				//el siguiente Item de anterior ahora sera el
				//siguiente Item de eliminar
				anterior->next = eliminar->next;
				//si el Item a eliminar apunta al ultimo Item
				//entonces el ultimo Item pasa a ser el Item anterior
				if( eliminar == this->last )
					this->last = anterior;
			}
			//entonces el Item a eliminar su siguiente Item apuntara a NULL
			//para que ya no forme parte de la lista
			eliminar->next = NULL;
			//restar 1 a la longitud de la lista
			this->length--;
			//retorna al interesado el Item a eliminar
			return eliminar;
		}
		//find: devuelve la posicion de la primera coincidencia encontrada de value
		//si no encuentra nada devuelve -1
		
		int find(string producto){
			//recorremos la estructura hasta encontrar el value
			Item *tmp = this->first;
			int pos = 0;
			while( tmp != NULL ){
				//si el value del Nodo actual es igual al value que buscamos:
				if( tmp->producto == producto )
					return pos;	//retornamos la posicion donde estamos
				
				tmp = tmp->next;
				pos++;
			}
			//si llego hasta aqui es porque no encontro nada
			return -1;
		}
		
		//Metodo para encontrar el Item con la cantidad/existencia en 0, y retorna el Item 
		Item *findItem(int existencia,Item *comienzo){
			//recorremos la estructura hasta encontrar el Item 
			Item *tmp = comienzo;
			while( tmp != NULL ){
				//si la cantidad/existencia del Item actual es igual a la cantidad/existencia que buscamos:
				if( tmp->cantidad == existencia )
					return tmp;	//retornamos el Item temporal.
				
				tmp = tmp->next;
			}
			//si llego hasta aqui es porque no encontro nada
			return NULL;
		}
		
			
		void ImprimiriSinExistencia(){
			//Inicializamos el Item donde empezara la busqueda
			Item *tmp = this->first;
			cout<<"Los productos sin existencia son: " << endl;
			//Buscamos con el findItem los items que tengan 0 existencias.
			while( tmp != NULL){
				//Llamamos el metodo.
				tmp = findItem(0,tmp);
				//Si este es encontrado imprime el valor de los parametros correspodientes al Item temporal.
				if(tmp != NULL){
					cout << "Item #" << find(tmp->producto) << " Cantidad: " << tmp->cantidad <<" " << tmp->tipoProducto << " " << tmp->fabricante  << " " << tmp->producto 
					<< " Precio: " << tmp->precio << " LPS"<<endl;
				}else{
					break;
				}
	
				//Damos el valor de tmp su propio next, para asi comenzar la busqueda en el siguiente Item.
				tmp = tmp->next;
			}
			
			}
			//Un find que nos ayuda a buscar items con la misma categoria para posteriormenta imprimirlas.
			void findItemCategoria(string categoria){
			//recorremos la estructura hasta encontrar el Item 
			Item *tmp = this->first;
			int contador =0;
			bool encontrado;
			while( tmp != NULL ){
				//si el tipoProducto del Item actual es igual a la categoria que buscamos:
				if( tmp->tipoProducto == categoria ){
					encontrado = true;
					cout << "Item #" << find(tmp->producto) << " Cantidad: " << tmp->cantidad <<" " << tmp->tipoProducto << " " << tmp->fabricante  << " " << tmp->producto 
					<< " Precio: " << tmp->precio << " LPS"<<endl;	//retornamos los valores del items temporal encontrado..
					contador++; //Contador para saber cuantos items encontramos.
				}
				tmp = tmp->next;
			}
			//Si no fue encontrado algun item:
			if(!(encontrado)){
				cout<<"No se encontraron items con misma categoria." <<endl;
			}else{//Si se logro encontrar algun item:
				cout<<"Se encontraron " << contador << " item en la lista con igual categoria."<<endl;
			}
			
			//si llego hasta aqui es porque no encontro nada
		}
		
		//lo siguiente no usarlo
		/*int find_OBSOLETO(int value){
			//no todas las soluciones cortas son optimas, el siguiente
			//algoritmo hace demasiados barridos por cada get por lo tanto 
			//no es eficiente
			for( int i = 0; i < this->length; i++ ){
				if( this->get(i) == value )
					return i;
			}
			return -1;
		}*/
};

#endif
