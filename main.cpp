#include <iostream>
#include "ListaSimpleEnlazada.h"

using namespace std;

void menu(int opcion); //Nos imprimira el menu
bool verificarTipoDeProducto(string producto); //Verificar si el tipo de producto es valido

int main(){
	
	int opcion = 0, opcion1 = 5, opcion2 = 12;
	bool close = false;
	//Lista de items de la tienda.
	ListaSimple *ls1 = new ListaSimple();
	
	//Lista de items del cliente
	ListaSimple *ls2c = new ListaSimple();
	
	//Procesadores
	ls1->push("Ryzen 7 8700G","Procesador","AMD",7,13000);
	ls1->push("Ryzen 5 8600G","Procesador","AMD",8,8900);
	ls1->push("Ryzen 5 8500G","Procesador","AMD",2,6900);
	
	ls1->push("Core i7-14700KF","Procesador","INTEL",1,16100);
	ls1->push("Core i5-14600KF","Procesador","INTEL",3,11900);
	ls1->push("Core i5-13600KF","Procesador","INTEL",4,10900);
	
	//Placas madres
	ls1->push("ROG STRIX B760-A","Placa Madre","ASUS",9,8700);
	ls1->push("PRO H510M-B","Placa Madre","MSI",13,2200);
	ls1->push("MAG B760 TOMAHAWK","Placa Madre","MSI",0,6800);
	
	//Memorias RAM
	ls1->push("Trident Z5 RGB Series 32 GB (2x16GB) DDR5 5600","RAM","G.SKILL",16,4300);
	ls1->push("Trident Z RGB 16 GB (2x8GB) DDR4 3600","RAM","G.SKILL",17,1900);
	ls1->push("Kingston Fury Beast RGB 16GB (2 x 8GB) DDR5 4800","RAM","G.SKILL",12,4200);
	
	//Tarjetas graficas
	ls1->push("RTX 3050 Ventus 2X XS 8G OC","GPU","MSI ",22,8700);
	ls1->push("AORUS Radeon RX 6900 XT Master 16G","GPU","GIGABYTE",4,20900);
	ls1->push("Dual Radeon RX 7600 V2 OC Edition 8GB GDDR6","GPU","ASUS",0,11800);
	
	//Almacenamiento
	ls1->push("NV2 2TB M.2 Gen 4x4","Almacenamiento","KINGSTON",32,4200);
	ls1->push("NV2 1TB M.2 Gen 4x4","Almacenamiento","KINGSTON",21,2200); 
	ls1->push("HDD Externo 2 TB Negro","Almacenamiento","SEAGATE",7,2995);
	
	//Monitores
	ls1->push("29in 29WQ500-B ULTRAWIDE 100 HZ 5ms","Monitor","LG",0,7700);
	ls1->push("LED 24  VG248QG  165HZ 0.5ms 12MG","Monitor","ASUS",4,7700); 
	ls1->push("LED 27  VK27FHD165 TRAX 165HZ 1ms","Monitor","Vorttek",5,5495);
	
	while(!(close)){
		//Menu principal
		if(opcion1 == 5 && opcion2 == 12){
			cout << "===== Bienvenido a CentroCompras =====" <<endl;
			cout << "1. Empleado" <<endl;
			cout << "2. Cliente" << endl;
			cout << "Digite la opcion: ";
			cin >> opcion;	
		}
		//Muestra menu empleado o cliente, segun eleccion.
		menu(opcion);
		//Empleado
		if(opcion == 1){
			cin>>opcion1;
			//Menu empleado
			switch(opcion1){
				case 1:
					//Imprime todos los productos
					ls1->printTodo();
					break;
				case 2: 
					//Imprime los productos sin existencia
					ls1->ImprimiriSinExistencia();
					break;
				case 3:{
						//Agrega nuevo producto
					string producto, tipoProducto, fabricante, cantidad, precio;
					int cant; float prec; 
					cin.ignore();
					cout<<"===== NUEVO PRODUCTO ====="<<endl;
					cout <<"Nombre: "; getline(cin,producto);
					
					do{
						cout <<"Tipo: "; getline(cin,tipoProducto);
						if(verificarTipoDeProducto(tipoProducto) == true)
							cout<< "Asegurese que sea uno de los siguientes tipo de producto: Procesador,Placa Madre,RAM,GPU,Almacenamiento,Monitor"<<endl;
					}while(verificarTipoDeProducto(tipoProducto));
					cout <<"Fabricante: "; getline(cin,fabricante);
					
					do{
						try{
							cout <<"Cantidad: "; getline(cin,cantidad);
							cant = stoi(cantidad);
							break;
							
						}catch(exception ex){
							cout<<"Debe ser un numero entero."<<endl;
						}
					}while(true);
					
					
					do{
						try{
						cout <<"Precio: "; getline(cin,precio);
						prec = stof(precio);
						break;
						
						}catch(exception ex){
						cout<<"Debe ser un numero."<<endl;
						}	
					}while(true);
					
		
					ls1->push(producto,tipoProducto,fabricante,cant,prec);
					cout<<"El producto agregado es: " << endl;
					ls1->printItemPos(ls1->getLength()-1);
					cout<<"Producto agregado con exito!"<<endl;
					break;
				}
			
				case 4:{
					//Retirar productos
					int posicion;
					string confirmar;
					ls1->printTodo();
					do{
						cout<<"Escriba el numero correspondiente al producto a querer retirar: ";
						cin>>posicion;
					
						if(!(posicion < 0 || posicion > ls1->getLength())){
							cout<<"Esta seguro de retirar el producto de la lista?" << endl;
							cout<<"Si o No : "; 
							cin.ignore();
							getline(cin,confirmar);
							if(confirmar == "Si"){
								ls1->pop(posicion);
								cout<<"Se ha retirado el producto con exito!"<<endl;
							}
								
							break;
						}else{
							cout<<"El numero debe estar dentro de la lista.";
						}
						
					}while(true);
					
					
					
					break;
				}
				case 5:{
					//Regresamos al menu principal
					opcion1 = 5;
					opcion2 = 12;
					break;
				}
				
				case 6:
					//Cerramos el programa
					cout <<"Saliendo del programa" << endl;
					close = true;
					break;
					
			}
			system("pause");
			system("cls");
		}
		//Cliente
		if(opcion == 2){
			cin>>opcion2;
			
			//Menu cliente
			switch(opcion2){
				case 1: {
					ls1->printTodo();
					break;
				}
				
				case 2:{
					//Mostar categoria de los procesadores
					ls1->findItemCategoria("Procesador");
					break;
				}
				
				case 3:{
					//Mostar categoria de las placas madres
					ls1->findItemCategoria("Placa Madre");
					break;
				}
				
				case 4: {
					//Mostar categoria de las RAMs
					ls1->findItemCategoria("RAM");
					break;
				}
				
				case 5: {
					//Mostar categoria de los GPUs
					ls1->findItemCategoria("GPU");
					break;
				}
				
				case 6:{
					//Mostar categoria de los almacenamientos
					ls1->findItemCategoria("Almacenamiento");
					break;
				}
				
				case 7: {
					//Mostar categoria de los Monitores
					ls1->findItemCategoria("Monitor");
					break;
				}
				case 8:{
					//Agregar producto a una lista de compra.
					ls1->printTodo();
					
					int pos;
					int cant;
					cout<<"Digite el numero correspondiente del articulo que desea agregar a la lista de compra: " << endl;
					do{
						cin>>pos;
						if(pos > 0 && pos <= ls1->getLength()){
							break;
						}else
							cout<<"El numero no esta dentro de la lista."<<endl;
					}while(true);
					
					if(ls2c->find(ls1->getItem(pos)->producto) != -1){
						cout <<"Este producto ya esta en su lista de compra."<<endl;
						break;
					}
					
					if(ls1->getItem(pos)->cantidad < 1){
						cout<<"Lo lamentamos, pero este producto no tiene existencias. " <<endl;
					}else{
							cout<<"Cuantas unidades desea comprar ? : ";
							cin>>cant;
							if(cant <= 0 || cant > ls1->getItem(pos)->cantidad){
								cout<<"No hay suficientes existencias del producto."<<endl;
								break;
							}
							ls2c->push(ls1->getItem(pos)->producto,ls1->getItem(pos)->tipoProducto,ls1->getItem(pos)->fabricante,cant,ls1->getItem(pos)->precio*cant);	
							cout<<"Item agregado a la lista exitosamente !" <<endl;
						}
					
					break;
				}
				
				case 9: {
					//Quitar un item de la lista de compra del cliente
					ls2c->printTodo();			
					int pos;
					cout<<"Digite el numero correspondiente del articulo que desea quitar de la lista de compra: " << endl;
					do{
						if(pos >= 0 || pos <= ls1->getLength()){
							cin>>pos;
							break;
						}
						cout<<"El numero no esta dentro de la lista."<<endl;
					}while(true);
					
					ls2c->pop(pos);
					cout<<"El item ha sido retirado de la lista exitosamente."<<endl;
					break;
				}
				
				case 10:{
					//Imprime la lista de compra del cliente
					if(ls2c->getFirst() == NULL){
						cout<<"No se ha agregado ningun Item a la lista."<<endl;
					}else
						ls2c->printTodo();
					break;
				}
				
				case 11:{
					if(ls2c->getFirst() != NULL){
						int total = 0;
						int pos = 0;
						string aceptar;
						ls2c->printTodo();
						//Se suma el total a pagar
						for(int i = 0; i < ls2c->getLength(); i++){
							total = total+ls2c->getItem(i)->precio;
						}
						cout<<"El total a pagar es: " << total<<endl;
						
						cout<<"Desea proceder con el pago ? " << endl;
						cout<<"Si o No : " ;
						cin.ignore();
						getline(cin,aceptar);
						//Si se acepta proceder con el pago se reducen las existencia de la lista de la tienda y se limpia la lista del cliente.
						if(aceptar == "Si"){
							for(int i = 0; i < ls2c->getLength(); i++){
							pos = ls1->find(ls2c->getItem(i)->producto);
							//Reducimos la cantidad de existencias en la lista de la tienda.
							ls1->set(pos,(ls1->getItem(pos)->cantidad-ls2c->getItem(i)->cantidad));
							//Liampiamos la lista de compra del cliente
							ls2c->pop(i);
							}
						
						
							cout<<"Gracias por su compra"<<endl;
						}
							
					}else
						cout<<"No se ha agregado ningun Item a la lista."<<endl;
						
					break;
				}
				
				case 12:{
					//Volvemos al menu principal
					opcion1 = 5;
					opcion2 = 12;
					break;
				}
					
				case 13:{
					//Cerramos el programa
					cout <<"Saliendo del programa" << endl;
					close = true;
					break;
				}
		}
		system("pause");
		system("cls");
		}
		}
	return 321;
}



bool verificarTipoDeProducto(string producto){
	string tiposDeProducto[] = {"Procesador","Placa Madre","RAM","GPU","Almacenamiento","Monitor"};
	for(int i = 0; i < end(tiposDeProducto)-begin(tiposDeProducto); i++){
		if(tiposDeProducto[i] == producto)
			return false;
	}
	return true;
};

void menu(int opc){
	if(opc == 2){
	cout << "===== Bienvenido a CentroCompras =====" <<endl;
	cout<< "Categorias: " <<endl;
	cout<<"1. Todos los productos" << endl;
	cout<<"2. Procesadores" << endl;
	cout<<"3. Placas madres" << endl;
	cout<<"4. Memorias RAM" << endl;
	cout<<"5. Tarjetas graficas" << endl;
	cout<<"6. Almacenamiento" << endl;
	cout<<"7. Monitores" << endl;
	cout<<"8. Agregar productos a la lista de compra." <<endl;
	cout<<"9. Quitar productos de la lista de compra." <<endl;
	cout<<"10. Consultar lista de compra." << endl;
	cout<<"11. Proceder con la compra." <<endl;
	cout<<"12. Volver" << endl;
	cout<<"13. Salir" << endl;
	cout<<"Digite su opcion: " << endl;
	
	}else if(opc == 1){
	cout << "===== Bienvenido a CentroCompras =====" <<endl;
	cout<< "Categorias: " <<endl;
	cout<<"1. Todos los productos" << endl;
	cout<<"2. Productos sin existencias" << endl;
	cout<<"3. Agregar nuevo producto" << endl;
	cout<<"4. Retirar producto" << endl;
	cout<<"5. Volver" << endl;
	cout<<"6. Salir" <<endl;
	cout<<"Digite su opcion: " << endl;	
	}
	
}


