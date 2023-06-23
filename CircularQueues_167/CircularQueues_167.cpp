#include <iostream>
using namespace std;

class Queues {
	int FRONT, REAR, max = 5;
	int queue_arrray[5];

public:
	Queues() {
		FRONT = -1;
		REAR = -1;
	}

	void insert() {
		int num;
		cout << "Enter a umber:";
		cin >> num;
		cout << endl;

		// max = n (jmlh index)
		// Cek apakah antrian penuh
		if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
			cout << "\nQueues over flow\n";
			return;
		}

		// cek apakah antrian kosong
		if (FRONT == -1) {
			FRONT = 0;
			REAR = 0;
		}
		else {
			//jika REAR berada diposisi terakhir array, kembali ke awal array
			if (REAR == max - 1)
				REAR = 0;
			else
				REAR = REAR + 1;
		}
		queue_arrray[REAR] = num; //step 4
	}

	void remove() {
		// cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "Queue underflow\n";
			return;

		}

		cout << "\n The element deleted from the queue is :" << queue_arrray[FRONT] << "\n";

		// cek antrian jika hanya memiliki satu elemen
		if (FRONT == REAR) {
			FRONT = -1;
			REAR = -1;
		}
		else {
			//jika elemen yang akan dihapus berada diposisi terakhir array, kembali ke awl array
			if (FRONT == max - 1)
				FRONT = 0;
			else
				FRONT = FRONT + 1;
		}
		
	}
	void display() {
		int FRONT_position = FRONT;
		int REAR_position = REAR;
	
		// cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "Queue is empty\n";
			return;
		}

		cout << "\nElement is the queue are...\n";

		// jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR 
		if (FRONT_position <= REAR_position) {
			while (FRONT_position <= REAR_position) {
				cout << queue_arrray[FRONT_position] << " ";
				FRONT_position++;
			}
			cout << endl;
		}
	}
};