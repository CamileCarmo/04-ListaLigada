#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
  int valor;
  NO *prox;
};

NO *primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO *posicaoElemento(int numero);
//--------------------------

int main() { menu(); }

void menu() {
  int op = 0;
  while (op != 7) {
    //system("cls"); // somente no windows
    cout << "Menu Lista Ligada";
    cout << endl << endl;
    cout << "1 - Inicializar Lista \n";
    cout << "2 - Exibir quantidade de elementos \n";
    cout << "3 - Exibir elementos \n";
    cout << "4 - Buscar elemento \n";
    cout << "5 - Inserir elemento \n";
    cout << "6 - Excluir elemento \n";
    cout << "7 - Sair \n\n";

    cout << "Opcao: ";
    cin >> op;

    switch (op) {
    case 1:
      inicializar();
      break;
    case 2:
      exibirQuantidadeElementos();
      break;
    case 3:
      exibirElementos();
      break;
    case 4:
      buscarElemento();
      break;
    case 5:
      inserirElemento();
      break;
    case 6:
      excluirElemento();
      break;

    case 7:
      return;
    default:
      break;
    }

    //system("pause"); // somente no windows
  }
}

void inicializar() {

  // se a lista j� possuir elementos
  // libera a memoria ocupada
  NO *aux = primeiro;
  while (aux != NULL) {
    NO *paraExcluir = aux;
    aux = aux->prox;
    free(paraExcluir);
  }

  primeiro = NULL;
  cout << "Lista inicializada \n";
}

void exibirQuantidadeElementos() {

  int nElementos = 0;
  NO *aux = primeiro;
  while (aux != NULL) {
    nElementos++;
    aux = aux->prox;
  }
  cout << "Quantidade de elementos: " << nElementos << endl;
}

void exibirElementos() {
  if (primeiro == NULL) {
    cout << "Lista vazia \n";
    return;
  } else {
    cout << "Elementos: \n";
    NO *aux = primeiro;
    while (aux != NULL) {
      cout << aux->valor << endl;
      aux = aux->prox;
    }
  }
}

void inserirElemento() {
  // aloca memoria dinamicamente para o novo elemento
  NO *novo = (NO *)malloc(sizeof(NO));
  if (novo == NULL) {
    return;
  }

  cout << "Digite o elemento: ";
  cin >> novo->valor;
  
  NO *aux = primeiro; //aux == auxiliar
  while (aux != NULL) {
      if (aux->valor == novo->valor) {
          cout << "Valor duplicado! O elemento não será inserido." << endl;
          free(novo); // Libera a memória alocada
          return;
      }
      aux = aux->prox;
  }

  novo->prox = NULL;

  if (primeiro == NULL) {
    primeiro = novo;
  } else {
    // procura o final da lista
    NO *aux = primeiro;
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = novo;
  }
}

void excluirElemento() {
  int valor;
  cout << "Digite o valor a ser excluído: ";
  cin >> valor;

  if (primeiro == NULL) {
      cout << "Lista vazia. Não é possível excluir." << endl;
      return;
  }

  NO *aux = primeiro;
  NO *anterior = NULL;

  // Procura o elemento a ser excluído
  while (aux != NULL && aux->valor != valor) {
      anterior = aux;
      aux = aux->prox;
  }

  // Se o elemento não foi encontrado
  if (aux == NULL) {
      cout << "ELEMENTO NAO ENCONTRADO" << endl;
      return;
  }

  // Se o elemento a ser excluído é o primeiro
  if (anterior == NULL) {
      primeiro = aux->prox; // Muda o primeiro
  } else {
      anterior->prox = aux->prox; // Remove o nó da lista
  }

  free(aux); // Libera a memória do nó excluído
}

void buscarElemento() {
  int valor;
   cout << "Digite o valor a ser buscado: ";
   cin >> valor;

   NO *resultado = posicaoElemento(valor);
   if (resultado != NULL) {
       cout << "ENCONTRADO" << endl;
   } else {
       cout << "ELEMENTO NAO ENCONTRADO" << endl;
   }
}

// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento n�o estiver na lista
NO *posicaoElemento(int numero) {
  NO *aux = primeiro;
  while (aux != NULL) {
    if (aux->valor == numero) {
      break;
    }
    aux = aux->prox;
  }
  return aux;
}