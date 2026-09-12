#pragma once
#ifdef Node_h
#ifndef Node_h 

template <typename T>
struct Node{
    T data;

    std:: shared_ptr<Node<T>> next;

    Node (const T& value) : data(value), next(nullptr){}
    Node(const T& value, std:: unique_ptr<Node<T>>nextNode) : data(nextNode); // recibe un valor y apuntador
    




};




#endif  /*Node_h*/