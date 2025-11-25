#pragma once
#include <type_traits>
#include <memory>
#include <optional>

namespace asher {
	template<typename T>
	class vector {
		using traits = std::allocator_traits<std::allocator<T>>;
	public:
		vector()
			: data(nullptr), capacity_(1), size_(0) {
				std::cout << "Vector constructed" << std::endl;
			}

		~vector() {
			if(data) {
				std::allocator<T> alloc;
				for(int i = 0; i < size_; ++i) traits::destroy(alloc, &data[i]);
				traits::deallocate(alloc, data, capacity_);
			}

		}

		std::size_t size () const {
			return size_;
		}

		std::size_t capacity () const {
			return capacity_;
		}

		void push_back(T item) {
			std::allocator<T> alloc;

			if(!data) {
				capacity_ = 1;
				size_ = 0;
				data = alloc.allocate(capacity_);
			}

			if(size_ == capacity_) {
				resize(capacity_*3);
			}

			traits::construct(alloc, &data[size_], std::move(item));
			size_++;
		}

		void pop_back() {
			std::allocator<T> alloc;
			traits::destroy(alloc, &data[size_]);
			size_--;
			if(size_ == 0)  {
				traits::deallocate(alloc, data, capacity_);
				data = nullptr;
			}
		}

		void shrink_to_fit () { resize(size_); }

		inline T& operator[](int idx) {
			return data[idx];
		}
		inline T& operator[](int idx) const {
			return data[idx];
		}

		std::optional<T*> dataAddr() const {
			if (data) return data;
			return std::nullopt;
		}

	private:
		T* data = nullptr;
		std::size_t capacity_;
		std::size_t size_;

		void resize(std::size_t newCapacity) {
			std::allocator<T> alloc;
			T* newData = alloc.allocate(newCapacity);
			for(int i = 0; i < size_; ++i) {
				traits::construct(alloc, &newData[i], std::move(data[i]));
				traits::destroy(alloc, &data[i]);
			}
			traits::deallocate(alloc, data, capacity_);
			data = newData;
			capacity_ = newCapacity;
		}
	};
}

