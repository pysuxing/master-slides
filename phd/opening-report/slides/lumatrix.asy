import matrix;

// defaultpen(opacity(0));
// currentpen = black;

Matrix A = Matrix.general(3, 3);
A.setLabel("$A$");
picture pic0;
A.draw(pic0);

A.tileCol(new int[] {1,2});
Matrix A0 = A.getSubMatrix(0);
Matrix A1 = A.getSubMatrix(1);
A.resetLabel();
A0.setLabel("$A0$");
A1.setLabel("$A1$");
picture pic1;
A.draw(pic1);

A0.tileDiagonal();
Matrix L0 = A0.getSubMatrix(0);
Matrix U00 = A0.getSubMatrix(1);
A0.resetLabel();
L0.setLabel("$L0$");
U00.setLabel("$U00$");
picture pic2;
A.draw(pic2);

A0.tileRow(new int[] {1,2});
Matrix A00 = A0.getSubMatrix(0);
Matrix L10 = A0.getSubMatrix(1);
A00.tileDiagonal();
Matrix L00 = A00.getSubMatrix(0);
U00 = A00.getSubMatrix(1);
A1.tileRow(new int[] {1,2});
Matrix A01 = A1.getSubMatrix(0);
Matrix A11 = A1.getSubMatrix(1);
A1.resetLabel();
L00.setLabel("$L00$");
U00.setLabel("$U00$");
L10.setLabel("$L10$");
A01.setLabel("$A01$");
A11.setLabel("$A11$");
picture pic3;
A.draw(pic3);

Matrix U01 = A01;
U01.setLabel("$U01$");
picture pic4;
A.draw(pic4);

A11.resetLabel();
A11.convert(SQUARE);
A11.tileDiagonal();
Matrix L11 = A11.getSubMatrix(0);
Matrix U11 = A11.getSubMatrix(1);
L11.setLabel("$L11$");
U11.setLabel("$U11$");
picture pic5;
A.draw(pic5);

A11.detile();
A11.tileCol(1);
L11 = A11.getSubMatrix(0);
U11 = A11.getSubMatrix(1);
L11.setLabel("$A11$");
U11.setLabel("$A12$");
picture pic6;
A.draw(pic6);

A11 = L11;
Matrix A12 = U11;
A11.resetLabel();
A11.tileDiagonal();
L11 = A11.getSubMatrix(0);
U11 = A11.getSubMatrix(1);
L11.setLabel("$L11$");
U11.setLabel("$U11$");
picture pic7;
A.draw(pic7);

A11.detile();
A11.tileRow(1);
Matrix A21 = A11.getSubMatrix(1);
A21.setLabel("$L21$");
A11 = A11.getSubMatrix(0);
A11.resetLabel();
A11.convert(SQUARE);
A11.tileDiagonal();
L11 = A11.getSubMatrix(0);
U11 = A11.getSubMatrix(1);
L11.setLabel("$L11$");
U11.setLabel("$U11$");
A12.resetLabel();
A12.tileRow(1);
Matrix A22 = A12.getSubMatrix(1);
A22.setLabel("$A22$");
A12 = A12.getSubMatrix(0);
A12.setLabel("$A12$");
picture pic8;
A.draw(pic8);

A12.setLabel("$U12$");
picture pic9;
A.draw(pic9);

A22.resetLabel();
A22.convert(SQUARE);
A22.tileDiagonal();
Matrix L22 = A22.getSubMatrix(0);
Matrix U22 = A22.getSubMatrix(1);
L22.setLabel("$L22$");
U22.setLabel("$U22$");
picture pic10;
A.draw(pic10);

L10.resetLabel();
L10.tileRow(1);
Matrix L20 = L10.getSubMatrix(1);
L20.setLabel("$L20$");
L10 = L10.getSubMatrix(0);
L10.setLabel("$L10$");
U01.resetLabel();
U01.tileCol(1);
Matrix U02 = U01.getSubMatrix(1);
U02.setLabel("$U02$");
U01 = U01.getSubMatrix(0);
U01.setLabel("$U01$");
picture pic11;
A.draw(pic11);

unitsize(pic0, 45); shipout("lu0", pic0);
unitsize(pic1, 45); shipout("lu1", pic1);
unitsize(pic2, 45); shipout("lu2", pic2);
unitsize(pic3, 45); shipout("lu3", pic3);
unitsize(pic4, 45); shipout("lu4", pic4);
unitsize(pic5, 45); shipout("lu5", pic5);
unitsize(pic6, 45); shipout("lu6", pic6);
unitsize(pic7, 45); shipout("lu7", pic7);
unitsize(pic8, 45); shipout("lu8", pic8);
unitsize(pic9, 45); shipout("lu9", pic9);
unitsize(pic10, 45); shipout("lu10", pic10);
unitsize(pic11, 45); shipout("lu11", pic11);
