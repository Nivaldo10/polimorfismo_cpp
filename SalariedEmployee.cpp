// Figura 13.16: SalariedEmployee.cpp
// Defini��es de fun��o-membro da classe SalariedEmployee.
#include <iostream>
using std::cout;

#include "SalariedEmployee.h" // defini��o da classe SalariedEmployee

// construtor
SalariedEmployee::SalariedEmployee( const string &first,
    const string &last, const string &ssn, double salary )
    : Employee( first, last, ssn )
{
    setWeeklySalary( salary );
} // fim do construtor SalariedEmployee
 
// configura o sal�rio
void SalariedEmployee::setWeeklySalary( double salary )
{
    weeklySalary = ( salary < 0.0 ) ? 0.0 : salary;
} // fim da fun��o setWeeklySalary
 
// retorna o sal�rio
double SalariedEmployee::getWeeklySalary() const
{
    return weeklySalary;
} // fim da fun��o getWeeklySalary
 
// calcula os rendimentos;
// sobrescreve a fun��o virtual pura earnings em Employee
double SalariedEmployee::earnings() const
{
    return getWeeklySalary();
} // fim da fun��o earnings

// imprime informa��es de SalariedEmployee
void SalariedEmployee::print() const
{
    cout << "salaried employee: ";
    Employee::print(); // reutiliza fun��o print da classe b�sica abstrata
    cout << "\nweekly salary: " << getWeeklySalary();
} // fim da fun��o print
 
