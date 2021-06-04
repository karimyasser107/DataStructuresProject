#pragma once
template <typename T>
class Nodo
{
	T item;
	Nodo<T>* next;
public:
	Nodo();
	Nodo(T& X);
	Nodo(Nodo<T>* nextnode, T& X);
	void setnext(Nodo<T>*nextnode);
	Nodo<T>* getnext();
	T getitem();
	void setitem(T& X);
};

template<typename T>
inline Nodo<T>::Nodo()
{
	next = nullptr;
}


template<typename T>
inline Nodo<T>::Nodo(T& X)
{
	item = X;
	next = nullptr;
}

template<typename T>
inline Nodo<T>::Nodo(Nodo<T>* nextnode, T& X)
{
	item = X;
	next = nextnode;
}

template<typename T>
inline void Nodo<T>::setnext(Nodo<T>* nextnode)
{
	next = nextnode;
}

template<typename T>
inline Nodo<T>* Nodo<T>::getnext()
{
	return next;
}

template<typename T>
inline T Nodo<T>::getitem()
{
	return item;
}

template<typename T>
inline void Nodo<T>::setitem(T& X)
{
	item = X;
}

