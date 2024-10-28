#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Pokemon
{
	char nome[20]; //nome do pokemon
	int dex; //numero do pokemon na pokedex (vai ser util depois)
	int hp; //vida do pokemon
	int speed; //velocidade do pokemon
	char itemEquipado[25]; //item que o pokemon esta equipado
} pkmn;

typedef struct Player
{
	char nome[15]; //nome dos jogadores
	int dinheiro; //dinheiro dos jogadores
	char timepokemon[6][25]; // pokemons dos jogadores
} player;


/* fun��es */
void construirPlayer(player *treinador); //foi o jeito que eu pensei de fazer um metodo construtor em C
void pokedex(pkmn pkdex[]); 
void adicionarNaPokedex(pkmn pokemon, pkmn pkdex[]); //adiciona um pokemon na lista pokedex
void printarpkmn(pkmn pokemon, pkmn vetor[]); 
/* fun��es */

int main()
{
	setlocale(LC_ALL, "Portuguese");
	// declara e monta a pokedex (ta funcionando ja)
	pkmn pkdex[16]; 
	pokedex(pkdex);
	
	
	
	// declara e monta os players (ta funcionando ja)
	player treinador1; 
	/* player treinador2; */
	construirPlayer(&treinador1);
	/* construirPlayer(&treinador2); */
	
	printf("Seu nome: %s", treinador1.nome);
	printf("\nSeu dinheiro: %d", treinador1.dinheiro);
	/*printf("\n\n%s", treinador2.nome); */
	/*printf("\n%d", treinador2.dinheiro); */
	printf("\n\n");
	
	// declara, adiciona na pokedex e printa o nome dos pokemon (n ta funcionando por algum motivo maligno)
	
	pkmn umbreon = {"Umbreon", 2, 20, 14, "nenhum"};
	pkmn gardevoir = {"Gardevoir", 1, 15, 10, "nenhum"};
	pkmn garchomp = {"Garchomp", 9, 25, 9, "nenhum"};

	adicionarNaPokedex(umbreon, pkdex);
	adicionarNaPokedex(gardevoir, pkdex);
	adicionarNaPokedex(garchomp, pkdex);

	printf("\n\n");
	printarpkmn(umbreon, pkdex);
	printarpkmn(gardevoir, pkdex);
	printarpkmn(garchomp, pkdex);
	
	return 0;
}

void construirPlayer(player *treinador)
{
//	printf("\n  Bem vindo treinador!\n\n");
//	system("pause"); system("cls"); //limpa a tela pra ficar bunitinho
	
	/* eu sou incapaz de usar fgets fgets(treinador->nome, 20, stdin); */ //eu consegui usar, mas eu ainda prefiro usar scanf
	printf("Vamos come�ar pelo seu nome: ");
	fflush(stdin);
	scanf("%s", treinador->nome);
	
	treinador->dinheiro = 1000; //inicializa o dinheiro inicial do jogador, (1000 � um valor tempor�rio)
	
	int i;
	for(i = 0; i < 6; i++) {strcpy(treinador->timepokemon[i], "placeholder");} //inicializa todos os pokemons como placeholders
	system("cls");
	
}

void pokedex(pkmn pkdex[])
{
	pkmn *listadepokemons = (pkmn *)malloc(sizeof(int) * 6); //tamanho provis�rio pq eu n sei quantos pokemon a gente tem lol
	int i;
	for(i = 0; i < 24; i++) { listadepokemons[i].dex = 0; /* (teste) printf("%d\n", listadepokemons[i]); */ }
	/* printf("\n\n"); */

	
	pkdex = listadepokemons;
}

void adicionarNaPokedex(pkmn pokemon, pkmn pkdex[])
{
	int i;
	
	for(i = 0; i < 24; i++) //tamanho provis�rio pq eu n sei quantos pokemon a gente tem lol	
	{
		if(pkdex[i].dex == 0) 
		{ 
			strcpy(pkdex[i].nome, pokemon.nome);
			pkdex[i].dex = pokemon.dex;
			pkdex[i].hp = pokemon.hp;
			pkdex[i].speed = pokemon.speed;
			strcpy(pkdex[i].itemEquipado, pokemon.itemEquipado);
			return;
			printf("\n%d", pkdex[i].dex);
		}
		// printf("\n%d", pkdex[i].dex);
		/* (teste) ; */
	}


}

void printarpkmn(pkmn pokemon, pkmn vetor[])
{
	int i;
	for(i = 0; i < 24; i++)
	{
		if(pokemon.dex == vetor[i].dex)
		{
			printf("O pokemon na posi��o %d �: %s \n", pokemon.dex, pokemon.nome);
			fflush(stdout);
		}
	}

	
}
