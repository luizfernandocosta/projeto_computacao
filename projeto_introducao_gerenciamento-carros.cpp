#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"

// Define a estrutura do vendedor
struct vendedor{
  char nome[40];
};

// Define a estrutura do proprietário
struct proprietario{
  char nome[40];
  int senha = 123456;
};

// Define a estrutura de cadastro do cadastraCarro
struct carro{
  char marca[40];
  char modelo[40];
  char cor[40];
  int ano;
  float valorVeiculo;
};

// Define o metodo para registro de carros
void cadastraCarro(){

  carro carro;
  vendedor vendedor;

  float gratificacao;

  char marcaParaTroca[40];
  char modeloParaTroca[40];
  int anoVeiculo;
  float valorDoVeiculoParaTroca;

  //Define variaveis para o FILE;
  FILE *carrosCadastrados;
  FILE *historicoOperacoes;

  char nomeComprador[40];
  int CPF = 0;

  char entrouCarro;

  fflush(stdin);
  printf("Digite o nome do comprador: ");
  gets(nomeComprador);
  printf("\n");
  printf("Digite o CPF do comprador: ");
  scanf("%d", &CPF);
  printf("\n");
  fflush(stdin);
  printf("Digite a marca do veiculo: ");
  gets(carro.marca);
  printf("\n");
  printf("Digite o modelo do veiculo: ");
  gets(carro.modelo);
  printf("\n");
  printf("Digite a cor do veiculo: ");
  gets(carro.cor);
  printf("\n");
  printf("Digite o ano do veiculo: ");
  scanf("%d", &carro.ano);
  printf("\n");
  printf("Digite o valor do veiculo: ");
  scanf("%f", &carro.valorVeiculo);
  printf("\n");
  fflush(stdin);
  printf("O comprador entrou com algum carro? ");
  scanf("%c", &entrouCarro);

  if(entrouCarro == 's'){
  	fflush(stdin);
  	printf("Digite a marca para troca: ");
  	gets(marcaParaTroca);
  	printf("\n");
    printf("Digite o modelo para troca: ");
    gets(modeloParaTroca);
    printf("\n");
  	printf("Digite o ano do veiculo: ");
  	scanf("%d", &anoVeiculo);
  	printf("\n");
  	printf("Digite o valor do veiculo: ");
  	scanf("%f", &valorDoVeiculoParaTroca);

  	fflush(stdin);
  	printf("Nome do vendedor: ");
  	gets(vendedor.nome);

    carrosCadastrados = fopen("carroscadastrados.txt", "a+");
    historicoOperacoes = fopen("historicodeoperacoes.txt", "a+");

    gratificacao = (carro.valorVeiculo - valorDoVeiculoParaTroca) * 0.05;

  if(carrosCadastrados != 0 && historicoOperacoes != 0){
    fprintf(carrosCadastrados, "Nome do Comprador: %s\nCPF: %d\nMarca do Veiculo: %s\nModelo do Veiculo: %s\nCor do Veiculo: %s\nAno: %d\nValor: %.2f\nMarca do veiculo para troca: %s\nModelo do veiculo: %s\nAno: %d\nValor: %.2f\nNome do Vendedor: %s\nGratificao: %.2f", nomeComprador, CPF, carro.marca, carro.modelo, carro.cor, carro.ano, carro.valorVeiculo, marcaParaTroca, modeloParaTroca, anoVeiculo, valorDoVeiculoParaTroca, vendedor.nome,
	gratificacao);
    printf("\nCarro cadastrado com sucesso!\n");
    fprintf(carrosCadastrados, "\n\n");
    fclose(carrosCadastrados);

    fprintf(historicoOperacoes, "%s vendido por %.2f reais!\n\n", carro.modelo, carro.valorVeiculo);
    fclose(historicoOperacoes);
  } else {
    printf("Nao foi possivel encontrar ");
  }



  } else if(entrouCarro == 'n') {

  fflush(stdin);
  printf("Nome do vendedor: ");
  gets(vendedor.nome);

  carrosCadastrados = fopen("carroscadastrados.txt", "a+");
  historicoOperacoes = fopen("historicodeoperacoes.txt", "a+");

  gratificacao = carro.valorVeiculo * 0.05;

  if(carrosCadastrados != 0 && historicoOperacoes != 0){
    fprintf(carrosCadastrados, "Nome do Comprador: %s\nCPF: %d\nMarca do Veiculo: %s\nModelo do Veiculo: %s\nCor do Veiculo: %s\nAno: %d\nValor: %.2f\nNome do Vendedor: %s\nGratificao: %.2f", nomeComprador, CPF, carro.marca, carro.modelo, carro.cor, carro.ano, carro.valorVeiculo, vendedor.nome,
	gratificacao);
    printf("\nCarro cadastrado com sucesso!\n");
    fprintf(carrosCadastrados, "\n\n");
    fclose(carrosCadastrados);

    fprintf(historicoOperacoes, "%s vendido por %.2f reais!\n\n", carro.modelo, carro.valorVeiculo);
    fclose(historicoOperacoes);
  } else {
    printf("Nao foi possivel encontrar ");
  }

  }
}

void pesquisaCarro(){
	FILE *carrosCadastrados;
	carrosCadastrados = fopen("carroscadastrados.txt", "a+");
	char pesquisa;

	if(carrosCadastrados == NULL){
		printf("Arquivo nao foi aberto\n");
		getch();
		exit(1);
	}

	rewind(carrosCadastrados);

	while(!feof(carrosCadastrados)){
		fscanf(carrosCadastrados, "%c", &pesquisa);
		if(!feof(carrosCadastrados)){
			printf("%c", pesquisa);
		}
	}
	fclose(carrosCadastrados);
}

void exibeHistorico(){

	FILE *historicoOperacoes;
	historicoOperacoes = fopen("historicodeoperacoes.txt", "r");

	char pesquisa;

	if(historicoOperacoes == NULL){
		printf("Arquivo nao foi aberto\n");
		getch();
		exit(1);
	}

	rewind(historicoOperacoes);

		while(!feof(historicoOperacoes)){
		fscanf(historicoOperacoes, "%c", &pesquisa);
		if(!feof(historicoOperacoes)){
			printf("%c", pesquisa);
		}
	}
	fclose(historicoOperacoes);
}

void verificaSenha(){

}

int main(){
  int opcao;
  printf("Selecione o operador: \n\n");
  printf("1 - Vendedor\n2 - Proprietario\n\nOpcao: ");
  scanf("%d", &opcao);
  printf("\n\n");
  system("cls");
do{
  switch (opcao) {
    // Vendedor
    case 1:
      printf("Seja bem-vindo ");
      int segundaOpcao, operacao;
      printf("O que voce deseja fazer?\n\n1 - Cadastrar novo veiculo\n2 - Pesquisar veiculo\n\n3 - Sair\n\nOperacao: ");
      scanf("%d", &segundaOpcao);
      printf("\n");

      switch (segundaOpcao) {
        case 1:
          system("cls");
          cadastraCarro();
          system("pause");
          system("cls");
          break;
        case 2:
          system("cls");
          pesquisaCarro();
          break;
        case 3:
        	exit(1);
      }
      break;
    // Proprietario
    case 2:
      proprietario proprietario;
      int senha, terceiraOpcao;
      printf("Digite a senha do proprietario: ");
      scanf("%d", &senha);
      if(senha == proprietario.senha){
        printf("Bem-vindo proprietario! O que deseja fazer?\n");
        printf("1 - Cadastrar novo veiculo\n2 - Pesquisar veiculo\n3 - Historico de Operacoes\n4 - Mudar senha\nOperacao: ");
        scanf("%d", &terceiraOpcao);
        switch(terceiraOpcao){
        	case 1:
        		system("cls");
        		cadastraCarro();
        		system("pause");
        		break;
        	case 2:
        		system("cls");
        		pesquisaCarro();
        		system("pause");
        		break;
        	case 3:
        		system("cls");
        		exibeHistorico();
        		system("pause");
        		break;
		}
      } else {
        printf("Senha incorreta");
      }
      break;
  }

  } while(opcao != 3);
}
