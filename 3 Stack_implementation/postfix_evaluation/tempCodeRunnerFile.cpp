

int main()
{
    FILE *fin = freopen("postfix_input.txt", "r", stdin);

    int n;
    cin >> n;
    cin.ignore(); // Ignore the newline after reading `n`

    string s[n];