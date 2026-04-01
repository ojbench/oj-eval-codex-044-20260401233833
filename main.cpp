#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;

class mystring {
private:
    char *ch = nullptr;
    int len = 0;

public:
    mystring() : ch(nullptr), len(0) {}

    mystring(int _len, int c) : ch(nullptr), len(0) {
        if (_len < 0) _len = 0;
        len = _len;
        if (len > 0) {
            ch = new char[len];
            char cc = static_cast<char>(c);
            for (int i = 0; i < len; ++i) ch[i] = cc;
        }
    }

    mystring(string &c) : ch(nullptr), len(0) {
        len = static_cast<int>(c.length());
        if (len > 0) {
            ch = new char[len];
            for (int i = 0; i < len; ++i) ch[i] = c[i];
        }
    }

    mystring(const mystring &other) : ch(nullptr), len(other.len) {
        if (len > 0) {
            ch = new char[len];
            memcpy(ch, other.ch, len);
        }
    }

    mystring &operator=(const mystring &other) {
        if (this == &other) return *this;
        char *newbuf = nullptr;
        if (other.len > 0) {
            newbuf = new char[other.len];
            memcpy(newbuf, other.ch, other.len);
        }
        delete[] ch;
        ch = newbuf;
        len = other.len;
        return *this;
    }

    ~mystring() {
        delete[] ch;
        ch = nullptr;
        len = 0;
    }

    char operator[](int x) const {
        if (x < 0 || x >= len) return '\0';
        return ch[x];
    }

    bool operator<(const mystring &other) const {
        int m = len < other.len ? len : other.len;
        for (int i = 0; i < m; ++i) {
            if (ch[i] != other.ch[i]) return ch[i] < other.ch[i];
        }
        return len < other.len;
    }

    void ADD(const mystring &other) {
        if (other.len == 0) return;
        char *newbuf = new char[len + other.len];
        if (len > 0) memcpy(newbuf, ch, len);
        if (other.len > 0) memcpy(newbuf + len, other.ch, other.len);
        delete[] ch;
        ch = newbuf;
        len += other.len;
    }

    void out() const {
        for (int i = 0; i < len; ++i) putchar(ch[i]);
    }

    int get_len() const { return len; }
};

string str_in1, str_in2;
int n, id;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> id)) return 0;
    if (id == 1) {
        mystring str1(100, 'a');
        str1.out(); puts("");
    } else if (id == 2) {
        cin >> str_in1;
        mystring str2 = str_in1;
        cin >> n;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            cout << str2[x] << '\n';
        }
    } else if (id == 3) {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cout << (int)(str2 < str3) << '\n';
    } else if (id == 4) {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        str2.ADD(str3);
        str2.out(); puts("");
    } else {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cin >> n;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            cout << str3[x] << '\n';
        }
        cout << str2.get_len() << " " << str3.get_len() << '\n';
        cout << (int)(str2 < str3) << '\n';
        str2.ADD(str3);
        str2.out(); puts("");
        cout << str2.get_len() << '\n';
    }
    return 0;
}
