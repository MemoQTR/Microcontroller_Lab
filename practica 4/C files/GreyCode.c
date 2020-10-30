#include <stdio.h>
int i, t = 1,m, x, limit,t1,suplimit,k,k1;



int grey(int bit){
	limit = 3;
	t = 1;
	//se inicializa un arreglo de longitud = bit. 
	int chain[bit];
	//se llena con zeros, y se calcula el numero
	//de cadenas para el codigo "t" = 2^bit
	for(i = 0;i<bit;i++){
		chain[i] = 0;
		t = t<<1;
	}
	t1 = 1;
	m = bit- 1; //"m" se define como la ultima posicion del arreglo
	
	while(t>0){
		//se imprime el arreglo
		for(i=0;i<bit;i++){
			printf("%d",chain[i]);	
		}
		printf(" ");
		//se invierte el bit de la posicion "m", que inicia
		//al final del arreglo, en el bit menos significativo
		if(t1<4){
			chain[m] = !(chain[m]);//toggle de chain[m] BIT
			m = m + 1;//se recorre al siguiente bit
		}
		
		//cuando t1 = 4, significa que se ha completado la secuencia
		//00 01 11 10 en los dos ultimos bits de Cadena
		if(!(t1 ^ 4 )){
			//entonces se invierte el siguiente bit, el tercero.
			//cuya posicion esta dada por bit-limit, donde limit
			//comienza con el valor de 3
			chain[bit-limit] = !(chain[bit-limit]);
			//(2-(chain[bit-limit]<<1))>>1;
			
			//si limit es mayor que la catindad de bits de la cadena
			//se le resta 2 para que pueda volver a incrementarse
			//cuando t1 vuelva a ser 4.
			if(limit<=bit){
				limit = limit + 1;//cuando se entre de nuevo al condicional
				//se invertira el siguiente bit
			}
			if(limit>bit){
			
				limit = limit - 2;
			}
			
			//se reinicia "m", pues este cambio no cuenta
			//dentro de la secuencia 00 01 11 10
			m = bit - 1;
			//lo mismo para t1, que se iguala a 0 para cancelar
			//el ultimo incremento y que comienze en 1 para el sig ciclo.
			t1 = 0;
		}
		
		//cuando la posicion m rebasa los dos ultimos lugares del arreglo
		//el bit menos significativo y el siguiente, se reinicia "m" 
		//para completar la secuencia 00 01 11 10
		if(m<(bit-2)){
			m = bit - 1;
		}
		//t contiene el valor del numero de cadenas a imprimir
		//el ciclo se detiene cuando t = 0.
		t = t - 1;
		
		//se incrementa en 1 el acumualdor "t1"
		t1 = t1 + 1;
	}
	
}
int main(){
	while(1){
		
		//se pide el numero de bits y se imprime
		// k-bit (n = k)
		printf("\n");
		printf("\n");
		printf("ingresa el numero de bits: ");
		scanf("%d",&k);
		printf("\n");
		k1 = k;
		printf("%d-bit ",k);
		printf("(n = %d)",k1);
		printf("\n");
		//se manda llamar la funcion para imprimir
		//las cadenas
		grey(k);	
	}
	
}
