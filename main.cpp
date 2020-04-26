
#include<iostream>
#include"Matrix.h"
#include"Complex.h"
using namespace std;

int main()
{
    cout << "<<Default Construster>>\ntest1\n";
    Matrix test1;
    test1.displayData();
    cout << endl;
    
    cout << "\n<<Constructor>> (只設定大小, 資料預設為0)"<<endl;
    cout<<"test2\n";
    Matrix test2(3, 4);
    test2.displayData();
    cout << endl;
    
    cout << "\n<<Constructor>>\ntest3a\n";
    Complex m2[6] = { Complex(3,-1),Complex(3.7,0),Complex(8.9,-1),Complex(2,0),Complex(-1.3,1),Complex(2.3,0) };
    Matrix test3a(3, 2, m2, 6);
    test3a.displayData();
    cout << endl;
    
    cout << "test3b\n"; //for multiply
    Complex m1[6] = { Complex(2.4,1),Complex(2.8,0),Complex(-29.1,1),Complex(4,0),Complex(-2,-1),Complex(72.3,0) };
    Matrix test3b(2, 3, m1, 6);
    test3b.displayData();
    cout << endl;
    
    cout << "\n<<Copy constructor>>\ntest4\n";
    Matrix test4(test3a);
    test4.displayData();
    cout << endl;
    
    cout << "\n<<Set data>>\ntest4\n";
    test4.setData(0, 1, Complex(7.4,-1));
    test4.displayData();
    cout << endl;
    
    cout << "\ntest4(row,col)="<<"("<< test4.getRow()<<","<< test4.getCol()<<")"<<endl;
    cout << endl;
    
    cout << "\ntest4(0,1)=";//Get data
    test4.getData(0, 1).print();
    cout << endl ;
    
    cout << "\n\n<<Add>>" << endl;
    cout << "test3a + test4:"<< endl;
    test3a.displayData();
    cout << " +\n";
    test4.displayData();
    cout << " =" << endl;
    test3a.add(test4).displayData();
    cout << endl;
    
    cout << "\n<<Mmultiply>>" << endl;
    cout << "test3a * test3b" << endl;
    test3a.displayData();
    cout << " *\n";
    test3b.displayData();
    cout << " =" << endl;
    test3a.multiply(test3b).displayData();
    cout << endl;
    
    cout << "\n<<Transpose>>\n";
    test4.displayData();
    cout << "transpose\n";
    test4.transpose().displayData();
    cout << endl;
    
    system("pause");
    return 0;
}

