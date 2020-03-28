#ifndef __DNIU_HASH_TABLE_H__
#define __DNIU_HASH_TABLE_H__

#include <list>
#include <map>

template<class T1, class T2>
class CHashTable
{
public:
    struct HashNode
    {
        T1 m_key;
        T2 m_value;
        
        HashNode() {}
        HashNode(T1 m_key, T2 m_value) :m_key(m_key), m_value(m_value) {}

        bool operator == (const HashNode& node) const
        {
            return((m_key == node.m_key) && (m_value == node.m_value));
        }
    };

public:
    CHashTable() {};
    virtual ~CHashTable() {};

    void insertNode(HashNode node);
    void removeNode(HashNode node);
    bool findNode(HashNode node);

    void printData();

    class iterator
    {
    public:
        iterator() :m_it(NULL){}

        HashNode* operator->()
        {
            return m_it;
        }

        iterator operator++()
        {}

    private:
        const CHashTable* m_hashTable;
        int m_index;
        T2 m_t2;
    };

private:
    //std::list<HashNode> m_CallList;
    std::map<T1, std::list<HashNode>*> m_MapStorage;
};

template<class T1, class T2>
void CHashTable<T1, T2>::insertNode(HashNode node)
{
    if (findNode(node))
    {
        return;
    }

    std::map<T1, std::list<HashNode>*>::iterator it = m_MapStorage.find(node.m_key);
    if (m_MapStorage.end() != it)
    {
        std::list<HashNode>* callList = m_MapStorage[node.m_key];
        if (callList)
        {
            callList->push_back(node);
        }
    }
    else
    {
        std::list<HashNode>* callList = new std::list<HashNode>;
        if (callList)
        {
            callList->push_back(node);
            m_MapStorage[node.m_key] = callList;
        }
    }
}

template<class T1, class T2>
void CHashTable<T1, T2>::removeNode(HashNode node)
{
    if (m_MapStorage.end() != m_MapStorage.find(node.m_key))
    {
        std::list<HashNode>* callList = m_MapStorage[node.m_key];
        if (callList)
        {
            std::list<HashNode>::iterator it = callList->begin();
            while (it != callList->end())
            {
                if (node == (*it))
                {
                    callList->erase(it);
                    break;
                }

                it++;
            }

            if (0 == callList->size())
            {
                delete callList;
                callList = 0;

                m_MapStorage.erase(node.m_key);
            }
        }
    }
}

template<class T1, class T2>
bool CHashTable<T1, T2>::findNode(HashNode node)
{
    if (m_MapStorage.end() != m_MapStorage.find(node.m_key))
    {
        std::list<HashNode>* callList = m_MapStorage[node.m_key];
        if (callList)
        {
            std::list<HashNode>::iterator it = callList->begin();
            while (it != callList->end())
            {
                if (node == *it)
                {
                    return true;
                }
                it++;
            }
        }
    }

    return false;
}

template<class T1, class T2>
void CHashTable<T1, T2>::printData()
{
    std::map<T1, std::list<HashNode>*>::iterator it = m_MapStorage.begin();
    while (m_MapStorage.end() != it)
    {
        std::cout << it->first << std::endl;
        std::list<HashNode>* callList = it->second;
        if (callList)
        {
            std::list<HashNode>::iterator it_list = callList->begin();
            while (it_list != callList->end())
            {
                T2 m_value = it_list->m_value;
                if (m_value)
                {
                    std::cout << m_value <<std::endl;
                }

                it_list++;
            }
        }
        std::cout << std::endl;

        it++;
    }
}

#endif