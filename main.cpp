// Figura 13.23: fig13_23.cpp
// Processando objetos da classe derivada Employee individualmente
// e polimorficamente utilizando vincula��o din�mica.
#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
 
#include <iomanip>
using std::setprecision;
 
#include <vector>
using std::vector;
 
// inclui defini��es de classes na hierarquia Employee
#include "Employee.h"
#include "SalariedEmployee.h"
#include "HourlyEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
  
void virtualViaPointer( const Employee * const ); // prot�tipo
void virtualViaReference( const Employee & ); // prot�tipo
  
int main()
{
// configura a formata��o de sa�da de ponto flutuante
    cout << fixed << setprecision( 2 );
  
// cria objetos da classe derivada
    SalariedEmployee salariedEmployee(
        "John", "Smith", "111-11-1111", 800 );
    HourlyEmployee hourlyEmployee(
        "Karen", "Price", "222-22-2222", 16.75, 40 );
    CommissionEmployee commissionEmployee(
        "Sue", "Jones", "333-33-3333", 10000, .06 );
    BasePlusCommissionEmployee basePlusCommissionEmployee(
        "Bob", "Lewis", "444-44-4444", 5000, .04, 300 );
 
    cout << "Employees processed individually using static binding:\n\n";
  
    // gera sa�da de informa��es e rendimentos dos Employees com vincula��o est�tica
    salariedEmployee.print();
    cout << "\nearned $" << salariedEmployee.earnings() << "\n\n";
    hourlyEmployee.print();
    cout << "\nearned $" << hourlyEmployee.earnings() << "\n\n";
    commissionEmployee.print();
    cout << "\nearned $" << commissionEmployee.earnings() << "\n\n";
    basePlusCommissionEmployee.print();
    cout << "\nearned $" << basePlusCommissionEmployee.earnings()
       << "\n\n";

    // cria um vector a partir dos quatro ponteiros da classe b�sica 
    vector < Employee * > employees( 4 ); 
  
    // inicializa o vector com Employees 
    employees[ 0 ] = &salariedEmployee; 
    employees[ 1 ] = &hourlyEmployee; 
    employees[ 2 ] = &commissionEmployee; 
    employees[ 3 ] = &basePlusCommissionEmployee; 
 
    cout << "Employees processed polymorphically via dynamic binding:\n\n";
 
    // chama virtualViaPointer para imprimir informa��es e rendimentos
    // de cada Employee utilizando vincula��o din�mica
    cout << "Virtual function calls made off base-class pointers:\n\n";
 
    for ( size_t i = 0; i < employees.size(); i++ ) 
        virtualViaPointer( employees[ i ] ); 
 
    // chama virtualViaReference para imprimir informa��es
    // de cada Employee utilizando vincula��o din�mica
    cout << "Virtual function calls made off base-class references:\n\n";
 
    for ( size_t i = 0; i < employees.size(); i++ ) 
        virtualViaReference( *employees[ i ] ); // observe o desreferenciamento 
 
    return 0;
} // fim de main
 
// chama fun��es print e earnings virtual de Employee a partir de um 
// ponteiro de classe b�sica utilizando vincula��o din�mica 
void virtualViaPointer( const Employee * const baseClassPtr ) 
{ 
    baseClassPtr->print(); 
    cout << "\nearned $" << baseClassPtr->earnings() << "\n\n"; 
} // fim da fun��o virtualViaPointer 
 
 // chama fun��es print e earnings virtual de Employee a partir de uma 
// refer�ncia de classe b�sica utilizando vincula��o din�mica 
void virtualViaReference( const Employee &baseClassRef ) 
{ 
   baseClassRef.print(); 
   cout << "\nearned $" << baseClassRef.earnings() << "\n\n"; 
} // fim da fun��o virtualViaReference 
