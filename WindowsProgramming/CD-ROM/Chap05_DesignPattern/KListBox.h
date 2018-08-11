//////////////////////////////////////////////////////////////////////////
/// @file   KListBox.h
///         interface for the KListBox class of 'vector' project.
/// @author seojt@kogsoft.com
/// @since  2003-07-05 am 08:43:31
///

#if !defined(_KListBox_Defined_)
#define _KListBox_Defined_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning(disable:4786)
#include <vector>


//////////////////////////////////////////////////////////////////////
/// @class  KListBox
///
/// @see
///
template<class T>
class KListBox
{
public:
    typedef std::vector<T>                  VTYPE; ///< item container type
    typedef typename VTYPE::iterator        VITOR; ///< item iterator

protected:
    VTYPE                   m_vector;           ///< vector container
    int                     m_iSelectedItem;    ///< selected item index
    int                     m_iStartIndex;      ///< display start index
    int                     m_numItemToDisplay; ///< number of items to display

public:
    /// constructor.
	KListBox()
    {
        m_iSelectedItem     = 0;
        m_iStartIndex       = 0;
        m_numItemToDisplay  = 13;
    }//KListBox()

    /// destructor.
	virtual ~KListBox()
    {
        Clear();
    }//~KListBox()

    /// get begin item.
    /// @return VITOR : iterator
    VITOR Begin()
    {
        return m_vector.begin();
    }//Begin()

    /// get last item.
    /// @return VITOR : iterator
    VITOR End()
    {
        return m_vector.end();
    }//End()

    /// clear all items in the vector container.
    /// @note   PreClear() and PostClear() will be called before container clearing
    void Clear()
    {
        PreClear();
        m_vector.clear();
        PostClear();
    }//Clear()

    /// Prepare m_vector.clear().
    virtual void PreClear(){}

    /// post processing after calling m_vector.clear().
    virtual void PostClear(){}

    /// insert item to the end of container.
    /// @param  item : item to insert
    void Insert(T item)
    {
        m_vector.push_back( item );
    }//Insert()

    /// insert item at specified position.
    /// @param  itor : insert before position
    /// @param  item : item to insert
    void Insert(VITOR itor, T item)
    {
        m_vector.insert( itor, item );
    }//Insert()

    /// access m_vector[index].
    /// @param  index : index to container
    T& At(int index)
    {
        return m_vector[index];
    }//At()

    /// access m_vector[index].
    /// @param  index : index to container
    T& operator[](int index)
    {
        return m_vector[index];
    }//operator[]()

    /// find item by value.
    /// @param  item : item to find
    /// @return VITOR : found iterator\n
    ///         - NULL when 'item' isn't found
    VITOR FindByValue(T item)
    {
        for (VITOR itor = m_vector.begin(); itor != m_vector.end(); ++itor)
        {
            if ( item == (*itor) ) return itor;
        }//for
        return NULL;
    }//FindByValue()

    /// erase item by value.
    /// @param  item : item to erase
    /// @return bool : 'true' when erased
    bool EraseByValue(T item)
    {
        VITOR itor = FindByValue( item );
        if ( itor ) m_vector.erase( itor );

        return itor != NULL;
    }//Erase()

    bool EraseByIndex(int iItem)
    {
        int index = 0;
        for (VITOR itor = m_vector.begin(); itor != m_vector.end(); ++itor)
        {
            if ( index == iItem )
            {
                Erase( itor );
                return true;
            }//if
        }//for

        return false;
    }//EraseByIndex()

    /// direct erase.
    /// @param  itor : iterator to erase
    void Erase(VITOR itor)
    {
        m_vector.erase( itor );
    }//Erase()

    /// erase ranged items.
    /// @param  itorBegin : begin iterator
    /// @param  itorEnd : end iterator
    void Erase(VITOR itorBegin, VITOR itorEnd)
    {
        m_vector.erase( itorBegin, itorEnd );
    }//Erase()

    /// check whether container is empty.
    /// @return bool : 'true' if containter is empty
    bool IsEmpty()
    {
        return m_vector.empty();
    }//IsEmpty()

    /// get number of items in the container.
    /// @return int : number of items in the m_vector[]
    int GetSize()
    {
        return m_vector.size();
    }//GetSize()

    /// reserve items.
    /// @param  size : number of items to reserve
    void Reserve(int size)
    {
        m_vector.reserve( size );
    }//Reserve()

public:
    /// set selected item index.
    /// @param  iItem : highlighted item index
    void SetSelected(int iItem)
    {
        m_iSelectedItem = iItem;
    }//SetSelected()

    int GetSelected()
    {
        return m_iSelectedItem;
    }//GetSelected()

    /// check whether iSelected is highlighted item.
    /// @param  iSelected : test index
    /// @return bool : true if 'iSelected' is highlighted
    bool IsSelected(int iSelected)
    {
        return m_iSelectedItem == iSelected;
    }//IsSelected()

    /// set display start index.
    /// @param  iIndex : item index started to display
    int SetDisplayStart(int iIndex)
    {
        m_iStartIndex = iIndex;

        int iPossibleLast = GetSize() - m_numItemToDisplay + 1;
        if ( m_iStartIndex > iPossibleLast)
            m_iStartIndex = iPossibleLast;
        if ( m_iStartIndex < 0 )
            m_iStartIndex = 0;

        return m_iStartIndex;
    }//SetDisplayStart()

    /// get display start index.
    /// @return int : start index of displaying
    int GetDisplayStart()
    {
        return m_iStartIndex;
    }//GetDisplayStart()

    /// set number of items to display.
    /// @param  iSize : number of items to display
    void SetNumDisplay(int iSize)
    {
        m_numItemToDisplay = iSize+1;
    }//SetNumDisplay()

    int GetNumDisplay()
    {
        return m_numItemToDisplay-1;
    }//GetNumDisplay()

    VITOR BeginDisplay()
    {
        if ( m_iStartIndex >= GetSize() ) return m_vector.end();
        return m_vector.begin() + m_iStartIndex;
    }//BeginDisplay()

    VITOR EndDisplay()
    {
        int endIndex = m_iStartIndex + m_numItemToDisplay - 1;
        if ( endIndex >= GetSize() ) return m_vector.end();
        return m_vector.begin() + endIndex;
    }//EndDisplay()
};//class KListBox

#endif // !defined(_KListBox_Defined_)


/** @example    class KListBox(list box usage)

    #include <iostream>
    #include "KListBox.h"

    using std::cout;
    using std::endl;

    void main()
    {
	    // Create a vector object of integers
	    KListBox<int>   kListBox;

	    // Fill the vector with 3 different elements
        for (int i=0; i<20; ++i)
        {
	        kListBox.Insert(i);
        }//for

        int iStart = kListBox.SetDisplayStart( 15 );
        kListBox.SetSelected( 17 );
	    // Now loop and print out all the element values
        for(KListBox<int>::VITOR itor = kListBox.BeginDisplay(); itor != kListBox.EndDisplay(); ++itor)
        {
            if ( kListBox.IsSelected(iStart) )
                cout << "* ";
            else
                cout << "  ";
		    cout << "element value = " << (*itor) << endl;
            ++iStart;
        }//for
    }//main()

*/

/** @example    class KListBox(general usage)

    #include <iostream>
    #include "KListBox.h"

    using std::cout;
    using std::endl;

    void main()
    {
	    // Create a vector object of integers
	    KListBox<int> c;
	    // Reserve room for 10 integers
	    c.Reserve(10);

	    // Fill the vector with 3 different elements
	    c.Insert(3);
	    c.Insert(99);
	    c.Insert(42);

	    // Now loop and print out all the element values
        for(KListBox<int>::VITOR itor = c.Begin(); itor != c.End(); ++itor)
		    cout << "element value = " << (*itor) << endl;

	    // Since the elements have been created, we can access or replace
	    // them just like a normal array.
	    c[0] = 12;
	    c[1] = 32;
	    c[2] = 999;
	    for(int i = 0; i < c.GetSize(); i++)
		    cout << "element value = " << c[i] << endl;
    }//main()

*/