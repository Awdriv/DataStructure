#include <awdriv>

int indexOf(const char *src, const char *find) {
    int l_src = strlen(src);
    int l_find = strlen(find);
    
    int i = 0, j = 0;
    
    while (i < l_src && j < l_find) {
        if (src[i] == find[j]) {
            ++i;
            ++j;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    
    if (j == l_find) {
        return i - j;
    }
    
    return -1;
} 

int main() {
    _sout(indexOf("abc", "bcd"));
    return 0;
}