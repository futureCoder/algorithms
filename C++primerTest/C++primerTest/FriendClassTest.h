#ifndef _FRIEND_CLASS_TEST__H_
#include "stdafx.h"
class GCommonDataObject
{
    friend class GCommonDataObjectTickList;
public:
    GCommonDataObject() {};
    ~GCommonDataObject() {};
    inline GCommonDataObject* prev() { return _prev; }
    inline void prev(GCommonDataObject* _p) { _prev = _p; }

    inline GCommonDataObject* next() { return _next; }
    inline void next(GCommonDataObject* _n) { _next = _n; }

    GCommonDataObject* Remove();
protected:
private:
    //tick list
    GCommonDataObject* _next;
    GCommonDataObject* _prev;
    GCommonDataObjectTickList* pList;
};
class GCommonDataObjectTickList
{
public:
    GCommonDataObjectTickList(void)
        :m_Count(0)
        , _head(NULL)
        , _back(NULL)
    {
    }
    virtual ~GCommonDataObjectTickList(void)
    {
    }
    //add to head
    void Add(GCommonDataObject* ptr)
    {
        if (!ptr || NULL != ptr->pList)
        {
            return;
        }
        ptr->prev(NULL);
        ptr->next(_head);
        if (_head)
        {
            _head->prev(ptr);
            _head = ptr;
        }
        else
        {
            _head = _back = ptr;
        }
        ptr->pList = this;
        m_Count++;
    }
    //return next
    GCommonDataObject* Remove(GCommonDataObject* ptr)
    {
        if (!ptr || (ptr->pList != this))
        {
            return NULL;
        }
        GCommonDataObject* res = ptr->next();
        if (ptr->prev())
        {
            ptr->prev()->next(ptr->next());
        }
        else
        {
            _head = ptr->next();
            if (_head)
            {
                _head->prev(NULL);
            }
        }
        if (ptr->next())
        {
            ptr->next()->prev(ptr->prev());
        }
        else
        {
            _back = ptr->prev();
            if (_back)
            {
                _back->next(NULL);
            }
        }
        ptr->next(NULL);
        ptr->prev(NULL);
        ptr->pList = NULL;
        m_Count--;
        return res;
    }
protected:
    int32 m_Count;
    GCommonDataObject* _head;
    GCommonDataObject* _back;
private:
};
#endif // !_FRIEND_CLASS_TEST__H_
