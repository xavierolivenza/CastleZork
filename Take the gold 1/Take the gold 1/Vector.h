#ifndef _Vector_
#define _Vector_

#include<assert.h>

template <class TYPE>
class Vector{
public:
	Vector(){
		buffer = new TYPE[capacity];
	}
	Vector(const Vector& v){
		capacity = v.num_elements;
		buffer = new TYPE[capacity];
		if (v.num_elements > 0){
			num_elements = v.num_elements;
			for (unsigned int i = 0; i < num_elements; i++){
				buffer[i] = v.buffer[i];
			}
		}
	}
	~Vector(){
		delete[] buffer;
	}

private:
	TYPE* buffer = nullptr;
	unsigned int capacity = 10;
	unsigned int num_elements = 0;

public:
	void pushback(const TYPE& num){
		if (capacity == num_elements){
			TYPE* temp = nullptr;
			capacity += 7;
			temp = new TYPE[capacity];
			for (unsigned int i = 0; i < num_elements; i++){
				temp[i] = buffer[i];
			}
			delete[]buffer;
			buffer = temp;
		}
		*(buffer + num_elements++) = num;
	}

	void pushfront(const TYPE& num){
		if (capacity == num_elements){
			TYPE *temp = nullptr;
			capacity += 7;
			temp = new TYPE[capacity];
			for (unsigned int i = 0; i < num_elements; i++){
				temp[i] = buffer[i];
			}
			delete[]buffer;
			buffer = temp;
		}
		for (unsigned int i = num_elements - 1; i >= 0; i--){
			temp[i + 1] = buffer[i];
		}
		*buffer = num;
		num_elements++;
	}

	bool empty() const{
		return (num_elements == 0);
	}

	void clear(){
		num_elements = 0;
	}

	unsigned int size() const{
		return num_elements;
	}

	unsigned int c_capacity() const{
		return capacity;
	}

	void popback(){
		if (num_elements > 0){
			num_elements--;
		}
	}

	void shrinktofit(){
		if (capacity != num_elements){
			TYPE* temp = nullptr;
			capacity = num_elements;
			temp = new TYPE[capacity];
			for (unsigned int = 0; i < capacity; i++){
				temp[i] = buffer[i];
			}
			delete[]vector;
			buffer = temp;
		}
	}

	const TYPE operator[](const int index) const{
		//printf("%i, %i", index, num_elements);
		assert(index >= 0 && index < num_elements);
		return buffer[index];
	}
};
#endif //_Vector_