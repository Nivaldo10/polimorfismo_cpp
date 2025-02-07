// Figura 13.13: Employee.h
// Classe b�sica abstrata Employee.
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string> // classe string padr�o C++
using std::string;

class Employee
{
public:
    Employee( const string &, const string &, const string & );
 
    void setFirstName( const string & ); // configura o nome
    string getFirstName() const; // retorna o nome
 
    void setLastName( const string & ); // configura o sobrenome
    string getLastName() const; // retorna o sobrenome
  
    void setSocialSecurityNumber( const string & ); // configura o SSN
    string getSocialSecurityNumber() const; // retorna o SSN
  
    // a fun��o virtual pura cria a classe b�sica abstrata Employee 
    virtual double earnings() const = 0; // virtual pura 
    virtual void print() const; // virtual 
private:
    string firstName;
    string lastName;
    string socialSecurityNumber;
}; // fim da classe Employee
  
#endif
