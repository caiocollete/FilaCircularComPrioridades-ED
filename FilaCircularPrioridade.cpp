#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <windows.h>
#include <time.h>
#include "tadCir.h"


int main(){
	int ut;
	TpFilaCir F;
	dado Dado;
	char a;
	
	srand(0);
	
	Inicializar(F);

	
	ut=0;
	printf("UT: %d\t%%3 = PUSH\t%%5 = POP\n",ut);
	printf("\nFILA:");ExibirFila(F);
	while(!FilaCheia(F.cont) && !kbhit()){
 		
		//INSERE
		if(ut%3==0){
			Dado.info=ut;
			a=rand()%10;
			if(a<=3){
				Dado.prioridade='A';
				PUSH(F,Dado);
			}
			if(a>3 && a<=7){
				Dado.prioridade='B';
				PUSH(F,Dado);
			}
			if(a>7){
				Dado.prioridade='C';
				PUSH(F,Dado);				
			}
		}
		
		//REMOVE
		if(ut%5==0 && !FilaVazia(F.cont)){
			POP(F);
		}		
		
		Sleep(1000);
		ut++;
		clrscr();
		printf("UT: %d\t%%3 = PUSH\t%%5 = POP\n",ut);
		printf("\nFILA:");ExibirFila(F);
	}

	getch();
	getch();
	
}
