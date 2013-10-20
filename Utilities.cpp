#include "Utilities.hpp"
#include <sdk.h>

wxString int_to_string(int a) {
	bool negative = false;
	if (a < 0) {
		negative = true;
		a = -a;
	}

	int digits = 0;// Count digits
	for (int t = a; t > 0; t/=10) {
		digits++;
	}
	if (!digits)// In case of int is zero, it's still one digit
		digits++;

	char num[digits+1+negative]; // Char array and null terminator
	num[digits+negative] = '\0';
	if (negative)
		num[0] = '-';
	for (int i = 0; i < digits; i++) { // Fills the array
		int divider = 1; // Divider algorithm since I can't do a 10 in the power of 'i'
		for (int j = 0; j < i; j++)
			divider *= 10;
		num[digits-1-i+negative] = a/divider%10+48;
		// a is divided with the calculated divider,
		// eleminates numbers on the right side, where the modulus 10
		// removes all numbers from the tenths and upward, leaving a single desired number.
		// add 48 on top of it, to allign the number with the ASCII character scheme.
	}
	return wxString::FromUTF8(num); // Feed to new string and return;
}

void Log(const char* a) {
	Manager::Get()->GetLogManager()->Log(wxString::FromUTF8(a));
}

void Log(const wchar_t* a) {
	Manager::Get()->GetLogManager()->Log(a);
}

void Log(bool a) {
	if (a)
		Manager::Get()->GetLogManager()->Log(wxString::FromUTF8("true"));
	else
		Manager::Get()->GetLogManager()->Log(wxString::FromUTF8("false"));
}
