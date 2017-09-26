#include "TemplateClass.h"
#include<iostream>
template <class T>
T* TemplateClass::createArray(T num1, int length) {
	T* array1 = new T[length];
	for (int i = 0; i < length; i++) {
		array1[i] = num1;
	}
	return array1;
}

int main() {
	float* array1 = TemplateClass::createArray<float>(2.0f, 20);
	for (int i = 0; i < 20; i++) {
		std::cout << i << "\t" << array1[i] << std::endl;
	}
}