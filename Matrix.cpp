/*
 Elements in the matrix are complex numbers.
 To change complex numbers into double type:
 1.declare Complex and set the second argument of Complex to 0(i.e. Complex(a,0) ) in main.cpp
 2.do the following modification:
 find the function below in Complex.cpp
 
 void Complex::print(){
 cout << "(" << real << " + " << imag << "i)";
 //cout << real;
 }
 
 then type "//" before the first "cout" and delete the "//" before the second one
 */
#include "Matrix.h"
#include <iostream>
#include <iomanip>

using namespace std;

Matrix::Matrix(){// default constructor, 什麼都不傳, 將data存入2*2都是0的值
    setUp(2, 2);
    data = new Complex *[row];
    for(int i=0; i<2; i++){
        data[i] = new Complex [col];
    }
    Complex value;//default constructor for Complex is 0
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            setData(i, j, value);
        }
    }
}//end default constructor

Matrix::Matrix(int r, int c){// constructor, 只設定大小, 資料預設為0
    setUp(r, c);
    data = new Complex *[row];
    for(int i=0; i<row; i++){
        data[i] = new Complex [col];
    }
    Complex value;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            setData(i, j, value);
        }
    }
}//end constructor(int,int)

Matrix::Matrix(int r, int c, Complex arr[], int size){// constructor, 將傳入的一維陣列轉存為二維陣列放入data中
    setUp(r, c);
    data = new Complex *[row];
    for(int i=0; i<row; i++){
        data[i] = new Complex [col];
    }
    for(int i=0, arr_flag=0; i<row; i++){
        for(int j=0; j<col; j++, arr_flag++){
            setData(i, j, arr[arr_flag]);
        }
    }
}// end constructor(int r, int c, Complex arr[], int x)

Matrix::Matrix(const Matrix & m2){// copy constructor
    setUp(m2.row, m2.col);
    data = new Complex *[row];
    for(int i=0; i<row; i++){
        data[i] = new Complex [col];
    }
    for(int i=0; i<this->row; i++){
        for(int j=0; j<this->col; j++){
            setData(i, j, m2.data[i][j]);
        }
    }
}//end copy constructor

Matrix::~Matrix(){// destructor, 清理data
    //cout << "destruct\n";
    //cout << row << ',' << col << endl;
    for(int i=0; i<row; i++){
        delete [] data[i];
    }
    delete [] data;
    //cout << "done\n";
}//end destructor

void Matrix::setUp(int r, int c){// utility function, 設定row和col的值
    row = r;
    col = c;
}//end setUp

void Matrix::setData(int i, int j, Complex value){// 設定第(r,c)位置data的值
    data[i][j] = value;
}//end setData

int Matrix::getRow() const{// 回傳private member: row
    return row;
}//end getRow

int Matrix::getCol() const{// 回傳private member: col
    return col;
}//end getCol

Complex Matrix::getData(int i, int j) const{// 拿到矩陣(r,c)位置的值
    return data[i][j];
}//end getData

Matrix Matrix::add(const Matrix &m2){// 矩陣相加, 回傳相加後的矩陣
    //invalid
    if((this->col != m2.col)||(this->row != m2.row)){
        cout << "Addition failed.\n";
        Matrix ans(this->row,this->col);
        Complex value(-1,0);
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                ans.setData(i, j, value);
            }
        }
        return ans;
    }
    //valid
    Matrix ans(this->row, this->col);
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            Complex e1(this->data[i][j].getReal(),this->data[i][j].getImag());
            Complex e2(m2.data[i][j].getReal(),m2.data[i][j].getImag());
            ans.setData(i, j, e1.add(e2));
        }
    }
    
    return ans;
}//end add

Matrix Matrix::multiply(const Matrix &m2){// 矩陣相乘, 回傳相乘後之矩陣
   
    //invalid
    if(this->col != m2.row){
        cout << "Multiplication failed.\n";
        Matrix ans(this->row,this->col);
        Complex value(-1,0);
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                ans.setData(i, j, value);
            }
        }
        return ans;
    }
    //valid
    Matrix ans(this->row, m2.col);
    for(int i=0; i<this->row; i++){
        for(int l=0; l<m2.col; l++){
            Complex value;
            for(int j=0; j<this->col; j++){
                Complex e1(this->data[i][j].getReal(),this->data[i][j].getImag());
                Complex e2(m2.data[j][l].getReal(),m2.data[j][l].getImag());
                value = value.add( e1.multiply(e2) );
            }
            ans.setData(i, l, value);
        }
    }
    return ans;
}//end multiply

Matrix Matrix::transpose(){// 矩陣轉置, 回傳轉置後的矩陣
    Matrix ans(this->col, this->row);
    for(int i=0; i<this->row; i++){
        for(int j=0; j<this->col; j++){
            ans.data[j][i] = this->data[i][j];
        }
    }
    return ans;
}//end transpose

