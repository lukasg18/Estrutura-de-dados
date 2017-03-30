(a) p -> lig = q;
	o proximo Nó de P aponta para o nó Q.
(b) (* p ) .lig = q -> lig;
	o proximo elemento de P aponta para o proximo elemento de Q.
(c) p -> info = (* q ) .info;
	o conteudo de P armazena o conteudoq esta em Q.
(d) p = q;
	o nó P recebe o nó Q.
(e) p -> lig = n ull ;
	o proximo nó de P aponta pra NULL;
(f) * p = q;
	o conteudo de P é substituido por Q.
(g) p = (* p ) .lig;
	o nó P recebe o proximo elemento de P.
(h) p = (* ( * p ) .lig) ) .lig;
	P recebe o proximo do proximo de P.

