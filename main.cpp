#include "matrix.h"

int main(int argc, char* argv[])
{
    EnableMemLeakCheck();
    _CrtSetBreakAlloc(167);
    matrix* mat = new matrix(3, 4);
    matrix* mat2 = new matrix(4, 5);
    *mat = *mat2;
    delete mat;
    delete mat2;
    return 0;

}