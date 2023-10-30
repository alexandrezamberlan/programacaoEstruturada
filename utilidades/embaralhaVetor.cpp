// C++ program to shuffle
// the given array
// using shuffle() method

#include <bits/stdc++.h>
using namespace std;

void show_array(int arr[], int n)
{
    // Printing our array
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

// embaralhando um array
void shuffle_array(int arr[], int n)
{

	// To obtain a time-based seed
	unsigned seed = 0;

	// Shuffling our array
	shuffle(arr, arr + n, default_random_engine(seed));
}

// Driver code
int main()
{
	int vetor[] = { 1, 2, 3, 4, 5, 6, 7 };

	int tamanho = sizeof(vetor) / sizeof(vetor[0]);

	shuffle_array(vetor, tamanho);

    show_array(vetor, tamanho);

	return 1;
}
