/*  AST (Abstract Syntax Tree) Printer, version 0.2  */

/*  Provides a means for visualizing nodes and symbol tables of abstract syntax trees and improves debugging efficiency.
    (c) 2018, Ritsuki KOKUBO
*/

#include "ASTPrinter.h"

/*-------------.
| Node Printer |
`--------------*/

// Symbol
void printSym(SymEntryPtr s) {
  if (s == NULL) {
    return;
  }

  char* sort = malloc(sizeof(char)*10);

  switch(s->sort) {
    case SYM_VAR:
      strcpy(sort, "SYM_VAR");
      break;
    case SYM_PARAM:
      strcpy(sort, "SYM_PARAM");
      break;
    case SYM_FUNC:
      strcpy(sort, "SYM_FUNC");
      break;
    case SYM_GLOBAL:
      strcpy(sort, "SYM_GLOBAL");
      break;
    default:
      strcpy(sort, "Unknown");
  }

  fprintf(stderr, "SymEntry@%p [prev:%p, sort:%s, name:%s, no:%d, nParam:%d, nVar:%d, belong: %p]\n", s, s->prev, sort, s->name, s->no, s->nParam, s->nVar, s->belong);
}

// Expression
void printExpr(ExprNodePtr e) {
  if (e == NULL) {
    return;
  }

  char* op = malloc(sizeof(char)*10);

  switch(e->op) {
    case OP_CONST:
      strcpy(op, "OP_CONST");
      break;
    case OP_UM:
      strcpy(op, "OP_UM");
      break;
    case OP_NOT:
      strcpy(op, "OP_NOT");
      break;
    case OP_BNOT:
      strcpy(op, "OP_BNOT");
      break;
    case OP_LSHIFT:
      strcpy(op, "OP_LSHIFT");
      break;
    case OP_RSHIFT:
      strcpy(op, "OP_RSHIFT");
      break;
    case OP_VAR:
      strcpy(op, "OP_VAR");
      break;
    case OP_ADD:
      strcpy(op, "OP_ADD");
      break;
    case OP_SUB:
      strcpy(op, "OP_SUB");
      break;
    case OP_BOR:
      strcpy(op, "OP_BOR");
      break;
    case OP_BAND:
      strcpy(op, "OP_BAND");
      break;
    case OP_BXOR:
      strcpy(op, "OP_BXOR");
      break;
    case OP_BLT:
      strcpy(op, "OP_BLT");
      break;
    case OP_BEQ:
      strcpy(op, "OP_BEQ");
      break;
    case OP_BNE:
      strcpy(op, "OP_BNE");
      break;
    case OP_MUL:
      strcpy(op, "OP_MUL");
      break;
    case OP_DIV:
      strcpy(op, "OP_DIV");
      break;
    case OP_MOD:
      strcpy(op, "OP_MOD");
      break;
    case OP_LOR:
      strcpy(op, "OP_LOR");
      break;
    case OP_LAND:
      strcpy(op, "OP_LAND");
      break;
    case OP_INC:
      strcpy(op, "OP_INC");
      break;
    case OP_DEC:
      strcpy(op, "OP_DEC");
      break;
    case OP_ASSIGN:
      strcpy(op, "OP_ASSIGN");
      break;
    case OP_FUNCALL:
      strcpy(op, "OP_FUNCALL");
      break;
    case OP_ALIST:
      strcpy(op, "OP_ALIST");
      break;
    default:
      strcpy(op, "Unknown");
  }

  fprintf(stderr, "ExprNode@%p [op:%s, val:%d, sym:%p, left:%p, right:%p]\n", e, op, e->val, e->sym, e->sub1, e->sub2);
}

// Statement
void printStmt(StmtNodePtr s) {
  if (s == NULL) {
    return;
  }

  char *sort = malloc(sizeof(char)*11);
  switch(s->sort) {
    case STMT_EXPR:
      strcpy(sort, "STMT_EXPR");
      break;
    case STMT_IF:
      strcpy(sort, "STMT_IF");
      break;
    case STMT_WHILE:
      strcpy(sort, "STMT_WHILE");
      break;
    case STMT_RETURN:
      strcpy(sort, "STMT_RETURN");
      break;
    default:
      strcpy(sort, "Unknown");
      break;
  }

  fprintf(stderr, "StmtNode@%p [sort:%s, next:%p, expr:%p, st1:%p, st2:%p]\n", s, sort, s->next, s->expr, s->st1, s->st2);
}

// Definition
void printDef(DefNodePtr d) {
  if (d == NULL) {
    return;
  }

  char *sort = malloc(sizeof(char)*10);
  switch(d->sort) {
    case DEF_FUNC:
      strcpy(sort, "DEF_FUNC");
      break;
    case DEF_GLOBAL:
      strcpy(sort, "DEF_GLOBAL");
      break;
    case PROTOTYPE:
      strcpy(sort, "PROTOTYPE");
      break;
    default:
      strcpy(sort, "Unknwon");
      break;
  }

  fprintf(stderr, "DefNode@%p [sort:%s, sym:%p, next:%p, body:%p]\n", d, sort, d->sym, d->next, d->body);
}

/*-------------.
| Tree Printer |
`--------------*/

// Print Offset Spaces (Represent a hierarchy)
void printOffsetSpace(int offset) {
  int o;
  o = offset;
  while(o-- > 0) {
    fprintf(stderr, " ");
  }
}

// Expression Tree (Expression with its member)
void printExprTree(ExprNodePtr e, int offset) {
  if (e == NULL) {
    return;
  }
  printOffsetSpace(offset);
  printExpr(e);

  if (e->sym != NULL) {
    printOffsetSpace(offset+2);
    printSym(e->sym);
  }

  printExprTree(e->sub1, offset+2);
  printExprTree(e->sub2, offset+2);

}

// Statement Tree (Statement -> Expression)
void printStmtTree(StmtNodePtr s, int offset) {
  StmtNodePtr stmt_p = NULL;
  if (s == NULL) {
    return;
  }
  stmt_p = s;
  while(stmt_p != NULL) {
    printOffsetSpace(offset);
    printStmt(stmt_p);

    printExprTree(stmt_p->expr, offset+2);

    printStmtTree(stmt_p->st1, offset+2);

    printStmtTree(stmt_p->st2, offset+2);

    stmt_p = stmt_p->next;
  }
}

// # USE THIS
// Definition Tree (Definition -> Statement -> Expression)
void printDefTree(DefNodePtr d) {
  DefNodePtr def_p = d;

  fprintf(stderr, "[AST]\n");

  while(def_p != NULL) {
    printDef(def_p);

    printOffsetSpace(2);
    printSym(def_p->sym);

    printStmtTree(def_p->body, 2);

    def_p = def_p->next;
  }
}

/*---------------------.
| Symbol Table Printer |
`----------------------*/

// Symbol Table
// Note: Print From LAST to HEAD
void printSymTable() {
  fprintf(stderr, "[Symbol Table]\n");
  SymEntryPtr sym_p = symtable;
  while (sym_p != NULL) {
    printSym(sym_p);
    sym_p = sym_p->prev;
  }
}

// Global Pointers
void printGlobalASTPointers() {
  fprintf(stderr, "symtable:   %p\n", symtable);
  fprintf(stderr, "curfunc:    %p\n", curfunc);
  fprintf(stderr, "sourcedefs: %p\n", sourcedefs);
}