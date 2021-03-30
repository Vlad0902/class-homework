#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void print_arr(int **arr, int M, int K)
{
    cout << endl;
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<K; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void shift_array(int **arr, int M, int K, int szuv)
{
    for(int a=0; a<szuv; a++)
    {
        for (int i = M -1; i-- > 0;)
        {
            for (int j = 0; j < K; j++)
            {
                int temp = arr[i+1][j];
                arr[i+1][j] = arr[i][j];
                arr[i][j] = temp;
            }
        }
    }
}

int main()
{
    int M, K, shift;
    cout << "Enter dimensions - ";
    cin >> M >> K;
    cout << "Enter rows to shift - ";
    cin >> shift;
    cout << endl;
    int **arr = new int*[M];
    for(int i = 0; i < M; i++)
        arr[i] = new int[K];

    for(int i=0; i<M; i++)
    {
        for(int j=0; j<K; j++)
        {
            arr[i][j] = i;
        }
    }

    print_arr(arr, M, K);
    shift_array(arr, M, K, shift);
    print_arr(arr, M, K);

    return 0;
}
