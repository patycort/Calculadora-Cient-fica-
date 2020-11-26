#include <iostream>                           //para la consola
#include <math.h>
using namespace std;                          //obligatoria

int aa, bb, cc;                                   //variables para funciones de eleccion
void opArit();
void opGeo();

class aritmetica{                             //CLASE TATARATATARABUELA

  private:
    int dim, num2;                           // numero usuario, divisor, potencia y resultado
    float r;                                 //resultado
    float nums[0];                            //numero de sumandos/restandos/ multiplicandos etc

  public:
    aritmetica(){                             //constructor default
    }

    aritmetica (int x, int y, float arr[]){   //constructor parametrizado
      setDim(x);                           //Dim es un numero
      setNum2(y);                          //Determinar potencia y colocar num en array
      setNums(arr);                        //Determinar numero de numeros que se van a sumar, restar, multiplicar, dividir
    }
                                          //mutadores
    void setDim(int a);                   //numero de numros
    void setNum2(int b);                  //potencia
    void setNums(float mat[]);            //numeros a sumar, resta e,tc

    int getDim();                         //accesos
    int getNum2();

    float suma();                         //operaciones
    float resta();
    float mult();
    float divis();                        //por si son decimales
    float pote();

    ~aritmetica(){                        //destructor, cuando los objetos no se vuelven a usar, los destruye
    }
};

class geometrica : public aritmetica{ //CLASE TATARABUELA

    private:
    float ancho, largo, profundidad, radio;
    
    public:
    geometrica(int x, int y, float arr[], float zan, float zla, float zp, float zra){
    setDim(x); //Dim es un numero
    setNum2(y); //Determinar potencia y colocar num en array
    setNums(arr);
    setAncho(zan);
    setLargo(zla);
    setProfundidad(zp);
    setRadio(zra);

}

    void setProfundidad(float p); //mutador
    void setRadio(float ra);
    void setAncho(float an);
    void setLargo(float la);
    
    
    float getProfundidad(); //acceso
    float getRadio();
    float getAncho();
    float getLargo();
    
    float volumenR(); //operaciones para diferentes fig geometricas R REC, T TRIAN, CCIRC
    float volumenT();
    float volumenC();
    float areaR();
    float areaT();
    float areaC();
    float perimetroR();
    float perimetroT();
    float perimetroC();

};

class matricial {
    
  public:

    void m_llenarm(int dim1, int *M);
    void m_imprimir(int dim1, int *M);
    void m_suma(int* ptr_m1, int* ptr_m2, int* ptr_op, int dim1);                        //operaciones matriciales
    void m_resta(int* ptr_m1, int* ptr_m2, int* ptr_op, int dim1);
    void m_multiplicacion(int* ptr_m1, int* ptr_m2, int* ptr_op, int dim1);
    void m_transposicion_m1(int* ptr_op, int* ptr_m1, int dim1);
};

class algebraica_vector : public matricial{//CLASE ABUELA

    public:
    
    void si_ecuaciones();                  //operacion algebraica
    void distancia_2p();                   //operaciones vectoriales
    void magnitud_vec();
    void sum_2vec();
};

class estadistica : public algebraica_vector{//CLASE MADRE

  public:

    float e_moda(int num_d, int datos[0]);   //operaciones estadisticas
    float e_prom(int num_d, int datos[0]);
    float e_mediana(int num_d, int datos[0]);
    void e_datos(int num_d, int datos[0]);
};

class calc_comp : public estadistica {
    
    public:
    void m_matrices();
    void algebraica_vector();
    void estadisticas();

};

int main(){
    calc_comp tr;

  int num, choice=0;
  bool flag=0, flag2=0;

  cout<<"Programa Calculadora Cientifica"<<endl;
  cout<<endl;
  cout<<"Ingresa el numero del tipo de operacion que deseas realizar"<<endl;

  while(1){                                               //este ciclo es para que se puedan hacer infinitas operaciones si no se selecciona la opción ultima
                                                            //en este ciclo se tienen dos condicionales, y dos variables que determinan qué hacer
    if(flag==0 && choice==0){                             //choice es la selección del menú que hará el usuario //flag es una bandera que nos dejará permanecer en el ciclo si es cero, pues, al final de cada opción se reinicia en cero
      cout<<"1: Operaciones Aritmeticas"<<endl;
      cout<<"2: Operaciones Geometricas"<<endl;
      cout<<"3: Operaciones Matriciales"<<endl;
      cout<<"4: Operaciones Algebraicas y Vectoriales"<<endl;
      cout<<"5: Operaciones Estadisticas"<<endl;
      cout<<endl;
      cout<<"Elige el tipo de operacion deseado"<<endl;
    flag=1;                                               //aquí, la bandera se pone en 1 para acceder a la pregunta
    }
    if(flag==1 && choice==0){
      cin>>choice;
    }//para este punto ni choice ni flag valen 0
    cout<<endl;

    switch (choice){

      case 1:
      opArit();
      flag=0;//se reinician las variables para que al final se vuelva al menú
      choice=0;
      break;

      case 2:
      opGeo();
      flag=0;//se reinician las variables para que al final se vuelva al menú
      choice=0;
      break;

      case 3:
      tr.m_matrices();
      flag=0;//se reinician las variables para que al final se vuelva al menú
      choice=0;
      break;

      case 4:
      tr.algebraica_vector();
      flag=0;//se reinician las variables para que al final se vuelva al menú
      choice=0;
      break;

      case 5:
      tr.estadisticas();
      flag2=1;

      default:
      flag2=1;

    }
    if(flag2==1) break;//break del while
  }
  return 0;
}

void opArit(){
  int elecc;

  cout<<"1: SUMA"<<endl;
  cout<<"2: RESTA"<<endl;
  cout<<"3: MULTIPLICACION"<<endl;
  cout<<"4: DIVISION"<<endl;
  cout<<"5: POTENCIA"<<endl;
  cout<<endl;
  cout<<"Elige la operacion deseada"<<endl;
  cin>>elecc;
  cout<<endl;

  switch(elecc){

    case 1:
    {
      cout<<"Ingresa la cantidad de numeros que quieres sumar"<<endl;
      cin>>aa;                                                           //equivalente a dim
      float array[aa];
      for (int i=0; i<aa;i++){
        cout<<"Ingresa el numero para la posicion "<<i<<" de tu suma:"<<endl;
        cin>>array[i];                                                //equivalente a nums[]
      }
      aritmetica ari(aa,0,array);
      cout<<"La suma que introdujiste es: "<<ari.suma()<<endl;
      cout<<endl;
      break;
    }

    case 2:
    {
      cout<<"Ingresa la cantidad de numeros que quieres restar, recueda que el primer numero que ingreses no tiene signo - antes de si mismo, los demás si"<<endl;
      cin>>aa;                                                           //equivalente a dim
      float array[aa];
      for (int i=0; i<aa;i++){
        cout<<"Ingresa el numero para la posicion "<<i<<" de tu resta:"<<endl;
        cin>>array[i];                                                  //equivalente a nums[]
      }
      aritmetica ari(aa,0,array);
      cout<<"La resta que introdujiste es: "<<ari.resta()<<endl;
      cout<<endl;
      break;
    }

    case 3:
    {
      cout<<"Ingresa la cantidad de numeros que quieres multiplicar:"<<endl;
      cin>>aa;                                                           //equivalente a dim
      float array[aa];
      for (int i=0; i<aa;i++){
        cout<<"Ingresa el numero para la posicion "<<i<<" de tu multiplicacion:"<<endl;
        cin>>array[i];                                                  //equivalente a nums[]
      }
      aritmetica ari(aa,0,array);
      cout<<"La multiplicacion que introdujiste es: "<<ari.mult()<<endl;
      cout<<endl;
      break;
    }

    case 4:
    {
      float array[2];
      cout<<"Ingresa el numerador:"<<endl;
      cin>>aa;                                                           //equivalente a dim
      cout<<"Ingresa el denominador"<<endl;
      cin>>bb;
      aritmetica ari(aa,bb,array);
      cout<<"La division que introdujiste es: "<<ari.divis()<<endl;
      cout<<endl;
      break;
    }

    case 5:
    {
      float array[2];
      cout<<"Ingresa el numero que quieres elevar a una potencia:"<<endl;
      cin>>aa;                                                           //equivalente a dim
      cout<<"Ingresa la potencia deseada"<<endl;
      cin>>bb;
      aritmetica ari(aa,bb,array);
      cout<<"La division que introdujiste es: "<<ari.pote()<<endl;
      break;
    }

      default:
      break;
  }
}

void opGeo(){
  int elecc;

  cout<<"Operaciones con rectangulo como base:"<<endl;
  cout<<" 1: Area de rectangulo"<<endl;
  cout<<" 2: Volumen de prisma rectangular"<<endl;
  cout<<" 3: Perimetro de rectangulo"<<endl;
  cout<<endl;
  cout<<"Operaciones con triangulo como base:"<<endl;
  cout<<" 4: Area de triangulo"<<endl;
  cout<<" 5: Volumen de prisma triangular"<<endl;
  cout<<" 6: Perimetro de triangulo"<<endl;
  cout<<endl;
  cout<<"Operaciones con circulo como base:"<<endl;
  cout<<" 7: Area de circulo"<<endl;
  cout<<" 8: Volumen de cilindro"<<endl;
  cout<<" 9: Perimetro de circulo"<<endl;
  cout<<endl;
  cout<<"Elige la operacion deseada"<<endl;
  cin>>elecc;
  cout<<endl;

  switch(elecc){

    case 1:
    {
      float array[2];
      cout<<"Ingresa el ancho entero de tu rectangulo"<<endl;
      cin>>aa;                                                           //equivalente a dim
      cout<<"Ingresa el largo entero de tu rectangulo"<<endl;
      cin>>bb;
      geometrica geo(0, 0, array, aa, bb, 0, 0);
      cout<<"El area de tu rectangulo es: "<<geo.areaR()<<endl;
      cout<<endl;
      break;
    }

    case 2:
    {
      float array[2];
      cout<<"Ingresa el ancho entero de tu prisma rectangular"<<endl;
      cin>>aa;                                                           //equivalente a dim
      cout<<"Ingresa el largo entero de tu prisma rectangular"<<endl;
      cin>>bb;
      cout<<"Ingresa la profundidad entera de tu prisma rectangular"<<endl;
      cin>>cc;
      geometrica geo(0, 0, array, aa, bb, cc ,0);
      cout<<"El volumen de tu prisma rectangular es: "<<geo.volumenR()<<endl;
      break;
    }

    case 3:
    {
      float array[2];
      cout<<"Ingresa el ancho entero de tu rectangulo"<<endl;
      cin>>aa;                                                           //equivalente a dim
      cout<<"Ingresa el largo entero de tu rectangulo"<<endl;
      cin>>bb;
      geometrica geo(0, 0, array, aa, bb, 0 ,0);
      cout<<"El perimetro de tu rectangulo es: "<<geo.perimetroR()<<endl;
      break;
    }

    case 4:
    {
      float array[2];
      cout<<"Ingresa el ancho entero de tu triangulo"<<endl;
      cin>>aa;                                                           //equivalente a dim
      cout<<"Ingresa el largo entero de tu triangulo"<<endl;
      cin>>bb;
      geometrica geo(0, 0, array, aa, bb, 0 ,0);
      cout<<"El area de tu triangulo es: "<<geo.areaT()<<endl;
      break;
    }

    case 5:
    {
      float array[2];
      cout<<"Ingresa el ancho entero de tu prisma triangular"<<endl;
      cin>>aa;                                                           //equivalente a dim
      cout<<"Ingresa el largo entero de tu prisma triangular"<<endl;
      cin>>bb;
      cout<<"Ingresa la profundidad entera de tu prisma triangular"<<endl;
      cin>>cc;
      geometrica geo(0, 0, array, aa, bb, cc ,0);
      cout<<"El volumen de tu prisma rectangular es: "<<geo.volumenT()<<endl;
      break;
    }

    case 6:
    {
      float array[2];
      cout<<"Solo funciona con triangulos equilateros e isoscles"<<endl;
      cout<<endl;
      cout<<"Ingresa el ancho entero de tu triangulo"<<endl;
      cin>>aa;                                                           //equivalente a dim
      cout<<"Ingresa el largo entero de tu triangulo"<<endl;
      cin>>bb;
      geometrica geo(0, 0, array, aa, bb, 0 ,0);
      cout<<"El perimetro de tu rectangulo es: "<<geo.perimetroT()<<endl;
      break;
    }

    case 7:
    {
      float array[2];
      cout<<"Ingresa el radio entero de tu circulo"<<endl;
      cin>>cc;                                                           //equivalente a dim
      geometrica geo(0, 0, array, 0, 0, 0 ,cc);
      cout<<"El area de tu circulo es: "<<geo.areaC()<<endl;
      break;
    }

    case 8:
    {
      float array[2];
      geometrica geo(0, 0, array, 0, 0, bb, cc);
      cout<<"Ingresa el radio entero de tu cilindro"<<endl;
      cin>>cc;
      cout<<"Ingresa la profundidad entera de tu cilindro"<<endl;
      cin>>bb;
      cout<<"El volumen de tu cilindro es: "<<geo.volumenC()<<endl;
      break;
    }

    case 9:
    {
      float array[2];
      cout<<"Ingresa el radio entero de tu circulo"<<endl;
      cin>>cc;                                                           //equivalente a dim
      geometrica geo(0, 0, array, 0, 0, 0 ,cc);
      cout<<"El perimetro de tu circulo es: "<<geo.perimetroC()<<endl;
      break;
    }

    default:
    break;
  }

}
//-----------------------------FUNCIONES ARITMETICA------------------------------

void aritmetica :: setDim(int a){                 //mutador dim
    dim=a;
}

void aritmetica :: setNum2(int b){                 //mutador num2
    num2=b;
}

void aritmetica :: setNums(float mat[]) {           
    //mutador nums[]
    for(int i=0;i<dim;i++){
      nums[i]=mat[i];
      //cout<<mat[i]<<endl;
    }
}

int aritmetica :: getDim(){                        //acceso dim
  return dim;
}

int aritmetica :: getNum2(){                       //acceso Num2
  return num2;
}

float aritmetica :: suma(){                         //operadores
  r=0;
  for(int i=0; i<dim;i++){
    r=r+nums[i];
  }
  return r;
}

float aritmetica :: resta(){
  for(int i=0; i<dim;i++){
    if(i==0) r=nums[0];
    else r=r-nums[i];
  }
  return r;
}

float aritmetica :: mult(){
  r=1;                                    //se inicia con 1 para que no afecte
  for(int i=0; i<dim;i++){
      r=r*nums[i];
  }
  return r;
}

float aritmetica :: divis(){
  float as;
  r=0;
  as=dim;
  r=as/num2;                                       //ocupo dim como numerador
  return r;
}

float aritmetica :: pote(){
  r=0;
  r=pow(dim,num2);
  return r;
}
//------------------------------------FUNCIONES GEOMETRICA--------------------------

//------------------------------------FUNCIONES GEOMETRICA--------------------------

void geometrica :: setAncho(float an){ //mutadores
ancho=an;
}

void geometrica :: setLargo(float la){
largo=la;
}

void geometrica :: setProfundidad(float p){
profundidad=p;
}

void geometrica :: setRadio(float ra){
radio=ra;
}

float geometrica :: getAncho(){ //accesos
return ancho;
}

float geometrica :: getLargo(){
return largo;
}

float geometrica :: getProfundidad(){
return profundidad;
}

float geometrica :: getRadio(){
return radio;
}
// Operaciones
float geometrica :: areaR(){
return ancho*largo;
}

float geometrica :: areaT(){
return ancho*largo/2;
}

float geometrica :: areaC(){
return 3.141516*pow(radio,2);
}

float geometrica :: volumenR(){
return ancho*largo*profundidad;
}

float geometrica :: volumenT(){ //PRISMA TRIANGULAR
return ancho*largo*profundidad/2;
}

float geometrica :: volumenC(){
return 3.141516*pow(radio,2)*profundidad; //CILINDRO
}

float geometrica :: perimetroR(){
return (ancho+largo)*2;
}

float geometrica :: perimetroT(){ //perimetro de triangulo equilatero o isósceles
int lado_pitagoras;
lado_pitagoras=sqrt(pow(ancho/2,2)+pow(largo,2));
return ancho+2*lado_pitagoras;
}



float geometrica :: perimetroC(){
return 2*3.141516*radio;
}

//------------------------FUNCIONES MATRICIAL------------------------------------------------

void matricial :: m_llenarm(int dim1, int *M){
for (int i=0; i<dim1; i++) //columnas
	{
		for (int j=0; j<dim1; j++) //filas
		{
			cout << "Elemento [" << j + 1 << "][" << i + 1 << "]: ";
			cin >> *(M + i * dim1 + j);//apuntadores para rellenar
		}
	}
}

void matricial :: m_suma (int* ptr_m1, int* ptr_m2, int* ptr_op, int dim1) {

  cout<<endl;
  cout<<"La suma de las matrices da como resultado la matriz SUMA: "<<endl;
 	for (int i=0;i<dim1;i++) 
	{
		for (int j=0;j<dim1;j++)
		{
				(*(ptr_op+i*dim1+j))=(*(ptr_m1+i*dim1+j)) + (*(ptr_m2+i*dim1+j));
				cout<<*(ptr_op+i*dim1+j)<<" "; 
		}
		cout<<endl;
	}
  }

void matricial :: m_resta (int* ptr_m1, int* ptr_m2, int* ptr_op, int dim1){

  cout<<endl;
  cout<<"La resta de las matrices da como resultado la matriz RESTA: "<<endl;
  for(int i=0; i<dim1;i++){
    for(int j=0; j<dim1;j++){
		(*(ptr_op+i*dim1+j))=(*(ptr_m1+i*dim1+j)) - (*(ptr_m2+i*dim1+j));
        cout<<*(ptr_op+i*dim1+j)<<" ";
    }
    cout<<endl;
  }
}

void matricial :: m_multiplicacion (int* ptr_m1, int* ptr_m2, int* ptr_op, int dim1){

    cout<<endl;
    cout<<"La multiplicacion de las matrices da como resultado la matriz MULTIPLICACION: "<<endl;
    
    int ciclo=0; //declaramos variable
	for (int i=0; i<dim1;i++)   
	{
		for (int j=0; j<dim1;j++)
		{
			for (int k=0; k<dim1; k++) 
			{
				ciclo=ciclo+((*(ptr_m1+k*dim1+j))*(*(ptr_m2+i*dim1+k)));
			}
			*(ptr_op+i*dim1+j)=ciclo;
			ciclo = 0;
			cout<<*(ptr_op+i*dim1+j)<<" ";
		}
		cout<<endl;
	}
}

void matricial :: m_transposicion_m1(int* ptr_op, int* ptr_m1, int dim1){

    cout<<endl;
    cout<<"La transposicion de tu matriz es: "<<endl;
    for(int i=0; i<dim1;i++)
    {
     for(int j=0; j<dim1;j++)
     {
        *(ptr_op+i*dim1+j)= *ptr_m1+j*dim1+i;
        cout<<*(ptr_op+i*dim1+j)<<" ";
    }
    cout<<endl;
    }
    
}
 
//------------------------FUNCIONES VECTORIALES------------------------------------------------

void algebraica_vector :: si_ecuaciones (){
    int e_A, e_B, e_C;
    
        cout<<"Dame el valor de A"<<endl;
        cin>>e_A;
        cout<<"Dame el valor de B"<<endl;
        cin>>e_B;   
        cout<<"Dame el valor de C"<<endl;
        cin>>e_C;
        cout<<endl;
    
        int X1;
        X1=(e_B * -1)+ sqrt(((e_B*e_B)- (4 *e_A*e_C))/2*e_A);
        cout<<"El valor de X1 es : "<<X1<<endl;
        cout<<endl;
    
        int X2;
        X2=(e_B * -1)- sqrt(((e_B*e_B)- (4 *e_A*e_C))/2*e_A);
        cout<<"El valor de X2 es : "<<X2<<endl;
        cout<<endl;
}

void algebraica_vector :: sum_2vec(){
    float xp1, xp2, yp1, yp2;
        cout<<"Dame la coordenada X de tu primer punto"<<endl;
        cin>> xp1;
        cout<<"Dame la coordenada Y de tu primer punto "<<endl; 
        cin>>yp1;   
        cout<<"Dame la coordenada X de tu segundo punto"<<endl;
        cin>>xp2;
        cout<<"Dame la coordenada Y de tu segundo punto"<<endl;
        cin>>yp2;
        cout<<endl;
    
        float sumax;
        float sumay;
    
        sumax=xp2+xp1;
        sumay=yp2+yp1;

        cout<<"Tu vector suma es : "<<sumax<<","<<sumay<<endl;
}

void algebraica_vector :: magnitud_vec(){
        int xp1, yp1;
        cout<<"Dame la coordenada X de tu punto"<<endl;
        cin>>xp1;
        cout<<"Dame la coordenada Y de tu punto "<<endl; 
        cin>>yp1;  
        
        float mag;
        mag=sqrt((xp1*xp1)+(yp1*yp1));
        
        cout<<"La magnitud de tu vector es: "<<mag<<endl; 
    
}

void algebraica_vector :: distancia_2p(){

        int xp1, yp1, xp2, yp2;
        cout<<"Dame la coordenada X de tu primer punto"<<endl;
        cin>>xp1;
        cout<<"Dame la coordenada Y de tu primer punto "<<endl; 
        cin>>yp1;   
        cout<<"Dame la coordenada X de tu segundo punto"<<endl;
        cin>>xp2;
        cout<<"Dame la coordenada Y de tu segundo punto"<<endl;
        cin>>yp2;
        cout<<endl;
        
        float restax;
        float restay;
        float D;
        restax= (xp2-xp1)*(xp2-xp1);
        restay=(yp2-yp1)*(yp2-yp1);
        D=sqrt(restax+restay);
        cout<<"La distancia entre los puntos es: "<<D<<endl;
}
 
//------------------------FUNCIONES ESTADISTICAS-----------------------------------

float estadistica :: e_moda(int num_d, int datos[0]){
        
        int suma=0;
		int  mo=suma;
		int d=1;
		for (int i=0; i<num_d; i++){
			suma=0;
			for (int j=0; j<num_d; j++){
				if (datos[i]==datos[j] && i !=j){
					suma=(suma+1);
				}
			}
			if (suma>=mo){
				mo=suma;
				d=i;
			}
		}
		return datos[d];
	}

float estadistica :: e_prom(int num_d, int moda[0]){
        
        int x=0;
        for (int i=0; i<num_d; i++){
            x=x+moda[i];
        }
        
        return (x/num_d);
}

float estadistica :: e_mediana(int num_d, int datos[0]){
    
    int y;
    	for (int i=0; i<num_d; i++){
		for (int j=0; j<num_d; j++){
			if (datos[j]> datos[j+ 1])
			 {
				y=datos[j];
				datos[j]= datos[j+ 1];
				datos[j + 1]=y;
			}
		}
	}
	return datos[(num_d/2)+ 1];
}

void estadistica :: e_datos(int num_d, int datos[0]){
    
    cout<<"Dame tus datos "<<endl;
    for (int i=0; i<num_d;i++){
        cin>>datos[i];
    }
}

//------------------------FUNCIONES CALCULADORA------------------------------------------------

void calc_comp :: m_matrices(){
      
    int dim1=3;
    int ptr_m1[dim1][dim1], ptr_m2[dim1][dim1], ptr_op[dim1][dim1];
        
    int opcion ;
    cout<<"Elige la operacion matricial"<<endl;
    cout<<endl;
    cout<<"1: SUMA DE MATRICES "<<endl;
    cout<<"2: RESTA DE MATRICES"<<endl;
    cout<<"3: MULTIPLICACION DE MATRICES"<<endl;
    cout<<"4: TRANSPOSICION DE MATRIZ"<<endl;
    cin>>opcion;

    switch(opcion){

      case 1:
            
        cout<<"Dame los valores de la matriz 1 de 3x3"<<endl;
        m_llenarm(dim1, (int*)ptr_m1);

        cout<<"Dame los valores de la matriz 2 de 3x3"<<endl;
        m_llenarm(dim1, (int*)ptr_m2);
        
        m_suma((int*) ptr_m1,(int*) ptr_m2, (int*) ptr_op, dim1);
		break;
		
	  case 2:
	        
        cout<<"Dame los valores de la matriz 1 de 3x3"<<endl;
        m_llenarm(dim1, (int*)ptr_m1);

        cout<<"Dame los valores de la matriz 2 de 3x3"<<endl;
        m_llenarm(dim1, (int*)ptr_m2);
		
		m_resta((int*) ptr_m1, (int*) ptr_m2, (int*) ptr_op, dim1);
		break;
			
	  case 3:
		    
        cout<<"Dame los valores de la matriz  de 3x3"<<endl;
        m_llenarm(dim1, (int*)ptr_m1);
    
        cout<<"Dame los valores de la matriz 2 de 3x3"<<endl;
        m_llenarm(dim1, (int*)ptr_m2);

		m_multiplicacion((int*) ptr_m1,(int*) ptr_m2,(int*) ptr_op, dim1);
		break;
			
      case 4:
		    
        cout<<"Dame los valores de la matriz de 3x3"<<endl;
        m_llenarm(dim1, (int*)ptr_m1);

		m_transposicion_m1((int*) ptr_op, (int*) ptr_m1, dim1);
		break;
		    
		default:
		break;
    }
  }
  
void calc_comp :: algebraica_vector(){

    int opcion ;
    cout<<"Elige la operacion vectorial o algebraica"<<endl;
    cout<<endl;
    cout<<"1: SISTEMA DE ECUACIONES, 2 INCOGNITAS"<<endl;
    cout<<"2: DISTANCIA ENTRE 2 PUNTOS"<<endl;
    cout<<"3: MAGNITUD DE VECTORES"<<endl;
    cout<<"4: SUMA DE VECTORES"<<endl;
    cin>>opcion;

    switch(opcion){
        case 1:
            si_ecuaciones();
            cout<<endl;
   	    	break;         
        case 2:
            distancia_2p();
            cout<<endl;
    		break;        
        case 3:
            magnitud_vec();
            cout<<endl;
    		break;        
        case 4:
            sum_2vec ();
            cout<<endl;
		    break;
            
        default:
		break;
    }       
  }
  
void calc_comp ::estadisticas(){
    
    int opcion ;
    cout<<"Elige la operacion estadistica"<<endl;
    cout<<endl;
    cout<<"1: MODA"<<endl;
    cout<<"2: PROMEDIO"<<endl;
    cout<<"3: MEDIANA"<<endl;
    cin>>opcion;
    
    int datos[30];
    int num;
    cout<<"Dime el numero de datos que quieres usar"<<endl;
	cin>>num;
	e_datos(num, datos);
	
    switch(opcion)
    {
        case 1:
         cout<<"La moda de los numeros es : "<<e_moda(num, datos)<<endl;
        break; 
        case 2:
         cout<<"El promedio de los numeros es : "<<e_prom(num, datos)<<endl;
        break; 
        case 3:
         cout<<"La mediana de los numeros es : "<<e_mediana(num, datos)<<endl;
        break; 
        default:
        break;
        
    }
   
  }
