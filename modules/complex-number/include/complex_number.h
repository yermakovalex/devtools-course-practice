// Copyright 2017 Korniakov Kirill

#ifndef MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_NUMBER_H_
#define MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_NUMBER_H_

class ComplexNumber {
 public:
    ComplexNumber();
    ComplexNumber(const double real, const double imaginary);
    ComplexNumber(const ComplexNumber& z);

    ComplexNumber& operator=(const ComplexNumber& z);

    double getRe() const;
    double getIm() const;
    void setRe(const double real);
    void setIm(const double imaginary);

    ComplexNumber operator + (const ComplexNumber& z) const;
    ComplexNumber operator - (const ComplexNumber& z) const;
    ComplexNumber operator * (const ComplexNumber& z) const;
    ComplexNumber operator / (const ComplexNumber& z) const;

    bool operator == (const ComplexNumber& z) const;
    bool operator != (const ComplexNumber& z) const;

 private:
    bool equalsZero(const ComplexNumber& z) const;
    double real_;
    double imaginary_;
};

#endif  // MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_NUMBER_H_
