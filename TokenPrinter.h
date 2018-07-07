/*  Token Printer, version 0.2  */

/*  Provides a means for visualizing tokens and improves debugging efficiency.
    (c) 2018, Ritsuki KOKUBO
*/

#ifndef TOKENPRINTER
#define TOKENPRINTER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AST.h"
#include "Parser.tab.h"

void printToken(int tok);
char* tokenSort(int tok);

#endif