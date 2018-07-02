/*  AST (Abstract Syntax Tree) Printer, version 0.1  */

/*  Provides a means for visualizing nodes and symbol tables of abstract syntax trees and improves debugging efficiency.
    (c) 2018, Ritsuki KOKUBO
*/

#ifndef ASTPRINTER
#define ASTPRINTER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ast.h"

/*-----------------.
| Define Variables |
`------------------*/
extern SymEntryPtr  symtable;                   // The tail pointer of Symbol Tree
extern SymEntryPtr  curfunc;                    // The symbol that program parse now
extern DefNodePtr   sourcedefs;                 // The head pointer of def node

/*-------------.
| Node Printer |
`--------------*/
void printSym(SymEntryPtr s);                   // Symbol
void printExpr(ExprNodePtr e);                  // Expression
void printStmt(StmtNodePtr s);                  // Statement
void printDef(DefNodePtr d);                    // Definition

/*-------------.
| Tree Printer |
`--------------*/
void printOffsetSpace(int offset);              // Print Offset Spaces
void printExprTree(ExprNodePtr e, int offset);  // Expression Tree
void printStmtTree(StmtNodePtr s, int offset);  // Statement Tree
void printDefTree(DefNodePtr d);                // Definition Tree

/*---------------------.
| Symbol Table Printer |
`----------------------*/
void printSymTable();                            // Symbol Table
void printGlobalASTPointers();                   // Global Pointers

#endif