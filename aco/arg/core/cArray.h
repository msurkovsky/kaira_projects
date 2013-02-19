/***************************************************************************}
 {																			}
 {    cArray.h																}
 {																			}
 {																			}
 {                 Copyright (c) 1998, 2011				Vaclav Snasel		}
 {																			}
 {    VERSION: 3.0										DATE 3/5/1998		}
 {																			}
 {             following functionality:										}
 {																			}
 {																			}
 {    UPDATE HISTORY:														}
 {																			}
 {																			}
 {***************************************************************************/

#ifndef __CARRAY_H__
#define __CARRAY_H__

#pragma once

#include <cstdio>
#include <memory.h>
#include <iostream>

#include "cIterator.h"

namespace arg
{
	template<class T>
	class cArrayConst
	{
		public:
			cArrayConst();
			~cArrayConst();
			const cArrayConst<T>& operator =(const cArrayConst& other);
			inline T operator[](const unsigned int Index) const;
			inline T& operator[](const unsigned int Index);
			inline operator T*(void);
			inline unsigned int Size(void) const;
			inline unsigned int Count(void) const;
			inline void Clear(void);
			inline void Resize(const unsigned int Size, const bool Move = false);
			inline void Resize(const unsigned int Size, const unsigned int Count);
			void Move(const T* Array, const unsigned int Count = 1);
			unsigned int Add(const T* Array, const unsigned int Count = 1);
			bool Delete(const unsigned int Index);
			inline void Left(const unsigned int Count);
			inline void Right(const unsigned int Count);
			inline void Append(const T& Value);
			inline T* GetArray(const unsigned int Index);
		private:
			unsigned int m_Size;
			unsigned int m_Count;
			T* m_Array;
			void m_Resize(const unsigned int Size, const bool Move);
	};

	template<class T>
	std::ostream& operator<<(std::ostream& os, const cArrayConst<T>& ts)
	{
		os << "[ ";
		for (unsigned int i = 0; i < ts.Count(); i++)
		{
			os << ts[i] << " ";
		}
		os << "]";
		return os;
	}

	template<class T>
	cArrayConst<T>::cArrayConst() :
		m_Size(0), m_Count(0), m_Array(0)
	{
	}

	template<class T>
	cArrayConst<T>::~cArrayConst()
	{
		m_Resize(0, false);
	}

	template<class T>
	const cArrayConst<T>& cArrayConst<T>::operator =(const cArrayConst& other)
	{
		if (this != &other)
		{
			Move((T*) (*(const_cast<cArrayConst<T>*> (&other))), other.Count());
		}
		return *this;
	}

	template<class T>
	T cArrayConst<T>::operator[](const unsigned int Index) const
	{
		return m_Array[Index];
	}

	template<class T>
	T& cArrayConst<T>::operator[](const unsigned int Index)
	{
		return m_Array[Index];
	}

	template<class T>
	cArrayConst<T>::operator T*(void)
	{
		return m_Array;
	}

	template<class T>
	unsigned int cArrayConst<T>::Size(void) const
	{
		return m_Size;
	}

	template<class T>
	unsigned int cArrayConst<T>::Count(void) const
	{
		return m_Count;
	}

	template<class T>
	void cArrayConst<T>::Clear(void)
	{
		m_Resize(0, false);
	}

	template<class T>
	void cArrayConst<T>::Resize(const unsigned int Size, const bool Move)
	{
		m_Resize(Size, Move);
	}

	template<class T>
	void cArrayConst<T>::Resize(const unsigned int Size, const unsigned int Count)
	{
		m_Resize(Size, false);
		m_Count = Count < m_Size ? Count : m_Size;
	}

	template<class T>
	void cArrayConst<T>::Move(const T* Array, const unsigned int Count)
	{
		if (m_Size <= Count)
		{
			m_Resize(Count, false);
		}
		memcpy(m_Array, Array, sizeof(T) * Count);
		m_Count = Count;
	}

	template<class T>
	unsigned int cArrayConst<T>::Add(const T* Array, const unsigned int Count)
	{
		unsigned int iRet;
		if (m_Count + Count >= m_Size)
		{
			m_Resize(m_Count + Count, true);
		}
		iRet = m_Count;
		if (Count == 1)
		{
			m_Array[m_Count++] = *Array;
		}
		else
		{
			memcpy((char *) &m_Array[m_Count], Array, sizeof(T) * Count);
			m_Count += Count;
		}
		return iRet;
	}

	template<class T>
	bool cArrayConst<T>::Delete(const unsigned int Index)
	{
		bool bRet = false;
		if (Index < m_Count)
		{
			if (m_Count == 1)
			{
				m_Count = 0;
				bRet = true;
			}
			else if (m_Count > 0)
			{
				m_Array[Index] = m_Array[--m_Count];
				bRet = true;
			}
		}
		return bRet;
	}

	template<class T>
	void cArrayConst<T>::Left(const unsigned int Count)
	{
		m_Count = Count < m_Count ? Count : m_Count;
	}

	template<class T>
	void cArrayConst<T>::Right(const unsigned int Count)
	{
		unsigned int tmp = (m_Count < Count ? 0 : m_Count - Count);
		unsigned int mCount = (m_Count < Count ? m_Count : Count);
		memmove(m_Array, (char*) &m_Array[tmp], sizeof(T) * mCount);
		m_Count = mCount;
	}

	template<class T>
	void cArrayConst<T>::Append(const T& Value)
	{
		if (!(m_Count < m_Size))
		{
			m_Resize(m_Size + 1, true);
		}
		m_Array[m_Count++] = Value;
	}

	template<class T>
	T* cArrayConst<T>::GetArray(const unsigned int Index)
	{
		return &m_Array[Index];
	}

	template<class T>
	void cArrayConst<T>::m_Resize(const unsigned int Size, const bool Move)
	{
		if (Size > m_Size)
		{
			unsigned int mSize = (Size & 7) ? Size + (8 - (Size & 7)) : Size;

			T *auxPtr = new T[mSize];
			if (Move && m_Array != 0)
			{
				memcpy(auxPtr, m_Array, sizeof(T) * (m_Count < mSize ? m_Count : mSize));
			}
			if (m_Array != 0)
			{
				delete[] m_Array;
			}
			m_Array = auxPtr;
			m_Size = mSize;
			if (m_Count > m_Size)
			{
				m_Count = m_Size;
			}
		}
		else if (Size == 0)
		{
			if (m_Array != 0)
			{
				delete[] m_Array;
				m_Array = 0;
			}
			m_Size = m_Count = 0;
		}
	}

	template<class T>
	class cArrayIterator;

	/**************************************************************************
	 cArrayPointer
	 ***************************************************************************/

	template<class T>
	class cArrayPointer
	{
		public:

			cArrayPointer();
			virtual ~cArrayPointer();
			inline unsigned int Count() const;
			inline virtual bool Insert(T* item) = 0;
			inline virtual bool Delete(const T* item);
			virtual bool Delete(const unsigned int index) = 0;
			inline virtual bool Free(const unsigned int index) = 0;
			inline T* operator[](const unsigned int index) const;
			virtual bool Find(const T* item, unsigned int& index) const = 0;
			friend class cArrayIterator<T> ;
			inline void DeleteAll();
			void FreeAll();

		protected:

			void Resize(const unsigned int Size);
			void m_set(const cArrayPointer<T>* Array);
			T** m_Items;
			unsigned int m_Count;
			unsigned int m_Size;
			int m_Status;
	};

	/**************************************************************************
	 cArray
	 ***************************************************************************/

	template<class T>
	class cArray: public cArrayPointer<T>
	{
		public:
			cArray(void);
			cArray(const cArray<T>* Array);
			virtual ~cArray();
			cArray<T>& operator =(const cArrayPointer<T>* Array);
			cArray<T>& operator =(const cArray<T>* Array);
			inline virtual bool Insert(T* item);
			inline virtual bool Delete(const unsigned int index);
			inline virtual bool Free(const unsigned int index);
			inline virtual bool Find(const T* item, unsigned int& index) const;
	};

	/**************************************************************************
	 cSortedArray
	 ***************************************************************************/

	template<class T>
	class cSortedArray: public cArrayPointer<T>
	{
		public:
			cSortedArray();
			cSortedArray(const cArrayPointer<T>* Array);
			virtual ~cSortedArray();
			cSortedArray<T>& operator =(const cArrayPointer<T>* Array);
			cSortedArray<T>& operator =(const cSortedArray<T>* Array);
			inline virtual bool Insert(T* item);
			inline virtual bool Delete(const unsigned int index);
			inline virtual bool Free(const unsigned int index);
			inline virtual bool Find(const T* item, unsigned int& index) const;
			void SetDuplicate(const bool Duplicate);
			bool GetDuplicate() const;
		protected:

			bool m_Duplicate;
			bool m_Find(const T* item, unsigned int& index, int& r) const;
	};

	/**************************************************************************
	 cArrayIterator
	 ***************************************************************************/

	template<class T>
	class cArrayIterator: public arg::cIterator<T>
	{
		public:
			cArrayIterator(cArrayPointer<T>* ArrayTmp);
			virtual void Next(void);
			virtual void Reset(void);
			virtual T& Data(void);
		private:
			cArrayPointer<T>* m_ArrayTmp;
			unsigned int m_current;
	};

	/**************************************************************************
	 cArrayPointer
	 ***************************************************************************/

	template<class T>
	cArrayPointer<T>::cArrayPointer() :
		m_Items(0), m_Count(0), m_Size(0), m_Status(0)
	{
	}

	template<class T>
	cArrayPointer<T>::~cArrayPointer()
	{
		Resize(0);
	}

	template<class T>
	inline unsigned int cArrayPointer<T>::Count() const
	{
		return m_Count;
	}

	template<class T>
	bool cArrayPointer<T>::Delete(const T* item)
	{
		unsigned int index;
		if (!Find(item, index))
		{
			return true;
		}
		else
		{
			return Delete(index);
		}
	}

	template<class T>
	T* cArrayPointer<T>::operator[](const unsigned int index) const
	{
		if (index >= m_Count)
		{
			return 0;
		}
		else
		{
			return m_Items[index];
		}
	}

	template<class T>
	void cArrayPointer<T>::Resize(const unsigned int Size)
	{
		T** tmp = 0;
		if (Size > 0)
		{
			unsigned int mSize = (Size & 7) ? Size + (8 - (Size & 7)) : Size;
			tmp = new T*[mSize];

			m_Count = (m_Count < mSize) ? m_Count : mSize;
			if (m_Items != 0)
			{
				memcpy(tmp, m_Items, sizeof(T*) * m_Count);
			}
			m_Size = mSize;
		}
		else
		{
			m_Size = m_Count = 0;
		}

		if (m_Items != 0)
		{
			delete[] m_Items;
		}
		m_Items = tmp;
	}

	template<class T>
	void cArrayPointer<T>::m_set(const cArrayPointer<T>* Array)
	{
		int n = Array->Count();
		Resize(n);
		m_Count = 0;
		for (int i = 0; i < n; i++)
		{
			Insert(const_cast<T*> ((*Array)[i]));
		}
	}

	template<class T>
	inline void cArrayPointer<T>::DeleteAll()
	{
		Resize(0);
	}

	template<class T>
	void cArrayPointer<T>::FreeAll()
	{
		for (unsigned int i = 0; i < m_Count; i++)
		{
			delete m_Items[i];
		}
		Resize(0);
	}

	/**************************************************************************
	 cArray
	 ***************************************************************************/

	template<class T>
	cArray<T>::cArray(void) : cArrayPointer<T> ()
	{
	}

	template<class T>
	cArray<T>::cArray(const cArray<T>* Array) :
		cArrayPointer<T> ()
	{
		Resize(Array->Count());
		*this = Array;
	}

	template<class T>
	cArray<T>::~cArray()
	{
	}

	template<class T>
	cArray<T>& cArray<T>::operator=(const cArrayPointer<T>* Array)
	{
		if (Array != this)
		{
			m_set(Array);
		}
		return *this;
	}

	template<class T>
	cArray<T>& cArray<T>::operator =(const cArray<T>* Array)
	{
		if (Array != this)
		{
			m_set(Array);
		}
		return *this;
	}

	template<class T>
	bool cArray<T>::Insert(T* item)
	{
		if (this->m_Count >= this->m_Size)
		{
			Resize(this->m_Size + 1);
		}
		//TODO this was most definitely an error
		this->m_Items[this->m_Count++] = item;
		return true;
	}

	template<class T>
	bool cArray<T>::Delete(const unsigned int index)
	{
		if (this->m_Count > 0 && index < this->m_Count)
		{
			this->m_Items[index] = this->m_Items[--(this->m_Count)];
			return true;
		}
		return false;
	}

	template<class T>
	bool cArray<T>::Free(const unsigned int index)
	{
		if (this->m_Count > 0 && index < this->m_Count)
		{
			delete (this->m_Items[index]);
			this->m_Items[index] = this->m_Items[--(this->m_Count)];
			return true;
		}
		return false;
	}

	template<class T>
	bool cArray<T>::Find(const T* item, unsigned int& index) const
	{
		bool bRet = false;

		index = 0;
		for (unsigned int i = 0; i < this->m_Count; i++)
		{
			if (item->Relat(this->m_Items[i]) == 0)
			{
				bRet = true;
				index = i;
				break;
			}
		}
		return bRet;
	}

	/**************************************************************************
	 cSortedArray
	 ***************************************************************************/

	template<class T>
	cSortedArray<T>::cSortedArray() :
		cArrayPointer<T> (), m_Duplicate(false)
	{
	}

	template<class T>
	cSortedArray<T>::cSortedArray(const cArrayPointer<T>* Array) :
		cArrayPointer<T> ()
	{
		Resize(Array->Count());
		*this = Array;
	}

	template<class T>
	cSortedArray<T>::~cSortedArray()
	{
	}

	template<class T>
	cSortedArray<T>& cSortedArray<T>::operator =(const cArrayPointer<T>* Array)
	{
		if (Array != this)
		{
			m_set(Array);
		}
		return *this;
	}

	template<class T>
	cSortedArray<T>& cSortedArray<T>::operator =(const cSortedArray<T>* Array)
	{
		if (Array != this)
		{
			m_set(Array);
		}
		return *this;
	}

	template<class T>
	bool cSortedArray<T>::Insert(T* item)
	{
		unsigned int index;
		int r;

		if (m_Find(item, index, r))
		{
			if (!m_Duplicate)
			{
				return true;
			}
		}

		if (this->m_Count >= this->m_Size)
		{
			Resize(this->m_Size + 1);
		}

		if (!m_Duplicate)
		{
			if (r > 0)
				index++;
		}
		else
		{
			if (r > 0)
			{
				index++;
				while (index < this->m_Count && item->Relat(this->m_Items[index]) == 0)
					index++;
			}
			else if (r < 0)
			{
				while (index > 1 && item->Relat(this->m_Items[index - 1]) == 0)
					index--;

			}
		}

		for (unsigned int n = this->m_Count; n > index; n--)
		{
			this->m_Items[n] = this->m_Items[n - 1];
		}
		this->m_Items[index] = item;

		(this->m_Count)++;
		return true;
	}

	template<class T>
	bool cSortedArray<T>::Delete(const unsigned int index)
	{
		if (this->m_Count > 0 && index < this->m_Count)
		{
			(this->m_Count)--;
			for (unsigned int i = index; i < this->m_Count; i++)
			{
				this->m_Items[i] = this->m_Items[i + 1];
			}
			return true;
		}

		return false;
	}

	template<class T>
	bool cSortedArray<T>::Free(const unsigned int index)
	{
		if (this->m_Count > 0 && index < this->m_Count)
		{
			(this->m_Count)--;
			delete (this->m_Items[index]);
			for (unsigned int i = index; i < this->m_Count; i++)
			{
				this->m_Items[i] = this->m_Items[i + 1];
			}
			return true;
		}

		return false;
	}

	template<class T>
	bool cSortedArray<T>::Find(const T* item, unsigned int& index) const
	{
		int r;
		return m_Find(item, index, r);
	}

	template<class T>
	void cSortedArray<T>::SetDuplicate(const bool Duplicate)
	{
		m_Duplicate = Duplicate;
	}

	template<class T>
	bool cSortedArray<T>::GetDuplicate() const
	{
		return m_Duplicate;
	}

	template<class T>
	bool cSortedArray<T>::m_Find(const T* item, unsigned int& index, int& r) const
	{
		int h = this->m_Count - 1;
		int l = 0;
		int mid = 0;
		int tmp = 0;
		bool bRet = false;

		if (this->m_Count != 0)
		{
			while (l <= h)
			{
				mid = (h + l) >> 1;
				tmp = item->Relat(this->m_Items[mid]);
				if (tmp < 0)
				{
					h = mid - 1;
				}
				else if (tmp > 0)
				{
					l = mid + 1;
				}
				else
				{
					bRet = true;
					break;
				}
			}
		}
		index = mid;
		r = tmp;
		return bRet;
	}

	/**************************************************************************
	 cArrayIterator
	 ***************************************************************************/

	template<class T>
	cArrayIterator<T>::cArrayIterator(cArrayPointer<T>* ArrayTmp) :
		cIterator<T> (), m_ArrayTmp(ArrayTmp), m_current(0)
	{
	}

	template<class T>
	void cArrayIterator<T>::Next(void)
	{
		if (m_current < m_ArrayTmp->Count())
		{
			m_current++;
		}
		this->m_IterationComplete = (m_current == m_ArrayTmp->Count());
	}

	template<class T>
	void cArrayIterator<T>::Reset(void)
	{
		m_current = 0;
		this->m_IterationComplete = m_ArrayTmp->Count() == 0;
	}

	template<class T>
	T& cArrayIterator<T>::Data(void)
	{
		return (*(*m_ArrayTmp)[m_current]);
	}
}

#endif //    __CARRAY_H__
