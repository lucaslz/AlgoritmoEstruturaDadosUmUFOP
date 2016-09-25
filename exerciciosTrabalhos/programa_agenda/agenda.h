/**
 * Estrutura de Data onde será inserido cada evendo
 */
typedef struct data {
	int dia;
	int mes;
	int ano;
}TData;

/**
 * Estruturo contendo o horario com hora e minutos
 */
typedef struct horario{
	int horas;
	int minutos;
}THorario;

/**
 * Estrutura de evento, apartir de uma data surgira um evendo
 */
typedef struct evento {
	THorario noHorario;
	char descricao_do_evento[100];
}TEvento;

/**
 * Estrutura de agenta com todo o escopo do programa sendo assim a estrutura de controle do sistema
 */
typedef struct agenda {
	TData data;
	TEvento evento;
	struct agenda* proxData;
	struct agenda* proxEvento;
}TAgenda;

/**
 * @description Retorna uma agenda já inicialida para o sistema 
 * @name iniciarAgenda
 * @return TAgenda
 */
TAgenda* iniciarAgenda();

/**
 * @description retorna 1 se a agenda tiver vazia, retorna 0 se ela estiver cheia
 * @name verificaAgendaVazia
 * @param agenda
 */
int verificaAgendaVazia(TAgenda* agenda);

/**
 * @description Faz a leitura da data, antes de ler um evento e preciso criar um data
 * [leituraData description]
 * @param data [description]
 */
void leituraData(TData* data);

/**
 * @description faz a leitura da data do evento do horário do evento e da descrição do evento
 * @name leituraInformacaoAgendascanf("%d", evento->noHorario->horas);
 * @param data
 * @param evento
 */
void leituraInformacaoAgenda(TEvento* evento);

/**
 * @description Auxilia a função inserir inserir um intem ordenadamente na lista
 * @param agenda         
 * @param percorrerLista 
 * @param anterior
 * @param tipo 1 => insere de acordo com o ano
 *             2 => insere de acordo com o mes
 *             3 => insere de acordo com o dia      
 */
void percorreDeAcordoAnoMesDia(TAgenda* agenda, TAgenda* percorrerLista, TAgenda* anterior, TData data,int tipo);

/**
 * @description Antes de inserir um evento o usuário precisa inserir uma data,
 * [inserirData]
 * @param agenda
 * @param data
 */
void inserirDataOrdenado(TAgenda* agenda, TData data);

/**
 * imprimir todas as datas
 * @param agenda
 */
void imprimirData(TAgenda* agenda);

/**
 * Pesquisa uma data dentro da agenda
 * @param  agenda 
 * @param  data   
 * @return percorrerAgenda
 */
TAgenda* pesquisarData(TAgenda* agenda, TData data);

/**
 * Percorre a agenda procurando o lugar certo de inserir o evento ou seja procura aposição para inserir ordenado
 * @param agenda         
 * @param percorrerLista 
 * @param anterior       
 * @param evento         
 * @param tipo 1 => insere de acordo com o hora
 *             2 => insere de acordo com o minutos           
 */
void percorrerDeAcordoHoraMinuto(TAgenda* agenda, TAgenda* percorrerLista, TAgenda* anterior, TEvento evento, int tipo);

/**
 * Inserir um evento de acordo com uma data
 * @param agenda  [description]
 * @param TEvento [description]
 */
void inserirEvento(TAgenda* agenda, TEvento evento, TData data);

/**
 * Entra com a descrição de um evento para exclui-lo ou procura-lo
 * @param evento
 */
void descricaoEvento(TEvento* evento);

/**
 * Remove um evento de acordo com a descrição pedida
 * @param agenda 
 * @param evento 
 */
void removerEvento(TAgenda* agenda, TEvento evento);

/**
 * Exclui uma data assim como seus eventos de acordo com uma data informada
 * @param agenda 
 * @param data   
 */
void removerData(TAgenda* agenda, TData data);