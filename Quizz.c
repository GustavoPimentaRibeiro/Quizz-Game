#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

#define NUM_QUESTOES 5
#define NUM_OPCOES 4

void clear(){
	printf("\n");
    system("PAUSE");
    system("CLS");
}

int main(){
    setlocale(LC_ALL, "portuguese");

    char questoes[][100] = {"1 - Qual a linguagem mais rápida em execução de código do mundo?",
                            "2 - Quem criou a linguagem C?",
                            "3 - Quem é o predecessor da linguagem C?",
							"4 - Qual a biblioteca da linguagem C responsável por entrada/saída?",
							"5 - Qual a biblioteca da linguagem C responsável por alocação de memória?"}; // Array de strings para armazenar todas as perguntas
    
    char opcoes[][100] = {"A. C++", "B. Java", "C. Python", "D. C",
                        "A. Dannis Ryan", "B. Dennis Ritchie", "C. Dennis Ritchies", "D. Dannis Ritchie",
                        "A. C#", "B. C++", "C. F#", "D. Java",
						"A. stdlib.h", "B. ctype.h", "C. time.h", "D. stdio.h",
						"A. bool.h", "B. string.h", "C. stdlib.h", "D. stdio.h"}; // Array de strings para armazenar todas as opções de cada alternativa

    char respostas[NUM_QUESTOES] = {'D','B','B', 'D', 'C'}; // Resposta em cada índice

    // int numeroDeQuestoes = sizeof(questoes) / sizeof(questoes[0]); // Maneira alternativa para conseguir o número de questões através do sizeof sem número de vetor fixo

    char palpite;
    int pontuacao = 0;
    int i, j;

    printf("########################## QUIZZ DE PROGRAMAÇÃO ##########################\n");

    for(i = 0; i < NUM_QUESTOES; i ++){
        printf("\n+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
		printf("%s", questoes[i]);
		printf("\n+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
        for(j = i * NUM_OPCOES; j < i * NUM_OPCOES + NUM_OPCOES; j ++){
        	printf("\n%s", opcoes[j]);
		}
		printf("\n\n: ");
		fflush(stdin);
        scanf("%c", &palpite);
        if(palpite == respostas[i]){
        	pontuacao ++;
		}
    }
    
    clear();
    if(pontuacao == 0){
    	printf("\n\nInfelizmente você não acertou nenhuma pergunta =(", pontuacao);
	}else if(pontuacao == NUM_QUESTOES){
		printf("\n\nVocê acertou todas as questões, parabéns!", pontuacao);
	}else if(pontuacao > 0){
		printf("\n\nVocê acertou um total de %d/%d perguntas!", pontuacao, NUM_QUESTOES);
	}
	printf("\n\nFim do programa!\n");
	
    return 0;
}
