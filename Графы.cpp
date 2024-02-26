
//определение существования графа
#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_ALL, "RU");

	int elem;
	int sum_of_pow = 0, count = 0, count_odd = 0;
	int max_pow = 0;

	int raw_count = 0;

	cout << "Введите количество вершин графа: ";
	cin >> raw_count;

	if (raw_count < 1) {
		cout << "Графа не существует.";
		return;
	}

	cout << "Введите степени графа" << endl;

	cin >> elem;

	while (--raw_count > 0)
	{
		if (elem < 0) {
			cout << "Элемент не может быть меньше нуля! Введите заново!\n";
			raw_count++;
			continue;
		}
		else if (elem != 0)
		{
			if (elem % 2 != 0) { count_odd++; } //считаем количество нечетных вершин

			count++;

			sum_of_pow += elem;

			if (elem > max_pow)
				max_pow = elem;       //если сушествует степень вершины больше, чем колличество, то граф не будет существ. 

		}
		cin >> elem;
	}

	if (count < max_pow) {
		cout << "Такого графа нет т.к количество вершин не превышает максимальную степень вершины\n";
	}
	else if (count >= sum_of_pow) {
		cout << "Такого графа нет т.к сумма степеней не превышает количество вершин\n";
	}
	else if (sum_of_pow % 2 != 0) {
		cout << "Такого графа нет т.к сумма степеней нечетна\n";
	}
	else if (count_odd % 2 != 0) {
		cout << "Такого графа нет т.к количество нечетных степеней нечетно\n";
	}
	else {
		cout << "Такой граф существует.";
	}
}