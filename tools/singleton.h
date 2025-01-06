/**
 * @file singleton.h
 * @brief 单例模式封装头文件
 * @date 2025.1.2
 * @author yancy
 */
#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include<memory>

 /**
 * @brief 单例模式封装类
 *  T 类型
 *  X 为了创造多个实例对应的Tag
 *  N 同一个Tag创造多个实例索引
 */
template<class T,class X=void,int N=0>
class Singleton
{
public:
    /**
     *  返回单例裸指针
     */
    static T* GetInstance() //返回单例裸指针
    {
        static T v;
        return &v;  //return &GetInstanceX<T, X, N>();
    }
};

/**
 * @brief 单例模式智能指针封装类
 * T 类型
 * X 为了创造多个实例对应的Tag
 * N 同一个Tag创造多个实例索引
 */
template<class T,class X=void,int N=0>
class SingletonPtr
{
public:
    static std::shared_ptr<T> GetInstance() //返回单例智能指针
    {
        static std::shared_ptr<T> v = std::make_shared<T>();
        return v;
    }
};

#endif // SINGLETON_H