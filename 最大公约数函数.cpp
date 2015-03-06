int gcd(int a, int b)
{
    if(a < b)
        return gcd(b, a);
    if(b == 0)
        return a;
    else
    {
        if(a % 2 == 0)
        {
            if(b % 2 == 0)
                return (gcd(a >> 1, b >> 1) << 1);
            else
            {
                return gcd(a >> 1, b);
            }
        }
        else
        {
            if(b % 2 == 0)
                return gcd(a, b>>1);
            else
                return  gcd(b, a - b);
        }
    }
}