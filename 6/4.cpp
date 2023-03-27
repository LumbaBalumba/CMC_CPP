#include <vector>
#include <algorithm>

template<class T1, class T2>
T2
myremove(T1 begin, T1 end, T2 del_begin, T2 del_end)
{
    std::vector v(begin, end);
    std::sort(v.begin(), v.end());
    auto v_end = std::unique(v.begin(), v.end());
    auto v_begin = v.begin();
    for (; *v_begin < 0 && v_begin != v_end; ++v_begin) {}
    ssize_t index = 0;
    ssize_t col = 0;
    auto result = del_begin;
    for (; del_begin != del_end; ++del_begin, ++index) {
        if (v_begin != v_end && index == *v_begin) {
            ++col;
            ++v_begin;
        } else {
            *result++ = std::move(*del_begin);
        }
    }
    if (!col) {
        return del_end;
    }
    return result;
}