/**
 * @brief   [PrintStream library](https://github.com/tttapa/Arduino-PrintStream/blob/6a9e0d365be0b3d84187daa2a8a7bda8d541472e/src/PrintStream.h)
 */

#ifndef PrintStream_h
#define PrintStream_h

#include<AH/Settings/NamespaceSettings.hpp>
#include <AH/Settings/Warnings.hpp>
AH_DIAGNOSTIC_WERROR() // Enable errors on warnings

AH_DIAGNOSTIC_EXTERNAL_HEADER()
#include <AH/Arduino-Wrapper.h> // Print
AH_DIAGNOSTIC_POP()

BEGIN_AH_NAMESPACE

#ifdef ARDUINO_API_VERSION
using arduino::Print;
#endif

/// @addtogroup  AH_PrintStream
/// @{

typedef Print &manipulator(Print &);

Print &endl(Print &printer);
Print &flush(Print &printer);
Print &hex(Print &printer);
Print &bin(Print &printer);
Print &dec(Print &printer);
/* Print &oct(Print &printer); */
Print &boolalpha(Print &printer);
Print &noboolalpha(Print &printer);
Print &leadingzeros(Print &printer);
Print &noleadingzeros(Print &printer);
Print &uppercase(Print &printer);
Print &nouppercase(Print &printer);
Print &showbase(Print &printer);
Print &noshowbase(Print &printer);

Print &operator<<(Print &printer, const __FlashStringHelper *s);
#ifdef ARDUINO
Print &operator<<(Print &printer, const String &s);
#endif
Print &operator<<(Print &printer, const char s[]);
Print &operator<<(Print &printer, char c);
Print &operator<<(Print &printer, unsigned char c);
Print &operator<<(Print &printer, int i);
Print &operator<<(Print &printer, unsigned int i);
Print &operator<<(Print &printer, int8_t i);
Print &operator<<(Print &printer, long i);
Print &operator<<(Print &printer, unsigned long i);
Print &operator<<(Print &printer, double d);
Print &operator<<(Print &printer, const Printable &p);
Print &operator<<(Print &printer, bool b);

Print &operator<<(Print &printer, manipulator pf);

struct Setbase {
    uint8_t M_base;
};
Setbase setbase(uint8_t base);
Print &operator<<(Print &printer, Setbase f);

struct Setprecision {
    int M_n;
};
Setprecision setprecision(int n);
Print &operator<<(Print &printer, Setprecision f);

struct Setbytesep {
    char M_bytesep;
};
Setbytesep setbytesep(char bytesep);
Print &operator<<(Print &printer, Setbytesep f);

/// @}

#ifndef ARDUINO

#include <iomanip>
#include <iostream>

// TODO: check conflicts between Arduino version and C++ STL version
using std::endl;
// using std::setbase;
// using std::setprecision;
using std::boolalpha;
using std::dec;
using std::flush;
using std::hex;
using std::noboolalpha;
using std::noshowbase;
using std::nouppercase;
using std::showbase;
using std::uppercase;

inline std::ostream &operator<<(std::ostream &os, uint8_t u) {
    // I'm lazy, I should probably implement one for uint8_t to get the leading
    // zeros right
    return os << static_cast<unsigned short>(u);
}

inline std::ostream &operator<<(std::ostream &os,
                                const __FlashStringHelper *s) {
    return os << reinterpret_cast<const char *>(s);
}

#endif

END_AH_NAMESPACE

AH_DIAGNOSTIC_POP()

#include <Settings/NamespaceSettings.hpp>

BEGIN_CS_NAMESPACE
using AH::operator<<;
using AH::manipulator;
using AH::endl;
using AH::flush;
using AH::hex;
using AH::bin;
using AH::dec;
using AH::boolalpha;
using AH::noboolalpha;
using AH::leadingzeros;
using AH::noleadingzeros;
using AH::uppercase;
using AH::nouppercase;
using AH::showbase;
using AH::noshowbase;
using AH::setbase;
using AH::setprecision;
using AH::setbytesep;
END_CS_NAMESPACE

#endif // PrintStream_h