#ifndef _H_TEMPLATECLASS_H_
#define _H_TEMPLATECLASS_H_

class TemplateClass {
public:
	template <class T>
	static T* createArray (T num1, int length);
};

template float* TemplateClass::createArray<float>(float num, int length);
template char* TemplateClass::createArray<char>(char num, int length);
template double* TemplateClass::createArray<double>(double num, int length);

#endif