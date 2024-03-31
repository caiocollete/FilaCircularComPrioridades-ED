#define MAXFILA 10

struct dado{
	char info;
	char prioridade;
};

struct TpFilaCir{
	int INICIO,FIM,cont;
	dado FILA[MAXFILA];	
};

void Inicializar(TpFilaCir &F){
	F.INICIO=0;
	F.FIM=-1;
	F.cont=0;
}

void PUSH(TpFilaCir &F,dado elemento){
	dado AUX;
	int i;
	
	 if(F.FIM==MAXFILA-1)
	 	F.FIM=-1;
	 	
	F.FILA[++F.FIM]=elemento;
	i=F.FIM;
	while(i>F.INICIO && F.FILA[i].prioridade<F.FILA[i-1].prioridade){
		AUX=F.FILA[i-1];
		F.FILA[i-1]=F.FILA[i];
		F.FILA[i]=AUX;
		i--;
	}
	F.cont++;
}

dado POP(TpFilaCir &F){
	dado aux=F.FILA[F.INICIO++];
	
	if(F.INICIO==MAXFILA-1){
		F.INICIO=0;
	}
	
	F.cont--;
	return aux;
}

char FilaVazia(int cont){
	return cont==0;
}

char FilaCheia(int cont){
	return cont==MAXFILA;
}

void ExibirFila(TpFilaCir F){
	dado aux;
	while(!FilaVazia(F.cont)){
		aux=POP(F);
		printf("\t%d.%c",aux.info,aux.prioridade);
	}
}

dado ElementoInicio(TpFilaCir F){
	return F.FILA[F.INICIO];
}

dado ElementoFim(TpFilaCir F){
	return F.FILA[F.FIM];
}
