#include "dayOfYearPtr.h"

int main()
{
    using namespace KangDahyun2649001;
    dayOfYearPtr dp1{11,5}; dp1.print();
    dayOfYearPtr dp2{dp1};
    dayOfYearPtr dp3{std::move(dp2)};

    dp2 = std::move(dp3);
    dp3 = dp2;

    dayOfYearPtr* dp{ new dayOfYearPtr };
    delete dp;

    std::unique_ptr<dayOfYearPtr> up1;
    auto up2{ std::make_unique<dayOfYearPtr>(dayOfYear{11,5})};
    up1 = std::move(up2); up1->print();
    std::shared_ptr<dayOfYearPtr> sp1{std::make_shared<dayOfYearPtr>{dayOfYear{12.5}}};

    std::weak_ptr<dayOfYearPtr> wp1{ sp1 };
    std::cout << sp1.use_count() << " " << sp2.use_count() << std::endl;

    sp1.reset();
    std::cout << sp1.use_count() << " " << sp2.use_count() << std::endl;

    if (!wp1.expired()) wp1.lock();
    
    return 0;
}