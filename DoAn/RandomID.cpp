#include "RandomID.h"


RandomID::RandomID()
{
    loadFromFile();
}

RandomID::~RandomID()
{
}

int RandomID::getLength()
{
    return n;
}

void RandomID::createListRandom()
{
	nodes = new int[MAX_SIZE_RANDOM + 1];
	n = 0;

	srand(time(NULL));

	// Tạo danh sách các số từ 1 đến max
	for (int i = 0; i < MAX_SIZE_RANDOM; i++) {
		nodes[i] = i + 1;
	}

	// Xáo trộn thứ tự
	for (int i = 0; i < MAX_SIZE_RANDOM; i++) {
		int j = i + rand() % (MAX_SIZE_RANDOM - i);
		int temp = nodes[i];
		nodes[i] = nodes[j];
		nodes[j] = temp;
	}

	// Cập nhật số lượng phần tử;
	n = MAX_SIZE_RANDOM;
    saveToFile();
}

void RandomID::printList()
{
	for (int i = 1; i <= n; i++) {
		cout << nodes[i] << " ";
	}
	cout << endl;
}

// Lưu danh sách xuống tệp
void RandomID::saveToFile() {
    ofstream file(FILE_RANDOM_SAVE, ios::binary);
    if (!file) {
        return;
    }

    // Ghi số lượng phần tử
    file.write((char*)&n, sizeof(n));
    // Ghi mảng nodes
    file.write((char*)nodes, n * sizeof(int));
    file.close();
}

// Tải danh sách từ tệp
void RandomID::loadFromFile() {
    ifstream file(FILE_RANDOM_SAVE, ios::binary);
    if (!file) {
        return;
    }

    // Đọc số lượng phần tử
    file.read((char*)&n, sizeof(n));
    // Cấp phát lại bộ nhớ cho nodes
    delete[] nodes;
    nodes = new int[n];
    // Đọc mảng nodes
    file.read((char*)nodes, n * sizeof(int));
    file.close();

}

int RandomID::getRandomId()
{
    if (n == 0) {
        return -1;
    }

    srand(time(NULL));

    int randomIndex = rand() % n;
    int randomID = nodes[randomIndex];

    // Xóa phần tử vừa lấy ra
    for (int i = randomIndex; i <= n - 1;i++) {
        nodes[i] = nodes[i + 1];
    }

    n--;

    saveToFile();

    return randomID;
}
