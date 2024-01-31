/*Integral de una función
Autor: Ivan Valdespin
Programación Avanzada
23/sep/2021
Apuntadores a funciones*/

#include <stdio.h>
#include <math.h>

#define NP 2000 //Puntos a evaluar
#define pi 3.1416


double fun1(double x){
	return (x*x*sin(sqrt(x)));}
double fun2(double x){
	return (log(x));}
double fun3(double x){
	return (sin(x));}




double integral(double xmin, double xmax, double(*f)(double)){
                                        //double: Valor de retorno, 
                                        //*f Apuntador a funcion, 
                                        //(double): Valor de entrada
	int i;
	double temp = 0;
	double x, dx;

	dx = (xmax - xmin)/((double)(NP-1));

	x = xmin;
	for(i = 0; i<NP; i++){
		x += dx;
		temp += (*f)(x)*dx; //Referencia a la funcion apuntada
	}
}



int main(int argc, char**argv)
{
	int x;

	x = atoi(argv[1]);
	x = x-1;


	double (*f[])(double) = {fun1, fun2, fun3};

	double y = integral(0, pi,f[x]);

	if (x == 0){
	printf("El resultado de fun1 es: %lf\n", y);
	}
	else if(x == 1){
		printf("El resultado de fun2 es: %lf\n", y);

	}

	else {
		printf("El resultado de fun3 es: %lf\n", y);

	}


	return 0;
}