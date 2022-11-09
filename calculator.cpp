#include<iostream> 
#include<string>
using namespace std;

const double PI = 3.14159265; 

//function to return factorial of a number ## 
double fact(int a)
{
    double factorial=1;
    for(int i=a;i>0;i--)
    {
        factorial*=i;
        
    }
    return factorial;
}

//exponentiation function ##
double exp(double a,int b)
{
    if(b==0)
    {
        return 1;
    }
    double value=1;
    for(int i=0;i<b;i++)
    {
        value*=a;
    }
    return value;
}

//sine function ##
double sin(double a)
{
    double sine=0; 
    float noOfPI; 
    int multiplier=1;
    
    if(a<0)
    {
        multiplier = -1;
        a*=-1;
    }

    noOfPI = a/PI;
    int n = static_cast<int>(noOfPI);
    double x = a - n*PI;

    if(n%2==1)
    {
        multiplier*=-1;
    }

    for(int i =0; i<10;i++)
    {
        sine+=exp(-1,i)*exp(x,2*i+1)/fact(2*i+1);
    }
    sine*=multiplier;


    return sine;
}

//cosine function ##
double cos(double a)
{
    double cosine=0;
    float noOfPI;
    int multiplier=1;
    if(a<0)
    {
        a*=-1;
    }

    noOfPI = a/PI;
    int n = static_cast<int>(noOfPI);
    double x = a - n*PI;
    if(n%2==1)
    {
        multiplier*=-1;
    }
    for(int i=0;i<10;i++)
    {
        cosine+=exp(-1,i)*exp(x,2*i)/fact(2*i);
    }

    cosine *=multiplier;
    return cosine;
}


//instructions ##
void instructions() 
{
    cout<<"Press a to add\nPress s to subtract\nPress m to multiply\nPress d to divide\n";
    cout<<"Press t to access trignometric functions\n";
    cout<<"Press e for exponentiation\n\n";
}

//trignometric functions switch case ##
void tcompute()
{
    cout<<"\n\npress 1 for sin\npress 2 for cos\npress 3 for tan\npress 4 for cosec\npress 5 for sec\npress 6 for cot\n";
    cout<<"input: ";
    short choice;
    cin>>choice;
    double rad;
    cout<<"Enter angle in radians: ";
    cin>>rad;
    switch (choice)
    {
    case 1:
    cout<<"sin("<<rad<<")= "<<sin(rad);
    break;

    case 2:
    cout<<"cos("<<rad<<")= "<<cos(rad);
    break;

    case 3:
    if(cos(rad)==0)
    {
        cout<<"undefined";
        break;
    }
    cout<<"tan("<<rad<<")= "<<sin(rad)/cos(rad);
    break;

    case 4:
    if(sin(rad)==0)
    {
        cout<<"undefined";
        break;
    }
    cout<<"cosec("<<rad<<")= "<<1/sin(rad);
    break;

    case 5:
    if(cos(rad)==0)
    {
        cout<<"undefined";
        break;
    }
    cout<<"sec("<<rad<<")= "<<1/cos(rad);
    break;

    case 6:
    if(sin(rad)==0)
    {
        cout<<"undefined";
        break;
    }
    cout<<"cot("<<rad<<")= "<<cos(rad)/sin(rad);
    break;
    }

}

//functions switch case ##
void compute()
{
    cout<<"input: ";
    char input;
    cin>>input;
    double num1,num2;
    switch(input)
    {
        case 'a':
        cout<<"enter a number: ";
        cin>>num1;
        cout<<"enter another number: ";
        cin>>num2;
        cout<<num1<<'+'<<num2<<"= "<<(num1+num2);
        break;

        case 's':
        cout<<"enter a number: ";
        cin>>num1;
        cout<<"enter another number: ";
        cin>>num2;
        cout<<num1<<'-'<<num2<<"= "<<(num1-num2);
        break;

        case 'm':
        cout<<"enter a number: ";
        cin>>num1;
        cout<<"enter another number: ";
        cin>>num2;
        cout<<num1<<'*'<<num2<<"= "<<(num1*num2);
        break;

        case 'd':
        cout<<"enter numerator: ";
        cin>>num1;
        cout<<"enter denominator: ";
        cin>>num2;
        cout<<num1<<'/'<<num2<<"= "<<(num1/num2);
        break;

        case 'e':
        cout<<"enter base: ";
        cin>>num1;
        cout<<"enter power: ";
        int pow;
        cin>>pow;
        cout<<num1<<'^'<<pow<<"= "<<exp(num1,pow);
        break;

        case 't':
        tcompute();
        break;

        default:
        cout<<"wrong entry";
    }
}

int main()
{
    cout<<"\n\n\t\t\t###CALCULATOR###\n\n";
    char again='y';

    while(again=='y')
    {
        instructions();
        compute();
        cout<<"\n\nDo you want to use again <y/n>: ";
        cin>>again;
    }
    cout<<"\nThank you!";
}


