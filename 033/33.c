void get_digits(int n_int)
{
    float n = (float)n_int;
    int rem, digit;
    while (n >= 1) {
        n /= 10;
        rem = n % 1.0f;
        digit = rem * 10;
        n -= rem;
    }
}

int main()
{
    get_digits(123);
    return 0;
}
