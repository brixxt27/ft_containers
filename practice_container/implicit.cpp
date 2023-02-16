#include <cassert>
 
template<typename T>
class zero_init
{
    T val;
public:
    zero_init() : val(static_cast<T>(0)) {}
    zero_init(T val) : val(val) {}
    operator T&() { return val; }
    operator T() const { return val; }
};
 
int main()
{
    zero_init<int> i;
    assert(i == 0);
 
    i = static_cast<int>(7);
    assert(i == 7);
}
