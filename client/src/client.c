#include "client.h"

t_log* iniciar_logger(void);
t_config* leer_config(void);
void terminar_programa(int conexion, t_log* logger, t_config* config);

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */
	logger = iniciar_logger();
	log_info(logger, "soy un log nuevo");

	config = leer_config();

	ip = config_get_string_value(config, "IP");
	puerto = config_get_string_value(config, "PUERTO");
	log_info(logger, "Lei la IP %s y puerto %s\n", ip, puerto);


	terminar_programa(conexion,logger,config);
}

t_log* iniciar_logger(void) {
    t_log *logger;
    if((logger = log_create("tp0.log", "TP0", 1, LOG_LEVEL_INFO)) == NULL) {
        printf("No pude crear el logger\n");
        exit(1);
    }
    return logger;
}


t_config* leer_config(void){
	t_config *config;
	if((config = config_create("/home/utnso/Desktop/tp0-grupo/client/cliente.config")) == NULL){
		printf("No pude leer la config\n");
		exit(2);
	}
	return config;
}

void terminar_programa(int conexion, t_log* logger, t_config* config){
	if (logger!=NULL){
		log_destroy(logger);
	}
	if (config!=NULL){
		config_destroy(config);
	}
}

