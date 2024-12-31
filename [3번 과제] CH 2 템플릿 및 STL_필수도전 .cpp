#include <iostream>
#include <algorithm> // sort 함수 포함
using namespace std;

template <typename T>
class SimpleVector {
private:
    T* data;
    int currentSize;
    int currentCapacity;

public:
    // 생성자
    SimpleVector(int capacity = 10) : currentCapacity(capacity), currentSize(0) {
        data = new T[currentCapacity];
    }

    // 복사 생성자
    SimpleVector(const SimpleVector& other)
        : currentSize(other.currentSize), currentCapacity(other.currentCapacity) {
        data = new T[currentCapacity];
        for (int i = 0; i < currentSize; ++i) {
            data[i] = other.data[i];
        }
    }

    // 소멸자
    ~SimpleVector() {
        delete[] data;
    }

    // push_back: 배열이 가득 차면 resize 호출
    void push_back(const T& value) {
        if (currentSize == currentCapacity) {
            resize(currentCapacity + 5);  // 용량을 5만큼 늘리기
        }
        data[currentSize] = value;  // 새 원소 추가
        currentSize++;
    }

    // pop_back: 마지막 원소 제거
    void pop_back() {
        if (currentSize > 0) {
            currentSize--;  // currentSize 감소
        }
        else {
            cout << "배열이 비어 있습니다!" << endl;
        }
    }

    // size 반환
    int size() const {
        return currentSize;
    }

    // capacity 반환
    int capacity() const {
        return currentCapacity;
    }

    // 배열 크기 확장 (resize)
    void resize(int newCapacity) {
        if (newCapacity <= currentCapacity) {
            return;  // 현재 크기보다 작으면 아무 동작도 하지 않음
        }

        // 새로운 배열 할당
        T* newData = new T[newCapacity];

        // 기존 데이터 복사
        for (int i = 0; i < currentSize; ++i) {
            newData[i] = data[i];
        }

        // 기존 배열 메모리 해제
        delete[] data;

        // 새 배열로 data 포인터 변경
        data = newData;
        currentCapacity = newCapacity;
    }

    // 배열 데이터 출력
    void print() const {
        for (int i = 0; i < currentSize; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // 배열 데이터 정렬
    void sortData() {
        sort(data, data + currentSize);  // STL sort 사용
    }
};

int main() {
    SimpleVector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    vec.push_back(60);  // 여기서 resize가 발생

    cout << "배열 크기: " << vec.size() << endl;
    cout << "배열 용량: " << vec.capacity() << endl;

    cout << "정렬 전: ";
    vec.print();  // 배열 원소 출력

    vec.sortData();  // 배열 정렬

    cout << "정렬 후: ";
    vec.print();  // 정렬된 배열 원소 출력

    return 0;
}
