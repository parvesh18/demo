#include <bits/stdc++.h>
using namespace std;
struct product
{
    int value;
    int weight;
};
class Selection
{
    product *knapsack;
    int N;
    int W;
    int **matrix;

public:
    Selection(int n, int w)
    {
        N = n;
        W = w;
        knapsack = new product[N];
        matrix = new int *[N + 1];
        for (int i = 0; i < N + 1; i++)
        {
            matrix[i] = new int[W + 1];
        }
        for (int i = 0; i < N + 1; i++)
        {
            for (int j = 0; j < W + 1; j++)
            {
                matrix[i][j] = -1;
            }
        }
    }
    void input()
    {
        for (int i = 0; i < N; i++)
        {
            cout << "For " << i << " Product\n";
            cout << "Enter the value : ";
            cin >> knapsack[i].value;
            cout << "Enter the weight: ";
            cin >> knapsack[i].weight;
        }
    }
    int opt(int n, int w)
    {
        if (n == 0 || w == 0)
        {
            return 0;
        }
        if (knapsack[n - 1].weight > w)
            return opt(n - 1, w);
        else
        {
            return max(knapsack[n - 1].value + opt(n - 1, w - knapsack[n - 1].weight), opt(n - 1, w));
        }
    }

    int mopt(int n, int w)
    {
        if (n == 0 || w == 0)
        {
            matrix[n][w] = 0;
            return matrix[n][w];
        }
        if (matrix[n][w] != -1)
            return matrix[n][w];
        if (knapsack[n - 1].weight > w)
        {
            matrix[n][w] = mopt(n - 1, w);
            return matrix[n][w];
        }
        else
        {
            matrix[n][w] = max(knapsack[n - 1].value + mopt(n - 1, w - knapsack[n - 1].weight), mopt(n - 1, w));
            return matrix[n][w];
        }
    }

    int knapSack(int n, int W)
    {
        int i, w;
        int K[n + 1][W + 1];

        // Build table K[][] in bottom up manner
        for (i = 0; i <= n; i++)
        {
            for (w = 0; w <= W; w++)
            {
                if (i == 0 || w == 0)
                    K[i][w] = 0;
                else if (knapsack[i - 1].weight <= w)
                    K[i][w] = max(knapsack[i - 1].value + K[i - 1][w - knapsack[i - 1].weight], K[i - 1][w]);
                else
                    K[i][w] = K[i - 1][w];
            }
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return K[n][W];
    }
};
int main()
{
    Selection s1(5, 7);
    s1.input();
    cout << "Max value is: " << s1.opt(5, 7) << endl;
    cout << "Max value is: " << s1.mopt(5, 7) << endl;
    cout << "Max value is: " << s1.knapSack(5, 7) << endl;
}