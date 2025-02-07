// Figura 13.19: CommissionEmployee.h
// Classe CommissionEmployee derivada de Employee.
#ifndef COMMISSION_H
#define COMMISSION_H

#include "Employee.h" // defini��o da classe Employee
 
class CommissionEmployee : public Employee
{
public:
    CommissionEmployee( const string &, const string &,
        const string &, double = 0.0, double = 0.0 );
  
    void setCommissionRate( double ); // configura a taxa de comiss�o
    double getCommissionRate() const; // retorna a taxa de comiss�o
   
    void setGrossSales( double ); // configura a quantidade de vendas brutas
    double getGrossSales() const; // retorna a quantidade de vendas brutas
 
// a palavra-chave virtual assinala inten��o de sobrescrever 
    virtual double earnings() const; // calcula os rendimentos 
    virtual void print() const; // imprime o objeto CommissionEmployee 
private:
    double grossSales; // vendas brutas semanais
    double commissionRate; // porcentagem da comiss�o
}; // fim da classe CommissionEmployee
 
#endif // COMMISSION_H
