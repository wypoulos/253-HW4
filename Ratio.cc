// This is my ratio.cc file

#include "Ratio.h"
#include <stdexcept>
#include <numeric>
#include <iostream>

using namespace std;


Ratio::Ratio(long numerator, long denominator) : top(numerator), bottom(denominator){
	if(denominator == 0){
		throw runtime_error("ZERO IN DENOMNATOR");
	}
	normalize();
}
Ratio::Ratio(int numerator, int denominator) : top(long(numerator)), bottom(long(denominator)){
	if(denominator == 0){
		throw runtime_error("ZERO IN DENOMINATOR");	
	}
	normalize();
}
long Ratio::numerator() const {
	return top;
}
void Ratio::numerator(long numerator){
	top = numerator;
	normalize();
}
long Ratio::denominator() const {
	return bottom;
}
void Ratio::denominator(long denominator){
	if(denominator == 0){
		throw runtime_error("ZERO IN DENOMINATOR");
	}
	bottom = denominator;
	normalize();
}
long double Ratio::ratio() const{
	return static_cast<long double>(top)/static_cast<long double>(bottom);
}
Ratio Ratio::add(Ratio r1, Ratio r2, Ratio r3, Ratio r4, Ratio r5, Ratio r6, Ratio r7, Ratio r8) const{
	Ratio ratio1 = addHelp(r1,r2);
	Ratio ratio2 = addHelp(r3,r4);
	Ratio ratio3 = addHelp(r7,r8);
	Ratio ratio4 = addHelp(r5,r6);			
	return addHelp(addHelp(addHelp(addHelp(ratio1,ratio2),ratio3),ratio4),*this);
}
Ratio Ratio::addHelp(Ratio r1, Ratio r2) const{
	long topp = r1.top*r2.bottom + r2.top*r1.bottom;
	long botttom = r1.bottom*r2.bottom;
	return Ratio(topp,botttom);
}
Ratio Ratio::subtract(Ratio r) const{
	r.numerator(r.numerator()*-1);
	return addHelp(*this,r);
}
Ratio Ratio::multiply(Ratio r) const{
	long topp = top*r.top;
	long botttom = bottom*r.bottom;
	return Ratio(topp, botttom);
}
Ratio Ratio::divide(Ratio r) const{
	long topp = top*r.bottom;
	long botttom = bottom*r.top;
	return Ratio(topp, botttom);
}
int Ratio::compare(Ratio r) const{
	if(ratio() < r.ratio()){return -1;}
	if(ratio() > r.ratio()){return 1;}
	return 0;
}
int Ratio::compare(long double r) const{	
	if(ratio() < r){return -1;}
	if(ratio() > r){return 1;}
	return 0;
}
void Ratio::normalize(){
	if(top < 0 && bottom < 0){
		top = -1*top;
		bottom = -1*bottom;
	}
	if(bottom < 0){
		top = -1*top;
		bottom = -1*bottom;	
	}
	long div = gcd(top, bottom);
	top = top/div;
	bottom = bottom/div;	
}
ostream& operator<<(ostream& oStrm, const Ratio& rat){
	oStrm << rat.numerator() << '/' << rat.denominator();
	return oStrm;
}
istream& operator>>(istream& iStrm, Ratio& rat){
	long numer;
	if(!(iStrm >> numer)){
		iStrm.setstate(ios_base::failbit);
		return iStrm;
	}
	char slash;
	if(!(iStrm >> slash)){
		iStrm.setstate(ios_base::failbit);
		return iStrm;
	}
	if(slash != '/'){
		iStrm.setstate(ios_base::failbit);
		return iStrm;
	}
	long denom;
	if(!(iStrm >> denom)){
		iStrm.setstate(ios_base::failbit);
		return iStrm;
	}

	Ratio result(numer, denom);
	rat = result;
	return iStrm;
}
