#pragma once 

#include <iostream>

namespace KangDahyun2649001
{
    const int daysInMonth[13]{0,31,28,31,30,31,30,31,31,30,31,30,31};

    class dayOfYear
    {
    //private:
        int month{}; //1~12
        int day{}; //1~31
        void testMonth()
        {
            if ((month < 1) || (month > 12)) {
                std::cout << "Invalid month value!\n";
                std::exit(1);
            }
        }
        void testDay()
        {
            if ((day < 1) || (day > daysInMonth[month])) {
                std::cout << "Invalid day value!\n";
                std::exit(1);
            }
        }
        void updateDay()
        {
            int maxDay(daysInMonth[month]); //31
            while (day > maxDay)
            {
                day -= maxDay; month += 1;
                if (month > 12) month -= 12;
                maxDay = daysInMonth[month];
            } 
        }
    public:

        dayOfYear(int m = 1, int d = 1):month{m}, day{d}
        {
            testMonth();
            testDay();
        }
        void input()
        {
            std::cout << "Enter the month as a number: ";
            std::cin >> month; testMonth();
            std::cout << "Enter the day of the month: ";
            std::cin >> day; testDay();
        }
        // 프렌드함수로서 입력연산자 >>
        friend std::istream& operator>>(std::istream& is, dayOfYear& d)
        {
            std::cout << "Enter the month as a number: ";
            is >> d.month; d.testMonth();
            std::cout << "Enter the day of the month: ";
            is >> d.day; d.testDay();
            return is;
        }

        void setMonth(int m) { month = m; testMonth(); }
        void setDay(int d) { day = d; testDay(); }
        void print() const
        {
            switch(month)
            {
                case 1: std::cout << "Jan. "; break;
                case 2: std::cout << "Feb. "; break;
                case 3: std::cout << "Mar. "; break;
                case 4: std::cout << "Apr. "; break;
                case 5: std::cout << "May. "; break;
                case 6: std::cout << "Jun. "; break;
                case 7: std::cout << "Jul. "; break;
                case 8: std::cout << "Aug. "; break;
                case 9: std::cout << "Sep. "; break;
                case 10: std::cout << "Oct. "; break;
                case 11: std::cout << "Nov. "; break;
                case 12: std::cout << "Dec. "; break;
            }
            std::cout << day << "\n";
        }
        
        friend std::ostream& operator<<(std::ostream& os, const dayOfYear& d)
        {
            switch(d.month)
            {
                case 1: os << "Jan. "; break;
                case 2: os << "Feb. "; break;
                case 3: os << "Mar. "; break;
                case 4: os << "Apr. "; break;
                case 5: os << "May. "; break;
                case 6: os << "Jun. "; break;
                case 7: os << "Jul. "; break;
                case 8: os << "Aug. "; break;
                case 9: os << "Sep. "; break;
                case 10: os << "Oct. "; break;
                case 11: os << "Nov. "; break;
                case 12: os << "Dec. "; break;
            }
            os << d.day << "\n";
            return os;
        }

        int getMonth() const { return month; }
        int getDay() const { return day; }

        dayOfYear& operator++()
        {
            ++day;
            updateDay();
            return *this; 
        }
        dayOfYear operator++(int) // 레퍼런스 x
        {
            dayOfYear temp{*this}; 
            ++(*this);
            return temp;
        }
        
        dayOfYear& operator+=(int p)
        {
            day += p; 
            updateDay();
            return *this;
        }

        friend bool operator==(const dayOfYear& d1, const dayOfYear& d2)
        {
            return d1.month == d2.month && d1.day == d2.day;
        }
      
        friend dayOfYear operator+(const dayOfYear& d1, const dayOfYear& d2)
        {
            return dayOfYear{d1.month + d2.month, d1.day + d2.day};
        }
    };
}