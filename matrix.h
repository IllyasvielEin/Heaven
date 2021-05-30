#ifndef MATRIX_INCLUDED
#define MATRIX_INCLUDED

#include <iomanip>
#include <iostream>
#include <random>

class matrix {
private:
    // 数据
    double** data;

public:
    // 行数
    size_t line;
    // 列数
    size_t col;
    // 默认构造器
    matrix();
    // 构造m*n矩阵
    matrix(size_t line, size_t col);
    // 拷贝构造函数
    matrix(const matrix& obj);
    // 移动构造函数
    matrix(matrix&& obj) noexcept;
    // 析构器
    ~matrix();
    // 深拷贝
    matrix operator=(const matrix& A);
    // 移动
    matrix& operator=(matrix&& A) noexcept;
    // 格式化输出
    friend std::ostream& operator<<(std::ostream& os, const matrix& A);
};

matrix::matrix() {
    this->line = 0;
    this->col = 0;
    this->data = nullptr;
}

matrix::matrix(size_t l, size_t c) {
    this->line = l;
    this->col = c;
    // 分配内存空间
    this->data = new double*[l];
    for (size_t i = 0; i < l; i++) this->data[i] = new double[c];
    // 初始化为零矩阵
    for (size_t i = 0; i < l; i++)
        for (size_t j = 0; j < c; j++) this->data[i][j] = 0;
}

matrix::matrix(const matrix& obj) {
    this->line = obj.line;
    this->col = obj.col;
    // 分配内存空间
    this->data = new double*[obj.line];
    for (size_t i = 0; i < obj.line; i++) this->data[i] = new double[obj.col];
    // 拷贝值
    for (size_t i = 0; i < obj.line; i++)
        for (size_t j = 0; j < obj.col; j++) this->data[i][j] = obj.data[i][j];
}

matrix::matrix(matrix&& obj) noexcept {
    this->line = obj.line;
    this->col = obj.col;
    this->data = obj.data;
    obj.data = nullptr;
}

matrix::~matrix() {
    if (this->data != nullptr) {
        for (size_t i = 0; i < this->line; i++) delete[] this->data[i];
        delete[] this->data;
    }
}

matrix matrix::operator=(const matrix& A) {
    this->line = A.line;
    this->col = A.col;
    // 分配内存空间
    this->data = new double*[A.line];
    for (size_t i = 0; i < A.line; i++) this->data[i] = new double[A.col];
    // 拷贝值
    for (size_t i = 0; i < A.line; i++)
        for (size_t j = 0; j < A.col; j++) this->data[i][j] = A.data[i][j];
    return *this;
}

matrix& matrix::operator=(matrix&& A) noexcept {
    this->line = A.line;
    this->col = A.col;
    this->data = A.data;
    A.data = nullptr;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const matrix& A) {
    for (size_t i = 0; i < A.line; i++) {
        for (size_t j = 0; j < A.col; j++) {
            if (j == 0) {
                if (i == 0)
                    os << std::left << std::setw(3) << "┏";
                else if (i == A.line - 1)
                    os << std::left << std::setw(3) << "┗";
                else
                    os << std::left << std::setw(3) << "┃";
            }
            os << std::setw(10) << std::fixed << A.data[i][j];
            if (j == A.col - 1) {
                if (i == 0)
                    os << std::right << std::setw(2) << "┓";
                else if (i == A.line - 1)
                    os << std::right << std::setw(2) << "┛";
                else
                    os << std::right << std::setw(2) << "┃";
            }
        }
        os << std::endl;
    }
    return os;
}
#endif  // !MATRIX_INCLUDED
