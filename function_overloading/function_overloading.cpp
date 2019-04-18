#include <dlfcn.h>
#include <cstdio>
#include <iostream>

#include "function_overloading.hpp"

using namespace std;

int main()
{
    int int_param = 5;
    char char_param = 'C';
    void *handle;
    void (*foo)(void);

	handle = dlopen("libfoo.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

	dlerror();  

	*(void **) (&foo) = dlsym(handle, "foo");

	if (foo)
	{
		foo();
	}
	
    dlclose(handle);

    return 0;
}


