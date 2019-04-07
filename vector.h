#pragma once

class Vector {
public:
	
	//Constroi um vetor vazio
	Vector();

	//Controi um vetor de dimensoes (x,y)
	Vector(double x, double y);

	//Retorna valor de x do vetor corrente
	double x();

	//Retorna valor de y do vetor corrente
	double y();

	//Retorna norma do vetor corrente
	double size();

	//Retorna soma de dois vetores
	Vector operator+(Vector v);

	//Retorna subtracao de dois vetores
	Vector operator-(Vector v);

	//Retorna multiplicacao de vetor por escalar
	Vector scalar(double k);

private:

	double x_;
	double y_;

};