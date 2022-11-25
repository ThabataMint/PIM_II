#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define N 100
#define TRUE			1
#define FALSE 		0

typedef unsigned char boolean;
typedef char string[50];

#define MAX_LINES 100
#define MAX_LEN 1000

typedef unsigned char boolean;
typedef char string[50];

struct Aniversario //estrutura de data de nascimento
{
  int dia, mes, ano;
};

// Estrutura para armazenar as informaçoes do funcionário, que serão fornecidas
// posteriormente
typedef struct {
  // ID, nome, cargo
  int id;
  char nome[50];
  char funcao[50];
  // Salario base, verba salarial (se é de risco, se é noturno, quantas horas
  float salBase;
  int risco;
  int noturno;
  int horasExtra;
  // Verba indenizatoria (vale-transporte, vale-refeição)
  float valeT;
  float valeR;
  // Dias no contrato, DSN, faltas, faltas descontadas de DSN
  int dias;
  int DSN;
  int faltas;
  int faltasDSN;
  // Porcentagem do adiantamento
  float adiantamento;
  // Por quantos dependentes o funcionário é responsável
  int dependentes;
  int idade;

  struct Aniversario aniversario; //aninhamento de estrutura
  struct Funcionario *prox;
} funcionario;

int CPF, senha;

int main() {
  
  telaLogin();
  telaMenu();

  return 0;
}

int funcaoMarcarPonto() {
  
  for (int i = 0; i < 2; i++) {
    for (int c = 0; c < 81; c++) {
      printf("*");
    }
    printf("\n");
  }
  printf("*****");
  for (int c = 0; c < 71; c++) {
    printf(" ");
  }
  printf("*****\n*****");
  for (int c = 0; c < 29; c++) {
    printf(" ");
  }
  printf("MARCAR PONTO");
  for (int c = 0; c < 30; c++) {
    printf(" ");
  }
  printf("*****\n*****");
  for (int c = 0; c < 71; c++) {
    printf(" ");
  }
  printf("*****\n");
  for (int i = 0; i < 2; i++) {
    for (int c = 0; c < 81; c++) {
      printf("*");
    }
    printf("\n");
  }

  int he,me,hs,ms,h;
  
  printf("Deseja inserir horário de entrada(1) ou saida(2)?\n");
  scanf("%d",&h);
  switch(h) {
    case 1:
      printf("Insira a hora de entrada:\n");
      scanf("%d",&he);
      printf("Insira o minuto de entrada:\n");
      scanf("%d",&me);
      printf("Horario de entrada: %d:%d\n",he,me);
      break;
    case 2:
      printf("Insira a hora de saida:\n");
      scanf("%d",&he);
      printf("Insira o minuto de saida:\n");
      scanf("%d",&me);
      printf("Horario de saida: %d:%d\n",he,me);
      break;
    default:
      printf("Operação invalida.\n");
    }
  
  return 0;
}

int funcaoMuralComunicados() {
  
  for (int i = 0; i < 2; i++) {
    for (int c = 0; c < 81; c++) {
      printf("*");
    }
    printf("\n");
  }
  printf("*****");
  for (int c = 0; c < 71; c++) {
    printf(" ");
  }
  printf("*****\n*****");
  for (int c = 0; c < 25; c++) {
    printf(" ");
  }
  printf("MURAL DE COMUNICADOS");
  for (int c = 0; c < 26; c++) {
    printf(" ");
  }
  printf("*****\n*****");
  for (int c = 0; c < 71; c++) {
    printf(" ");
  }
  printf("*****\n");
  for (int i = 0; i < 2; i++) {
    for (int c = 0; c < 81; c++) {
      printf("*");
    }
    printf("\n");
  }
  

  refaz:

  printf("O que voce deseja fazer?\n\n");

  int EscolhaUsuario;
  char titulo[100];
  char noticia[256];

  printf("1. Escrever um comunicado\n");
  printf("2. Ver comunicados");
  printf("\n\n****************\n\n");

  scanf("%d", &EscolhaUsuario);

  switch (EscolhaUsuario) {
    case 1:
      printf("\n*****************************\n");
      printf("** INSERIR NOVO COMUNICADO **\n");
      printf("*****************************\n\n");
      printf("Titulo do comunicado: ");
      
      scanf("%s", &titulo);
      printf("\n--------------------------------------------\n");
      printf("\n%s\n", titulo);
      printf("\n--------------------------------------------\n");
      printf("Escreva a noticia: ");
      
      scanf("%s", &noticia);
      printf("--------------------------------------------\n");
      printf("%s\n", titulo);
      printf("%s\n", noticia);
      printf("Noticia cadastrada.\n");
      
      //system('pause');
      //printf("Pressione qualquer tecla para continuar.\n");
      //system('clear');
      break;

    case 2:
      printf("%s\n\n", titulo);
      printf("--------------------------------------------");
      printf("%s\n\n", noticia);
      //system('clear');
      //printf("\n\n\nPressione qualquer tecla para continuar...");
      //system('clear');
      break;

    default:
      printf("Nenhuma ação válida associada.\n");
      goto refaz;
  }
  
  return 0;
}

int cadastroPermanente(funcionario f) {
  FILE *perm;
  perm = fopen("funcionarios.txt", "a");
  if (perm == NULL) {
    printf("Erro no cadastro.");
    return 0;
  } else {
    
    fprintf(perm, "\nID#$Nome#");
    fprintf(perm, f.nome);
    fprintf(perm, "$Idade#$Função#");
    fprintf(perm, f.funcao);
    fprintf(perm, "$Salário base#%.2f$Risco#%d$Noturno#%d$Horas extras#%d$", f.salBase, f.risco, f.noturno, f.horasExtra);
    fprintf(perm, "Vale transporte#%.2f$Vale refeição#%.2f$Dias#%d$DSN#%d$Faltas#%d$Faltas DSN#%d$", f.valeT, f.valeR, f.dias, f.DSN, f.faltas, f.faltasDSN);
    fprintf(perm, "Adiantamento#%.2f$Dependentes#%d$DiaN#%d$MesN#%d$AnoN#%d$", f.adiantamento, f.dependentes, f.aniversario.dia, f.aniversario.mes, f.aniversario.ano);
    fclose(perm);

    return 0;
  }
}

int matricula = 0; // variavel de controle do numero de funcionarios cadastrados

//declaração das funções que seram utilizadas no codigo
int menu();
funcionario* adicionar();
void insere_item(funcionario **lista, funcionario *item);
void atualizar(funcionario* lista);
void relatorio(funcionario* lista);
void consultar(funcionario* lista);
void deletar(funcionario **lista);
void apaga_todos_os_dados(funcionario **lista);
void exporta_dados_arquivo_txt(funcionario *lista);
void importa_dados_arquivo_txt(funcionario **lista);
void salva_dados_arquivo_bin(funcionario *lista);
void recupera_dados_arquivo_bin(funcionario **lista);
void remove_enter(char s[N]);
boolean lista_esta_vazia(funcionario *lista);

int funcaoCadastroFuncionarios() {
  
  for (int i = 0; i < 2; i++) {
    for (int c = 0; c < 81; c++) {
      printf("*");
    }
    printf("\n");
  }
  printf("*****");
  for (int c = 0; c < 71; c++) {
    printf(" ");
  }
  printf("*****\n*****");
  for (int c = 0; c < 23; c++) {
    printf(" ");
  }
  printf("CADASTRO DE FUNCIONÁRIOS");
  for (int c = 0; c < 24; c++) {
    printf(" ");
  }
  printf("*****\n*****");
  for (int c = 0; c < 71; c++) {
    printf(" ");
  }
  printf("*****\n");
  for (int i = 0; i < 2; i++) {
    for (int c = 0; c < 81; c++) {
      printf("*");
    }
    printf("\n");
  }
  
  funcionario *lista = NULL, *novo;
  
  int varwhile = 1; //loop para sempre voltar pro menu
  int opc; // variavel de escolha do menu

  //importa dados salvos anteriormente
  recupera_dados_arquivo_bin(&lista);
  
  while (varwhile) {
    
    opc = menu();
    system("clear");
    switch(opc){
      case 1:
        printf("\n Adicionar ficha de funcionario:  \n");
        novo = adicionar();
        cadastroPermanente(*novo);
        insere_item(&lista, novo);
        break;
      case 2:
        printf("\n Atualizar ficha de funcionario: \n");
        atualizar(lista);
        break;
      case 3:
        printf("\n Relatorio de funcionarios: \n");
        relatorio(lista);
        break;
      case 4:
        printf("\n Consultar funcionario: \n");
        consultar(lista);
        break;
      case 5:
        printf("\n Deletar um funcionario: \n");
        deletar(&lista);
        break;
      case 6:
        printf("\n Importar dados de um arquivo txt \n");
        importa_dados_arquivo_txt(&lista);
        break;
      case 7:
        printf("\n Exportar dados para um arquivo txt \n");
        exporta_dados_arquivo_txt(lista);
        break;
      case 8:
        printf("\n Apaga todos os dados cadastrados \n");
        apaga_todos_os_dados(&lista);
        break;
      case 9:
        printf("\n Encerrando programa... \n");
        //salva dados em um arquivo binario
        salva_dados_arquivo_bin(lista);
        varwhile = 0; //quebra o loop
        break;
      default:
        printf("\n Nenhuma ação válida associada a esta opção.");
      }
  }
  
  return 0;
}

int funcio() {

	char Nomes[40][20];                               // nome dependentes.
	int cont;                                     // break das entre respostas
	int op;                                       // Variavel da operação.
	float n1, n2, n3, n4, contador, contador1, i; // variaveis.
	int idaded[40][20];                               // Idade dos dependentes.
	char parente[40][20];								// Grau de parentesco.
	char materiais[40];							// Materiais de solicitação.
	int quantm[40];								//QUANTIDADE DOS MATERIAIS.
	char nomepm[40][20];						// nome Fun, Consulta medica.
	char espe[40][20];     					// especialidade do médico.
	
	// Primeira parte do painel

	  printf("\n._____________________________________.");
	  printf("\n|                                     |\n");
	  printf("|     ★★ Painel do funcionário ★★     |\n");
	  printf("|         ★ ACCESS FOR ALL ★          |");
	  printf("\n|_____________________________________|");

	  // Menu das opções.
	  printf("\n._____________________________________.");
	  printf("\n|                                     |");
	  printf("\n| 1 - Cadastro de dependentes         |");
	  printf("\n| 2 - Solicitação de exame médico     |");
	  printf("\n| 3 - Solicitação de materiais        |\n");
	  printf("| 4 - Sair                            |\n");
	  printf("|_____________________________________|\n");
	  printf("\n Selecione uma opção: ");
	  scanf("%d", &op);
	  printf("\n✎ ___________________________________________________________\n ");

  switch (op) {

	case 1:

		do { 
			printf("\n ► Cadastro de dependentes ◄\n");
			printf("Qual o nome do dependente?\n");
			printf("Nome: ");
			scanf("%S", &Nomes[0]);
			printf("Idade: ");
			scanf("%d", &idaded);
			printf("Grau de parentesco: ");
			scanf("%S", &parente);
			printf("\nPerfeito. %S %S foi cadastrado(a) com sucesso √√√\n", &parente[0], &Nomes[0]);
		

			printf("\n____________________________________________________________\n");
			printf("\n  Digite 1 se quiser continuar cadastrando.\n");
			scanf("%d", &cont);
			printf("\n____________________________________________________________\n");
			
		} while (cont == 1);
		break;

	case 2:

		do{
			printf("\n ► Exame médico ◄ \n\n");
			printf("Por gentileza, digite seu nome:\n");
			scanf("%s", nomepm[0]);
			printf("De qual especialidade você precisa?\n");
			scanf("%s", espe[0]);
			printf("\nSolicitação registrada com sucesso √√√");
			printf("\nNossa equipe entrará em contato com você em breve.");
			printf("\nSe precisar de urgência, entre em contato com ► 0800 2018 9587 ◄\n");
			printf("\n______________________________________________________________\n");
			printf("\nDigite 1 se quiser realizar outra solicitação.\n");
			scanf("%d", &cont);
			printf("\n____________________________________________________________\n");
			
		} while (cont == 1);
		break;
	  
	case 3:
	
		do {
		  
			printf("\n ► Solicitação de materiais de escritório ◄\n\n");
			printf("De qual você material você precisa?\n");
			scanf("%S", &materiais);
			printf("Em que quantidade você precisa?\n");
			scanf("%d", &quantm);
			printf("\nSolicitação foi registrada com sucesso √√√\n");
			printf("\n______________________________________________________________\n");
			printf("\nDigite 1 se quiser solicitar mais materiais.\n");
			scanf("%d", &cont);
			printf("\n____________________________________________________________\n");

		} while (cont == 1);
		break;

	case 4:
	
		printf("\nObrigado por utilizar nosso sistema.\n");
		printf("Para reportar erros no sistema, entre em contato com ► 0800 2018 9587 ◄\n");
		printf("\n___________________________________________________________\n");
		break;
	  
	default:
		
		printf("\nNenhuma opção válida detectada.");
    	printf("\nQue tal tentar de novo?\n");
		printf("\n____________________________________________________________\n"); 
		printf("\n");
  }

  return 0;
}

int funcaoFuncionarios() {
  
  for (int i = 0; i < 2; i++) {
    for (int c = 0; c < 81; c++) {
      printf("*");
    }
    printf("\n");
  }
  printf("*****");
  for (int c = 0; c < 71; c++) {
    printf(" ");
  }
  printf("*****\n*****");
  for (int c = 0; c < 29; c++) {
    printf(" ");
  }
  printf("FUNCIONÁRIOS");
  for (int c = 0; c < 30; c++) {
    printf(" ");
  }
  printf("*****\n*****");
  for (int c = 0; c < 71; c++) {
    printf(" ");
  }
  printf("*****\n");
  for (int i = 0; i < 2; i++) {
    for (int c = 0; c < 81; c++) {
      printf("*");
    }
    printf("\n");
  }

  funcio();
  
  return 0;
}

int funcaoPlanoFerias() {
  
  for (int i = 0; i < 2; i++) {
    for (int c = 0; c < 81; c++) {
      printf("*");
    }
    printf("\n");
  }
  printf("*****");
  for (int c = 0; c < 71; c++) {
    printf(" ");
  }
  printf("*****\n*****");
  for (int c = 0; c < 28; c++) {
    printf(" ");
  }
  printf("PLANO DE FÉRIAS");
  for (int c = 0; c < 28; c++) {
    printf(" ");
  }
  printf("*****\n*****");
  for (int c = 0; c < 71; c++) {
    printf(" ");
  }
  printf("*****\n");
  for (int i = 0; i < 2; i++) {
    for (int c = 0; c < 81; c++) {
      printf("*");
    }
    printf("\n");
  }
  
  char nome[50];
  char funcao[50];
  char mes[20];
  int dia_do_mes;
  int prim_switch;
  int seg_switch;
  
  printf("\nNome do funcionário:\n");
  scanf("%s", &nome);
  printf("\nFunção do funcionário:\n");
  scanf("%s", funcao);
  printf("\nDeseja o período de férias completo [1] ?\nDeseja o período de férias fragmentado (até 2 períodos semanais e/ou um período de 14 dias) [2] ?\nDeseja vender suas férias (10 dias) [3] ?\n");
  scanf("%d", &prim_switch);
  
  switch(prim_switch) {
      
    case 1:
      printf("\nQual o mês de início do período de férias?\n");
      scanf("%s", &mes);
      printf("\nQual o dia de início do período de férias?\n");
      scanf("%d", &dia_do_mes);
      printf("\nA data selecionada para início das férias é: %d", dia_do_mes);
      printf(" de %s", &mes);
      break;
    
    case 2:
      printf("\nAgendar período semanal [1] ou de 14 dias [2]?\n");
      scanf("%d", &seg_switch);
      
      switch (seg_switch) {
        
        case 1:
          printf("\nQual o mês de início do período de férias?\n");
          scanf("%s", &mes);
          printf("\nQual o dia de início do período de férias?\n");
          scanf("%d", &dia_do_mes);
          printf("\nA data selecionada para início das férias é: %d", dia_do_mes);
          printf(" de %s", &mes);
          break;
        
        case 2:
          printf("\nQual o mês de início do período de férias?\n");
          scanf("%s", &mes);
          printf("\nQual o dia de início do período de férias?\n");
          scanf("%d", &dia_do_mes);
          printf("\nA data selecionada para início das férias é: %d", dia_do_mes);
          printf(" de %s", &mes);
          break; 
      }
      break;
        
    case 3:
      printf("\nQual o mês de início do período de venda de férias?\n");
      scanf("%s", &mes);
      printf("\nQual o dia de início da venda de férias?\n");
      scanf("%d", &dia_do_mes);
      printf("\nA data selecionada para início da venda de férias é: %d", dia_do_mes);
      printf(" de %s", &mes);
      break;
  }
  
  return 0;
}

// Estrutura para o cálculo que será feito baseado em informações do funcionário
typedef struct {
  // Bonus por ser de risco, bonus por ser noturno, bonus por horas extras, dias
  // comparecidos
  float risco;
  float noturno;
  float horasExtra;
  int totalDias;
  // Verba salarial, verba indenizatoria, remuneração
  float verbaSal;
  float verbaInde;
  float remuneracao;
  // Porcentagem de VT, porcentagem de VR, dedução por dependentes, valor do
  // INSS
  float VT;
  float VR;
  float deducao;
  float INSS;
  // Base de cálculo IRRF, valor do IRRF, valor do adiantamento
  float baseCalc;
  float IRRF;
  float adiantamento;
  // Total de descontos, porcentagem do FGTS, valor do FGTS, salário líquido
  float desconto;
  float FGTS;
  float fundoGar;
  float salLiq;
} holerite;

// Estrutura para ler texto do arquivo
typedef struct {
  char texto[MAX_LINES][MAX_LEN];
} pagina;

// Fornce as informações do usuário. Nesta iteração está fixo; estou fazendo uma
// forma para pegar as informações da lista de funcionários
funcionario atribuiFunc(funcionario f) {
  printf("Digite o nome do funcionário:\n");
  scanf("%s", &f.nome);
  printf("\nDigite a função exercida pelo funcionário:\n");
  scanf("%s", &f.funcao);
  printf("\nSe a função do funcionário apresenta risco, digite 1.\nCaso contrário, digite 0.\n");
  scanf("%d", &f.risco);
  printf("\nSe o funcionário trabalha horas noturnas, digite 1.\nCaso contrário, digite 0.\n");
  scanf("%d", &f.noturno);
  printf("\nInforme quantas horas extras o funcionário trabalhou este mês: ");
  scanf("%d", &f.horasExtra);
  printf("\nInforme o salário deste funcionário: R$ ");
  scanf("%f", &f.salBase);
  printf("\nInforme o vale-transporte disponibilizado ao funcionário:\nR$ ");
  scanf("%f", &f.valeT);
  printf("\nInforme o vale-refeição disponibilizado ao funcionário:\nR$ ");
  scanf("%f", &f.valeR);
  printf("\nQuantos dias o funcionário faltou este mês?\n");
  scanf("%d", &f.faltas);
  printf("\nQuantos dias do descanso semanal remunerado serão descontados?\n");
  scanf("%d", &f.faltasDSN);
  printf("\nPor quantos dependentes o funcionário é responsável?\n");
  scanf("%d", &f.dependentes);
  f.dias = 22;
  f.DSN = 9;
  return f;
}

// Calcular o INSS em específico
float calculoINSS(float remuneracao) {
  float INSS = 0;
  if (remuneracao <= 1212)
    INSS = 0.075 * remuneracao;
  else if (remuneracao <= 2427.35)
    INSS = 0.09 * remuneracao;
  else if (remuneracao <= 3641.03)
    INSS = 0.12 * remuneracao;
  else if (remuneracao <= 7087.22)
    INSS = 0.14 * remuneracao;
  else
    INSS = 0.275 * remuneracao;
  return INSS;
}

// Calcular o IRRF em específico
float calculoIRRF(float baseCalc) {
  float IRRF;
  if (baseCalc <= 1903.98)
    IRRF = 0;
  else if (baseCalc <= 2826.65)
    IRRF = 0.075 * baseCalc;
  else if (baseCalc <= 3751.05)
    IRRF = 0.15 * baseCalc;
  else if (baseCalc <= 4664.68)
    IRRF = 0.225 * baseCalc;
  else
    IRRF = 0.275 * baseCalc;
  return IRRF;
}

// Calcular o salário baseado nas informações do funcionário
holerite calculoHoler(funcionario f, holerite h) {

  h.totalDias = f.dias + f.DSN - f.faltas - f.faltasDSN;

  h.risco = (f.risco) ? f.salBase * 0.3 : 0;
  h.noturno = (f.noturno) ? f.salBase * 0.2 : 0;
  h.horasExtra = f.horasExtra * (f.salBase / 220) * 0.5;
  h.verbaSal = h.risco + h.noturno + h.horasExtra;
  h.verbaInde = f.valeT + f.valeR;

  h.remuneracao = f.salBase + h.verbaSal + h.verbaInde;

  // Função dentro de função
  h.INSS = calculoINSS(h.remuneracao);
  h.baseCalc = h.remuneracao - h.INSS;
  // Função dentro de função
  h.IRRF = calculoIRRF(h.baseCalc);
  h.deducao = f.dependentes * 150;
  if (h.deducao > h.IRRF)
    h.IRRF = 0;
  else
    h.IRRF -= h.deducao;
  h.VT = f.salBase * 0.06;
  h.VR = f.valeR * 0.06;
  h.adiantamento = f.adiantamento * h.remuneracao;

  h.desconto = h.INSS + h.IRRF + h.VT + h.VR + h.adiantamento;

  h.salLiq = h.remuneracao - h.desconto;

  return h;
}

//Desenhar linha quando for escrever o Holerite
void linha(FILE *impHol) {
  int comprimento = 40;
  for (int c = 0; c < comprimento; c++) {
    fprintf(impHol, "-");
  };
  fprintf(impHol, "\n");
}

// Escrever os dados que foram calculados; por enquanto está super simples, deve
// ficar mais estiloso na versão final
int escrever(funcionario f, holerite h, FILE *impHol) {
  
  
  linha(impHol);
  fprintf(impHol, "%s\n", f.nome);
  linha(impHol);
  fprintf(impHol, "%s\n", f.funcao);
  linha(impHol);
  fprintf(impHol, "Dias: %d\n", h.totalDias);
  linha(impHol);
  fprintf(impHol, "Verba salarial: R$ %.2f\n", h.verbaSal);
  linha(impHol);
  fprintf(impHol, "Verba indenizacional: R$ %.2f\n", h.verbaInde);
  linha(impHol);
  fprintf(impHol, "Remuneração: R$ %.2f\n", h.remuneracao);
  linha(impHol);
  fprintf(impHol, "INSS: R$ %.2f\n", h.INSS);
  linha(impHol);
  fprintf(impHol, "IRRF: R$ %.2f\n", h.IRRF);
  linha(impHol);
  fprintf(impHol, "Adiantamento: R$ %.2f\n", h.adiantamento);
  linha(impHol);
  fprintf(impHol, "Desconto: R$ %.2f\n", h.desconto);
  linha(impHol);
  fprintf(impHol, "Salário líquido: R$ %.2f\n", h.salLiq);
  linha(impHol);
}

int imprimirHolerite() {

  

  funcionario f;
  // Atribuir valores aos dados do funcionário
  f = atribuiFunc(f);
  holerite h;
  h = calculoHoler(f, h);

  
  FILE *impHol;
  impHol = fopen("holerite.txt", "w");
  if (impHol == NULL) {
    printf("Erro.");
    return 1;
  } else {
    int impressao = escrever(f, h, impHol);
    fclose(impHol);
    printf("\nHolerite salvo no arquivo holerite.txt");
  }

  return 0;
}

int funcaoHolerite() {

  for (int i = 0; i < 2; i++) {
    for (int c = 0; c < 81; c++) {
      printf("*");
    }
    printf("\n");
  }
  printf("*****");
  for (int c = 0; c < 71; c++) {
    printf(" ");
  }
  printf("*****\n*****");
  for (int c = 0; c < 31; c++) {
    printf(" ");
  }
  printf("HOLERITE");
  for (int c = 0; c < 32; c++) {
    printf(" ");
  }
  printf("*****\n*****");
  for (int c = 0; c < 71; c++) {
    printf(" ");
  }
  printf("*****\n");
  for (int i = 0; i < 2; i++) {
    for (int c = 0; c < 81; c++) {
      printf("*");
    }
    printf("\n");
  }
  printf("\n");
  
  imprimirHolerite();
  
  return 0;
}

int continuarOuSair() {
  
  int voltar = 0;
  printf("\nVoltando para o menu. Digite 1 se quiser sair ao invés de voltar.\n");
  scanf("%d", &voltar);
  if (voltar == 1) {
    printf("Tenha um bom dia.");
    return 7;
  } else {
    return 0;
  }
}

int telaMenu() {
  
  int acao = 0;
  do {
    printf("Digite o número da ação que deseja realizar:\n\n");
    printf("*******\n** 1 **  Holerite\n*******\n");
    printf("*******\n** 2 **  Plano de férias\n*******\n");
    printf("*******\n** 3 **  Funcionários\n*******\n");
    printf("*******\n** 4 **  Cadastro de funcionários\n*******\n");
    printf("*******\n** 5 **  Mural de comunicados\n*******\n");
    printf("*******\n** 6 **  Marcar ponto\n*******\n");
    printf("*******\n** 7 **  Sair\n*******\n");
  
    scanf("%d", &acao);
    system("clear");

    switch(acao) {
      
      case 1:
        acao = funcaoHolerite();
        acao = continuarOuSair();
        break;
      case 2:
        acao = funcaoPlanoFerias();
        acao = continuarOuSair();
        break;
      case 3:
        acao = funcaoFuncionarios();
        acao = continuarOuSair();
        break;
      case 4:
        acao = funcaoCadastroFuncionarios();
        acao = continuarOuSair();
        break;
      case 5:
        acao = funcaoMuralComunicados();
        acao = continuarOuSair();
        break;
      case 6:
        acao = funcaoMarcarPonto();
        acao = continuarOuSair();
        break;
      case 7:
        printf("Tenha um bom dia.");
        break;
      default:
        acao = 0;
        printf("Verifique se digitou um número válido.\n");
    }
  } while (acao != 7);

  return 0;
}

int telaLogin() {
  
  for (int i = 0; i < 2; i++) {
    for (int c = 0; c < 81; c++) {
      printf("*");
    }
    printf("\n");
  }
  printf("*****");
  for (int c = 0; c < 71; c++) {
    printf(" ");
  }
  printf("*****\n*****");
  for (int c = 0; c < 33; c++) {
    printf(" ");
  }
  printf("LOGIN");
  for (int c = 0; c < 33; c++) {
    printf(" ");
  }
  printf("*****\n*****");
  for (int c = 0; c < 71; c++) {
    printf(" ");
  }
  printf("*****\n");
  for (int i = 0; i < 2; i++) {
    for (int c = 0; c < 81; c++) {
      printf("*");
    }
    printf("\n");
  }
  printf("\nDigite seu CPF: ");
  scanf("%d", &CPF);
  printf("Digite sua senha: ");
  scanf("%d", &senha);
  system("clear");

  for (int i = 0; i < 2; i++) {
    for (int c = 0; c < 81; c++) {
      printf("*");
    }
    printf("\n");
  }
  printf("*****");
  for (int c = 0; c < 71; c++) {
    printf(" ");
  }
  printf("*****\n*****");
  for (int c = 0; c < 32; c++) {
    printf(" ");
  }
  printf("CONEXUS");
  for (int c = 0; c < 32; c++) {
    printf(" ");
  }
  printf("*****\n*****");
  for (int c = 0; c < 71; c++) {
    printf(" ");
  }
  printf("*****\n");
  for (int i = 0; i < 2; i++) {
    for (int c = 0; c < 81; c++) {
      printf("*");
    }
    printf("\n");
  }
  printf("\n");
  
  return 0;
}

int menu() {
    int opc;
    printf("\n ---------------- MENU ------------------\n");
    printf("\n 1. Adicionar ficha de funcionario \n");
    printf("\n 2. Atualizar ficha de funcionario \n");
    printf("\n 3. Relatorio de funcionarios \n");
    printf("\n 4. Consultar funcionario \n");
    printf("\n 5. Deletar um funcionario \n");
    printf("\n 6. Importar dados para um arquivo txt \n");
    printf("\n 7. Exportar dados para um arquivo txt \n");
    printf("\n 8. Apagar todos os dados cadastrados \n");
    printf("\n 9. Fechar programa \n"); //quebra o loop
    printf("\n------------------------------------------ \n\n Opção: ");
    scanf("%i", &opc);

  return opc;
}

funcionario* adicionar() {
  funcionario *no = (funcionario*)malloc(sizeof(funcionario));
  // impede o usuario de cadastrar mais funcionarios após atingir o limite
  if (matricula == N) {
    printf("\nNúmero limite de funcionarios cadastrados atingido.\n");
  } else {
    //adiciona mais um numero na matricula para contar mais um funcionario no sistema.
    matricula++; 
    
    getchar();
    printf("\n Nome do funcionario: ");
    fgets(no->nome, 50, stdin);
    remove_enter(no->nome);
    printf(" Função exercida pelo funcionário: ");
    fgets(no->funcao, 50, stdin);
    remove_enter(no->funcao);
    printf(" Se a função exercida pelo funcionário apresenta risco, digite 1. Caso contrário, digite 0.\n ");
    scanf("%d", &no->risco);
    if (no->risco != 1) no->risco = 0;
    printf(" Se o funcionário for trabalhar no período noturno, digite 1. Caso contrário, digite 0.\n ");
    scanf("%d", &no->noturno);
    if (no->risco != 1) no->noturno = 0;
    printf(" Número do dia de nascimento: ");
    scanf("%d", &no->aniversario.dia);
    printf(" Número do mês de nascimento: ");
    scanf("%d", &no->aniversario.mes);
    printf(" ano de nascimento do funcionario: ");
    scanf("%d", &no->aniversario.ano);
    printf(" Salário do funcionario: R$ ");
    scanf("%f", &no->salBase);
    printf(" Vale-refeição disponibilizado ao funcionário: R$ ");
    scanf("%f", &no->valeR);
    printf(" Vale-transporte disponibilizado ao funcionário: R$ ");
    scanf("%f", &no->valeT);
    printf(" Por quantos dependentes o funcionário é responsável?\n ");
    scanf("%d", &no->dependentes);
    
    no->horasExtra = 0;
    no->adiantamento = 0;
    no->faltas = 0;
    no->faltasDSN = 0;
    no->dias = 22;
    no->DSN = 9;
    
    no->prox = NULL;
  }
  return no;
}

void insere_item(funcionario **lista, funcionario *item) {
  funcionario *aux;
	if (lista_esta_vazia(*lista) == TRUE) {
		*lista = item;
	} else {
		aux = *lista;
		while (aux->prox != NULL) {
      aux = aux->prox;
    }
		aux->prox = item;
	}
}

void atualizar(funcionario* lista) {
  funcionario* aux = lista;
  string alterar;//ficha a ser alterada
  int varencontrada = 0; //variavel que diz se a ficha a ser alterada foi encontrada

  if (aux == NULL) {
    printf("\n Nenhum funcionário cadastrado no sistema.\n");
  } else {
    printf("\n Digite o nome do funcionario cuja ficha deseja alterar: ");
    scanf("%s", alterar);

    while (aux != NULL) {
      if (strcmp(alterar, aux->nome) == 0) {
        varencontrada++; //valida para dizer se o funcionario foi encontrado
        getchar();
        printf("\n Nome do funcionario: ");
        fgets(aux->nome, 50, stdin);
        remove_enter(aux->nome);
        printf(" Função exercida pelo funcionário: ");
        fgets(aux->funcao, 50, stdin);
        remove_enter(aux->funcao);
        printf(" Se a função exercida pelo funcionário apresenta risco, digite 1. Caso contrário, digite 0.\n ");
        scanf("%d", &aux->risco);
        if (aux->risco != 1) aux->risco = 0;
        printf(" Se o funcionário for trabalhar no período noturno, digite 1. Caso contrário, digite 0.\n ");
        scanf("%d", &aux->noturno);
        if (aux->risco != 1) aux->noturno = 0;
        printf(" Número do dia de nascimento: ");
        scanf("%d", &aux->aniversario.dia);
        printf(" Número do mês de nascimento: ");
        scanf("%d", &aux->aniversario.mes);
        printf(" ano de nascimento do funcionario: ");
        scanf("%d", &aux->aniversario.ano);
        printf(" Salário do funcionario: R$ ");
        scanf("%f", &aux->salBase);
        printf(" Vale-refeição disponibilizado ao funcionário: R$ ");
        scanf("%f", &aux->valeR);
        printf(" Vale-transporte disponibilizado ao funcionário: R$ ");
        scanf("%f", &aux->valeT);
        printf(" Por quantos dependentes o funcionário é responsável?\n ");
        scanf("%d", &aux->dependentes);
        printf(" Quantas horas extras o funcionário trabalhou este mês?");
        scanf("%d", &aux->horasExtra);
        printf(" Quanto do salário do funcionário já foi adianto? (Digite com zero virgula)");
        scanf("%f", &aux->adiantamento);
        printf(" Quantas faltas o funcionário acumulou este mês?");
        scanf("%d", &aux->faltas);
        printf(" Quantos dias serão descontados do Descanso Semanal Remunerado do funcionário?");
        scanf("%d", &aux->faltasDSN);
        printf(" Quantos horas extras o funcionário trabalhou este mês?");
        
        return; 
      }
      aux = aux->prox;
    }
    if (varencontrada == 0) {
      printf("\nFuncionário não encontrado.");
    }
  }
  return;
}

void relatorio(funcionario *lista) {
  funcionario *aux = lista;
  
  //verifica se a lista está vazia
  if (aux == NULL) {
    printf("\n Nenhum funcionário cadastrado no sistema.\n");
  } else {
    while (aux != NULL) {
      //estrutura que extrai a data do sistema
      time_t mytime;
      mytime = time(NULL);
      struct tm tm = *localtime(&mytime);
      int idade = 365*(tm.tm_year + 1900) + 30*(tm.tm_mon + 1) + (tm.tm_mday) - 365*(aux->aniversario.ano) - 30*(aux->aniversario.mes - aux->aniversario.dia);
      
      // imprime a ficha de funcionario por funcionario
      printf("Nome: %s - ", aux->nome);
  	  printf("Data de nascimento: %d/%d/%d - ", aux->aniversario.dia, aux->aniversario.mes, aux->aniversario.ano);
      printf("Idade: %d anos - ", idade/365);
  	  printf("Salário: %.2f ", aux->salBase);
  	  printf("\n");
  	  
  		aux = aux->prox;
    }
  }
}

void consultar(funcionario *lista) {
  funcionario *aux = lista;
  string buscafunc; //variavel para procurar um funcionario
  int varbusca=0; //variavel de controle de busca encontrada ou não

  if (aux == NULL) {
    printf("\n Nenhum funcionário cadastrado no sistema. \n");
  } else {
    printf("\n Por qual funcionario voce procura?\n");
    scanf(" %s", buscafunc);

    while (aux != NULL) {
      if (strcmp(aux->nome, buscafunc) == 0) {
        //estrutura que extrai a data do sistema
        time_t mytime;
        mytime = time(NULL);
        struct tm tm = *localtime(&mytime);
        int idade = 365*(tm.tm_year + 1900) + 30*(tm.tm_mon + 1) + (tm.tm_mday) - 365*(aux->aniversario.ano) - 30*(aux->aniversario.mes - aux->aniversario.dia);
        
        varbusca++; //variavel auxiliar que informa se o funcionario buscado foi encontrado
        printf("\n Funcionario %s encontrado.", aux->nome);
        printf("\n Data de nascimento: %i/%i/%i ", aux->aniversario.dia, aux->aniversario.mes, aux->aniversario.ano);
        printf("\n Idade: %d anos", idade/365);
        printf("\n Salário: %.2f reais", aux->salBase);
      }
      aux=aux->prox;
    }
    if (varbusca == 0) {
      printf("\nesse funcionario nao consta nos funcionarios cadastrados.");
    }
  }

  return;
}

void deletar(funcionario** lista) {
  funcionario *aux, *percorre = *lista; //ponteiro que aponta para o elemento que aponta para 
  string deletar; //variavel contadora e variavel que armazena qual funcionario deletar
  int varencontrada = 0; //variavel que indica se o funcionario a ser deletado esta cadastrado

  if ((*lista) == NULL) {
    printf("\n Nenhum funcionário cadastrado no sistema.\n");
  } else {
    getchar();
    printf("\n Nome do funcionário cuja ficha deseja deletar: ");
    fgets(deletar, 50, stdin);
    remove_enter(deletar);
    
    while (percorre != NULL) {
      if (strcmp(deletar, percorre->nome) == 0) {
        varencontrada++;
        matricula--;
        //verifica se o elemento é o primeiro da lista
        if (percorre->prox == (*lista)->prox) {
          funcionario* auxp = (*lista)->prox;
          free(*lista);
          *lista = auxp;
          printf("\nfuncionario deletado!");
          break;
        }
          //verifica se o elemento é o ultimo da lista
        else if (percorre->prox == NULL) {
          aux->prox = NULL;
          free(percorre);
          printf("\nfuncionario deletado!");
          break;
        }
        //verifica se é um item valido
        else {
          aux->prox = percorre->prox;
          free(percorre);
          printf("\nfuncionario deletado!");
          break;
        }
        printf("\n ficha do funcionario deletada!\n"); 
      }
      aux = percorre;
      percorre=percorre->prox;
    }
    if (varencontrada == 0) {
      printf("\n funcionario nao encontrado. ");
    }
  }
  return;
}

void apaga_todos_os_dados(funcionario **lista) {
	funcionario *aux;
	while (*lista != NULL) {
		aux = *lista;
		*lista = (*lista)->prox;
		printf("Apagando o item %s\n", aux->nome);		
		free(aux);
	}	
}

void exporta_dados_arquivo_txt(funcionario *lista) {
	FILE* arq_funcionarios;
  funcionario *aux = lista;
  //abre arquivo texto
  arq_funcionarios = fopen("registro_funcionarios.txt", "w+");
  
  if (arq_funcionarios == NULL) {
    printf("Não foi possivel abrir o arquivo.\n");
    exit(0);
  }

	while (aux != NULL) {
		fprintf(arq_funcionarios, "%s\n", aux->nome);
		fprintf(arq_funcionarios, "%d\n", aux->aniversario.dia);
    fprintf(arq_funcionarios, "%d\n", aux->aniversario.mes);
    fprintf(arq_funcionarios, "%d\n", aux->aniversario.ano);
		fprintf(arq_funcionarios, "%.2f\n\n", aux->salBase);
    aux=aux->prox;
	}
	fclose(arq_funcionarios);
}

void importa_dados_arquivo_txt(funcionario **lista) {
  if (*lista != NULL) {
    printf("\nNão foi possível importar o arquivo. Já existem arquivos cadastrados na base de dados.");
  } else {
    funcionario *aux;
    FILE* arq_funcionarios;
    //abre arquivo texto
    arq_funcionarios = fopen("registro_funcionarios.txt", "a+");
    
    if (arq_funcionarios == NULL) {
      printf("não foi possivel abrir o arquivo.\n");
      exit(0);
    }
    //passa os dados do arquivo para o programa
  	while (!feof(arq_funcionarios)) {
      aux = (funcionario*)malloc(sizeof(funcionario));
      fscanf(arq_funcionarios, "%s\n", aux->nome);
  		fscanf(arq_funcionarios, "%d\n", &aux->aniversario.dia);
      fscanf(arq_funcionarios, "%d\n", &aux->aniversario.mes);
      fscanf(arq_funcionarios, "%d\n", &aux->aniversario.ano);
  		fscanf(arq_funcionarios, "%f\n\n", &aux->salBase);
      aux->prox=NULL;
      insere_item(lista, aux);
      matricula++;
  	}
  	fclose(arq_funcionarios);
  }
  
   return;
}

void salva_dados_arquivo_bin(funcionario *lista) {
  	FILE* arq_funcionarios;
    funcionario *aux = lista;
  //abre arquivo binario
  arq_funcionarios = fopen("base_de_dados", "w+b");
  
  if(arq_funcionarios == NULL) {
    printf("ERROR.\n");
    exit(0);
  }
  
  while (aux != NULL) {
  		fwrite(aux->nome, sizeof(string), 1, arq_funcionarios);
  		fwrite(&aux->aniversario.dia, sizeof(int), 1,arq_funcionarios);
      fwrite(&aux->aniversario.mes, sizeof(int), 1, arq_funcionarios);
      fwrite(&aux->aniversario.ano, sizeof(int), 1, arq_funcionarios);
  		fwrite(&aux->salBase, sizeof(float), 1, arq_funcionarios);
      aux=aux->prox;
  	}
  	fclose(arq_funcionarios); 
}

void recupera_dados_arquivo_bin(funcionario **lista) { 
  FILE* arq_funcionarios;
  funcionario *aux;
  
    //abre arquivo texto
    arq_funcionarios = fopen("base_de_dados", "a+b");
    
    if (arq_funcionarios == NULL) {
      printf("ERROR\n");
      exit(0);
    }

    //passa os dados do arquivo para o programa
  	while (!feof(arq_funcionarios)) {
      aux = (funcionario*)malloc(sizeof(funcionario));
      fread(aux->nome, sizeof(string), 1, arq_funcionarios);
  		fread(&aux->aniversario.dia, sizeof(int), 1,arq_funcionarios);
      fread(&aux->aniversario.mes, sizeof(int), 1, arq_funcionarios);
      fread(&aux->aniversario.ano, sizeof(int), 1, arq_funcionarios);
  		fread(&aux->salBase, sizeof(float), 1, arq_funcionarios);
      aux->prox = NULL;
      if (!feof(arq_funcionarios)) {
        matricula++;
        insere_item(lista, aux);
  	  } else {
        free(aux);
      }
  	}
    matricula--;
  	fclose(arq_funcionarios);
}

void remove_enter(char s[N]) {
	int tamanho = strlen(s);
	s[tamanho-1] = '\0';
}

boolean lista_esta_vazia(funcionario *lista) {
	if (lista == NULL) return TRUE;
	return FALSE;
}
