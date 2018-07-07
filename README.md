# is2018-astprinter

　応用実験第三部コンパイラ作成実験の構文解析器の作成（第4章）では**抽象構文木および記号表の状態の確認**が，字句解析器の作成（第3章）では**出力されたトークン列の把握**が重要になります．

　そこで，それらを把握しやすくするように可視化する関数群を作成しました．作るのが面倒だと思うのでここで共有しておきます．

## 抽象構文木および記号表
　ASTPrinter.cを使って下さい．

### 更新履歴
| 日付 | 内容 |
| ---- | ---- |
| 2018/7/2 | 作成 |
| 2018/7/8 | 余分なラベルを削除して表示をコンパクトにしました |

### 使用例

~~~~
// プログラム
// ここまでで構文解析器により抽象構文木や記号表が作成されています．

fprintf(stderr, "============================\n");
printGlobalASTPointers();

fprintf(stderr, "============================\n");
printSymTable();

fprintf(stderr, "============================\n");
printDefTree(sourcedefs);
~~~~

~~~~
// 出力
============================
symtable:   0x7f81f7d00690
curfunc:    0x7f81f7d00620
sourcedefs: 0x7f81f7c027d0
============================
[Symbol Table]
SymEntry@0x7f81f7d00690 [prev:0x7f81f7d00620, sort:SYM_VAR, name:v, no:1, nParam:0, nVar:0, belong: 0x7f81f7d00620]
SymEntry@0x7f81f7d00620 [prev:0x7f81f7d00120, sort:SYM_FUNC, name:main, no:4, nParam:0, nVar:1, belong: 0x0]
SymEntry@0x7f81f7d00120 [prev:0x7f81f7d000d0, sort:SYM_PARAM, name:k, no:1, nParam:0, nVar:0, belong: 0x7f81f7d000d0]
SymEntry@0x7f81f7d000d0 [prev:0x7f81f7d00020, sort:SYM_FUNC, name:fib, no:3, nParam:1, nVar:0, belong: 0x0]
SymEntry@0x7f81f7d00020 [prev:0x7f81f7c02840, sort:SYM_PARAM, name:x, no:1, nParam:0, nVar:0, belong: 0x7f81f7c02840]
SymEntry@0x7f81f7c02840 [prev:0x7f81f7c02770, sort:SYM_FUNC, name:out, no:2, nParam:1, nVar:0, belong: 0x0]
SymEntry@0x7f81f7c02770 [prev:0x0, sort:SYM_FUNC, name:in, no:1, nParam:0, nVar:0, belong: 0x0]
============================
[AST]
DefNode@0x7fe34ad00050 [sort:PROTOTYPE, sym:0x7fe34ad00010, next:0x7fe34ad00140, body:0x0]
  SymEntry@0x7fe34ad00010 [prev:0x0, sort:SYM_FUNC, name:in, no:1, nParam:0, nVar:0, belong: 0x0]
DefNode@0x7fe34ad00140 [sort:PROTOTYPE, sym:0x7fe34ad00080, next:0x7fe34ad00480, body:0x0]
  SymEntry@0x7fe34ad00080 [prev:0x7fe34ad00010, sort:SYM_FUNC, name:out, no:2, nParam:1, nVar:0, belong: 0x0]
DefNode@0x7fe34ad00480 [sort:DEF_FUNC, sym:0x7fe34ad000e0, next:0x7fe34ad00640, body:0x7fe34ae00050]
  SymEntry@0x7fe34ad000e0 [prev:0x7fe34ad00080, sort:SYM_FUNC, name:fib, no:3, nParam:1, nVar:0, belong: 0x0]
  StmtNode@0x7fe34ae00050 [sort:STMT_IF, next:0x7fe34ad00430, expr:0x7fe34ad00270, st1:0x7fe34ae00020, st2:0x0]
    ExprNode@0x7fe34ad00270 [op:OP_BLT, val:0, sym:0x0, left:0x7fe34ad00230, right:0x7fe34ad00250]
      ExprNode@0x7fe34ad00230 [op:OP_VAR, val:0, sym:0x7fe34ad001b0, left:0x0, right:0x0]
        SymEntry@0x7fe34ad001b0 [prev:0x7fe34ad000e0, sort:SYM_PARAM, name:k, no:1, nParam:0, nVar:0, belong: 0x7fe34ad000e0]
      ExprNode@0x7fe34ad00250 [op:OP_CONST, val:2, sym:0x0, left:0x0, right:0x0]
    StmtNode@0x7fe34ae00020 [sort:STMT_RETURN, next:0x0, expr:0x7fe34ae00000, st1:0x0, st2:0x0]
      ExprNode@0x7fe34ae00000 [op:OP_CONST, val:1, sym:0x0, left:0x0, right:0x0]
  StmtNode@0x7fe34ad00430 [sort:STMT_RETURN, next:0x0, expr:0x7fe34ad00410, st1:0x0, st2:0x0]
    ExprNode@0x7fe34ad00410 [op:OP_ADD, val:0, sym:0x0, left:0x7fe34ad00330, right:0x7fe34ad003f0]
      ExprNode@0x7fe34ad00330 [op:OP_FUNCALL, val:0, sym:0x7fe34ad000e0, left:0x7fe34ad00310, right:0x0]
        SymEntry@0x7fe34ad000e0 [prev:0x7fe34ad00080, sort:SYM_FUNC, name:fib, no:3, nParam:1, nVar:0, belong: 0x0]
        ExprNode@0x7fe34ad00310 [op:OP_ALIST, val:0, sym:0x0, left:0x7fe34ad002f0, right:0x0]
          ExprNode@0x7fe34ad002f0 [op:OP_SUB, val:0, sym:0x0, left:0x7fe34ad002b0, right:0x7fe34ad002d0]
            ExprNode@0x7fe34ad002b0 [op:OP_VAR, val:0, sym:0x7fe34ad001b0, left:0x0, right:0x0]
              SymEntry@0x7fe34ad001b0 [prev:0x7fe34ad000e0, sort:SYM_PARAM, name:k, no:1, nParam:0, nVar:0, belong: 0x7fe34ad000e0]
            ExprNode@0x7fe34ad002d0 [op:OP_CONST, val:2, sym:0x0, left:0x0, right:0x0]
      ExprNode@0x7fe34ad003f0 [op:OP_FUNCALL, val:0, sym:0x7fe34ad000e0, left:0x7fe34ad003d0, right:0x0]
        SymEntry@0x7fe34ad000e0 [prev:0x7fe34ad00080, sort:SYM_FUNC, name:fib, no:3, nParam:1, nVar:0, belong: 0x0]
        ExprNode@0x7fe34ad003d0 [op:OP_ALIST, val:0, sym:0x0, left:0x7fe34ad003b0, right:0x0]
          ExprNode@0x7fe34ad003b0 [op:OP_SUB, val:0, sym:0x0, left:0x7fe34ad00370, right:0x7fe34ad00390]
            ExprNode@0x7fe34ad00370 [op:OP_VAR, val:0, sym:0x7fe34ad001b0, left:0x0, right:0x0]
              SymEntry@0x7fe34ad001b0 [prev:0x7fe34ad000e0, sort:SYM_PARAM, name:k, no:1, nParam:0, nVar:0, belong: 0x7fe34ad000e0]
            ExprNode@0x7fe34ad00390 [op:OP_CONST, val:1, sym:0x0, left:0x0, right:0x0]
DefNode@0x7fe34ad00640 [sort:DEF_FUNC, sym:0x7fe34ad004b0, next:0x0, body:0x7fe34ae00180]
  SymEntry@0x7fe34ad004b0 [prev:0x7fe34ad001b0, sort:SYM_FUNC, name:main, no:4, nParam:0, nVar:1, belong: 0x0]
  StmtNode@0x7fe34ae00180 [sort:STMT_EXPR, next:0x7fe34ad00570, expr:0x7fe34ae00160, st1:0x0, st2:0x0]
    ExprNode@0x7fe34ae00160 [op:OP_ASSIGN, val:0, sym:0x7fe34ae00090, left:0x7fe34ae00140, right:0x0]
      SymEntry@0x7fe34ae00090 [prev:0x7fe34ad004b0, sort:SYM_VAR, name:v, no:1, nParam:0, nVar:0, belong: 0x7fe34ad004b0]
      ExprNode@0x7fe34ae00140 [op:OP_FUNCALL, val:0, sym:0x7fe34ad00010, left:0x0, right:0x0]
        SymEntry@0x7fe34ad00010 [prev:0x0, sort:SYM_FUNC, name:in, no:1, nParam:0, nVar:0, belong: 0x0]
  StmtNode@0x7fe34ad00570 [sort:STMT_EXPR, next:0x7fe34ad005e0, expr:0x7fe34ad00550, st1:0x0, st2:0x0]
    ExprNode@0x7fe34ad00550 [op:OP_FUNCALL, val:0, sym:0x7fe34ad00080, left:0x7fe34ad00530, right:0x0]
      SymEntry@0x7fe34ad00080 [prev:0x7fe34ad00010, sort:SYM_FUNC, name:out, no:2, nParam:1, nVar:0, belong: 0x0]
      ExprNode@0x7fe34ad00530 [op:OP_ALIST, val:0, sym:0x0, left:0x7fe34ae00220, right:0x0]
        ExprNode@0x7fe34ae00220 [op:OP_FUNCALL, val:0, sym:0x7fe34ad000e0, left:0x7fe34ae00200, right:0x0]
          SymEntry@0x7fe34ad000e0 [prev:0x7fe34ad00080, sort:SYM_FUNC, name:fib, no:3, nParam:1, nVar:0, belong: 0x0]
          ExprNode@0x7fe34ae00200 [op:OP_ALIST, val:0, sym:0x0, left:0x7fe34ae001e0, right:0x0]
            ExprNode@0x7fe34ae001e0 [op:OP_VAR, val:0, sym:0x7fe34ae00090, left:0x0, right:0x0]
              SymEntry@0x7fe34ae00090 [prev:0x7fe34ad004b0, sort:SYM_VAR, name:v, no:1, nParam:0, nVar:0, belong: 0x7fe34ad004b0]
  StmtNode@0x7fe34ad005e0 [sort:STMT_RETURN, next:0x0, expr:0x7fe34ad005c0, st1:0x0, st2:0x0]
    ExprNode@0x7fe34ad005c0 [op:OP_CONST, val:0, sym:0x0, left:0x0, right:0x0]
~~~~

## トークン
　TokenPrinter.cを使って下さい．

### 更新履歴
| 日付 | 内容 |
| ---- | ---- |
| 2018/7/8 | 作成 |

### 使用例
~~~
int tok;
tok = yylex();
while (tok) {
  if (tok < 128) {
    printf("CHAR: %c\n", tok);
  } else {
    printToken(tok);
  }
  tok = yylex();
}
~~~
~~~
TINT
ID, in
TINT
ID, out
TINT
ID, v
TINT
ID, fib
TINT
ID, k
IF
ID, k
TWO OP
NUM, 2
RETURN
NUM, 1
RETURN
ID, fib
ID, k

NUM, 2
TWO OP
ID, fib
ID, k

NUM, 1
TINT
ID, main
TINT
ID, v
ID, v
ASSIGN =
ID, in
ID, out
ID, fib
ID, v
RETURN
NUM, 0
~~~
