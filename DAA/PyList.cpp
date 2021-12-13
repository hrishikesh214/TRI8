#include <bits/stdc++.h>
#include <string>
#include <vector>

template <class T>
void print(std::vector<T> pl)
{
    for (int i = 0; i < pl.size(); i++)
    {
        std::cout << pl[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
class PyList
{
    std::vector<T> data;

public:
    PyList()
    {
        data.clear();
    }
    PyList(int n, T val)
    {
        data.resize(n, val);
    }
    PyList(std::vector<T> v)
    {
        data = v;
    }
    PyList(const PyList<T> &other)
    {
        data = other.data;
    }
    int size()
    {
        return data.size();
    }
    PyList<T> &operator=(const PyList<T> &other)
    {
        data = other.data;
        return *this;
    }
    PyList<T> &operator=(const std::vector<T> &other)
    {
        data = other;
        return *this;
    }
    T operator[](int i)
    {
        return data[i];
    }

    PyList<T> operator[](std::string s)
    {
        PyList<T> selected;
        std::string _parts[3];
        _parts[0] = "";
        _parts[1] = "";
        _parts[2] = "";
        int start = 0, end = 0, jump = 1;
        int c = 0, c1 = 0, c2 = 0;
        // std::cout << "s: " << s.substr(1, 2 - 1) << std::endl;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ':')
            {
                c++;
                continue;
            }
            _parts[c] += s[i];
        }
        if (_parts[0] == "")
        {
            _parts[0] = "-1";
        }
        if (_parts[1] == "")
        {
            _parts[1] = "0";
        }
        if (_parts[2] == "")
        {
            _parts[2] = "1";
        }
        // print(std::vector<std::string>{_parts[0], _parts[1], _parts[2]});

        start = std::stoi(_parts[0], nullptr, 10);
        end = std::stoi(_parts[1], nullptr, 10);
        jump = std::stoi(_parts[2], nullptr, 10);
        start = start == -1 ? 0 : start;
        end = end == 0 ? data.size() : end;
        jump = jump == 0 ? 1 : jump;
        // print(std::vector<int>{start, end, jump});
        for (int i = start; i < end; i += jump)
        {
            selected.data.push_back(data[i]);
        }
        return selected;
    }
};

template <class T>
void print(PyList<T> pl)
{
    for (int i = 0; i < pl.size(); i++)
    {
        std::cout << pl[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    PyList<int> l1(std::vector({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    PyList<int> l2 = l1["::2"];
    print(l2["::2"]);
    return 0;
}