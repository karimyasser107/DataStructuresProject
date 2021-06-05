#pragma once
template <typename T>
class Nodo
{
	T item;
	Nodo<T>* next;
	int sign = 0;
public:
	Nodo();
	Nodo(const T& X);
	Nodo(const T& X, int signo);
	Nodo(Nodo<T>* nextnode,const T& X);
	void setnext(Nodo<T>*nextnode);
	void setsign(int signo);
	int getsign();
	Nodo<T>* getnext();
	T getitem();
	void setitem(const T& X);
};

template<typename T>
inline Nodo<T>::Nodo()
{
	next = nullptr;
}


template<typename T>
inline Nodo<T>::Nodo(const T& X)
{
	item = X;
	next = nullptr;
}

template<typename T>
inline Nodo<T>::Nodo(const T& X, int signo)
{
	item = X;
	sign = signo;
}

template<typename T>
inline Nodo<T>::Nodo(Nodo<T>* nextnode,const T& X)
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
inline void Nodo<T>::setsign(int signo)
{
	sign = signo;
}

template<typename T>
inline int Nodo<T>::getsign()
{
	return sign;
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
inline void Nodo<T>::setitem(const T& X)
{
	item = X;
}

