

typedef struct{
    char titulo[50];
    char genero[50];
    char linkImagen[100];
    int duracion;
    int puntaje;
    //int flag_estado;
   // int id_movie;
}eMovie;

int getOpcion(int opc);


int getInt();
float getFloat();
char getChar();



int esNumerico(char *str) ;
int esTelefono(char *str);
int esAlfaNumerico(char *str);
int esSoloLetras(char *str);
int esNumericoFlotante(char str[]);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
void getValidString(char requestMessage[],char errorMessage[], char input[]);

void cleanStdin(void);

void loadData(eMovie* p);
int saveMovie(eMovie* p);
eMovie* readMovie(char* title);


