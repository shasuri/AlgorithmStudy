int Solve()
{
    vector<pair<int, int>> A;
    for (int i = 0; i < N; i++)
    {
        A.push_back({sm[i] * 100 + sd[i], em[i] * 100 + ed[i]});
    }
    sort(A.begin(), A.end());
    int cnt = 0, i = 0, e = 301;
    for (;;)
    {
        int maxv = 0;
        while ((i < A.size()) &&
               (A[i].first <= e))
        {
            maxv = max(maxv, A[i].second);
            i++;
        }
        if (maxv <= e)
            return 0;
        cnt++;
        if (maxv > 1130)
            return cnt;
        e = maxv;
    }
}