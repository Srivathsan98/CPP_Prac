/*Build a generic ObjectPool<T> using unique_ptr that recycles objects instead of deleting them.*/

#include <iostream>
#include <memory>
#include <vector>
#include <functional>
template<typename T>
class ObjectPool
{
public:
    using PoolPtr = std::unique_ptr<T, std::function<void(T*)>>;

    void push(std::unique_ptr<T> obj)
    {
        pool.push_back(std::move(obj));
    }

    PoolPtr acquire()
    {
        if(pool.empty())
        {
            return PoolPtr(new T(), [this](T* ptr)
            {
                this->push(std::unique_ptr<T>(ptr));
            });
        }
        else
        {
            std::unique_ptr<T> obj = std::move(pool.back());
            pool.pop_back();
            return PoolPtr(obj.release(), [this](T* ptr)
            {
                this->push(std::unique_ptr<T>(ptr));
            });
        }
    }
private:
    std::vector<std::unique_ptr<T>> pool;
};

struct Particle
{
    float x,y,z;
    Particle()
    {
        std::cout << "Particle created" << std::endl;
    }
    ~Particle()
    {
        std::cout << "Particle destroyed" << std::endl;
    }
};

int main()
{
    ObjectPool<Particle> particlePool;

    {
        auto p1 = particlePool.acquire();
        p1->x = 1.0f;
        std::cout << "Particle 1: (" << p1->x << ", " << p1->y << ", " << p1->z << ")" << std::endl;
    }

    {
        auto p2 = particlePool.acquire();
        std::cout << "Particle 2: (" << p2->x << ", " << p2->y << ", " << p2->z << ")" << std::endl;
    }
}