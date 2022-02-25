int main()
{
    int n = 10;
    int i = 3;
    // Modulo 2
    n & 1;

    // Multiply by 2
    n << 1;

    // Divide by 2
    n >> 1;

    // 2n+1
    (n << 1) | 1;

    // Check if the number is 2^k
    n &(n - 1);

    // Check if the number is 2^k-1
    n &(n + 1);

    // Set i-th Bit
    n | (1 << i);

    // Check if i-th bit is set
    n &(1 << i);

    // Reset i-th bit
    n &(~(1UL << i));

    // Toggle i-th bit
    n ^ (1 << i);
}