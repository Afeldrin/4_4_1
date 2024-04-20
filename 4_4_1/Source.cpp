#include <iostream>
#include <vector>
#include <chrono>
#define M 0
using namespace std;

template<typename Container>

void print(Container& cont, char c) {

	for (auto i = cont.begin(); i != cont.end(); ++i) {
		if (i != cont.begin()) {
			cout << c;
		}
		cout << *i;
	}
}

void shellSort(int arr[], int N)
{
	for (int gap = N / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < N; i += 1)
		{
			//сортировка подсписков, созданных с помощью gap 

			int temp = arr[i];

			for (int j = i; j >= gap && arr[j - gap] > temp; j -= gap)
			{
				arr[j] = arr[j - gap];

				arr[j] = temp;
			}
				
		}
	}
}

int main()
{

#if M == 1

	vector<int> data;

	data.reserve(10000);

	for (int i = 0; i != 10000; ++i)
	{
		data.push_back(rand());
	}

	//print(data, ',');

	auto start_time = std::chrono::steady_clock::now();

	for (int i = 0; i < 10000; i++)
	{
		for (int j = 0; j < 9999; j++)
		{
			if (data[j] > data[j + 1])
			{
				int b = data[j];
				data[j] = data[j + 1];
				data[j + 1] = b;
			}
		}
	}

	auto end_time = std::chrono::steady_clock::now();

	auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

	cout << "Elapsed time: " << elapsed_ms.count() << " ms\n";

#else

	int arr[10000];

	for (int i = 0; i != 10000; ++i)
	{
		arr[i] = rand();
	}

	int N = sizeof(arr) / sizeof(arr[0]);

	//cout << "Array to be sorted: \n";
	//for (int i = 0; i < N; i++)
		//cout << arr[i] << " ";
	//cout << endl;

	auto start_time = std::chrono::steady_clock::now();

	shellSort(arr, N);

	auto end_time = std::chrono::steady_clock::now();

	auto elapsed_mcs = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

	cout << "Elapsed time: " << elapsed_mcs.count() << " mcs\n";

	//cout << "\nArray after shell sort: \n";
	//for (int i = 0; i < N; i++)
		//cout << arr[i] << " ";

#endif

	return 0;
}