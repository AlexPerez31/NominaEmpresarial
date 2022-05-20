/*  Alex Jordan Perez Rojas    Codigo:20172578109
Programa "Nomina":
El siguiente programa emula las funcion de una nomina (no exacta, pero si lo mas
cercana posible), esta constituido con las librearias necesarias, con algunas 
funciones con y sin parametros, sin variables globales y usando struct.
La forma mas eficiente que halle para hacerlo sin variables globales y sin tener
que ponerle muchos parametos a las funciones es usando los archivos como escritura
y lectura, ya que al guardar informacion por palabra en unarchivo esta se puede
volver a llamar sin necesidad de usar exactemente las mimas variables con las
que se guardo la informacion, lo importante aqui es saber el orden en el que 
se guardo la informacion y en ese mismo orden se vuelve a invocar.
El programa aunque imprime en pantalla no fue exclusivamente dise�ado para
guardar la informacion en 3 archivos los cuales son:
empleados: este archivo guarda toda la informacion de la nomina, como
		nombres, valores, etc. y fue la base para generar los demas archivos.
gasto: solo guarda el valor que se gasto la empresa por cada empleado.
recibo: Contiene el recibo de Nomina de solo los empleados que hallan sido seleccionados.
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class empleado{
	public:
	int leer (void);
	void gasto (void);
	void mostrartodo (void);
	void mostraruno (char empresa[30]);
	char menu (void);
	void info (void);
	~empleado();
};


empleado::~empleado(){  //Destructor borra los archivos
		remove("empleados.txt");
		remove("recibo.txt");
		remove("gasto.txt");
}

int empleado::leer(){		//Funcion que lee y genera el archivo empleados
	struct variables{       //Uso de estruct con sus respectivas variables
	char nom[50], ape[50], dir[50],w[1],id[20],aux[20], cargo[30], telefono[20];
	float sueldo, transporte, salud, salariofinal, comision, hd,hn,hfd,hfn,salario,gasto,salud2;
	}var;
	int nhd,nhn,nhfd,nhfn;
	gets(var.w);
	cout<<"Digite la identificacion "<<endl ;
	gets(var.id);
	cout<<"Digite el nombre"<<endl ;
	gets(var.nom);
	cout<<"Digite el apellido"<<endl ;
	gets(var.ape);
	cout<<"Digite la direccion"<<endl ;
	gets(var.dir);
	cout<<"Digite el cargo"<<endl ;
	gets(var.cargo);
	cout<<"Digite el telefono"<<endl ;
	gets(var.telefono);
	var.sueldo=-1;
	while (var.sueldo<781242){   //Todos deben ganar por lo menos un salario minimo
 	cout<<" �Cuanto gana este empleado al mes?    SUELDO MINIMO: $ 781242"<<endl;
 	cin>>var.sueldo;}
 	if (strcmp(var.cargo,"vendedor") == 0){  //Si el empleado es un vendedor puede obtener comision
 		cout<<"�Cuanto gano de comosion este vendedor durante el mes?"<<endl;
 		cin>>var.comision;}
 		else var.comision=0;
 	nhd = nhn = nhfd = nhfn = -1;
 	cout<<"Cuantas horas extras trabajo durante el mes, recuerde que son maximo 48"<<endl;
 	cout<<"Diurnas max: 12, Nocturnas max 12,"<<endl<<"Festivas Diurnas max 12, Festivas Nocturnas 12.";
 	while ((nhd<0)or(nhd>12)){     //En un mes solo se pueden trabajar maximo 48 horas extra
	 	cout<<endl<<"Horas extras diurnas: ";cin>>nhd;}
	while ((nhn<0)or(nhn>12)){   
 		cout<<endl<<"Horas extras nocturnas: ";cin>>nhn;}
 	while ((nhfd<0)or(nhfd>12)){
 		cout<<endl<<"Horas extras festivas diurnas: ";cin>>nhfd;}
 	while ((nhfn<0)or(nhfn>12)){
 		cout<<endl<<"Horas extras festivas nocturnas: ";cin>>nhfn;}

	float h;
	if (var.sueldo<=1562484){   //Si el empleado gana mas de dos salarios minimos no puede recivir
		var.transporte = 88211; //apoyo de transporte
	}
	else var.transporte=0;
	h=var.sueldo/240;    //Calculando el precio por hora y por cada hora extra
	var.hd=(h+(h/4))*nhd;
	var.hn=(h+((h/4)*3))*nhn;
	var.hfd=(h+h)*nhfd;
	var.hfn=(h+((h/4)*6))*nhfn;
	var.salario = var.sueldo + var.hd + var.hn + var.hfd + var.hfn + var.comision;
	var.salud = (var.salario / 100)*4;
	var.salud2 = (var.salario / 100)*8.5;
	var.salariofinal=var.salario-var.salud;   //Slario del empleado
	var.gasto= var.salario+var.salud+var.transporte;  //Gasto de la empresa por el empleado
	
	ofstream escritura("empleados.txt",ios::out|ios::app);  //Generando el archivo que guarda todo
		escritura<<var.id<<"   "<<var.cargo<<endl;          //empleados.txt
		escritura<<var.nom<<" "<<var.ape<<endl;
		escritura<<var.dir<<" "<<var.telefono<<endl;
		escritura<<" "<<var.sueldo<<" "<<var.transporte<<" "<<var.salud<<" "<<var.comision<<" ";
		escritura<<var.hd<<" "<<var.hn<<" "<<var.hfd<<" "<<var.hfn<<" "<<endl<<" "<<var.gasto<<endl;
		escritura<<var.salariofinal<<endl<<endl;
		
	ofstream entrada("gasto.txt", ios::out|ios::app);   //Generando el archivo que guarda los gastos de
		entrada<<var.id<<"   "<<var.cargo<<endl;//la empresa gasto.txt
		entrada<<var.nom<<"   "<<var.ape<<endl;
		entrada<<"Con este empleado se gasto un total de: "<<endl;
		entrada<<"$"<<var.gasto<<" PESOS"<<endl;
		entrada<<"___________________________________________"<<endl<<endl;
}


void empleado::mostrartodo(){   //Funcion exclusiva para mostrar los datos de todos los empleado en pantalla
	struct variables{
	char nom[50],dir[50],ape[50],id[20],cargo[30],telefono[20];
	float sueldo, transporte, salud,salariofinal, comision, hd,hn,hfd,hfn,gasto;
	}var;		
	ifstream sacar("empleados.txt");
	if (sacar.fail()){
		cout<<"no hay nadie registrado";
	}
	else{
		sacar>>var.id;
	while(!sacar.eof()){
		sacar>>var.cargo>>var.nom>>var.ape>>var.dir>>var.telefono>>var.sueldo>>var.transporte;
		sacar>>var.salud>>var.comision>>var.hd>>var.hn>>var.hfd>>var.hfn>>var.gasto>>var.salariofinal;
		cout<<"________________________________________________________________________________________________________________"<<endl;
		cout<<"Identificacion: "<<var.id<<endl;
		cout<<"Cargo: "<<var.cargo<<endl;
		cout<<"Nombre: "<<var.nom<<" "<<var.ape<<endl;
		cout<<"Direccion: "<<var.dir<<endl;
		cout<<"Telefono: "<<var.telefono<<endl;
		cout<<"sueldo: $"<<var.sueldo<<"  (+) Transporte: $"<<var.transporte<<"  (-) Salud: $"<<var.salud<<"  (+) Comision: $"<<var.comision<<endl;
		cout<<"(+) Hora extra diurna $"<<var.hd<<"  (+) Hora extra nocturna $"<<var.hn;
		cout<<"  (+) Hora extra festiva diurna $"<<var.hfd<<"  (+) Hora extra festiva nocturna $"<<var.hfn<<endl;
		cout<<"  Salario Total: $"<<var.salariofinal<<endl<<endl;
		sacar>>var.id;
	} 
	}
}

void empleado::mostraruno(char empresa[30]){  //Funcion que genera el recibo de nomina del empleado seleccionado 
	struct variables{						  //solo genera el recibo de un empleado por vez ya que es mas entretino
	char nom[50], ape[50], dir[50],id[20],aux[20], cargo[30], telefono[20];//buscar al empleado seleccionado en todo
	float sueldo, transporte, salud, salariofinal, comision, hd,hn,hfd,hfn,salario,gasto,salud2;//el archvio y asi
	bool encontrado;                                             						//generar su recibo de nomina
	}var;							//ademas de que con esta manera se puede ver otras de las formas de recorer un archivo
	ifstream lectura;
    lectura.open("empleados.txt",ios::out|ios::in);
    if(lectura.is_open()){
        cout<<"Ingresa la identificacion que deseas Buscar: ";
        gets(var.aux);
        gets(var.aux);
       lectura>>var.id;
        var.encontrado=false;
        while(!lectura.eof()){    //Buscando en el archivo empleados.txt
            	lectura>>var.cargo>>var.nom>>var.ape>>var.dir>>var.telefono>>var.sueldo>>var.transporte;
				lectura>>var.salud>>var.comision>>var.hd>>var.hn>>var.hfd>>var.hfn>>var.gasto>>var.salariofinal;
            if(strcmp(var.aux,var.id)==0){
         	   cout<<"________________________________________________________________________________________________________________"<<endl;
				cout<<"Identificacion: "<<var.id<<endl;
				cout<<"Cargo: "<<var.cargo<<endl;
				cout<<"Nombre: "<<var.nom<<" "<<var.ape<<endl;
				cout<<"Direccion: "<<var.dir<<endl;
				cout<<"Telefono: "<<var.telefono<<endl;
				cout<<"sueldo: $"<<var.sueldo<<"  (+) Transporte: $"<<var.transporte<<"  (-) Salud: $"<<var.salud<<"  (+) Comision: $"<<var.comision<<endl;
				cout<<"(+) Hora extra diurna $"<<var.hd<<"  (+) Hora extra nocturna $"<<var.hn;
				cout<<"  (+) Hora extra festiva diurna $"<<var.hfd<<"  (+) Hora extra festiva nocturna $"<<var.hfn<<endl;
				cout<<"  Salario Total: $"<<var.salariofinal<<endl<<endl;
                var.encontrado=true;
                					
				ofstream entrada("recibo.txt",ios::out|ios::app); //Generando el archivo recibo.txt
				entrada<<"EMPRESA:    "<<empresa<<" | FECHA:  01/04/2018  AL  30/04/2018"<<endl;
				entrada<<"DOCUMENTO:  NOMINA MES DE ABRIL 2018 "<<endl;
				entrada<<"______________________________________________________"<<endl;
				entrada<<"|IDENTIFICACION |      NOMBRE      | CARGO |  BASE   |"<<endl;
				entrada<<"| "<<var.id<<" | "<<var.nom<<" | "<<var.cargo<<" | "<<var.sueldo<<" | "<<endl;
				entrada<<"_____________________________________________________|"<<endl;
				entrada<<"|       DESCRIPCION             |    VALOR       |"<<endl;
				entrada<<"| Horas Extra Diurnas           | $"<<var.hd<<" | "<<endl;
				entrada<<"| Horas Extra Noctrunas         | $"<<var.hn<<" | "<<endl;
				entrada<<"| Horas Extra Festivas Diurnas  | $"<<var.hfd<<" | "<<endl;
				entrada<<"| Horas Extra Festivas Noctrunas| $"<<var.hfn<<" | "<<endl;
				entrada<<"| Comision De Vendedor          | $"<<var.comision<<" | "<<endl;
				entrada<<"| (-) Salud                     | $"<<var.salud<<" | "<<endl;
				entrada<<"|_______________________________|________________|"<<endl;
				entrada<<"| Sueldo Total                  | $"<<var.salariofinal<<" | "<<endl;
				entrada<<"| Transporte                    | $"<<var.transporte<<" | "<<endl;
				entrada<<"_________________________________________________|"<<endl<<endl<<endl;
					
				cout<<"Recibo de Nomina Generado, por favor revice el archivo: recibo.txt"<<endl;
				
				
            }
         	lectura>>var.id;
            
        }
        if(var.encontrado==false){
            cout<<endl<<"No hay registros con la identificacion "<<var.aux<<endl;
        }
    }
	else{
        cout<<"No se pudoAbrir el Archivo, aun no ha sido Creado"<<endl;
    }
    lectura.close();
}

void empleado::info(){ //Decidi poner algo de informacion de como funciona una nomina 
	cout<<endl; 		//en el a�o 2018, Solo para curiosos.
	cout<<"______________________________________________________________________"<<endl;
	cout<<"NOMINA:"<<endl;
	cout<<"En 2018 en Colombia el sueldo minimo quedo establecido en $781.242,"<<endl;
	cout<<"el auxilio de transporte esta establecido en $88.211, pero solo puede"<<endl;
	cout<<"recivido por un empleado que viva a mas de un kilometro de distancia"<<endl;
	cout<<"de la empresa y que ademas el sueldo que reciva sea menos a dos"<<endl;
	cout<<"salarios minimos."<<endl;
	cout<<"Prima legal de Servicios: la cual se le reconoce al trabajador 15 d�as"<<endl;
	cout<<"de sueldo antes del 30 de junio de cada a�o y otros 15 d�as de sueldo"<<endl;
	cout<<"en el mes de diciembre antes del 20 de diciembre de cada a�o."<<endl;
	cout<<"Auxilio de Cesant�a y los intereses a la misma: al trabajador se le "<<endl;
	cout<<"reconocer� y otorgar� un mes de sueldo por cada a�o de servicios,"<<endl;
	cout<<"auxilio que se deber� consignar antes del 15 de febrero de cada a�o."<<endl;
	cout<<"Por su parte los intereses corresponden al 12% del valor de la cesantia."<<endl;
	cout<<"______________________________________________________________________"<<endl;
}

char empleado::menu(){ //Funcion que contiene el menu principal y la interfaz del programa
	int d;
	char empresa[30];
	cout<<"Alex Jordan Perez Rojas    20172578109"<<endl;
	empleado e;
	cout<<"Por Favor Digite El Nombre De Su Empresa: ";
	gets(empresa);
	int sw;
	do{
		cout<<endl<<endl;
		cout<<"Fecha actual:"<<endl;
		cout<<"||30 - ABRIL - 2018||"<<endl;
		cout<<endl<<"   'NOMINA' DE EMPLEADO   "<<endl;
   		cout<<endl;
   		cout<<"      1.  Insertar empleado      "<<endl;    
   		cout<<"      2.  Mostrar todos los empleados       "<<endl;
   		cout<<"      3.  Generar recibo de nomina     "<<endl;
   		cout<<"      4.  BORRAR LOS ARCHIVOS Y SALIR"<<endl;
   		cout<<"        | |6.Informacion sobre la Nomina| |  "<<endl;
   		cin>>sw;
   		switch (sw){
   			case 1:
   				e.leer();break;
   			case 2:
			    e.mostrartodo();	break;
			case 3:
				e.mostraruno(empresa); break;
			case 4:
				cout<<"Seguro que desea borrar el archivo?"<<endl;
				cout<<"    Se perderan todos los registros"<<endl;
				cout<<"          1.SI"<<endl;
				cout<<"          2.NO"<<endl;
				cin>>d;
				if(d==1){
					cout<<"   ||GRACIAS POR USAR EL PROGRAMA||"<<endl;
					cout<<"Alex Jordan Perez Rojas    20172578109";break;}
				else { break;}
			case 6:
				e.info(); break;
		   }
	}while (d!=1); 
	return empresa[30];
}


int main(){  //Main xD
	empleado e;
	e.menu();
}
