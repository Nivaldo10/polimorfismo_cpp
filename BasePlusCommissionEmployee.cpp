// Figura 13.22: BasePlusCommissionEmployee.cpp
// Defini��es de fun��o-membro BasePlusCommissionEmployee.
#include <iostream>
using std::cout;

// defini��o da classe BasePlusCommissionEmployee
#include "BasePlusCommissionEmployee.h"

// construtor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
    const string &first, const string &last, const string &ssn,
    double sales, double rate, double salary )
    : CommissionEmployee( first, last, ssn, sales, rate )
{
    setBaseSalary( salary ); // valida e armazena o sal�rio-base
} // fim do construtor BasePlusCommissionEmployee
 
// configura o sal�rio-base
void BasePlusCommissionEmployee::setBaseSalary( double salary )
{
    baseSalary = ( ( salary < 0.0 ) ? 0.0 : salary );
} // fim da fun��o setBaseSalary
 
// retorna o sal�rio-base
double BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary;
} // fim da fun��o getBaseSalary
 
// calcula os rendimentos;
// sobrescreve a fun��o virtual pura earnings em Employee
double BasePlusCommissionEmployee::earnings() const
{
    return getBaseSalary() + CommissionEmployee::earnings();
} // fim da fun��o earnings

// imprime informa��es de BasePlusCommissionEmployee
void BasePlusCommissionEmployee::print() const
{
    cout << "base-salaried ";
    CommissionEmployee::print(); // reutiliza��o de c�digo
    cout << "; base salary: " << getBaseSalary();
} // fim da fun��o print
