/**
 * @description Retorna uma agenda já inicialida para o sistema 
 * [iniciarAgenda]
 * @return TAgenda
 */
TAgenda* iniciarAgenda() {

	//Aloca memória para agenda
	TAgenda* agenda = (TAgenda*)malloc(sizeof(TAgenda));

	if(!agenda) {
		printf("Tem memória Disponível.\n");
		exit(1);
	}

	//Setando a celula cabeça da agenda como NULL
	agenda->proxData = NULL;

	//Retornando a agenda já inicializada
	return agenda;
}

/**
 * @description retorna 1 se a agenda tiver vazia, retorna 0 se ela estiver cheia
 * [verificaAgendaVazia]
 * @param agenda
 */
int verificaAgendaVazia(TAgenda* agenda) {

	int retorno;

	//Verifica se a agenda está vazia
	retorno = agenda->proxData != NULL ?  1 :  0;

	return retorno;
}

/**
 * @description Faz a leitura da data, antes de ler um evento e preciso criar um data
 * [leituraData description]
 * @param data [description]
 */
void leituraData(TData* data) {

	system("clear");
	
	printf("\t####### Informações da Data #######\n");

	//Informações da data
	printf("\tDigite o dia do evento: ");
	scanf("%d", &data->dia);

	printf("\tDigite o mês do evento: ");
	scanf("%d", &data->mes);

	printf("\tDigite o ano do evento: ");
	scanf("%d", &data->ano);
}

/**
 * @description faz a leitura do horário do evento e da descrição do evento
 * [leituraInformacaoAgenda]
 * @param evento
 */
void leituraInformacaoAgenda(TEvento* evento) {

	system("clear");

	printf("\t####### Informações do evento #######\n");

	//Informações do evento
	printf("\tDigite a hora do evento: ");
	scanf("%i", &evento->noHorario.horas);

	printf("\tDigite os minutos do evento: ");
	scanf("%i", &evento->noHorario.minutos);
	getchar(); 

	printf("\tDescrição do evento: ");
	fgets(evento->descricao_do_evento, 100, stdin);
}

/**
 * @description Auxilia a função inserir inserir um intem ordenadamente na Agenda
 * @param agenda         
 * @param percorrerLista 
 * @param anterior
 * @param tipo 1 => insere de acordo com o ano
 *             2 => insere de acordo com o mes
 *             3 => insere de acordo com o dia      
 */
void percorreDeAcordoAnoMesDia(TAgenda* agenda, TAgenda* percorrerLista, TAgenda* anterior, TData data, int tipo) {

	//Percorrendo o A agenda e inserindo ordenado de acordo com o mes
	switch (tipo) {

		case 1: { 
			while(percorrerLista != NULL && percorrerLista->data.ano < data.ano) {
				//Guardando o ponteiro anterior
				anterior = percorrerLista;
				//Pegando o proximo ponteiro
				percorrerLista = percorrerLista->proxData;

			}
			break;
		}case 2: {
			while(percorrerLista != NULL && percorrerLista->data.mes < data.mes) {
				//Guardando o ponteiro anterior
				anterior = percorrerLista;
				//Pegando o proximo ponteiro
				percorrerLista = percorrerLista->proxData;

			}
			break;			
		}case 3: {
			while(percorrerLista != NULL && percorrerLista->data.dia < data.dia) {
				// Guardando o ponteiro anterior
				anterior = percorrerLista;
				// Pegando o proximo ponteiro
				percorrerLista = percorrerLista->proxData;

			}
			break;
		}
	}	
}

/**
 * @description Antes de inserir um evento o usuário precisa inserir uma data,
 * [inserirData]
 * @param agenda
 * @param data
 */
void inserirDataOrdenado(TAgenda* agenda, TData data) {

	//Lendo a data para inserir no sistema
	leituraData(&data);

	//alocando memória para uma agenda auxiliar
	TAgenda* nova = (TAgenda*)malloc(sizeof(TAgenda));
	//Ponteiro para o anterior
	TAgenda* anterior = NULL;
	//Ponteiro para percorre a lista
	TAgenda* percorrerLista = agenda;

	//Chamando a função e percorrendo a agenda
	percorreDeAcordoAnoMesDia(agenda, percorrerLista, anterior, data, 1);

	//Se o ano for igual ao ano a ser inserido chama o mes
	if((percorrerLista->data.ano == data.ano)) {

		//Chamando o caso 2 que é verifica o mes
		percorreDeAcordoAnoMesDia(agenda, percorrerLista, anterior, data, 2);
		percorreDeAcordoAnoMesDia(agenda, percorrerLista, anterior, data, 3);
	
	}

	nova->data = data;

	//Insere elemento no inicio da lista caso o prox anterior for NULL
	if (anterior == NULL){

		//Pegando a data digitada e guardando em um ponteiro auxliar
		nova->data = data;
		//Avançando o prox da agenda auxiliar
		nova->proxData = agenda->proxData;
		//Fazendo a agenda recerber a agenda auxiliar com todos os dados
		agenda->proxData = nova;

	}else {
		//Insere no meio da lista, ou no lugar correto
		nova->proxData = anterior->proxData;
		anterior->proxData = nova;
	}
}

/**
 * imprimir todas as datas
 * @param agenda
 */
void imprimirData(TAgenda* agenda) {

	TAgenda* imprimir;

	for(imprimir = agenda; imprimir->proxData != NULL; imprimir = imprimir->proxData) {

		printf("Ano: %d\n", agenda->proxData->data.ano);
		printf("mes: %d\n", agenda->proxData->data.mes);
		printf("dia: %d\n", agenda->proxData->data.dia);
	}
}

/**
 * Pesquisa uma data dentro da agenda
 * @param  agenda 
 * @param  data   
 * @return percorrerAgenda
 */
TAgenda* pesquisarData(TAgenda* agenda, TData data) {
		
	leituraData(&data);

	TAgenda* percorrerAgenda = agenda;

	while(percorrerAgenda != NULL) {
		
		if(percorrerAgenda->data.ano == data.ano) {

			while(percorrerAgenda != NULL) { 
				
				if(percorrerAgenda->data.mes == data.mes) {
					
					while(percorrerAgenda != NULL) {
						
						if(percorrerAgenda->data.dia == data.dia) {
							
							return percorrerAgenda;
						}

						percorrerAgenda = percorrerAgenda->proxData;						
					}
				}

				percorrerAgenda = percorrerAgenda->proxData;
			}
		}	

		percorrerAgenda = percorrerAgenda->proxData;
	}

	printf("\tNão existe essa data, não é possivel inserir o evento.\n");
	getchar();
	
	return NULL;
}

/**
 * Percorre a agenda procurando o lugar certo de inserir o evento ou seja procura aposição para inserir ordenado
 * @param agenda         
 * @param percorrerLista 
 * @param anterior       
 * @param evento         
 * @param tipo 1 => insere de acordo com o hora
 *             2 => insere de acordo com o minutos           
 */
void percorrerDeAcordoHoraMinuto(TAgenda* agenda, TAgenda* percorrerLista, TAgenda* anterior, TEvento evento, int tipo) {

	switch(tipo) {
		case 1: {
			while(percorrerLista != NULL && percorrerLista->evento.noHorario.horas < evento.noHorario.horas) {
				//Guardando o ponteiro anterior
				anterior = percorrerLista;
				//Pegando o proximo ponteiro
				percorrerLista = percorrerLista->proxData;				
			}
			break;
		}
		case 2: {
			while(percorrerLista != NULL && percorrerLista->evento.noHorario.minutos < evento.noHorario.minutos) {
				//Guardando o ponteiro anterior
				anterior = percorrerLista;
				//Pegando o proximo ponteiro
				percorrerLista = percorrerLista->proxData;
			}
			break;
		}
	}
}

/**
 * Inserir um evento de acordo com uma data
 * @param agenda  [description]
 * @param TEvento [description]
 */
void inserirEvento(TAgenda* agenda, TEvento evento, TData data) {

	//Pegar a agenda que retorna o prox da data
	TAgenda* inserirEvento;
	
	//alocando memória para uma agenda auxiliar
	TAgenda* nova = (TAgenda*)malloc(sizeof(TAgenda));
	
	//Ponteiro para o anterior
	TAgenda* anterior = NULL;
	
	//Ponteiro para percorre a lista
	TAgenda* percorrerLista = agenda;

	printf("\tAperte enter para verificar a data em que o evento será inserido.\n");
	system("pause");

	inserirEvento = pesquisarData(agenda, data);

	if(inserirEvento != NULL) {
		
		leituraInformacaoAgenda(&evento);

		percorrerDeAcordoHoraMinuto(agenda, inserirEvento, anterior, evento, 1);
		
		if(inserirEvento->evento.noHorario.horas == evento.noHorario.horas){

			percorrerDeAcordoHoraMinuto(agenda, inserirEvento, anterior, evento, 2);	
		} 		

	}

	//Cria um novo elemento
	nova->evento = evento;	

	//Insere elemento no inicio da lista caso o prox anterior for NULL
	if (anterior == NULL){

		//Pegando a data digitada e guardando em um ponteiro auxliar
		nova->evento = evento;
		//Avançando o prox da agenda auxiliar
		nova->proxEvento = agenda->proxEvento;
		//Fazendo a agenda recerber a agenda auxiliar com todos os dados
		agenda->proxEvento = nova;

	}else {
		//Insere no meio da lista, ou no lugar correto
		nova->proxEvento = anterior->proxEvento;
		anterior->proxEvento = nova;
	}	
}

/**
 * Entra com a descrição de um evento para exclui-lo ou procura-lo
 * @param evento
 */
void descricaoEvento(TEvento* evento) {

	printf("Descrição do evento: ");
	fgets(evento->descricao_do_evento, 100, stdin);
}

/**
 * Remove um evento de acordo com a descrição pedida
 * @param agenda 
 * @param evento 
 */
void removerEvento(TAgenda* agenda, TEvento evento) {

	//Pegando a descrição do evento que eu quero excluir
	descricaoEvento(&evento);
	
	//Ponteiro auxiliar para percorrer a agenda
	TAgenda* pA;
	TAgenda* pE;
	TAgenda* anterior = agenda;

	//Percorrendo as datas que contem na agenda
	for(pA = agenda; pA != NULL; pA = pA->proxData) {

		for(pE = pA; pE != NULL; pE = pE->proxEvento) {

			anterior = pE;	
			
			if(strcmp(pE->evento.descricao_do_evento, evento.descricao_do_evento) == 0) {

				anterior->proxEvento = pE->proxEvento;
				free(pE);
			}
		}
	}
}

/**
 * Exclui uma data assim como seus eventos de acordo com uma data informada
 * @param agenda 
 * @param data   
 */
void removerData(TAgenda* agenda, TData data) {

	leituraData(&data);

	TAgenda* pA;
	TAgenda* pE;
	TAgenda* anterior = agenda;

	for(pA = agenda; pA != NULL; pA = pA->proxData) {

		if(pA->data.ano == data.ano && pA->data.mes == data.mes && pA->data.dia == data.dia) {
				
			anterior = pA;	
			anterior->proxData = pA->proxData;
			free(pA);
		}	
	}
}

void imprimirEventosData(TAgenda* agenda, TData data) {
	
	leituraData(&data);

	//Percorrer agenda
	TAgenda* pA;
	//Imprimir enventos
	TAgenda* iE;

	for(pA = agenda; pA != NULL; pA = pA->proxData) {

		if(pA->data.ano == data.ano && pA->data.mes == data.mes && pA->data.dia == data.dia) {
				
			for(iE = pA; iE != NULL; iE = iE->proxEvento) {

				printf("Hora: %i\n", iE->evento.noHorario.horas);
				printf("Minutos: %i\n", iE->evento.noHorario.minutos);
				printf("Descrição: %s\n", iE->evento.descricao_do_evento);
			}
		}
	}	
}