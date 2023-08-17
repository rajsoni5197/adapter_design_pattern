#include<iostream>
using namespace std;

class CelsiusToKelvin
{
    public:
    virtual float changeCelsiusToKelvin(float celsius) = 0 ;
};

class FahrenheitToKelvin
{
    public:
     float changeFahrenheitToKelvin(float fahrenheit)
     {
        return ((fahrenheit-32)*(5.00/9)+273.15);
     }
};

class AdapterFahrenheitToKelvin:public CelsiusToKelvin  //here FahrenheitToKelvin is adapting for celsius
{
    FahrenheitToKelvin* ftok ;
    public:
    AdapterFahrenheitToKelvin(FahrenheitToKelvin* obj)
    {
        this->ftok = obj;
    }

    float changeCelsiusToKelvin(float celsius) override
    {
        int fahrenheit = (celsius*(9.00/5))+32;
        return this->ftok->changeFahrenheitToKelvin(fahrenheit);
    }

};
class Client
{
    public:
    Client()
    {
        int celsius;
        cout<<"Give Temprature in celsius to convert into kelvin\n";
        cin>>celsius;

        CelsiusToKelvin* ctok  = new AdapterFahrenheitToKelvin(new FahrenheitToKelvin);

        cout <<celsius<<"degree celsius = "<< ctok->changeCelsiusToKelvin(celsius)
        <<" degree kelvin \n";
    }
};

int main()
{
    Client c1;
    return 0;
}