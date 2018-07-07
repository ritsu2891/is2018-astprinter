/*  Token Printer, version 0.2  */

/*  Provides a means for visualizing tokens and improves debugging efficiency.
    (c) 2018, Ritsuki KOKUBO
*/

#include "TokenPrinter.h"

int yydebug = 0;

void printToken(int tok) {
  char* sort;
  switch (tok) {
    case NUM:
      fprintf(stderr, "%s, %d\n", tokenSort(tok), yylval.ival);
      break;
    case ID:
      fprintf(stderr, "%s, %s\n", tokenSort(tok), yylval.name);
      break;
    default:
      if ((sort = tokenSort(tok)) != NULL) {
        fprintf(stderr, "%s\n", sort);
      } else {
        fprintf(stderr, "%c\n", tok);
      }
      break;
  }
}

char* tokenSort(int tok) {
  switch (tok) {
    case NUM:
      return "NUM";
      break;
    case ID:
      return "ID";
      break;
    case ASSIGN:
      return "ASSIGN =";
      break;
    case LOR:
      return "LOR ||";
      break;
    case LAND:
      return "LAND &&";
      break;
    case BLT:
      return "BLT <";
      break;
    case BEQ:
      return "BEQ ==";
      break;
    case BNE:
      return "BNE !=";
      break;
    case ADD:
      return "ADD +";
      break;
    case SUB:
      return "SUB -";
      break;
    case MUL:
      return "MUL *";
      break;
    case DIV:
      return "DIV /";
      break;
    case MOD:
      return "MOD %";
      break;
    case NOT:
      return "NOT !";
      break;
    case IF:
      return "IF";
      break;
    case ELSE:
      return "ELSE";
      break;
    case WHILE:
      return "WHILE";
      break;
    case RETURN:
      return "RETURN";
      break;
    case TINT:
      return "TINT";
      break;
    default:
      return NULL;
      break;
  }
}