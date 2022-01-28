// Counts the total numbers from 1 to n that has 1 at i-th bit -> O(1)
int count(int n, int i)
{
    int a = 1 << i;
    int ans = a * ((n + 1) / 2 * a);
    if ((n / a) % 2)
    {
        ans += (n + 1) % a;
    }
    return ans;
}
