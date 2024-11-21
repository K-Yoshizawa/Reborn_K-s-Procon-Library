/**
 * @file DoublyLinkedList.hpp
 * @brief Doubly Linked List - 双方向連結リスト
 * @version 0.1
 * @date 2024-03-10
 */

#include <map>
#include <utility>
using namespace std;

template<typename T>
struct DoublyLinkedList{
    struct node{
        node *prev{nullptr}, *next{nullptr};
        T value;
        int ts{0};
        node() = default;
        node(T value, int time) : value(value), ts(time) {}
    };

    using U = pair<T, int>;

    node *front, *back;
    map<U, node*> dict;
    int m_size, m_timestamp;
    bool m_unique;

    int settime(){
        return m_unique ? 0 : ++m_timestamp;
    }

    int gettime(){
        return m_unique ? 0 : m_timestamp;
    }

    DoublyLinkedList(bool UniqueKey = false) : m_unique(UniqueKey) {
        front = new node();
        back = new node();
        front->next = back;
        back->prev = front;
        m_size = 0;
        m_timestamp = 0;
    }

    size_t size(){
        return m_size;
    }

    bool empty(){
        return size() == 0;
    }

    node* make_node(T value){
        return new node(value, settime());
    }

    int insert_front(T value){
        node *nd = make_node(value);
        nd->next = front->next;
        nd->prev = front;
        front->next  = nd;
        dict[{value, settime()}] = nd;
        ++m_size;
        return gettime();
    }

    int insert_back(T value){
        node *nd = make_node(value);
        nd->next = back;
        nd->prev = back->prev;
        back->prev  = nd;
        dict[{value, settime()}] = nd;
        ++m_size;
        return gettime();
    }

    int insert_after(T value, T target){
        if(!dict.contains(target)) return;
        node *tn = dict[target];
        node *nd = make_node(value);
        nd->next = tn->next;
        nd->prev = tn;
        tn->next = nd;
        dict[{value, settime()}] = nd;
        ++m_size;
        return gettime();
    }

    int insert_before(T value, T target){
        if(!dict.contains(target)) return;
        node *tn = dict[target];
        node *nd = make_node(value);
        nd->next = tn;
        nd->prev = tn->prev;
        tn->prev = nd;
        dict[{value, settime()}] = nd;
        ++m_size;
        return gettime();
    }

    void erase_front(){
        if(empty()) return;
        node *tn = front->next;
        front->next = tn->next;
        delete tn;
    }
};