#include "Utils.h"
#include "Vector.h"

#include <cstdlib>
#include <cstring>

namespace structures
{
	Vector::Vector(size_t size) :
		memory_(std::calloc(size, 1)),
		size_(size)
	{
	}

	Vector::Vector(Vector& other) :
		Vector(other.size_)
	{
		std::memcpy(this->memory_, other.memory_, this->size_); //ak oba bloky pamate nemaju prekryv, co pri vektoroch musi platit
		//memmove - ked sa pamat prekryva		
	}

	Vector::~Vector()
	{
		free(this->memory_); //ked nizka uroven calloc a malloc,ak new tak delete 
		this->memory_ = nullptr; // jednoduchsie odhalim chybu pripadnu
		this->size_ = 0;
	}

	size_t Vector::size()
	{
		return this->size_;
	}

	Structure& Vector::assign(Structure& other)
	{
		if (this != &other)
		{
			Vector& otherVector = dynamic_cast<Vector&>(other); //dynamicke pretypovanie
			this->memory_ = std::realloc(this->memory_, otherVector.size_);
			std::memcpy(this->memory_, otherVector.memory_, this->size_);
			this->size_ = otherVector.size_;
		}
		return *this;
	}

	bool Vector::equals(Structure& other)
	{
		Vector* otherVector = dynamic_cast<Vector*>(&other); //dynamicke pretypovanie
		if (otherVector == nullptr) {
			return false;
		}
		return this->size_ == otherVector->size_ &&
			memcmp(this->memory_, otherVector->memory_, this->size_) == 0;

	}

	byte& Vector::operator[](int index)
	{
		return at(index);
	}

	byte& Vector::at(int index)
	{
		return *this->getBytePointer(index);
	}

	void Vector::copy(Vector& src, int srcStartIndex, Vector& dest, int destStartIndex, int length)
	{
		//pomocou Utils::rangeCheckExcept skontrolovat:
		// srcStartIndex patri do <0, src.size_)
		// srcStartIndex + length patri do <0, src.size_>
		// destStartIndex patri do <0, dest.size_)
		// destStartIndex + length patri do <0, dest.size_>



		//ak su src a dest identicke, a vzdialenost medzi srcStartIndex a destStartIndex je mensia ako length
		// tak: memmove
		// inak: memcpy



		Utils::rangeCheckExcept(srcStartIndex, src.size_, "Invalid srcStartIndex!");
		Utils::rangeCheckExcept(srcStartIndex + length, src.size_ + 1, "Invalid srcStartIndex!");
		Utils::rangeCheckExcept(destStartIndex, src.size_, "Invalid destStartIndex!");
		Utils::rangeCheckExcept(destStartIndex + length, src.size_ + 1, "Invalid destStartIndex!");



		if (&src == &dest && abs(srcStartIndex - destStartIndex) < length) {
			memmove(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
		}
		else {
			memcpy(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
		}
	}

	byte* Vector::getBytePointer(int index)
	{
		if (index < 0 || index >= this->size_) {
			throw std::out_of_range("Vector::getBytePointer: invalid index.");
		}
		Utils::rangeCheckExcept(index, size_, "Invalid index!");
		return reinterpret_cast<byte*>(this->memory_) + index;
	}
}