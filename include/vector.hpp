#pragma once
#include <type_traits>

namespace asher {
	template<typename T>
	class vector {
	public:
		vector()
			: capacity_(1), size_(0) {
				std::cout << "Vector constructed" << std::endl;
			}

		~vector() {
			delete[] data;
			//data = nullptr;
			std::cout << "Vector desctructed" << std::endl;
		}

		std::size_t size () const {
			return size_;
		}

		std::size_t capacity () const {
			return capacity_;
		}

		void push_back(T item) {
			std::cout << "[Vector] push\n";
			if(size_ == capacity_) {
				std::cout << "[Vector] at capacity must reallocate\n";
				resize(capacity_*3);
			}
			data[size_++] = item;
		}

		void pop_back() {
			// theyve said it wont be called on an empty as a constraint
			size_--;
			std::cout << "[Vector] pop\n";
		}

		void shrink_to_fit () {
			std::cout << "[Vector] shrink to fit \n";
			resize(size_);
		}


		inline T& operator[](int idx) {
			return data[idx];
		}
		inline T& operator[](int idx) const {
			return data[idx];
		}

		T* dataAddr() const { return data; }

	private:
		T* data = new T[1];
		std::size_t capacity_;
		std::size_t size_;

		void resize(std::size_t newCapacity) {
			T* newData = new T[newCapacity];
			std::cout << "new data address: " << newData << "\n";
			for(int i = 0; i < size_; ++i) {
				newData[i] = std::move(data[i]);
			}
			delete[] data;
			data = newData;
			capacity_ = newCapacity;
		}
	};
}

