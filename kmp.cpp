// declaramos uma única função de matching que contém a função pi e o algoritmo de kmp
vector<int> matching(string t, string s)
{
    vector<int> p(1001233), match;
    int n = t.size(), m = s.size();
    // temos que p[0] sempre é zero porque contém um único char
    p[0] = 0;
    for (int i = 1, j = 0; i < m; i++)
    {
        /* tentamos encontrar naquela posição j o i correspondente e para isso,
        fazemos o pre-processamento da palavra buscada e construção do array p, de mesmo
        tamanho da string s (padrão). Buscamos pelo maior sufixo que também seja prefi-
        xo próprio, evitando comparações desnecessárias
        */
        while (j > 0 && s[j] != s[i])
        {
            j = p[j - 1];
        }
        if (s[j] == s[i])
            j++;
        p[i] = j;
    }
    /* Na segunda parte do código, queremos verificar sempre o que
    é possível reaproveitar para não haver excesso de comparações
    */
    for (int i = 0, j = 0; i < n; i++)
    {
        /*o j recebe sempre o índice do que vamos comparar a seguir
        e tudo o que vem para trás dele já foi comparado e dá match
        entre as strings s e t
        */
        while (j > 0 && t[i] != s[j])
            j = p[j - 1];

        // caso as posições sejam iguais, o j é incrementado
        if (s[j] == t[i])
            j++;
        /* caso o índice j seja igual ao tamanho do padrão,
        significa que encontramos um match e marcamos no vetor
        de matches o índice do match de s e t
        */
        if (j == m)
            match.push_back(i - j + 1);
    }
    return match;
}