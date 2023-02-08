namespace Task3;

internal class Complex
{
    public double A { get; set; }
    public double B { get; set; }

    public Complex(double a, double b)
    {
        A = a;
        B = b;
    }
    public Complex() { }

    public static Complex operator +(Complex c1, Complex c2)
    {
        return new Complex((c1.A + c2.A), (c1.B + c2.B));
    }
    public static Complex operator -(Complex c1, Complex c2)
    {
        return new Complex((c1.A - c2.A), (c1.B - c2.B));
    }
    public static Complex operator *(Complex c1, Complex c2)
    {
        return new Complex((c1.A * c2.A - c1.B * c2.B), (c1.B * c2.A + c1.A * c2.B));
    }
    public static Complex operator /(Complex c1, Complex c2)
    {
        return new Complex(((c1.A * c2.A + c1.B * c2.B) / (c2.A * c2.A + c2.B * c2.B)), ((c1.B * c2.A - c1.A * c2.B) / (c2.A * c2.A + c2.B * c2.B)));
    }

    public static implicit operator string(Complex c)
    {
        return $"{c.A}+{c.B}i";
    }
}