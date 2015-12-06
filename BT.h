
#pragma once

/*!
	
	\file
	\brief Заголовочный файл с объявлением основных функций для реализации бинарного дерева
	\author Осмоловский Павел
	\version 1.0
	\date Декабрь 2015 года
	
*/

namespace BT1 
{
		typedef int base;
		struct Node //! Основная структура
		{
			int data;//!<Ключ, данные хранящиеся в листе
			Node *leftPtr; //!<указатель на левое поддерево
			Node *rightPtr; //!<указатель на правое поддерево 
			int size; //!<Размер, уровень элемента в бинарном дереве
			int theX1;//!<Координаты по х
			int theY1;//!<Координаты по у
			Node (int k) {data = k; leftPtr = rightPtr = 0; size = 1; } //!<конструктор
		};
		
		typedef Node* binTree;
		/** \brief Поиск ключа k в дереве p.
		*	\param[out] dest Исходная область памяти
		*	\param[in] p Бинарное Дерево
		*	\param[in] x Искомый элемент
		*/
		inline binTree find(binTree p,const base x);

		 /** \brief Создает пустое дерево.
		  * \return Пустое дерево
		  */
		inline binTree Create();

		/** \brief Проверяет, не пусто ли дерево.
		*	\param[in] binTree Бинарное Дерево
		*/
		inline bool isNull(binTree b);

		/** \brief Функция поиска корня дерева.
		*	\param[in] b Бинарное Дерево
		*	\return Значение корня дерева
		*/
		inline base RootBT (binTree b); 
		/** \brief Функция перехода к левому поддереву.
		*	\param[in] b Бинарное Дерево
		*	\return Левое поддерево
		*/
		inline binTree Left1 (binTree b);

		/** \brief Функция перехода к правому поддереву.
		*	\param[in] b Бинарное Дерево
		*	\return Правое поддерево
		*/
		inline binTree Right1 (binTree b);
		
		/** \brief Функция добавления элемента в дерево.
		*	\param[in] b Бинарное Дерево
		*	\param[in] k Элемент
		*	\return Дерево с добавленным в него элементом k
		*/
		inline binTree insert(binTree p, base k); 

		/** \brief Функция присваивает переменной размера текущий размер дерева, высчитываемый с помощью функции getsize.
		*	\param[in] binTree Бинарное Дерево
		*/
		inline void fixsize(binTree p);

		/** \brief Функция возвращает текущий размер дерева.
		*	\param[in] p Бинарное Дерево
		*	\return Размер дерева
		*/
		inline int getsize(binTree p);

		/** \brief Функция "поворачивает" дерево направо.
		*	\param[in] p Бинарное Дерево
		*	\return Повернутое вправо дерево
		*/
		inline binTree rotateright(binTree p);

		/** \brief Функция "поворачивает" дерево налево.
		*	\param[in] p Бинарное Дерево
		*	\return Повернутое влево дерево
		*/
		inline binTree rotateleft(binTree p);
		
		/** \brief Функция вставляет элемент в корень дерева.
		*	\param[in] p Бинарное Дерево
		*	\param[in] k элемент
		*	\return Получившееся в результате вставки в корень дерево
		*/
		inline binTree insertroot(binTree p, base k);

		/** \brief Функция объединяет два дерева.
		*	\param[in] p Бинарное Дерево
		*	\param[in] q Бинарное Дерево
		*	\return Получившееся в результате объединения дерево
		*/
		inline binTree join(binTree p, binTree q);

		/** \brief Функция удаляет элемент из дерева.
		*	\param[in] p Бинарное Дерево
		*	\param[in] k элемент
		*	\return Дерево с удаленным из него элементом
		*/
		inline binTree remove(binTree p, base k);
		
}