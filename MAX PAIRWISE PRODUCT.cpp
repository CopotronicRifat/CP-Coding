#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int MaxPairwiseProduct(vector<int>& numbers)
{
    int result = 0;
    int n = numbers.size();
    int max= numbers[0];
    int maxpos=0;
    int max2=numbers[0];
    for (int i = 0; i < n; ++i)
    {
        if(numbers[i]>=max)
        {
            max=numbers[i];
            maxpos=i;

        }
    }
    numbers.insert(numbers.begin()+maxpos, 0);
    for (int i = 0; i < n; ++i)
    {
        if(numbers[i]>=max2)
        {
            max2=numbers[i];
        }
    }
    return max*max2;
}

int main()
{
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> numbers[i];
    }

    int result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}
