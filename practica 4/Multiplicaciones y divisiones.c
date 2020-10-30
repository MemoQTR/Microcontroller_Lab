#include <stdio.h>
#include <math.h>
int a,b,c,e,f = 0 ,i=1,w,y,z = 1,x,x1,p,p1,x2,c2,d;
float g;
char h,j;
int multi(int a, int b){
	e = a; //se alamacena el primer operando "a"
	c = b; //se almacena el segundo operando "b"
	d = 0;// se inicializa un acumulador
	c2 = 0;
	f = 0;
	//se determina si b es par o impar comparando
	//el doble de su division truncada con su valor --> (b//2)*2 < b
	if(((b>>1)<<1<b)){
		c = b - 1; //se resta 1 a c para que sea numero par
		f = 1; //se registra la entrada al condicional con f = 1	
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
	d= c2;//se reinicializa el acumulador d
	//for(w=0;w<c2;w++){//con el for se encuentra 2^c2
	//	d = d<<1;
	//}
	p = 0;//se inicializa el acumulador p
	//se reinicia w y se inicializa y como 0
	w = 0;
	y = 0;

	while(p<d){
		//se incrementa y, hasta a*2 + w, iniciando en w = 0
		for(y=w;y<(a<<1)+w;y++){
			
		}
		//si p es mayor o igual a "d" (2^c2) entonces se sale del ciclo while
		//implicando que a<<2 se ha sumado c2 veces
		p = p +1;//se multiplica p por 2 para incrementar el acumulador
		if(p>=d){
			a = y;//a contiene ahora el resultado de la multiplicacion
			break;
		}
		//si no se cumple la condicion, se incrementa w, hasta a*2 + y
		//entonces en la siguiente corrida el primer ciclo comienza
		//en y = w, para incrementarse hasta a*2 + su valor incial.
		for(w=y;w<(a<<1)+y;w++){
			
		}
		//se vuelve ha hacer la misma condicional
		p = p +1;
		if(p>=d){
			a = w;//a contiene ahora el resultado de la multiplicacion
			break;
		}
	
		
	}
	

	if(f){//si b fue impar se le suma el primer operando al resultado
	//a = a + e
		
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
	return(a);//se regresa el resultado

}
int main(){
	
	while(1){
		f = 0;
		printf("\n");
		printf("enter operation as V1*V2 or V1/V2: ");
		//se pide la operacion a traves de tres parametros
		//un operando y 2 operadores
		scanf("%d%c%d", &a , &h, &b); 
		printf("\n");
		//dependiendo del caracter se escoge entra en una condicion
		if(h == '*'){
			//se manda llamar la funcion de multipliacion que recibe
			//los dos operandos enteros pedidos.
			printf("resultado = %d",multi(a,b));
			printf("\n");
	    }
	
	    x2 = 1;
	    z = 1;
		if(h == '/'){
			while(multi(b,x2)<=a){
				
				//para encontrar el valor truncado, se verifica que
				//la multipolicacion del valor actual de x2 + 1, sea menor
				//que el dividendo, de esa forma se evita que se admitan valores
				//mayores cuando el resultado es decimal y queda entre medio
				if((multi(b,x2+1))>a){
					z = x2;
					break;
				}
				
				x2 = x2 + 1;
				
			}
			//z = x2;
			printf("resultados = %d",z);
			printf("\n");
			}
		}
	
		
		
		}
	
	

	


