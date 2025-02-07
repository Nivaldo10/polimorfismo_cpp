// Figura 13.20: CommissionEmployee.cpp
// Defini��es de fun��o-membro da classe CommissionEmployee.
#include <iostream>
using std::cout;
 
#include "CommissionEmployee.h" // defini��o da classe CommissionEmployee
 
// construtor
CommissionEmployee::CommissionEmployee( const string &first,
    const string &last, const string &ssn, double sales, double rate )
    : Employee( first, last, ssn )
{
    setGrossSales( sales );
    setCommissionRate( rate );
} // fim do construtor CommissionEmployee
 
// configura a taxa de comiss�o
void CommissionEmployee::setCommissionRate( double rate )
{
    commissionRate = ( ( rate > 0.0 && rate < 1.0 ) ? rate : 0.0 );
} // fim da fun��o setCommissionRate
 
// retorna a taxa de comiss�o
double CommissionEmployee::getCommissionRate() const
{
     return commissionRate;
} // fim da fun��o getCommissionRate

// configura a quantidade de vendas brutas
void CommissionEmployee::setGrossSales( double sales )
{
    grossSales = ( ( sales < 0.0 ) ? 0.0 : sales );
} // fim da fun��o setGrossSales
 
// retorna a quantidade de vendas brutas
double CommissionEmployee::getGrossSales() const
{
    return grossSales;
 
} // fim da fun��o getGrossSales
 // calcula os rendimentos;
 // sobrescreve a fun��o virtual pura earnings em Employee
double CommissionEmployee::earnings() const
{
    return getCommissionRate() * getGrossSales();
} // fim da fun��o earnings
 // imprime informa��es do CommissionEmployee
void CommissionEmployee::print() const
{
    cout << "commission employee: ";
    Employee::print(); // reutiliza��o de c�digo
    cout << "\ngross sales: " << getGrossSales()
        << "; commission rate: " << getCommissionRate();
} // fim da fun��o print
 
