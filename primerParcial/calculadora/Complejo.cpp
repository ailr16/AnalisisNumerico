#include "Complejo.h"

Complejo::Complejo(void){
	real=0.0;
	imaginario=0.0;
}
Complejo::Complejo(double r, double i){
	real=r;
	imaginario=i;
}
Complejo::~Complejo(void){
}
void Complejo::pideleAlUsuarioTusDatos(void){
	cout<<"Dame mi real ";cin>>real;
	cout<<"Dame mi imaginario ";cin>>imaginario;
}
void Complejo::muestraTusDatos(void){
	cout<<real;
	if(imaginario<0)
		cout<<imaginario;
	else
		cout<<"+"<<imaginario;
	cout<<"i";
}
double Complejo::dameTuReal(void){
	return real;
}
void Complejo::modificaTuReal(double real){
	this->real=real;
}
double Complejo::dameTuImaginario(void){
	return imaginario;
}
void Complejo::modificaTuImaginario(double imaginario){
	this->imaginario=imaginario;
}
Complejo suma(Complejo C1, Complejo C2){
    Complejo R(
        C1.dameTuReal()+C2.dameTuReal()
        ,
        C1.dameTuImaginario()+C2.dameTuImaginario()
    );
    return R;
}
Complejo resta(Complejo C1, Complejo C2){
    Complejo R(
        C1.dameTuReal()-C2.dameTuReal()
        ,
        C1.dameTuImaginario()-C2.dameTuImaginario()
    );
    return R;
}
Complejo multiplica(Complejo C1, Complejo C2){
    Complejo R(
            C1.dameTuReal()*C2.dameTuReal()
               -
            C1.dameTuImaginario()*C2.dameTuImaginario()
        ,
            C1.dameTuReal()*C2.dameTuImaginario()
               +
            C1.dameTuImaginario()*C2.dameTuReal()
    );
    return R;
}
Complejo divide(Complejo C1, Complejo C2){
    Complejo R(
            (
             C1.dameTuReal()*C2.dameTuReal()
             +
             C1.dameTuImaginario()*C2.dameTuImaginario()
            )
            /
            (pow(C2.dameTuReal(),2) + pow(C2.dameTuImaginario(),2))
        ,
            (
             C1.dameTuImaginario()*C2.dameTuReal()
             -
             C1.dameTuReal()*C2.dameTuImaginario()
            )
            /
            (pow(C2.dameTuReal(),2) + pow(C2.dameTuImaginario(),2))
    );
    return R;
}
Complejo operator+(Complejo C1, Complejo C2) {
	return suma(C1, C2);
}
Complejo operator-(Complejo C1, Complejo C2) {
	return resta(C1, C2);
}
Complejo operator*(Complejo C1, Complejo C2) {
	return multiplica(C1, C2);
}
Complejo operator/(Complejo C1, Complejo C2) {
	return divide(C1, C2);
}
istream& operator>>(istream& Izq, Complejo& Der) {
	Der.pideleAlUsuarioTusDatos();
	return Izq;
}
ostream& operator<<(ostream& Izq, Complejo Der) {
	Der.muestraTusDatos();
	return Izq;
}

