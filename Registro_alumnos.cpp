
#include <iostream>
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

// Variables globales
int _ingresar_opcion=0;
string _alumnos[100], _materias[100];
float _promedios[100], _contador_de_notas=0, _promedio_de_notas;
int _contador_de_aprobados=0, _contador_de_reprobados=0;
int _registro_de_alumnos, _contador_de_alumnos;
string _alumno_promedio_bajo = "Desconocido", _alumno_promedio_alto="Desconocido";
int _promedio_alto_tmp = 0, _promedio_bajo_tmp = 10; 


// Funcion principal
int main() {

// Registrar alumnos
cout<<"Que promedio considero como el m\xA0s alto? _"; cin >> _promedio_bajo_tmp;
cout<<"Que promedio considero como el m\xA0s bajo? _"; cin >> _promedio_alto_tmp;
cout<<"Cuantos alumnos deseas registrar? _"; cin >> _registro_de_alumnos;
for(_contador_de_alumnos = 1; _contador_de_alumnos <= _registro_de_alumnos;  _contador_de_alumnos++){
	system("cls");
	string _alumnoX, _materiaX;
	float _promedioX=0;
	cout<<"Promedio alto: "<< _promedio_bajo_tmp << " Promedio bajo: " << _promedio_alto_tmp << endl;
	cout<<"Ingrese el nombre del alumno numero #"<< _contador_de_alumnos <<" : #"<<_registro_de_alumnos<<" > ";
	cin>>_alumnoX;
	cout<<"Ingrese el nombre de la materia: _";
	cin>>_materiaX;
	cout<<"Ingrese el promedio de la materia: _";
	cin>> _promedioX;
	// Al macenar datos en el array con el identificar _contador_de_alumnos
	_alumnos[_contador_de_alumnos] = _alumnoX;
	_materias[_contador_de_alumnos] = _materiaX;
	_promedios[_contador_de_alumnos] = _promedioX;
	_contador_de_notas += _promedioX; // sumar todos los promedios
	
	if(_promedioX >= 7.0){ // Mayor o igual a 7 de promedio es aprobado
		_contador_de_aprobados++; 
	} else if(_promedioX < 7.0 ){ // Menor a 7 de promedio es reprobado
		_contador_de_reprobados++; 
	}
	
}

// Buscar al alumno con el promedio mas alto
for(int _i = _contador_de_alumnos-1; _i > 0; _i--){
		
		// _promedio_bajo_tmp , _alumno_promedio_bajo
		if( _promedios[_i] < _promedio_bajo_tmp){
			_promedio_bajo_tmp = _promedios[_i]; // si es verdad
			_alumno_promedio_bajo = _alumnos[_i];
		}else{
			_promedio_bajo_tmp = _promedio_bajo_tmp; // si es falso
		}
		
		// _promedio_alto_tmp , _alumno_promedio_alto
		if( _promedios[_i] > _promedio_alto_tmp){
			_promedio_alto_tmp = _promedios[_i]; // si es verdad
			_alumno_promedio_alto = _alumnos[_i];
		}else{ 
			_promedio_alto_tmp = _promedio_alto_tmp; // si es falso
		}		
							
}

cout<<endl;
system ("pause");
system ("cls");
cout<<endl;

do{
system("cls");
// Mostrar resultados
cout<<"\n\t\t\tQue desea ver ?"<<endl; 
cout<<"\t\t1. ->Porcentaje de Aprobados"<<endl;
cout<<"\t\t2. ->Porcentaje de Reprobados"<<endl;
cout<<"\t\t3. ->Promedio de notas por materias"<<endl;
cout<<"\t\t4. ->Alumno con calificacion mas alta"<<endl;
cout<<"\t\t5. ->Alumno con calificacion mas baja"<<endl;
cout<<"\t\t0. ->Salir"<<endl;
cout<<"\tIngrese su opcion: "; cin>>_ingresar_opcion;

if(_ingresar_opcion == 1){
	float _porcentaje_de_aprobados = (100/_registro_de_alumnos) * _contador_de_aprobados;
	cout << "El porcentaje de aprobados es: "<< _porcentaje_de_aprobados; cout<<endl;
	if(_contador_de_reprobados == 0)
	cout << "\(*_*)/ !!! Felicidades todos aprobaron !!!"; cout<<endl;
}else if (_ingresar_opcion == 2){
	float _porcentaje_de_reprobados = (100/_registro_de_alumnos) * _contador_de_reprobados;
	cout << "El porcentaje de reprobados es: "<< _porcentaje_de_reprobados << endl;
	if(_contador_de_reprobados == 0)
	cout << "\(*_*)/ !!! Enhorabuena !!!"; cout<<endl;
}else if(_ingresar_opcion == 3){
	float _promedio_de_notas_por_materias = (_contador_de_notas/_registro_de_alumnos);
	cout << "El promedio de notas por materias es: "<< _promedio_de_notas_por_materias << endl << endl;
}else if(_ingresar_opcion == 4){
	cout << "El alumno con el promedio mas alto es: "<< _alumno_promedio_alto << " con " << _promedio_alto_tmp << " de promedio " << endl << endl;
}else if(_ingresar_opcion == 5){
	cout << "El alumno con el promedio mas bajo es: "<< _alumno_promedio_bajo << " con " << _promedio_bajo_tmp << " de promedio " << endl << endl;
}


cout<<endl;
system("pause");
}while(_ingresar_opcion > 0);

cout << "\t\t***** FIN DEL PROGRAMA *****" << endl;
getch();
return 0;
}
