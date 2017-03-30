19) Considere o seguinte conjunto de números 1234 e as seguintes operações:
	(a) inserir o no 1 em uma pilha 
	(b) inserir o 2 na pilha 
	(c) retirar o 2 da pilha 
	(d) inserir o 3 na pilha 
	(e) inserir o 4 na pilha 
	(f) retirar o 4 da pilha 
	(g) retirar o 3 da pilha 
	(h) retirar o 1 da pilha. 
	A seqüência de saídas do procedimento acima é 2431. Considere agora a seqüência 123456.
a) Podemos obter as seqüências 325641 e 154623 utilizando um processo semelhante ao do exemplo anterior?
-> Não, só é possível obter a 1º seqüência 325641. A 2º seqüência 154623 não é possível, pois não tem como retirar primeiro 
   o número 2 e depois o número 3 porque o número 2 foi inserido primeiro que o número 3 e está mais abaixo na pilha sendo 
   que em uma estrutura de pilha o ultimo elemento inserido é o primeiro que sai.

b) Se I e R representam respectivamente inserção e remoção da pilha, o exemplo acima
pode ser descrito como IIRIIRRR. Se possível descreva as seqüências do item (a) em termos de
I e R.
-> A primeira seqüência é possível: IIIRRIIRIRRR.

c)Qual seria uma regra simples para anlisar se uma sequ^encia de I's e R's é valida?
-> verificar a ordem que os elementos foram inseridos na pilha. Se um elemento maior q o primeiro elemento for inserido antes do primeiro
   elemento, na hora de desempilhar vai ser invalido. Exemplo: se o 2 for inserido antes do 1, é invalido.
   	
