# tp3_paa
Terceiro trabalho prático da disciplina de Projeto e Análise de Algoritmos.

## Descrição do problema
O problema resume-se a encontrar a substring perdida dentro de uma série de palavras encantadas. Para isso, é dado um texto (string) na entrada, que será utilizado para encontrar a substring também dada na entrada, além de K consultas, cada uma contendo um intervalo no texto onde a substring será procurada. Se a substring estiver presente em uma palavra dentro do intervalo indicado, devemos revelar sua localização.

### Entrada
A primeira linha de entrada contém uma string de tamanho \( n \). A segunda linha contém uma string de tamanho \( m \). A terceira linha contém um inteiro \( k \): o número de consultas.

Após isso, a entrada possui \( k \) linhas descrevendo as consultas. Cada linha contém dois inteiros \( a \) e \( b \): o intervalo começa em \( a \) e termina em \( b \). Os índices são baseados em 1.

### Saída
Para cada consulta, imprima "sim" caso a substring esteja presente e "não" caso contrário.

##### Exemplo de entrada:
```
abbaab
ab
3
1 4
3 5
2 6
```
##### Exemplo de saída
```
sim
nao
sim
```
### Compilação e execução

#### Compilação

Para compilar, abra a pasta raiz do projeto em um terminal e digite o comando:


#### Execução

Para executar o programa, digite o comando
```
$ ./tp3 <algoritmo> arquivo_de_entrada.txt
```
##### Algoritmos aceitos
`1` - Knuth-Morris-Pratt;  
`2` - Boyer-Moore-Horspool;
`3` - Boyer-Moore-Horspool-Sunday;  
`4` - Força Bruta;