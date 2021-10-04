#include <stdio.h>
#include <mysql.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	
	MYSQL *conn;
	int err;
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	char consulta[80];
	
	conn = mysql_init(NULL);
	if(conn == NULL){
		printf("Error al crear la conexion: %u %s\n", mysql_errno(conn),mysql_error(conn));
		exit(1);
	}
	
	conn = mysql_real_connect(conn, "localhost","root","mysql","juego",0,NULL,0);
	if(conn == NULL){
		printf("Error al crear la conexion: %u %s\n", mysql_errno(conn),mysql_error(conn));
		exit(1);
	}
	
	
	
	strcpy(consulta, "SELECT DISTINCT(Jugadores.USER) FROM (Jugadores, Participacion) WHERE (SELECT Participacion.ID_PARTIDA from (Jugadores,Participacion) WHERE Jugadores.USER = 'Juan' AND Jugadores.ID = Participacion.ID_JUGADOR ) AND Jugadores.ID = Participacion.ID_JUGADOR");
	err=mysql_query (conn, consulta);
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	resultado = mysql_store_result(conn);
	row = mysql_fetch_row(resultado);
	printf(row[1]);
}



