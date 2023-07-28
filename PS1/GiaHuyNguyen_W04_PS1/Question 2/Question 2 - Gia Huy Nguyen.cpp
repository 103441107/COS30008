#pragma once
class Combination 
{
private:
    unsigned int fN;
    unsigned int fK;
public:
    Combination(unsigned int aN, unsigned int aK);

    unsigned int getN() const;
    unsigned int getK() const;

    unsigned long long operator()() const;
};

Combination::Combination(unsigned int aN, unsigned int aK) 
{
    fN = aN;
    fK = aK;
}

unsigned int Combination::getN() const 
{
    return fN;
}

unsigned int Combination::getK() const 
{
    return fK;
}

unsigned long long Combination::operator()() const 
{
    long long res = 1;
    for (int i = 0; i < fK; i++) 
	{
        res = res * (fN - i) / (i + 1);
    }
    return res;
}


#include <iostream>
using namespace std;
void runProblem2() 
{
    Combination a(6, 2);
    Combination b(5, 2);
    Combination c(28, 14);
    Combination d(52, 5);
    Combination e(5, 5);

    cout << a.getN() << " over " << a.getK() << " = " << a() << endl;
    cout << b.getN() << " over " << b.getK() << " = " << b() << endl;
    cout << c.getN() << " over " << c.getK() << " = " << c() << endl;
    cout << d.getN() << " over " << d.getK() << " = " << d() << endl;
    cout << e.getN() << " over " << e.getK() << " = " << e() << endl;
}

int main()
{
    runProblem2();
    return 0;
} 
