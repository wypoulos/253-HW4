//Wow its ratio.h

#ifndef ratio_included
#define ratio_included
#include <iostream>

class Ratio{
	long top;
	long bottom;
	public:
		Ratio(long numerator, long denominator = 1);
		Ratio(int numerator, int denominator = 1);
		Ratio(const Ratio&) = default;
		Ratio& operator=(const Ratio&) = default;
		~Ratio() = default;
		long numerator() const;
		void numerator(long numerator);
		long denominator() const;
		void denominator(long denominator);
		long double ratio() const;
		Ratio add(Ratio r1, Ratio r2 = Ratio(0,1), Ratio r3 = Ratio(0,1), Ratio r4 = Ratio(0,1), Ratio r5 = Ratio(0,1), Ratio r6 = Ratio(0,1), Ratio r7 = Ratio(0,1), Ratio r8 = Ratio(0,1)) const;
		Ratio subtract(Ratio r) const;
		Ratio multiply(Ratio r) const;
		Ratio divide(Ratio r) const;
		int compare(Ratio r) const;
		int compare(long double r) const;
		Ratio addHelp(Ratio r1, Ratio r2) const;
		void normalize();
};

std::ostream& operator<<(std::ostream& oStrm, const Ratio& rat);
std::istream& operator>>(std::istream& iStrm, Ratio& rat);

#endif
