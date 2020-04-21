#ifndef MATRIX_H
#define MATRIX_H
#include <map>


template<typename T, T init_value, size_t dim = 2>
class Matrix
{
public:
	using ProxieType = Matrix<T, init_value, dim-1>;
	ProxieType& operator [](int index)
	{
		/*auto it = proxies.find(index);
		if (it != proxies.end()) {
			return it->second;
		}*/
		return  proxies[index];
	}
	size_t size() {
		size_t result{ 0 };
		for (auto proxie : proxies) {
			result += proxie.second.size();
		}
		return result;
	}

private:
	std::map<int, ProxieType> proxies;
	ProxieType tmp;
};

template<typename T, T init_value>
class Matrix<T,init_value,1>
{
public:
    T& operator [](const int index) {
        CheckBuffer();
        tmp_buffer.first = index;
        auto it = values.find(index);
        if (it != values.end()) {
            tmp_buffer.second = it->second;
        }
        else {
            tmp_buffer.second = init_value;
        }
        return tmp_buffer.second;
    }
    size_t size(){
        CheckBuffer();
        return values.size();
    }

private:
    void CheckBuffer() {
        if (tmp_buffer.second != init_value) {
            values[tmp_buffer.first] = tmp_buffer.second;
        }
        else {
            auto it = values.find(tmp_buffer.first);
            if (it != values.end()) {
                values.erase(it);
            }
        }
    }
private:
    std::map<int, T> values;
    std::pair<int, T> tmp_buffer{0,init_value};
};

#endif //MATRIX_H
