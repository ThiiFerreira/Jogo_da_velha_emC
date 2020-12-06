#include <stdio.h>
#include <stdlib.h>

//Thiago da Silva Ferreira, PT300984X
/*1- Crie um jogo da velha ou também conhecido como cerquilha, jogo do galo ou tic-tac-toe.
O seu jogo deve permiter que dois jogadores joguem. Um com X e outro com O.
Não se esqueça de identar o código e de colocar comentários. COLOQUE SEU NOME COMPLETO DENTRO DO ARQUIVO.
Dica: utilize uma matriz 3x3 para criar o tabuleiro. */

char velha[3][3]={' ',' ',' ',
				  ' ',' ',' ',
			      ' ',' ',' ',}; //declarando a matriz para guardas as jogadas

void jogo(){ // funcao para desenhar o jogo na tela e mostras as jogadas feitas
	system("cls");
	printf(" %c | %c | %c                         1-1|1-2|1-3\n",velha[0][0],velha[0][1],velha[0][2]);
	printf("------------  exemplo de preencher -----------\n");
	printf(" %c | %c | %c 	    ----> [l-c]    2-1|2-2|2-3\n",velha[1][0],velha[1][1],velha[1][2]);	
	printf("------------                       -----------\n");	
	printf(" %c | %c | %c                         3-1|3-2|3-3\n\n",velha[2][0],velha[2][1],velha[2][2]);		
}
int venceu1(){//verifica se o jogador 1 preencheu algum caso que vença o jogo
  int jogador=0;
	if(velha[0][0]=='x' && velha[1][0]=='x' && velha[2][0]=='x')
	  	jogador=1;
	if(velha[0][1]=='x' && velha[1][1]=='x' && velha[2][1]=='x')
	  	jogador=1;
	if(velha[0][2]=='x' && velha[1][2]=='x' && velha[2][2]=='x')
		jogador=1;
	if(velha[0][0]=='x' && velha[0][1]=='x' && velha[0][2]=='x')
	  	jogador=1;
	if(velha[1][0]=='x' && velha[1][1]=='x' && velha[1][2]=='x')
	  	jogador=1;
	if(velha[2][0]=='x' && velha[2][1]=='x' && velha[2][2]=='x')
	  	jogador=1;
	if(velha[0][0]=='x' && velha[1][1]=='x' && velha[2][2]=='x')
	  	jogador=1;
	if(velha[0][2]=='x' && velha[1][1]=='x' && velha[2][0]=='x')
	  	jogador=1;//caso caia na condicação altera o jogador de 0 para 1
	return jogador;
}
int venceu2(){//verifica se o jogador 2 preencheu algum caso que vença o jogo
int jogador=0;
	if(velha[0][0]=='o' && velha[1][0]=='o' && velha[2][0]=='o')
		jogador=2;
	if(velha[0][1]=='o' && velha[1][1]=='o' && velha[2][1]=='o')
	  	jogador=2;
	if(velha[0][2]=='o' && velha[1][2]=='o' && velha[2][2]=='o')
	  	jogador=2;
	if(velha[0][0]=='o' && velha[0][1]=='o' && velha[0][2]=='o')
	 	 jogador=2;
	if(velha[1][0]=='o' && velha[1][1]=='o' && velha[1][2]=='o')
	  	jogador=2;
	if(velha[2][0]=='o' && velha[2][1]=='o' && velha[2][2]=='o')
	 	jogador=2;
	if(velha[0][0]=='o' && velha[1][1]=='o' && velha[2][2]=='o')
	 	jogador=2;
	if(velha[0][2]=='o' && velha[1][1]=='o' && velha[2][0]=='o')
		jogador=2; //caso caia na condicação altera o jogador de 0 para 2
  	return jogador;
}
int main(void) {
	int l=0, c=0;//variaveis para guarda a linha e a coluna que o jogador escolheu 
	int rodada=1,ganhador=0; //variaveis de controle para final de jogo
	char jogador1[10];
	char jogador2[10];
	printf("Digite o nome do jogador 1:");
	scanf("%s", jogador1);
	printf("Digite o nome do jogador 2:");
	scanf("%s", jogador2);
	
	//loop do jogo
	do{
		jogo();//chama a funcao jogo para mostra a velha na tela
		printf("Rodada %d\n", rodada);//mostra qual rodada esta o jogo
		printf("\nVez do %s\nDigite a linha e a coluna:", jogador1);//jogador 1 escolhe aonde jogar
		scanf("%d%d",&l,&c);
	
		
		while(velha[l-1][c-1]!=' ' || l>3 || c>3){//verifica se a opcao é valida para jogar se nao pede para o jogador jogar novamente
			printf("Linha ou coluna invalida (%d-%d)\nEscolha outra:",l,c);
			scanf("%d%d", &l,&c);
		}
		velha[l-1][c-1]='x';//guarda o 'x' no lugar do espaço que ta la armazenado
		ganhador=venceu1();//chama a funcao venceu1 para verificar se o jogador ja preencheu todas as casas para vencer o jogo 
						   //e alterando o ganhador para 1		
		
		//verifica se o ganhador ainda é 0 e as rodada porque o jogador 2 só joga 4 vezes
		if(ganhador==0 && rodada<5){
			jogo();//chama a funcao jogo para mostra a velha na tela					
			printf("\nVez do %s\nDigite a linha e a coluna:", jogador2);//jogador 2 escolhe aonde jogar
			scanf("%d%d",&l,&c);
			while(velha[l-1][c-1]!=' ' || l>3 || c>3){//verifica se a opcao é valida para jogar se nao pede para o jogador jogar novamente
			printf("Linha ou coluna invalida (%d-%d)\nEscolha outra:",l,c);
			scanf("%d%d", &l,&c);
		}
			velha[l-1][c-1]='o';//guarda o 'o' no lugar do espaço que ta la armazenado
			ganhador=venceu2();//chama a funcao venceu2 para verificar se o jogador ja preencheu todas as casas para vencer o jogo
		}				       //e alterando o ganhador para 2
		rodada++;//conta as rodadas
	}while(ganhador==0 && rodada<6);//verifica a condicao para ver se fica no loop ou sai
	
	if(ganhador==1){//caso o jogador 1 ganhe
		jogo();
		printf("jogador 1 %s venceu\n", jogador1);
	}
	if(ganhador==2){//caso o jogador 2 ganhe
		jogo();
		printf("jogador 2 %s venceu\n", jogador2);
	}
	if(ganhador==0){//caso de empate 
		jogo();
		printf("Empate\niiiiii deu velha hahaha\n");
	}	
}
