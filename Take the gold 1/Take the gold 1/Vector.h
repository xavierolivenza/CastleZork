template <class TYPE>
class Vector{
public:
	Vector(){
		num_elements = 1;
		buffer = new TYPE[capacity];
		for (unsigned int i = 0; i < num_elements; i++){
			buffer[i] = 0;
		}
	}
	Vector(const Vector& v){
		num_elements = v.num_elements;
		capacity = v.capacity;
		buffer = new TYPE[capacity];
		for (unsigned int i = 0; i < num_elements; i++){
			buffer[i] = v.buffer[i];
		}
	}
	~Vector(){
		delete[] buffer;
	}

private:
	TYPE* buffer;
	unsigned int capacity = 10;
	unsigned int num_elements = 0;

public:
	void pushback(const TYPE& num){
		if (capacity == num_elements){
			TYPE* temp = nullptr;
			capacity *= 2;
			temp = new TYPE[capacity];
			for (unsigned int i = 0; i < num_elements; i++){
				*(temp + i) = *(buffer + i);
			}
			delete[]buffer;
			buffer = temp;
		}
		*(buffer + num_elements++) = num;
	}

	void pushfront(const TYPE& num){
		TYPE* temp = nullptr;
		if (capacity == (num_elements + 1)){
			capacity *= 2;
		}
		temp = new TYPE[capacity];
		for (unsigned int i = 0; i < num_elements; i++){
			*(temp + i + 1) = *(buffer + i);
		}
		delete[]buffer;
		buffer = temp;
		*buffer = num;
		num_elements++;
	}

	bool empty(){
		return (num_elements == 0);
	}

	void clear(){
		num_elements = 0;
	}

	unsigned int size(){
		return num_elements;
	}

	unsigned int c_capacity(){
		return capacity;
	}

	void popback(){

	}

	void shrinktofit(){
		TYPE* temp;
		temp = new TYPE[num_elements];



		/*
		String

		char *temp;
		temp = new char[length() + 1];
		strcpy_s(temp, length() + 1, buffer);
		capacity = length() + 1;
		delete[]buffer;
		buffer = new char[capacity];
		strcpy_s(buffer, capacity, temp);

		*/
	}

	TYPE operator[](const int index){
		return buffer[index];
	}
};