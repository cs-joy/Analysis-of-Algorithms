#include<iostream>
//#include<cmath>

using namespace std;

void yogurtProblem()
{
    int cases;
    cin >> cases;

    for(int testCase=1; testCase <= cases; testCase++)
    {
        int N;
        cin >> N;

        int K;
        cin >> K;

        int size = N + 1;
        int buckets[size];

        for(int i=0; i < N; i++)
        {
            int ai;
            cin >> ai;

            if(ai > N)
            {
                ai = N;
            }
            buckets[ai]++;
        }

        int total = 0;
        for(int j = N; j > 0; j--)
        {
            int today = min(K, buckets[j]);
            total += today;
            buckets[j-1] += buckets[j] - today;
        }

        cout << "Case #" << testCase << ": " << total << endl;
    }
}

int main()
{
    yogurtProblem();

    return 0;
}