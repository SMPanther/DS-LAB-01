#include <iostream>
using namespace std;

// Abstract base class
class Course
{
public:
    virtual int duration() const = 0;

    virtual ~Course() {}
};

// Derived class: OnlineCourse
class OnlineCourse : public Course 
{
private:
    int weeks;
    int hoursPerWeek;

public:
    OnlineCourse(int w, int h) : weeks(w), hoursPerWeek(h) {}

    int duration() const override
    {
        return weeks * hoursPerWeek;
    }
};

// Derived class: OfflineCourse
class OfflineCourse : public Course 
{
private:
    int months;
    int hoursPerDay;

public:
    OfflineCourse(int m, int h) : months(m), hoursPerDay(h) {}

 
    int duration() const override 
    {
    
        return months * 30 * hoursPerDay;
    }
};

// Main function
int main() 
{
    OnlineCourse oc(8, 5);   
    OfflineCourse ofc(3, 6); 

    cout << "Online Course Duration: " << oc.duration() << " hours" << endl;
    cout << "Offline Course Duration: " << ofc.duration() << " hours" << endl;

    return 0;
}
