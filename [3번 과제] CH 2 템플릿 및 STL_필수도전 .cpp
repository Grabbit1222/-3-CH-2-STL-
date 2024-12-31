#include <iostream>
#include <algorithm> // sort �Լ� ����
using namespace std;

template <typename T>
class SimpleVector {
private:
    T* data;
    int currentSize;
    int currentCapacity;

public:
    // ������
    SimpleVector(int capacity = 10) : currentCapacity(capacity), currentSize(0) {
        data = new T[currentCapacity];
    }

    // ���� ������
    SimpleVector(const SimpleVector& other)
        : currentSize(other.currentSize), currentCapacity(other.currentCapacity) {
        data = new T[currentCapacity];
        for (int i = 0; i < currentSize; ++i) {
            data[i] = other.data[i];
        }
    }

    // �Ҹ���
    ~SimpleVector() {
        delete[] data;
    }

    // push_back: �迭�� ���� ���� resize ȣ��
    void push_back(const T& value) {
        if (currentSize == currentCapacity) {
            resize(currentCapacity + 5);  // �뷮�� 5��ŭ �ø���
        }
        data[currentSize] = value;  // �� ���� �߰�
        currentSize++;
    }

    // pop_back: ������ ���� ����
    void pop_back() {
        if (currentSize > 0) {
            currentSize--;  // currentSize ����
        }
        else {
            cout << "�迭�� ��� �ֽ��ϴ�!" << endl;
        }
    }

    // size ��ȯ
    int size() const {
        return currentSize;
    }

    // capacity ��ȯ
    int capacity() const {
        return currentCapacity;
    }

    // �迭 ũ�� Ȯ�� (resize)
    void resize(int newCapacity) {
        if (newCapacity <= currentCapacity) {
            return;  // ���� ũ�⺸�� ������ �ƹ� ���۵� ���� ����
        }

        // ���ο� �迭 �Ҵ�
        T* newData = new T[newCapacity];

        // ���� ������ ����
        for (int i = 0; i < currentSize; ++i) {
            newData[i] = data[i];
        }

        // ���� �迭 �޸� ����
        delete[] data;

        // �� �迭�� data ������ ����
        data = newData;
        currentCapacity = newCapacity;
    }

    // �迭 ������ ���
    void print() const {
        for (int i = 0; i < currentSize; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // �迭 ������ ����
    void sortData() {
        sort(data, data + currentSize);  // STL sort ���
    }
};

int main() {
    SimpleVector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    vec.push_back(60);  // ���⼭ resize�� �߻�

    cout << "�迭 ũ��: " << vec.size() << endl;
    cout << "�迭 �뷮: " << vec.capacity() << endl;

    cout << "���� ��: ";
    vec.print();  // �迭 ���� ���

    vec.sortData();  // �迭 ����

    cout << "���� ��: ";
    vec.print();  // ���ĵ� �迭 ���� ���

    return 0;
}
