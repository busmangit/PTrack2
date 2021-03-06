/*
 * Matrix.h
 *
 *  Created on: 31/08/2011
 *      Author: juanin
 */
#include <iostream>
#include <cstdlib>

#ifndef MYMATRIX
#define MYMATRIX

using namespace std;

/**
 * Clase Template representante de una Matriz contenedora de datos del tipo myType especifica.
 */
template <class myType>
class MyMatrix{
private:
	/**
	 * Arreglo de punteros de datos.
	 */
	myType** data;

	/**
	 * Funciona para reservar memoria para los datos.
	 */
	void allocate();

	/**
	 * Tamaño en X de la Matriz
	 */
	unsigned int _sizeX;

	/**
	 * Tamaño en Y de la Matriz
	 */
	unsigned int _sizeY;
public:

	/**
	 * Constructor vacios. Deja el tamaño de la matriz en 0x0 y los punteros a datos en 0.
	 */
	MyMatrix();

	/**
	 * Constructor en base a las dimensiones especificadas como X e Y.
	 * Establece las dimensiones de la Matriz, reserva memoria y establece los valores de los datos en 0.s
	 * @param x Dimension en X de la Matriz
	 * @param y Dimension en Y de la Matriz
	 */
	MyMatrix(unsigned int x, unsigned int y);

	/**
	 * Constructor en base a las dimensiones especificadas como X e Y y un valor por defecto de la Matriz.
	 * Establece las dimensiones de la Matriz, reserva memoria y establece los valores de los datos en 0.s
	 * @param x Dimension en X de la Matriz
	 * @param y Dimension en Y de la Matriz
	 * @param def Valor por defecto de todos los datos contenidos en la Matriz.
	 */
	MyMatrix(unsigned int x, unsigned int y, myType def);

	/**
	 * Destructor de la Matriz.
	 * Libera la memoria reservada, establece las dimensiones en 0.
	 */
	~MyMatrix();

	/**
	 * Retorna la dimension en X de la Matriz.
	 * @return Dimension en X de la Matriz.
	 */
	unsigned int sX();

	/**
	 * Retorna la dimension en Y de la Matriz.
	 * @return Dimension en Y de la Matriz.
	 */
	unsigned int sY();

	/**
	 * Reserva memoria para la Matriz del tamaño especificado por X e Y y establece las Dimensiones de la Matriz.
	 * Esta funcion se puede ocupar una vez construida la matriz usando el constructor vacio , bien despues de llamar
	 * a la funcion deallocate().
	 * @see deallocate()
	 * @param x Dimension en X para reservar datos de la Matriz.
	 * @param y Dimension en Y para reservar datos de la Matriz.
	 */
	void allocate(unsigned int x, unsigned int y);

	/**
	 * Libera la memoria reservada y establece las dimensiones de la Matriz en 0x0.
	 */
	void deallocate();

	/**
	 * Restablece todos los datos de la Matriz segun el valor especificado.
	 * @param def Valor a reestablecer en la Matriz, por defecto este es 0.
	 */
	void reset(myType def = 0);

	/**
	 * Obtiene el valor de la celda de la Matriz segun los parametros X e Y.
	 * @param x Posicion en X de la celda.
	 * @param y Posicion en Y de la celda.
	 * @return Valor de la Matriz en la posicion indicada.
	 */
	myType getValue(unsigned int x, unsigned int y);

	/**
	 * Obtiene el contenido de la celda de la Matriz segun los parametros X e Y.
	 * Este contenido es modificable si se le asigna un valor.
	 * @param x Posicion en X de la celda.
	 * @param y Posicion en Y de la celda.
	 * @return Contenido de la Matriz en la posicion indicada.
	 */
	myType & at(unsigned int x, unsigned int y);

	/**
	 * Es la misma funcion que at(unsigned int, unsigned int), solo que por conveniencia representada en el operador ().
	 * @param x Posicion en X de la celda.
	 * @param y Posicion en Y de la celda.
	 * @return Contenido de la Matriz en la posicion indicada.
	 */
	myType & operator () (unsigned int x, unsigned int y);

	/**
	 * Operador = para copiar una Matriz
	 * @param mtrx Matriz a copiar
	 */
	void operator = (MyMatrix<myType> mtrx);
};

/**
 *******************************
 * Constructores y Destructores
 *******************************
 */
template <class myType>
MyMatrix<myType>::MyMatrix() {
	data = 0;
	_sizeX = 0; _sizeY = 0;
}

template <class myType>
MyMatrix<myType>::MyMatrix(unsigned int x, unsigned int y){
	data = 0;
	_sizeX = x; _sizeY = y;
	allocate();
}

template <class myType>
MyMatrix<myType>::MyMatrix(unsigned int x, unsigned int y, myType def){
	data = 0;
	_sizeX = x; _sizeY = y;
	allocate();
	reset(def);
}

template <class myType>
MyMatrix<myType>::~MyMatrix() {
	deallocate();
}

template <class myType>
void MyMatrix<myType>::allocate(){
	if(data)
		deallocate();

	data = new myType*[_sizeX];
	for(unsigned int h=0; h < _sizeX; ++h){
		data[h] = new myType[_sizeY];
	}
}

template <class myType>
void MyMatrix<myType>::allocate(unsigned int x, unsigned int y){
	_sizeX = x;_sizeY = y;
	allocate();
}

template <class myType>
void MyMatrix<myType>::deallocate(){
	if(data){
		for(unsigned int h=0; h < _sizeX; ++h){
			if(data[h])
				delete [] data[h];
			data[h] = 0;
		}
		delete [] data;
	}

	_sizeX = 0; _sizeY = 0;
	data = 0;
}
/**
 *******************************
 * Metodos
 *******************************
 */

template <class myType>
void MyMatrix<myType>::reset(myType def){
	for(unsigned int x=0; x<_sizeX; ++x){
		for(unsigned int y=0; y<_sizeY; ++y){
			data[x][y]= def;
		}
	}
}

template <class myType>
unsigned int MyMatrix<myType>::sX(){
	return _sizeX;
}

template <class myType>
unsigned int MyMatrix<myType>::sY(){
	return _sizeY;
}

template <class myType>
myType MyMatrix<myType>::getValue(unsigned int x, unsigned int y){
	return data[x][y];
}

template <class myType>
myType & MyMatrix<myType>::at(unsigned int x, unsigned int y){
	return data[x][y];
}

template <class myType>
myType & MyMatrix<myType>::operator () (unsigned int x, unsigned int y){
	return data[x][y];
}

template <class myType>
void MyMatrix<myType>::operator = (MyMatrix<myType> mtrx){
	allocate(mtrx.sX(), mtrx.sY());
	for(unsigned int x=0; x < mtrx.sX(); ++x)
		for(unsigned int y=0; y < mtrx.sY(); ++y){
			data[x][y] = mtrx.getValue(x,y);
		}
}

#endif
