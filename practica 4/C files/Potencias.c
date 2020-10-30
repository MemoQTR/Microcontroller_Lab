#include <stdio.h>

int a,b,c,d,e,f = 0 ,i=1,w, y, x,z,p,c2;

float g;
char h,j;
int main(){
	while(1){
		f = 0;
		printf("Enter number_ ");
		scanf("%d", &a); //se pide el numero a elevar
		e = a;
		b = a;
		c = b;
		d = 0;
		
		//se determina si b es par o impar comparando
		//el doble de su division truncada con su valor --> (b//2)*2 < b
		if(((b>>1)<<1<b)){
			c = b - 1;//se resta 1 a c para que sea numero par
			f = 1;//se registra la entrada al condicional con f = 1
		}
		//se calcula el multiplo de 2 para c y se alamcena en d
		for(w=1;w<c;w++){
			d = w<<1;//se multiplica w por 2
			//printf(" c2 =  %d ",d);
			if(!(d^c)){//cuando se encuentre w a la mitad de c se cumplira la condicion
				c2 = d>>1;//se divide d/2 para regresar rescatar la mitad de c
				//printf("c1 %d",c2);
				break;//se sale del ciclo
			}		
		}
		d = c2;
		p = 0;
		w = 0;
		y = 0;
		//se usa la siguiente secuencia para sumar a*2 el numero de vece
		//dado por el acumulador d.
		while(p<d){
			//se incrementa y, hasta a*2 + w, iniciando en w = 0
			for(y=w;y<(a<<1)+w;y++){
				
			}
			//si p es mayor o igual a "d" entonces se sale del ciclo while.
			p = p + 1;
			if(p>=d){
				a = y;//a contiene ahora el resultado de la multiplicacion
				break;
			}
			//si no se cumple la condicion, se incrementa w, hasta a*2 + y
			//entonces en la siguiente corrida el primer ciclo comienza
			//en y = w, para incrementarse hasta a*2 + su valor incial.
			for(w=y;w<(a<<1)+y;w++){
				
			}
			p = p +1;
			if(p>=d){
				a = w;//a contiene ahora el resultado de la multiplicacion
				break;
			}
		}
		
		//si al principio el "b" fue impar se realiza una suma de
		// a + e, donde "e" tiene el valor inicial de "a", ingresado
		//al principio del programa.
		if(f){
		for(w=0;w<a;w++){//se incrementa w desde 0 hasta "a"
			}
		x = w<<2;//se multiplica es valor por 4 para que sea mayor a "a + e"
		for(y=w;y<x;y++){//se incrementa "y" con valor incial de "w", hasta
		//x = 4*w
			if(y-w==e){//cuando y-w = e significa que y se ha incremntado "e" veces
			//donde "e" = al primer operando ingresado inicialmente.
				a=y;
			}
		
		}
		if(c == 0){//en caso de que el segundo operando fuese menor que 2, 
		//se iguala el resultado al primer operando ingresado nada mas.
			a = e;
			
		}
		}
		if(!b){
			a = 0;
		}

		//se imprime el resultado
		printf("input: %d^2\n", e);
		printf("output = %d\n\n",a);
		
	}


	

	
}
