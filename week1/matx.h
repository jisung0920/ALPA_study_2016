#include <stdio.h>
#include <math.h>
#define ROW 4
#define COL 4


void matprint(float (*arry)[COL]);

void unitMatMaker(float (*E)[COL]);

void matscan(float (*arry)[COL]);

void mrowChange(float (*arr)[COL],float (*P)[COL],int r1, int r2);

void mrowOp(float (*arr)[COL],float (*E)[COL],int r1, float n, int r2);

void LUconvert(float (*arr)[COL],float (*E)[COL],float (*P)[COL]);

void ZeroRowChanger(float (*arr)[COL],float (*P)[COL],int l);

void PivotOp(float (*arr)[COL],float (*E)[COL],int i, int j);
