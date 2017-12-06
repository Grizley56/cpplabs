#include "BustException.h"



BustException::BustException() : std::exception() { }

BustException::BustException(const char* const str) : std::exception(str) { }

BustException::~BustException() { }
