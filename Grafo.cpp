#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void calc(int x,int vert);
char matriz [100][100];
int grafo[100]={0};
int vertvisitado = 0,arst=0,cnx = 1;



int main(){
	setlocale(LC_ALL, "Portuguese");
	int escolha,TAMmatriz, vert,x=0,y=0,w=0,q=0;	
	printf("\t\nNumero de vertices:  ");
	scanf("%d", &TAMmatriz);
		TAMmatriz=TAMmatriz+1;
		for ( x=1; x<TAMmatriz; x++ ){
    	for ( y=1; y<TAMmatriz; y++ ){
			
		matriz[x][y]=NULL;
		
		if(x==y){
		matriz[x][y]='0';	
			}
		}
		}	
	int z=TAMmatriz;	
	printf("\n");
  	do{
  		printf(" |=====================================================================|\n");
        printf(" |1--------------------------ADICIONAR VERTICE-------------------------|\n");
        printf(" |2----------------------------REMOVER VERTICE-------------------------|\n");
        printf(" |3-------------------------------ARESTAS------------------------------|\n");
        printf(" |4--------------------------NUMERO DE VERTICES------------------------|\n");
        printf(" |5---------------------------NUMERO DE ARESTAS------------------------|\n");
        printf(" |6----------------------------GRAU DOS VERTICES-----------------------|\n");
        printf(" |7------------------------VERIFICAR GRAFO EULERIANO-------------------|\n");
        printf(" |8-----------------------------MOSTRAR MATRIZ-------------------------|\n");
        printf(" |0----------------------------------SAIR------------------------------|\n");
        printf(" |=====================================================================|\n");
        printf("\nESCOLHA UMA OPÇÃO:");
		scanf("%d", &escolha);
		 printf("\n");
		switch(escolha){
			case 1:
				printf("Vertice a adicionar: ");
				scanf("%d", &vert);
				for ( y=1; y<=z; y++ ){
				matriz[vert][y]= NULL;
				matriz[y][vert]= NULL;}
				if(vert==y){
				matriz[vert][y]='0';
				}
				printf("\n");
				break;
			case 2:
				printf("Vertice a remover: ");
				scanf("%d", &vert);
				for ( y=1; y<z; y++ ){
				matriz[vert][y]=NULL;
				matriz[y][vert]=NULL;}
				printf("\n");
				break;
			case 3:
                printf ("\nEscolha 1 ou 0\n\n");
 
				for ( x=1; x<z; x++ ){
					q=x;
				for ( y=q+1;y<z; y++){
      			 printf ("[%d][%d] = ", x, y);
      			 scanf (" %c",&matriz[ x ][ y ]);
       
    			if(matriz[ x ][ y ] == '0' || matriz[ x ][ y ] == '1'){
    			if(matriz[ x ][ y ] == '1'){
    				arst++;
				}
        		matriz[y] [x] = matriz[x] [y];	   
    			}
    			}
    			}
    			printf("\n");
                break;
            case 4:
                for ( x=1; x<z; x++ ){
    			for ( y=1; y<z; y++ ){
				if(x==y){
				if(matriz[ x ][ y ] == '0' || matriz[ x ][ y ] == '1')	{
				w++;
				 }
				}
				}
				}
				printf("Quantidade de vertices: %d\n",w);
				printf("\n");
                break;
            case 5:
                for ( x=1; x<z; x++ ){
    			for ( y=x+1; y<z; y++ ){
				if(matriz[x][y]=='1'){
				w++;
				}
				}
				}
				printf("Quantidade de arestas: %d\n",w);
				printf("\n");
                break;
            case 6:
                for ( x=1; x<z; x++ ){
				w=0;
		
    			for ( y=1; y<z; y++ ){
				if(matriz[x][y]=='1'){
				w++;
				}
				if(y==z-1 && matriz[x][y]!= NULL){
				printf ("Elmt[%d] = %d", x, w);
				}
				}
				printf("\n");
				}
				printf("\n");
                break;
            case 7:	
    			for(x = 1; x < vert; x++){
        		calc(x, vert);
       			 if(vertvisitado+1 != vert){ 
         		 cnx = 0;                              
                 }
                 }
    			if(cnx == 0){
        		printf("\n Grafo desconexo!");
    			}else{
   			     printf("\n Grafo conexo!");
				}
				printf("\n");
                break;
            case 8:
            	for ( x=1; x<z; x++ ){
    			for ( y=1; y<z; y++ ){
				if(matriz[x][y]=='0' || matriz[x][y]=='1'){
				printf("%d-%d %c ",x,y,matriz[x][y]);
				}
				}
				printf("\n");
				}
				printf("\n");
				break;
			case 0:
				break;
		}
	}while(escolha != 0);
}
void calc(int x, int vert){
    int y;
	grafo[x] = 1;
    for(y = 1; y <= vert; y++){
        if(grafo[y]==0 && matriz[x][y] == '1'){
            vertvisitado++;
            calc(y,vert);
        }
        
    }


}

