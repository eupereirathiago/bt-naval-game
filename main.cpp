#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    int opcao = 0;
    char tabuleiro1[10][10];
    char tabuleiro2[10][10];
    int l, c;
    int linha, coluna;
    char direcao;
    int linhaAtaque, colunaAtaque;
    int jogador;
    int pontosJogador1 = 0;
    int pontosJogador2 = 0;
    char continuar;
    
	printf("=====================================\n");
    printf("=          BATALHA NAVAL            =\n");
    printf("=====================================\n\n");
	
	  printf("          |    |    |\n");
    printf("         )_)  )_)  )_)\n");
    printf("        )___))___))___)\\\n");
    printf("       )____)____)_____)\\\\\n");
    printf("     _____|____|____|____\\\\__\n");
    printf("----\\                   /-----\n");
    printf("     \\_________________/\n");
    printf("      \\  \\  /    \\  \\  /\n");
    printf("~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~\n");
	
	printf("=====================================\n");
    printf("=          1 - INICIA               =\n");
    printf("=          2 - COMO JOGAR           =\n");
    printf("=          3 - SOBRE                =\n");
    printf("=====================================\n\n");
    
    printf("DIGITE UMA OP��O: \n");
	scanf("%d", &opcao);
    
    system("cls");
    
    switch(opcao){
    	case 1:
    
	// INICIA O JOGO 
    do {
        jogador = 1;
        
		// INICIALIZA OS TABULEIROS COM �GUA REPRESENTADA POR '~'
    for (l = 0; l < 10; l++) {
        for (c = 0; c < 10; c++) {
        	
            tabuleiro1[l][c] = '~';
            tabuleiro2[l][c] = '~';

        }
    }


	//POSICIOMANTO DE NAVIOS P1
    // TABULEIRO PLAYER1
    printf("Tabuleiro do Jogador 1:\n");
    printf("   0 1 2 3 4 5 6 7 8 9\n");
    for (l = 0; l < 10; l++) {
        printf("%d ", l);
        for (c = 0; c < 10; c++) {
            printf("%c ", tabuleiro1[l][c]);
        }
        printf("\n");
    }
    
    
	//PORTA AVIOES (3)
    do {
        printf("Posicione o Porta-avi�o (3 c�lulas)\n");
        printf("Linha inicial (0-9): ");
        scanf("%d", &linha);
        printf("Coluna inicial (0-9): ");
        scanf("%d", &coluna);
        printf("Dire��o (h para horizontal, v para vertical): ");
        scanf(" %c", &direcao);
		
		// VERIFICA SE O NAVIO FICA DENTRO DO TABULEIRO
        if ((direcao == 'h' && coluna + 3 > 10) || (direcao == 'v' && linha + 3 > 10)) {
            printf("Posi��o inv�lida: o navio ultrapassa o tabuleiro. Tente novamente.\n\n");
        } else {
            break;
        }
    } while (1);
	
	// POSICIONA O NAVIO NO TABULEIRO (H=horizontal | V=vertical)
    if (direcao == 'h')
        for (c = coluna; c < coluna + 3; c++)
            tabuleiro1[linha][c] = 'P';
    else
        for (l = linha; l < linha + 3; l++)
            tabuleiro1[l][coluna] = 'P';

    //SUBMARINO (2)
    do {
        printf("\nPosicione o Submarino (2 c�lulas)\n");
        printf("Linha inicial (0-9): ");
        scanf("%d", &linha);
        printf("Coluna inicial (0-9): ");
        scanf("%d", &coluna);
        printf("Dire��o (h para horizontal, v para vertical): ");
        scanf(" %c", &direcao);

        if ((direcao == 'h' && coluna + 2 > 10) || (direcao == 'v' && linha + 2 > 10)) {
            printf("Posi��o inv�lida: o navio ultrapassa o tabuleiro. Tente novamente.\n\n");
        } else {
            break;
        }
    } while (1);

    if (direcao == 'h')
        for (c = coluna; c < coluna + 2; c++)
            tabuleiro1[linha][c] = 'S';
    else
        for (l = linha; l < linha + 2; l++)
            tabuleiro1[l][coluna] = 'S';

    // BBOTE (1 c�lula)
    do {
        printf("\nPosicione o Bote (1 c�lula)\n");
        printf("Linha (0-9): ");
        scanf("%d", &linha);
        printf("Coluna (0-9): ");
        scanf("%d", &coluna);

        if (linha < 0 || linha > 9 || coluna < 0 || coluna > 9) {
            printf("Posi��o inv�lida: fora do tabuleiro. Tente novamente.\n\n");
        } else {
            break;
        }
    } while (1);

    tabuleiro1[linha][coluna] = 'B';

    // TABULEIRO PRONTO DO PLAYER 1
    printf("\nTabuleiro final do Jogador 1:\n");
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for (l = 0; l < 10; l++) {
        printf("%d ", l);
        for (c = 0; c < 10; c++)
            printf("%c ", tabuleiro1[l][c]);
        printf("\n");
    }
    
    
	printf("\n");
	
	//PAUSA E LIMPAR TELA
	system("pause");
	system("cls");
	
	// REPETE O PROCESSO PARA O PLAYER2
	
	//POSICIONAMENTO DE NAVIOS P2
	
	  // EXIBINDO O TABULEIRO PARA O P2 SE POSICIONAR
    printf("Tabuleiro do Jogador 2:\n");
    printf("   0 1 2 3 4 5 6 7 8 9\n");
    for (l = 0; l < 10; l++) {
        printf("%d ", l);
        for (c = 0; c < 10; c++) {
            printf("%c ", tabuleiro2[l][c]);
        }
        printf("\n");
    }
	
	
		//PORTA AVIOES (3)
    do {
        printf("Posicione o Porta-avi�o (3 c�lulas)\n");
        printf("Linha inicial (0-9): ");
        scanf("%d", &linha);
        printf("Coluna inicial (0-9): ");
        scanf("%d", &coluna);
        printf("Dire��o (h para horizontal, v para vertical): ");
        scanf(" %c", &direcao);

        if ((direcao == 'h' && coluna + 3 > 10) || (direcao == 'v' && linha + 3 > 10)) {
            printf("Posi��o inv�lida: o navio ultrapassa o tabuleiro. Tente novamente.\n\n");
        } else {
            break;
        }
    } while (1);

    if (direcao == 'h')
        for (c = coluna; c < coluna + 3; c++)
            tabuleiro2[linha][c] = 'P';
    else
        for (l = linha; l < linha + 3; l++)
            tabuleiro2[l][coluna] = 'P';

    //SUBMARINO (2)
    do {
        printf("\nPosicione o Submarino (2 c�lulas)\n");
        printf("Linha inicial (0-9): ");
        scanf("%d", &linha);
        printf("Coluna inicial (0-9): ");
        scanf("%d", &coluna);
        printf("Dire��o (h para horizontal, v para vertical): ");
        scanf(" %c", &direcao);

        if ((direcao == 'h' && coluna + 2 > 10) || (direcao == 'v' && linha + 2 > 10)) {
            printf("Posi��o inv�lida: o navio ultrapassa o tabuleiro. Tente novamente.\n\n");
        } else {
            break;
        }
    } while (1);

    if (direcao == 'h')
        for (c = coluna; c < coluna + 2; c++)
            tabuleiro2[linha][c] = 'S';
    else
        for (l = linha; l < linha + 2; l++)
            tabuleiro2[l][coluna] = 'S';

    // BBOTE (1 c�lula)
    do {
        printf("\nPosicione o Bote (1 c�lula)\n");
        printf("Linha (0-9): ");
        scanf("%d", &linha);
        printf("Coluna (0-9): ");
        scanf("%d", &coluna);

        if (linha < 0 || linha > 9 || coluna < 0 || coluna > 9) {
            printf("Posi��o inv�lida: fora do tabuleiro. Tente novamente.\n\n");
        } else {
            break;
        }
    } while (1);

    tabuleiro2[linha][coluna] = 'B';
    
      // TABULEIRO FINAL PLAYER2
    printf("\nTabuleiro final do Jogador 2:\n");
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for (l = 0; l < 10; l++) {
        printf("%d ", l);
        for (c = 0; c < 10; c++)
            printf("%c ", tabuleiro2[l][c]);
        printf("\n");
    }
    
    //PAUSA E LIMPA A TELA
    system("pause");
	system("cls");

	// ########### RODADA DOS ATAQUES ########### //
	
    int fimDeJogo = 0;
    while (!fimDeJogo) {
    	
    printf("\n=== VEZ DO JOGADOR %d ===\n", jogador);
	
	// MOSTRAR TABULEIRO PARA ATAQUE DEPENDENDO DE QUAL PLAYER EST� JOGANDO
	//IF P1, TABULEIRO P2 | ELSE P2 TABULEIRO P1
    if (jogador == 1) {
        printf("Tabuleiro do Jogador 2:\n");
        printf("  0 1 2 3 4 5 6 7 8 9\n");
        for (l = 0; l < 10; l++) {
            printf("%d ", l);
            for (c = 0; c < 10; c++) {
                char valor = tabuleiro2[l][c];
                if (valor == 'X' || valor == 'O') {
                	printf("%c ", valor);
                } else {
                	printf("~ ");
                }
            }
            printf("\n");
        }
    } else {
        printf("Tabuleiro do Jogador 1:\n");
        printf("  0 1 2 3 4 5 6 7 8 9\n");
        for (l = 0; l < 10; l++) {
            printf("%d ", l);
            for (c = 0; c < 10; c++) {
                char valor = tabuleiro1[l][c];
            	if (valor == 'X' || valor == 'O') {
                	printf("%c ", valor);
            	} else {
                	printf("~ ");
                }
            }
                printf("\n");
        }
    }
		
	// JOGADOR ESCOLHE ONDE ATACAR
	printf("Digite a linha de ataque (0-9): ");
	scanf("%d", &linhaAtaque);
	printf("Digite a coluna de ataque (0-9): ");
	scanf("%d", &colunaAtaque);
	
	
	// VERIFICA SE A COORDENADA � V�LIDA,
	if (linhaAtaque < 0 || linhaAtaque >= 10 || colunaAtaque < 0 || colunaAtaque >= 10) {
	    printf("Coordenada invalida!\n");
	    
	} else {
	    char celula;
	
	    if (jogador == 1) {
	        celula = tabuleiro2[linhaAtaque][colunaAtaque];
	    } else {
	        celula = tabuleiro1[linhaAtaque][colunaAtaque];
	    }
	    
	    if (celula == 'P' || celula == 'S' || celula == 'B') {
	        printf("ACERTOU um navio!\n");
	        
	        //SE O JOGADOR 1 TIVER JOGANDO, MARCA NO TAB2 | SE N�O � CONTRARIO 
	        if (jogador == 1) {
	            tabuleiro2[linhaAtaque][colunaAtaque] = 'X'; // JOGADOR MARCA ACERTO NO TAB2
	        } else {
	            tabuleiro1[linhaAtaque][colunaAtaque] = 'X'; // JOGADOR2 MARCA ACERTO NO TAB1
	        }
	    } else if (celula == '~') {
	        printf("�gua! Errou.\n");
	        if (jogador == 1) {
	            tabuleiro2[linhaAtaque][colunaAtaque] = 'O'; // JOGADOR MARCA ERRO NO TAB2
	        } else {
	            tabuleiro1[linhaAtaque][colunaAtaque] = 'O'; // JOGADOR2 MARCA ERRO NO TAB1
	        }
	    } else if (celula == 'X' || celula == 'O') {
	        printf("Essa posi��o j� foi atacada. Perdeu a vez!\n"); //SE ACERTAR COORDENADA JA ATINGIDA EXUBE A MENSAGEM
	    }

	}
	
		
		// A QUANTIDADE DE NAVIOS H� EM CAMPO
        int naviosRestantes = 0;
        if (jogador == 1) {
        	
            for (l = 0; l < 10; l++) {
            	
            	for (c = 0; c < 10; c++) {
            		
               	 if (tabuleiro2[l][c] == 'P' || tabuleiro2[l][c] == 'S' || tabuleiro2[l][c] == 'B') {
                    naviosRestantes++;
               	 }
            	}
            }
        } else {
        	
            for (l = 0; l < 10; l++) {
            	
            	for (c = 0; c < 10; c++) {
            		
               	 if (tabuleiro1[l][c] == 'P' || tabuleiro1[l][c] == 'S' || tabuleiro1[l][c] == 'B') {
                    naviosRestantes++;
               	 }
            	}
        	}
        }
        
		// VERIFICA SE N�O RESTA MAIS NENHUM NAVIO INTEIRO NO TABULEIRO DO ADVERS�RIO
        if (naviosRestantes == 0) {
        	
        	printf("Jogador %d venceu a partida!\n", jogador); // EXIBE MENSAGEM DE VIT�RIA PARA O JOGADOR ATUAL
        	
        	// ADICIONA PONTO AO JOGADOR VENCEDOR
            if (jogador == 1)
                pontosJogador1++;
            else
                pontosJogador2++;
            fimDeJogo = 1;
        } else {
        	
            jogador = (jogador == 1) ? 2 : 1; // ALTERNA A VEZ PARA O OUTRO JOGADOR
        }
        
		// PAUSA E LIMPA A TELA
        system("pause");
        system("cls");
        }
		
		// MOSTRA O PLACAR E PERGUNTA SE QUER JOGAR NOVAMENTE	
        printf("PLACAR ATUAL:\nJogador 1: %d ponto(s)\nJogador 2: %d ponto(s)\n", pontosJogador1, pontosJogador2);
        
        printf("/n");
        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &continuar);
        
		system("cls");
	
    } while (continuar == 's' || continuar == 'S');
    	
    	
    	break;
    	
    	case 2:
    	//como jogar
    	printf("COMO JOGAR:\n");
    	
    	printf("\n");
        printf("Cada jogador posiciona seus navios:\n");
        printf("- Porta-Avi�o (3 c�lulas)\n");
        printf("- Submarino (2 c�lulas)\n");
        printf("- Bote (1 c�lula)\n\n");
        
		printf("\n");
        printf("Depois, os jogadores alternam ataques tentando acertar os navios inimigos.\n");
        printf("Vence quem destruir todos os navios do oponente.\n\n");
        
        system("pause");
        system("cls");
        
		main();
    	break;
    	
    	case 3:
    	//SOBRE
    	printf("Esse jogo foi desenvolvido para fins educacionais e pr�tica de programa��o em C. \n");
        printf("Por: Thiago Pereira, Carlos Iarley, Jos� Ven�ncio, Yuri Carvalho, Italo Kau�, Dandara Gomes, Lucas Oliveira \n\n");
        
		system("pause");
        system("cls");
       
	    main();
    	
    	break;
	}

    

    return 0;
}
