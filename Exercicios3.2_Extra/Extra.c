#include <stdio.h>

double calculoMedia(double mediaFinal,double n1, double n2, double ppd, double exameUni, double n3,int validacao1, int validacao2){
	if(validacao1 == 1 && validacao2 == 0){
		mediaFinal = n1 + n2 + ppd + exameUni;
	}else if(validacao1 == 0 && validacao2 == 0){
		mediaFinal = n1 + n2 + ppd;
	}else if(validacao1 == 1 && validacao2 == 1){
		if(n1 < n2){
			n1 = n3;
			mediaFinal = n1 + n2 + ppd + exameUni;
		}else{
			n2 = n3;								
			mediaFinal = n1 + n2 + ppd + exameUni;
		}	
	} else if(validacao1 == 0 && validacao2 == 1){
		if(n1 < n2){
			n1 = n3;
			mediaFinal = n1 + n2 + ppd;
		}else{
			n2 = n3;
			mediaFinal = n1 + n2 + ppd + exameUni;
		}	
	}
	return mediaFinal;
} // Funcao que valida e calcula a media Final do Aluno

int main(){
	double n1,n2,n3,ppd,exameUni,mediaFinal;
	int media = 7,validacao1,validacao2;
	
	// Entrada de dados
	
	do{
	printf("Digite sua nota na N1:");
	scanf("%lf", &n1);
	printf("Digite sua nota na N2:");
	scanf("%lf", &n2);
	printf("Digite sua nota no PPD:");
	scanf("%lf", &ppd);
	printf("Voce realizou o Exame unificado? [0]Nao [1]Sim.");
	scanf("%d", &validacao1);
	
	// Valida se o aluno fez o Exame Unificado ou a N3
	
	if(validacao1 == 1){
		printf("Digite sua nota no Exame unificado:");
		scanf("%lf", &exameUni);
	}
	printf("Voce realizou a Recuperacao(N3)? [0]Nao [1]Sim.");
	scanf("%d", &validacao2);
	if(validacao2 == 1){
		printf("Digite sua nota na N3:");
		scanf("%lf", &n3);
	}
	
	// Verifica se as notas Estao no intervalo permitido.
	
	if((n1 < 0 || n1 > 4.5) || (n2 < 0 || n2 > 4.5) || (validacao2 == 1 &&(n3 < 0 || n3 > 4.5))){
		printf("O valor das notas bimestrais deve estar entre 0 e 4.5.Por favor digite novamente...\n");
	} else if(ppd < 0 || ppd > 1){
		printf("O valor da PPD deve estar entre 0 e 1.Por favor digite novamente...\n");
	} else if(validacao1 == 1 && (exameUni < 0 || exameUni > 1)){
		printf("O valor do Exame Unificado deve estar entre 0 e 1.Por favor digite novamente....\n");
	}	
	
	// Repete caso algo esteja incorreto.
	
	}while((n1 < 0 || n1 > 4.5) || (n2 < 0 || n2 > 4.5) || 
	(validacao2 == 1 &&(n3 < 0 || n3 > 4.5)) || (ppd < 0 || ppd > 1) ||
	(validacao1 == 1 && (exameUni < 0 || exameUni > 1)));
	
	mediaFinal = calculoMedia(mediaFinal,n1,n2,ppd,exameUni,n3,validacao1,validacao2);
	
	// Verifica se o Aluno esta abaixo, acima ou ultrapassou a media.
	
	if(mediaFinal < media){
		printf("Infelizmente voce esta Reprovado: %.2lf", mediaFinal);
	} else if(mediaFinal > 10){
		printf("Meus parabens voce Passou com folga, mas a nota maxima e 10");
	}else{
		printf("Felizmente voce esta Aprovado: %.2lf", mediaFinal);
	}

	return 0;
	
}