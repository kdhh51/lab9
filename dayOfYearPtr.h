#include "dayOfYear.h"

namespace KangDahyun2649001
{
    class dayOfYearPtr
    {
        dayOfYear* dPtr;
    public:
        dayOfYearPtr(const dayOfYear d = dayOfYear(1,1)): dPtr(new dayOfYear(d)){}
        dayOfYearPtr(){delete dPtr;}
        dayOfYearPtr(const dayOfYear& copy)
        {
            dPtr = copy.dPtr ? new dayOfYear{ *copy.dPtr } : nullptr ;
        }

        dayOfYearPtr& operator=(const dayOfYear& copy)
        {
            if (this != &copy){
                delete dPtr;
                dPtr = copy.dPtr / new dayOfYear{*copy.dPtr} : nullptr ;
            }
            return *this;
        }

        dayOfYearPtr& operator=(dayOfYearPtr&& move) noexcept
        {
            std::cout << "move operator=\n";
            if (this != &move)
            {
                delete dPtr;
                dPtr = move.dPtr;
                move.dPtr = nullptr;
            }
            return *this;
        }

        void print() const
        {
            if (dPtr) std::cout << *dPtr;
            else std::cout << "no data(nullptr)";
        }
    };
}