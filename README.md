# is2018-astprinter

応用実験第三部コンパイラ作成実験の構文解析器（第三章）では**抽象構文木および記号表の状態の確認**が重要になります．
いちいちyaccのアクション部とかで出力していると出力方法に統一感が無くなってきてコードが煩雑になってきたので，抽象構文木および記号表の状態を可視化する関数群を作成しました．記号，抽象構文木のノード，最上位定義のノード単体の情報の出力およびそれらを使って抽象構文木の階層的な表示および記号表の表示を行う関数を作成しました．とりあえず説明はここまでにしておきます．質問があったら追記する予定です．

## 使用例
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
[Def]
DefNode@0x7f81f7c027d0 [sort:DEF_FUNC, sym:0x7f81f7c02770, next:0x7f81f7d00080, body:0x0]
  [Symbol]
  SymEntry@0x7f81f7c02770 [prev:0x0, sort:SYM_FUNC, name:in, no:1, nParam:0, nVar:0, belong: 0x0]
  (NULL)
[Def]
DefNode@0x7f81f7d00080 [sort:DEF_FUNC, sym:0x7f81f7c02840, next:0x7f81f7d005d0, body:0x0]
  [Symbol]
  SymEntry@0x7f81f7c02840 [prev:0x7f81f7c02770, sort:SYM_FUNC, name:out, no:2, nParam:1, nVar:0, belong: 0x0]
  (NULL)
[Def]
DefNode@0x7f81f7d005d0 [sort:DEF_FUNC, sym:0x7f81f7d000d0, next:0x7f81f7d009e0, body:0x7f81f7d002e0]
  [Symbol]
  SymEntry@0x7f81f7d000d0 [prev:0x7f81f7d00020, sort:SYM_FUNC, name:fib, no:3, nParam:1, nVar:0, belong: 0x0]
  [Statement]
  StmtNode@0x7f81f7d002e0 [sort:STMT_IF, next:0x7f81f7d00560, expr:0x7f81f7d00210, st1:0x7f81f7d00290, st2:0x0]
    [Expression]
    ExprNode@0x7f81f7d00210 [op:OP_BLT, val:0, sym:0x0, left:0x7f81f7d001b0, right:0x7f81f7d001e0]
    [Sym]
    (NULL)
      [Expression]
      ExprNode@0x7f81f7d001b0 [op:OP_VAR, val:0, sym:0x7f81f7d00120, left:0x0, right:0x0]
      [Sym]
      SymEntry@0x7f81f7d00120 [prev:0x7f81f7d000d0, sort:SYM_PARAM, name:k, no:1, nParam:0, nVar:0, belong: 0x7f81f7d000d0]
        (NULL)
        (NULL)
      [Expression]
      ExprNode@0x7f81f7d001e0 [op:OP_CONST, val:2, sym:0x0, left:0x0, right:0x0]
      [Sym]
      (NULL)
        (NULL)
        (NULL)
    [St1]
    [Statement]
    StmtNode@0x7f81f7d00290 [sort:STMT_RETURN, next:0x0, expr:0x7f81f7d00260, st1:0x0, st2:0x0]
      [Expression]
      ExprNode@0x7f81f7d00260 [op:OP_CONST, val:1, sym:0x0, left:0x0, right:0x0]
      [Sym]
      (NULL)
        (NULL)
        (NULL)
      [St1]
      (NULL)
      [St2]
      (NULL)
    [St2]
    (NULL)
  StmtNode@0x7f81f7d00560 [sort:STMT_RETURN, next:0x0, expr:0x7f81f7d00540, st1:0x0, st2:0x0]
    [Expression]
    ExprNode@0x7f81f7d00540 [op:OP_ADD, val:0, sym:0x0, left:0x7f81f7d00400, right:0x7f81f7d00510]
    [Sym]
    (NULL)
      [Expression]
      ExprNode@0x7f81f7d00400 [op:OP_FUNCALL, val:0, sym:0x7f81f7d000d0, left:0x7f81f7d003e0, right:0x0]
      [Sym]
      SymEntry@0x7f81f7d000d0 [prev:0x7f81f7d00020, sort:SYM_FUNC, name:fib, no:3, nParam:1, nVar:0, belong: 0x0]
        [Expression]
        ExprNode@0x7f81f7d003e0 [op:OP_ALIST, val:0, sym:0x0, left:0x7f81f7d003c0, right:0x0]
        [Sym]
        (NULL)
          [Expression]
          ExprNode@0x7f81f7d003c0 [op:OP_SUB, val:0, sym:0x0, left:0x7f81f7d00360, right:0x7f81f7d00390]
          [Sym]
          (NULL)
            [Expression]
            ExprNode@0x7f81f7d00360 [op:OP_VAR, val:0, sym:0x7f81f7d00120, left:0x0, right:0x0]
            [Sym]
            SymEntry@0x7f81f7d00120 [prev:0x7f81f7d000d0, sort:SYM_PARAM, name:k, no:1, nParam:0, nVar:0, belong: 0x7f81f7d000d0]
              (NULL)
              (NULL)
            [Expression]
            ExprNode@0x7f81f7d00390 [op:OP_CONST, val:2, sym:0x0, left:0x0, right:0x0]
            [Sym]
            (NULL)
              (NULL)
              (NULL)
          (NULL)
        (NULL)
      [Expression]
      ExprNode@0x7f81f7d00510 [op:OP_FUNCALL, val:0, sym:0x7f81f7d000d0, left:0x7f81f7d004f0, right:0x0]
      [Sym]
      SymEntry@0x7f81f7d000d0 [prev:0x7f81f7d00020, sort:SYM_FUNC, name:fib, no:3, nParam:1, nVar:0, belong: 0x0]
        [Expression]
        ExprNode@0x7f81f7d004f0 [op:OP_ALIST, val:0, sym:0x0, left:0x7f81f7d004d0, right:0x0]
        [Sym]
        (NULL)
          [Expression]
          ExprNode@0x7f81f7d004d0 [op:OP_SUB, val:0, sym:0x0, left:0x7f81f7d00470, right:0x7f81f7d004a0]
          [Sym]
          (NULL)
            [Expression]
            ExprNode@0x7f81f7d00470 [op:OP_VAR, val:0, sym:0x7f81f7d00120, left:0x0, right:0x0]
            [Sym]
            SymEntry@0x7f81f7d00120 [prev:0x7f81f7d000d0, sort:SYM_PARAM, name:k, no:1, nParam:0, nVar:0, belong: 0x7f81f7d000d0]
              (NULL)
              (NULL)
            [Expression]
            ExprNode@0x7f81f7d004a0 [op:OP_CONST, val:1, sym:0x0, left:0x0, right:0x0]
            [Sym]
            (NULL)
              (NULL)
              (NULL)
          (NULL)
        (NULL)
    [St1]
    (NULL)
    [St2]
    (NULL)
[Def]
DefNode@0x7f81f7d009e0 [sort:DEF_FUNC, sym:0x7f81f7d00620, next:0x0, body:0x7f81f7d00770]
  [Symbol]
  SymEntry@0x7f81f7d00620 [prev:0x7f81f7d00120, sort:SYM_FUNC, name:main, no:4, nParam:0, nVar:1, belong: 0x0]
  [Statement]
  StmtNode@0x7f81f7d00770 [sort:STMT_EXPR, next:0x7f81f7d008c0, expr:0x7f81f7d00750, st1:0x0, st2:0x0]
    [Expression]
    ExprNode@0x7f81f7d00750 [op:OP_ASSIGN, val:0, sym:0x7f81f7d00690, left:0x7f81f7d00720, right:0x0]
    [Sym]
    SymEntry@0x7f81f7d00690 [prev:0x7f81f7d00620, sort:SYM_VAR, name:v, no:1, nParam:0, nVar:0, belong: 0x7f81f7d00620]
      [Expression]
      ExprNode@0x7f81f7d00720 [op:OP_FUNCALL, val:0, sym:0x7f81f7c02770, left:0x0, right:0x0]
      [Sym]
      SymEntry@0x7f81f7c02770 [prev:0x0, sort:SYM_FUNC, name:in, no:1, nParam:0, nVar:0, belong: 0x0]
        (NULL)
        (NULL)
      (NULL)
    [St1]
    (NULL)
    [St2]
    (NULL)
  StmtNode@0x7f81f7d008c0 [sort:STMT_EXPR, next:0x7f81f7d00960, expr:0x7f81f7d00890, st1:0x0, st2:0x0]
    [Expression]
    ExprNode@0x7f81f7d00890 [op:OP_FUNCALL, val:0, sym:0x7f81f7c02840, left:0x7f81f7d00870, right:0x0]
    [Sym]
    SymEntry@0x7f81f7c02840 [prev:0x7f81f7c02770, sort:SYM_FUNC, name:out, no:2, nParam:1, nVar:0, belong: 0x0]
      [Expression]
      ExprNode@0x7f81f7d00870 [op:OP_ALIST, val:0, sym:0x0, left:0x7f81f7d00840, right:0x0]
      [Sym]
      (NULL)
        [Expression]
        ExprNode@0x7f81f7d00840 [op:OP_FUNCALL, val:0, sym:0x7f81f7d000d0, left:0x7f81f7d00820, right:0x0]
        [Sym]
        SymEntry@0x7f81f7d000d0 [prev:0x7f81f7d00020, sort:SYM_FUNC, name:fib, no:3, nParam:1, nVar:0, belong: 0x0]
          [Expression]
          ExprNode@0x7f81f7d00820 [op:OP_ALIST, val:0, sym:0x0, left:0x7f81f7d00800, right:0x0]
          [Sym]
          (NULL)
            [Expression]
            ExprNode@0x7f81f7d00800 [op:OP_VAR, val:0, sym:0x7f81f7d00690, left:0x0, right:0x0]
            [Sym]
            SymEntry@0x7f81f7d00690 [prev:0x7f81f7d00620, sort:SYM_VAR, name:v, no:1, nParam:0, nVar:0, belong: 0x7f81f7d00620]
              (NULL)
              (NULL)
            (NULL)
          (NULL)
        (NULL)
      (NULL)
    [St1]
    (NULL)
    [St2]
    (NULL)
  StmtNode@0x7f81f7d00960 [sort:STMT_RETURN, next:0x0, expr:0x7f81f7d00930, st1:0x0, st2:0x0]
    [Expression]
    ExprNode@0x7f81f7d00930 [op:OP_CONST, val:0, sym:0x0, left:0x0, right:0x0]
    [Sym]
    (NULL)
      (NULL)
      (NULL)
    [St1]
    (NULL)
    [St2]
    (NULL)
~~~~
