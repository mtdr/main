/*!
	\file
	\brief ���������� ������� ��� ������
	\author ����������� �����
	\version 1.0
	\date ������� 2015 ����
	
*/
#pragma once
#include <iostream>
#include "BT.h"

using namespace std;

namespace BT1
{
	/*!
		*������� ������ ������.
		*\return ������ ������
		*/
	inline binTree Create()
	{	
		return NULL;
	}
//-------------------------------------
	inline bool isNull(binTree b)
	{	
		return (b == NULL);
	}
//-------------------------------------
	inline base RootBT (binTree b)			//!< ��� ��������� ���.������
	{	
		if (b == NULL) return 0;
		else return b->data;
	}
//-------------------------------------	
	inline binTree Left1 (binTree b)		//!< ��� ��������� ���.������
	{	
		if (b == NULL) return 0;
		else return b ->leftPtr;
	}
//-------------------------------------	
	inline binTree Right1 (binTree b)		//!< ��� ��������� ���.������
	{	
		if (b == NULL) return 0;
		else return b->rightPtr;
	}


	

	inline binTree find(binTree p, const base k) //!< ����� ����� k � ������ p
{
    if( !p ) return 0; //!< � ������ ������ ����� �� ������
    if( k == p->data )
        return p; 
    if( k < p->data )
        return find(p->leftPtr,k); 
    else
        return find(p->rightPtr,k); 
}
 

	inline binTree insert( binTree p, int k) //!< ����������������� ������� ������ ���� � ������ k � ������ p
	{
		if( !p ) return new Node(k); 
		else 
		{
		
		if( rand()%(p->size+1) == 0 ) 
			return insertroot(p,k);
		else
		{
		if( p->data>k ) 
			p->leftPtr = insert(p->leftPtr,k); 
		else
			p->rightPtr = insert(p->rightPtr,k); 
		fixsize(p); 
		return p; 
		}
		}
	}

	inline int getsize(binTree p) //!< ������� ��� ���� size, �������� � ������� ��������� (t=NULL)
	{
		if( !p ) return 0; 
		return p->size; 
	}

	inline void fixsize(binTree p) //!< ������������ ����������� ������� ������
	{
		p->size = getsize(p->leftPtr)+getsize(p->rightPtr)+1; 
	}
	inline binTree rotateright(binTree p) //!< ������ ������� ������ ���� p
	{
		binTree q = p->leftPtr; 
		if( !q ) return p; 
		p->leftPtr = q->rightPtr; 
		q->rightPtr = p; 
		q->size = p->size; 
		fixsize(p); 
		return q; 
	}

	inline binTree rotateleft(binTree q) //!< ����� ������� ������ ���� q
	{
		binTree p = q->rightPtr;
		if( !p ) return q;
		q->rightPtr = p->leftPtr;
		p->leftPtr = q;
		p->size = q->size;
		fixsize(q);
		return p;
	}

	inline binTree insertroot(binTree p, base k) //!< ������� ������ ���� � ������ k � ������ ������ p 
	{
		if( !p ) return new Node(k); 
		if( k<p->data ) 
		{
			p->leftPtr = insertroot(p->leftPtr,k); 
			return rotateright(p); 
		}
		else 
		{
			p->rightPtr = insertroot(p->rightPtr,k);
			return rotateleft(p);
		}
	}

	inline binTree join(binTree p, binTree q) //!< ����������� ���� ��������
	{
		if( !p ) return q;
		if( !q ) return p;
		if( rand()%(p->size+q->size) < p->size ) 
		{
			p->rightPtr = join(p->rightPtr,q); 
			fixsize(p); 
			return p; 
		}
		else 
		{
			q->leftPtr = join(p,q->leftPtr); 
			fixsize(q); 
			return q; 
		}
	}


	inline binTree remove(binTree p, base k) //!< �������� �� ������ p ������� ���������� ���� � ������ k 
	{
		if( !p ) return p; 
		if( p->data==k ) 
		{
			binTree q = join(p->leftPtr,p->rightPtr); 
			delete p; 
			return q; 
		}
		else if( k<p->data ) 
			p->leftPtr = remove(p->leftPtr,k); 
		else 
			p->rightPtr = remove(p->rightPtr,k); 
		return p; 
	}
}

