#include <stdio.h>
#include<conio.h>
//declarando variables
int k, z=0, i,yy,m;
int seen[] = {0};
int rest[] = {0};	
int Secuencia(int x[],int x1){
	int len = x1; //len se define como la longitud del arreglo
	k = 0;//es la variable donde se almacenara la solucion
	
	//se recorren los valores del arreglo un ciclo for  1 sola vez
	//el arreglo seen[] contiene los numero recorridos
	//el arreglo rest[] contiene aquellos que ya se han
	//encontrado mas de 2 veces
	for(i =0;i<len;i++){
		//se evalua si el valor actual x1[i] es igual al valor de seen[] en su
		//posicion igual al valor actual, en referencia a que ha sido visto
		if(!(seen[x[i]]^x[i])){
			//si rest[] en su posicion igual al valor actual es igual al valor actual
			//implicando que se ha integrado a seen[] y se ha vuelto a encontrar
			if(!(rest[x[i]]^x[i])){
				k = k^x[i];	//se elimina el valor actual de k con un X0R
			}
			//se almacena el valor actual en rest[], en el indice igual al valor actual
			rest[x[i]] = x[i];
		}
		//Si el valor actual no sea visto, no es igual al valor de seen[] en su
		//indice igual a valor actual
		if(seen[x[i]]^x[i]){
		//seen en su inidice igual al valor actual se iguala a x[i]
			seen[x[i]] = x[i];
		//se almacena en k con un X0R
			k = k^x[i];		
		}	
	}
	printf("\n");
	return (k);//se regresa k
}
int main(){
	printf("Enter size of array_\n");
	scanf("%d",&m);
	//se inicializa un arreglo de logitud dada y se piden sus valores uno por uno
	int array[m]; 
	for(w=0;w<m;w++){
		printf("enter array[%d]>:\n ",w);
		scanf("%d",&array[w]);	
	}
	//se imprime el arreglo ingresado
	printf("array = (");
	for(w=0;w<sizeof(array)/4;w++){
		printf("%d ",array[w]);
	}
	printf(")\n");
	//se envia el arreglo mas su talla a la funcion secuencia
 	yy = Secuencia(array,m);
 	//se imprime el resultado de salida
 	printf("Output= %d",yy);
}

