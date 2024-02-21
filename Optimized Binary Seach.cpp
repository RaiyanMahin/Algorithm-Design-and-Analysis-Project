#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n; vector < int > a(n, 0);
    for(auto &i : a) cin >> i;

    int low = 0, high = n - 1;

    int value; cin >> value;

    int flag = 0;

    while(low <= high)
    {
        int avg_var = (a[high] - a[low]) / (high - low);

        int guess_index = ((value - a[low]) / avg_var) + low;

        if(a[guess_index] == value)
        {
            cout << "Element Found\n";
            flag = 1;
            return;
        }
        else
        {
            if(value > a[guess_index])
            {
                low = guess_index + 1;
            }
            else
            {
                high = guess_index - 1;
            }

            if( (a[low + ((high - low) / 2) ] <= value) )
            {
                low = low + ((high - low) / 2);
            }
            else
            {
                high = high - ((high - low) / 2);

            }
        }
    }

    if(flag == 0)
    {
        cout << "Value not found\n";
    }

    return;
}

int main()
{
    solve();
}
