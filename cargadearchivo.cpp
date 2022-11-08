struct info{
	
	int id_jugada;
	char nombre_jugador[20+1];
	int fecha;
	int puntaje;
};

void cargarArchivo(FILE*,info,int[][],int);

int main()
{
	FILE* f= fopen("JUGADAS.dat","wb+");
	info variable;
	
	cargarArchivo(f,variable,matriz,n); //n cantidad d jugadores
			
	
}

void cargarArchivo(FILE* f, info variable, int matriz[][],int n);
{
	
	int i=0;
	while(i<n)
	{
		//carga de datos
		i++;
	}
	
	fwrite(&variable,sizeof(info),1,f);
	fclose(f);	
}