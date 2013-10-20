#ifndef UTILITIES_H
#define UTILITIES_H

#include <wx\string.h>

wxString int_to_string(int a);
void Log(const char*);
void Log(const wchar_t*);
void Log(bool);

#endif // UTILITIES_H
