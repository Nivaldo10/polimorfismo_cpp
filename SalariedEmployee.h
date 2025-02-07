// Figura 13.15: SalariedEmployee.h
// Classe SalariedEmployee derivada de Employee.
#ifndef SALARIED_H
#define SALARIED_H

#include "Employee.h" // defini��o da classe Employee

class SalariedEmployee : public Employee
{
public:
    SalariedEmployee( const string &, const string &,
        const string &, double = 0.0 );
 
    void setWeeklySalary( double ); // configura o sal�rio semanal
    double getWeeklySalary() const; // retorna o sal�rio semanal
 
// palavra-chave virtual assinala inten��o de sobrescrever 
    virtual double earnings() const; // calcula os rendimentos 
    virtual void print() const; // imprime objeto SalariedEmployee 
private:
    double weeklySalary; // sal�rio por semana
}; // fim da classe SalariedEmployee

#endif // SALARIED_H

