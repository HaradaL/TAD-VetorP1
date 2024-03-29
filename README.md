# TAD-VetorP1

<h1>Tipo Abstrato de Dados (Vetor)</h1>

<p>Desenvolver um tipo abstrato de dados para armazenar e manipular vetores de valores inteiros.</p>

<h2>DADOS</h2><br>
Os dados do vetor serão organizados em uma struct denominada Vetor

```c
  typedef struct{
  int* vetor;
  int size;
  int length;
  } Vetor;
```

Vamos utilizar outras duas definições para nos auxiliar na implementação e manutenção do código. O tipo DataType será definido representar o tipo de dado manipulado pelo TAD Vetor. Neste exemplo, o tipo manipulado é o int. Caso queiramos utilizar outro tipo, basta alterar essa linha.
```
  typedef DataType int;
```
O segundo tipo definido é o Boolean. Como a linguagem C não possui um tipo primitivo para representar valores booleanos, criamos um tipo enumerado para permitir o uso dos valores true e false. Dessa forma, quando precisarmos criar uma função booleana, basta definir o retorno com o tipo Boolean e devolver os valores true ou false.
```
  typedef enum {false, true} Boolean;
```
<h2>OPERAÇÕES</h2>
Todas as operações previstas para o vetor serão mapeadas para funções. Todas as funções serão desenvolvidas especificamente para manipular a estrutura definida Vetor.

<p>**Importante:** Você deve ser capaz de validar se sua função funciona ou não. Para isso, crie pequenos casos de teste para validar as funções desenvolvidas.</p>
Para facilitar a identificação, utilizaremos o prefixo "vetor_" para cada função.

<h3>PARTE 1</h3>
<h4>Criar o vetor</h4>

```
  Vetor* vetor_new();
```

<h4>Destruir o vetor</h4>

```
  void vetor_free(Vetor* v);
```

<h4>Imprimir o vetor</h4>

```
  void vetor_print(Vetor* m);
```

<h4>Adicionar um elemento em uma posição do vetor</h4>
A funcionalidade de inserção deve providenciar espaço sempre que necessário. Crie uma função auxiliar para isso e utilize a estratégia de dobrar o tamanho do vetor sempre que houver necessidade de espaço.

```
  Boolean vetor_insert(Vetor* v, DataType element, int index);
```

<h4>Adicionar um elemento no final do vetor</h4>
A funcionalidade de inserção deve providenciar espaço sempre que necessário. Crie uma função auxiliar para isso e utilize a estratégia de dobrar o tamanho do vetor sempre que houver necessidade de espaço.

```
  Boolean vetor_add(Vetor* v, DataType element);
```

<h4>Remover um elemento do vetor de uma posição específica</h4>
A remoção deve se preocupar com a quantidade de espaço ocioso no vetor. Caso a remoção resulte em uma taxa de ocupação abaixo de 25%, o tamanho do vetor deve ser reduzido pela metade. Crie uma função auxiliar para verificar e efeturar a redução.

```
  DataType vetor_remove1(Vetor* v, int index);
  Boolean vetor_remove2(Vetor* v, int index, Datatype* ptr);
```

<h4>Remover o elemento da primeira posição do vetor</h4>
A remoção deve se preocupar com a quantidade de espaço ocioso no vetor. Caso a remoção resulte em uma taxa de ocupação abaixo de 25%, o tamanho do vetor deve ser reduzido pela metade. Crie uma função auxiliar para verificar e efeturar a redução.

```
  DataType vetor_shift1(Vetor* v);
  Boolean vetor_shift2(Vetor* v, Datatype* ptr);
```

<h4>Acessar um elemento do vetor</h4>
Essa funcionalidade deve ser disponibilizada por meio de três funções. As funções provêm o mesmo comportamento, porém, de formas distintas.

```
  Datatype vetor_get1(Vetor* v, int index);
  Boolean vetor_get2(Vetor* v, int index, DataType *ptr);
  Datatype* vetor_get3(Vetor* v, int index);
```

<h4>Alterar um elemento no vetor</h4>

```
  void vetor_set(Vetor* v, int index, DataType valor);
```

<h4>Aplicar uma alteração à todos os elementos do vetor.</h4>
Essa funcionalidade pode ser obtida por meio de uma função que recebe por parâmetro um ponteiro da função que realizará a alteração em cada elemento. Essa funcionalidade já foi discutida em sala de aula.

```
  void vetor_map(Vetor* v, void (*funcao)(DataType*));
```

A função recebe o vetor e o ponteiro da função que será invocada para cada elemento.

<h4>Criar um sub‒vetor.</h4>
O sub‒vetor pode ser adquirido com base nos índices do vetor.
A primeira função recebe o vetor v e o índice index e cria o sub‒vetor a partir de index. Quando o indice é negativo, ele representará as posições do fim para o inicio. Por exemplo, o índice ́‒1́ representa a última posição do vetor, ‒2 a penúltima e assim por diante.

```
  Vetor* vetor_sub1(Vetor* v, int index);
```

A segunda função recebe o intervalo desejado para a criação do sub‒vetor.

```
  Vetor* vetor_sub2(Vetor* v, int start, int end);
```
