#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED


template <class T>
class Queue;

template <class T>
class QueueIterator;

template <class T>
class ConstQueueIterator;

//----CLASS QUEUE_NODE-------------------------------------

template <class T>
class QueueNode {
    friend class Queue<T>;
    friend class QueueIterator<T>;
    friend class ConstQueueIterator<T>;

private:
    QueueNode() : element(), next(nullptr) {}
    QueueNode(const T & e, QueueNode * next_ele);

    T element;
    QueueNode<T> * next;
    };

//----CLASS QUEUE_ITERATOR---------------------------------

template <class T>
class QueueIterator {
   friend class Queue<T>;
   friend class ConstQueueIterator<T>;

public:
    QueueIterator() : current_node_ptr(nullptr) {}

    T & operator*() const { return current_node_ptr->element; }
    T * operator->() const { return &(current_node_ptr->element); }

    bool operator==(const QueueIterator & compare_element) const {
        return (current_node_ptr == compare_element.current_node_ptr);
        }
    bool operator!=(const QueueIterator & compare_element) const {
        return (current_node_ptr != compare_element.current_node_ptr);
        }

    QueueIterator & operator++();
    QueueIterator & operator--();
private:
    explicit QueueIterator(QueueNode<T> * p) : current_node_ptr(p) {}

    QueueNode<T> * current_node_ptr;
    };

template <class T>
inline QueueIterator<T> & QueueIterator<T>::operator++() {
    current_node_ptr = current_node_ptr->next;
    return *this;
    }

//----CLASS CONST_QUEUE_ITERATOR---------------------------------------------------

template <class T>
class ConstQueueIterator {
   friend class Queue<T>;

public:
    ConstQueueIterator() : current_node_ptr(nullptr) {}

    ConstQueueIterator(const QueueIterator<T> & itr) :
        current_node_ptr(itr.current_node_ptr) {}

    const T & operator*() const { return current_node_ptr->element; }
    const T * operator->() const {
        return &(current_node_ptr->element);
        }

    bool operator==(const ConstQueueIterator & compare_itr) const {
        return (current_node_ptr == compare_itr.current_node_ptr);
        }
    bool operator!=(const ConstQueueIterator & compare_itr) const {
        return (current_node_ptr != compare_itr.current_node_ptr);
        }

    ConstQueueIterator & operator++();
    ConstQueueIterator & operator--();

private:
    explicit ConstQueueIterator(const QueueNode<T> * p) :
        current_node_ptr(p) {}
    const QueueNode<T> * current_node_ptr;
    };

template <class T>
inline ConstQueueIterator<T> & ConstQueueIterator<T>::operator++() {
    current_node_ptr = current_node_ptr->next;
    return *this;
    }

//----CLASS QUEUE-----------------------------------------------------------

template <class T>
class Queue {
public:
    typedef QueueIterator<T> iterator;
    typedef ConstQueueIterator<T> const_iterator;

    Queue();
    //~Queue();

    void push(const T & e);
    T pop();

    int size();
    bool empty();
    T front_of();

    iterator begin() { return iterator(empty_node->next); }
    iterator end() { return iterator(current_node); }

    typename Queue<T>::iterator erase(const_iterator const_itr);

    const_iterator begin() const {
        return const_iterator(empty_node->next);
        }

    const_iterator end() const {
        return const_iterator(current_node);
        }

    Queue<T> & operator=( const Queue<T> & assign_queue );

    private:
        QueueNode<T> * empty_node;
        QueueNode<T> * current_node;
    };

template <class T>
inline Queue<T>::Queue() {
    empty_node = new QueueNode<T>;
    empty_node->next = empty_node;
    current_node = empty_node;
    }

template <class T>
inline int Queue<T>::size() {
    int size_of = 0;
    for (QueueIterator<T> itr = begin(); itr != end(); ++itr) {
        ++size_of;
        }

    return size_of;
    }

template <class T>
inline bool Queue<T>::empty() {
    bool queue_empty = false;
    if ( size() == 0 ) queue_empty = true;

    return queue_empty;
    }

template <class T>
inline T Queue<T>::front_of() {
    QueueNode<T> * return_node = current_node;
    return return_node->element;
    }

template <class T>
inline T Queue<T>::pop() {
    QueueNode<T> * return_node = front_of();

    empty_node->next = return_node->next();

    return return_node->element;
    }

template <class T>
inline void Queue<T>::push(const T & e) {
    QueueNode<T> * new_node = (QueueNode<T> * )(e, nullptr);
    current_node->next = new_node;
    }

template <class T>
inline typename Queue<T>::iterator Queue<T>::erase(const_iterator const_itr) {
    QueueNode<T> * target_node = (QueueNode<T> *)(const_itr.current_node);

    QueueNode<T> * next_node = target_node->next;
    target_node->next = nullptr;
    delete target_node;

    return iterator(next_node);
    }

#endif // QUEUE_H_INCLUDED
