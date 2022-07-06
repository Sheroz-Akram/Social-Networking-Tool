#include "Event.h"


class MaxHeap {
	Event * arr;
	int Size;
	int Current;

public:

	MaxHeap() {
		arr = NULL;
		Size = 0;
		Current = 0;
	}

	MaxHeap(int Size) {
		arr = new Event[Size];
		this->Size = Size;
		Current = 0;
	}

	Event * getEvents() {
		return arr;
	}

	int getSize() {
		return Size;
	}

	int getTotal() {
		return Current;
	}

	int isHigherPriorityThan(Event a, Event b) {
		if (a.getYear() < b.getYear()) {
			return 1;
		}
		else if ((a.getMonth() < b.getMonth()) && (a.getYear() == b.getYear())) {
			return 1;
		}
		else if ((a.getDate() < b.getDate()) && (a.getMonth() == b.getMonth()) && (a.getYear() == b.getYear())) {
			return 1;
		}
		else if ((a.getHour() < b.getHour()) && (a.getDate() == b.getDate()) && (a.getMonth() == b.getMonth()) && (a.getYear() == b.getYear())) {
			return 1;
		}
		else if ((a.getMinute() < b.getMinute()) && (a.getHour() == b.getHour()) && (a.getDate() == b.getDate()) && (a.getMonth() == b.getMonth()) && (a.getYear() == b.getYear())) {
			return 1;
		}
		else {
			return 0;
		}
	}

	void Swap(int x, int y) {
		int temp = x;
		x = y;
		y = temp;
	}

	Event Top() {
		return arr[0];
	}

	void Insert(Event Data) {
		if (Current < Size) {
			arr[Current] = Data;

			int temp = Current;
			while (Current > 0 && isHigherPriorityThan(arr[temp] , arr[(temp - 1)/2]) )
			{
				swap(arr[temp], arr[(temp - 1) / 2]);
				temp = (temp - 1) / 2;
			}

			Current++;
		}
	}

	void Display() {
		for (int i = 0; i <= Current; i++)
		{
			if (arr[i].getYear() != 0) {
				arr[i].DisplaySmall();
				cout << " , ";
			}
		}
		cout << " ... " << endl;
	}
};