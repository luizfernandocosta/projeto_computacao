// Programa feito por Luiz Fernando, Renan Barroso e Guilherme Abe

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"

//Define o struct do proprietario
struct proprietario{
  char nomeProprietario[40];
  FILE *senha = fopen("senhaproprietario.txt", "r");
};

//Define o struct do vendedor
struct vendedor{
  char nome[40];
};

//Define o struct do comprador
struct comprador{
  char nome[40];
  int CPF;
};

//Define o struct do carro para venda
struct carro{
  char marca[40];
  char modelo[40];
  char cor[40];
  int ano;
  float valorDoCarro;
};

//Define o struct do carro para troca
struct carroParaTroca{
  char marca[40];
  char modelo[40];
  char cor[40];
  int ano;
  float valorDoCarro;
};

void cadastraVenda(){

  //Chamando os structs e criando variaveis para eles
  carro carro;
  vendedor vendedor;
  carroParaTroca carroParaTroca;
  comprador comprador;

  //Zerando as variaveis para evitar lixo
  comprador.CPF = 0;
  carro.ano = 0;
  carro.valorDoCarro = 0;
  carroParaTroca.ano = 0;
  carroParaTroca.valorDoCarro = 0;

  //Define as variaveis para manipular o FILE
  FILE *carrosCadastrados;
  FILE *historicoDeOperacoes;

  //Variavel para calculo de gratificacao do vendedor depois
  float gratificacao;

  //Variavel para verificacao se o comprador entrou carro para troca
  char entrouCarro;

  //Aqui comeca o procecsso de cadastro da venda
  fflush(stdin);
  printf("Digite o nome do comprador: ");
  gets(comprador.nome);
  printf("\n");
  printf("Digite o CPF do comprador: ");
  scanf("%d", &comprador.CPF);
  printf("\n");
  fflush(stdin);
  printf("Digite a marca do carro comprado: ");
  gets(carro.marca);
  printf("\n");
  printf("Digite o modelo do carro comprado: ");
  gets(carro.modelo);
  printf("\n");
  printf("Digite a cor do veiculo comprado: ");
  gets(carro.cor);
  printf("\n");
  printf("Digite o ano do veiculo comprado: ");
  scanf("%d", &carro.ano);
  printf("\n");
  printf("Digite o valor do carro comprado: ");
  scanf("%f", &carro.valorDoCarro);
  printf("\n");
  fflush(stdin);
  printf("O comprador entrou com algum carro para trocar?\n");
  printf("[S/N]: ");
  scanf("%c", &entrouCarro);
  printf("\n");
  //Aqui termina o cadastro e verifica se o comprador entrou com carro para troca
  if(entrouCarro == 's' || entrouCarro == 'S'){
    fflush(stdin);
    printf("Digite a marca do carro para troca: ");
    gets(carroParaTroca.marca);
    printf("\n");
    printf("Digite o modelo do carro para troca: ");
    gets(carroParaTroca.modelo);
    printf("\n");
    fflush(stdin);
    printf("Digite a cor do veiculo para troca: ");
    gets(carroParaTroca.cor);
    printf("\n");
    printf("Digite o ano do veiculo para troca: ");
    scanf("%d", &carroParaTroca.ano);
    printf("\n");
    printf("Digite o valor do veiculo: ");
    scanf("%f", &carroParaTroca.valorDoCarro);
    printf("\n");
    fflush(stdin);
    printf("Nome do vendedor: ");
    gets(vendedor.nome);

    //Abrindo os arquivos para cadastro
    carrosCadastrados = fopen("carroscadastrados.txt", "a+");
    historicoDeOperacoes = fopen("historicodeoperacoes.txt", "a+");

    //Calculo da gratificacao do vendedor
    gratificacao = (carro.valorDoCarro - carroParaTroca.valorDoCarro) * 0.05;

    if(carrosCadastrados != 0 && historicoDeOperacoes != 0){

      //Cadastrando o que o usuario digital no txt historicodeoperacoes
      fprintf(historicoDeOperacoes, "Nome do comprador: %s\nCPF: %d\nMarca do carro comprado: %s\nModelo do carro comprado: %s\nCor do veiculo comprado: %s\nAno: %d\nValor: %.2f\nComprador entrou com carro para troca?: Sim\nMarca do carro para troca: %s\nModelo do carro para troca: %s\nCor: %s\nAno: %d\nValor: %.2f\nNome do vendedor: %s\nGratificacao: %.2f", comprador.nome, comprador.CPF, carro.marca, carro.modelo, carro.cor, carro.ano, carro.valorDoCarro, carroParaTroca.marca, carroParaTroca.modelo, carroParaTroca.cor, carroParaTroca.ano, carroParaTroca.valorDoCarro, vendedor.nome, gratificacao);
      printf("\nVenda cadastrada com sucesso!\n");
      fprintf(historicoDeOperacoes, "\n\n");
      fclose(historicoDeOperacoes);

      //Cadastrando o carro que entrou para troca para venda
      fprintf(carrosCadastrados, "Marca: %s\nModelo: %s\nCor: %s\nAno: %d\nValor: %.2f", carroParaTroca.marca, carroParaTroca.modelo, carroParaTroca.cor, carroParaTroca.ano, carroParaTroca.valorDoCarro);
      printf("\nCarro trocado cadastrado para venda!\n");
      fprintf(carrosCadastrados, "\n\n");
      fclose(carrosCadastrados);
    } else {
      printf("Nao foi possivel abrir arquivo!\n");
    }
  } else if (entrouCarro == 'n' || entrouCarro == 'N'){
    fflush(stdin);
    printf("Nome do vendedor: ");
    gets(vendedor.nome);

    carrosCadastrados = fopen("carroscadastrados.txt", "a+");
    historicoDeOperacoes = fopen("historicodeoperacoes.txt", "a+");

    gratificacao = carro.valorDoCarro * 0.05;

    if(carrosCadastrados != 0 && historicoDeOperacoes != 0){
      fprintf(historicoDeOperacoes, "Nome do comprador: %s\nCPF: %d\nMarca do carro comprado: %s\nModelo do carro comprado: %s\nCor do veiculo comprado: %s\nAno: %d\nValor: %.2f\nComprador entrou com algum carro para troca?: Nao\nNome do vendedor: %s\nGratificacao: %.2f", comprador.nome, comprador.CPF, carro.marca, carro.modelo, carro.cor, carro.ano, carro.valorDoCarro, vendedor.nome, gratificacao);
      printf("\nVenda cadastrada com sucesso!\n");
      fclose(historicoDeOperacoes);
    } else {
      printf("Nao foi possivel abrir arquivo!\n");
    }
  }
}

//Funcao para cadastrar novos carros
void cadastraCarro(){

  //Variavel para chamar o struct carro
  carro carro;
  //Variavel para manipular o FILE
  FILE *carrosCadastrados;

  fflush(stdin);
  printf("Digite a marca do carro: ");
  gets(carro.marca);
  printf("\n");
  printf("Digite o modelo do carro: ");
  gets(carro.modelo);
  printf("\n");
  printf("Digite a cor do carro: ");
  gets(carro.cor);
  printf("\n");
  printf("Digite o ano do carro: ");
  scanf("%d", &carro.ano);
  printf("\n");
  printf("Digite o valor do veiculo para venda: ");
  scanf("%f", &carro.valorDoCarro);
  printf("\n");

  carrosCadastrados = fopen("carroscadastrados.txt", "a+");

  if(carrosCadastrados != 0){
    fprintf(carrosCadastrados, "Marca: %s\nModelo: %s\nCor: %s\nAno: %d\nValor: %.2f", carro.marca, carro.modelo, carro.cor, carro.ano, carro.valorDoCarro);
    printf("\nCarro cadastrado para venda!\n");
    fprintf(carrosCadastrados, "\n\n");
    fclose(carrosCadastrados);
  } else {
    printf("Nao foi possivel abrir arquivo!\n");
  }
}

//Funcao para pesquisar carros a venda
void pesquisaCarroParaVenda(){

  	FILE *carrosCadastrados;
  	carrosCadastrados = fopen("carroscadastrados.txt", "r");
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

//Funcao para exibir o historico de operacoes
void exibeHistoricoDeOperacoes(){

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

void mudaSenhaProprietario(){
  FILE *senhaProprietario = fopen("senhaproprietario.txt", "w+");
  char senha[80];
  char verifica[80];
  char novaSenha[80];

  printf("Por favor, digite sua senha atual: ");
  gets(senha);
  rewind(senhaProprietario);
  fscanf(senhaProprietario, "%s", verifica);

  if(strcmp(verifica, senha) == 0){
    printf("Digite sua nova senha: ");
    gets(novaSenha);
    fprintf(senhaProprietario, "%s", novaSenha);
    fclose(senhaProprietario);
    printf("Sua senha foi alterada com sucesso!");
    printf("\n");
  } else {
    printf("Senha incorreta, por favor digite novamente: \n");
    system("pause");
    system("cls");
    }
}

//Funcao criada para o menu do proprietario
void menuProprietario(){

    int opcaoCase1;

      printf("Seja bem vindo, proprietario!\n");
      printf("O que deseja fazer?\n\n1 - Cadastrar nova venda\n2 - Cadastrar novo carro\n3 - Pesquisar carro\n4 - Verificar historico de operacoes\n5 - Mudar senha\n6 - Sair\n\nOperacao: ");
      scanf("%d", &opcaoCase1);
      do{
      switch (opcaoCase1) {
        case 1:
          system("cls");
          //Chamando a funcao para cadastrar nova venda
          cadastraVenda();
          system("pause");
          system("cls");
          menuProprietario();
        break;
        case 2:
          system("cls");
          //Chamando a funcao para cadastrar novo carro
          cadastraCarro();
          system("pause");
          system("cls");
          menuProprietario();
          break;
        case 3:
          system("cls");
          //Funcao que chama para pesquisar a lista de carros disponiveis
          pesquisaCarroParaVenda();
          system("pause");
          system("cls");
          menuProprietario();
          break;
        case 4:
          system("cls");
          //Funcao que chama o historico de operacoes
          exibeHistoricoDeOperacoes();
          system("pause");
          system("cls");
          menuProprietario();
          break;
        case 5:
          system("cls");
          //Funcao que chama para mudar a senha
          mudaSenhaProprietario();
          system("pause");
          system("cls");
          menuProprietario();
        case 6:
          exit(1);
        default:
          printf("Escolhe uma opcao dentre 1 e 6!\n");
          system("pause");
          system("cls");
          menuProprietario();
          break;
        }
    }while(opcaoCase1 != 6);
}

void menuVendedor(){
  int opcaoCase2;
  printf("Seja bem vindo!\n");
  printf("O que deseja fazer?\n\n1 - Cadastrar nova venda\n2 - Cadastrar novo carro\n3 - Pesquisar carro\n4 - Sair\n\nOperacao: ");
  scanf("%d", &opcaoCase2);
  printf("\n");
    do{
    switch (opcaoCase2) {
      case 1:
        system("cls");
        //Chamando a funcao para cadastrar nova venda
        cadastraVenda();
        system("pause");
        system("cls");
        menuVendedor();
        break;
      case 2:
        system("cls");
        //Chamando a funcao para cadastrar novo carro
        cadastraCarro();
        system("pause");
        system("cls");
        menuVendedor();
        break;
      case 3:
        system("cls");
        //Funcao que chama para pesquisar a lista de carros disponiveis
        pesquisaCarroParaVenda();
        system("pause");
        system("cls");
        menuVendedor();
        break;
      case 4:
        //Sair do programa
        exit(1);
      default:
        printf("Escolha uma opcao dentre 1 ate 4!\n");
        system("pause");
        system("cls");
        menuVendedor();
        break;
    }
  }while(opcaoCase2 != 4);
}

//Funcao para verificar a senha do proprietario
void verificaSenhaProprietario(){
  FILE *senhaProprietario = fopen("senhaproprietario.txt", "r");
  char senha[80];
  char verifica[80];
  printf("Por favor, digite a senha do proprietario: ");
  gets(senha);
  rewind(senhaProprietario);
  fscanf(senhaProprietario, "%s", verifica);
  fclose(senhaProprietario);

  if(strcmp(verifica, senha) == 0){
    menuProprietario();
  } else {
    printf("Senha incorreta, por favor digite novamente: \n");
    system("cls");
  }
}

//Funcao do menu principal do programa
void menu(){
  //Define a variavel para a escolha no switch-case
  int opcaoParaEscolha;

  printf("Selecione o operador: \n\n");
  printf("1 - Proprietario\n2 - Vendedor\n3 - Sair\n\nOpcao: ");
  scanf("%d", &opcaoParaEscolha);
  printf("\n\n");
  system("cls");

  do{
      switch(opcaoParaEscolha){
        //Opcao 1 para o proprietario
        case 1:
          verificaSenhaProprietario();
          break;
        //Opcao 2 para o vendedor
        case 2:
        menuVendedor();
        break;
        //Opcao para sair
        case 3:
          exit(1);
        default:
          printf("Por favor, escolha entre proprietario e vendedor");
          printf("\n");
          menu();
          break;
      }
  }while(opcaoParaEscolha != 3);
}

int main(){
  menu();
  return(0);
}
