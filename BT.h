
#pragma once

/*!
	
	\file
	\brief ������������ ���� � ����������� �������� ������� ��� ���������� ��������� ������
	\author ����������� �����
	\version 1.0
	\date ������� 2015 ����
	
*/

namespace BT1 
{
		typedef int base;
		struct Node //! �������� ���������
		{
			int data;//!<����, ������ ���������� � �����
			Node *leftPtr; //!<��������� �� ����� ���������
			Node *rightPtr; //!<��������� �� ������ ��������� 
			int size; //!<������, ������� �������� � �������� ������
			int theX1;//!<���������� �� �
			int theY1;//!<���������� �� �
			Node (int k) {data = k; leftPtr = rightPtr = 0; size = 1; } //!<�����������
		};
		
		typedef Node* binTree;
		/** \brief ����� ����� k � ������ p.
		*	\param[out] dest �������� ������� ������
		*	\param[in] p �������� ������
		*	\param[in] x ������� �������
		*/
		inline binTree find(binTree p,const base x);

		 /** \brief ������� ������ ������.
		  * \return ������ ������
		  */
		inline binTree Create();

		/** \brief ���������, �� ����� �� ������.
		*	\param[in] binTree �������� ������
		*/
		inline bool isNull(binTree b);

		/** \brief ������� ������ ����� ������.
		*	\param[in] b �������� ������
		*	\return �������� ����� ������
		*/
		inline base RootBT (binTree b); 
		/** \brief ������� �������� � ������ ���������.
		*	\param[in] b �������� ������
		*	\return ����� ���������
		*/
		inline binTree Left1 (binTree b);

		/** \brief ������� �������� � ������� ���������.
		*	\param[in] b �������� ������
		*	\return ������ ���������
		*/
		inline binTree Right1 (binTree b);
		
		/** \brief ������� ���������� �������� � ������.
		*	\param[in] b �������� ������
		*	\param[in] k �������
		*	\return ������ � ����������� � ���� ��������� k
		*/
		inline binTree insert(binTree p, base k); 

		/** \brief ������� ����������� ���������� ������� ������� ������ ������, ������������� � ������� ������� getsize.
		*	\param[in] binTree �������� ������
		*/
		inline void fixsize(binTree p);

		/** \brief ������� ���������� ������� ������ ������.
		*	\param[in] p �������� ������
		*	\return ������ ������
		*/
		inline int getsize(binTree p);

		/** \brief ������� "������������" ������ �������.
		*	\param[in] p �������� ������
		*	\return ���������� ������ ������
		*/
		inline binTree rotateright(binTree p);

		/** \brief ������� "������������" ������ ������.
		*	\param[in] p �������� ������
		*	\return ���������� ����� ������
		*/
		inline binTree rotateleft(binTree p);
		
		/** \brief ������� ��������� ������� � ������ ������.
		*	\param[in] p �������� ������
		*	\param[in] k �������
		*	\return ������������ � ���������� ������� � ������ ������
		*/
		inline binTree insertroot(binTree p, base k);

		/** \brief ������� ���������� ��� ������.
		*	\param[in] p �������� ������
		*	\param[in] q �������� ������
		*	\return ������������ � ���������� ����������� ������
		*/
		inline binTree join(binTree p, binTree q);

		/** \brief ������� ������� ������� �� ������.
		*	\param[in] p �������� ������
		*	\param[in] k �������
		*	\return ������ � ��������� �� ���� ���������
		*/
		inline binTree remove(binTree p, base k);
		
}