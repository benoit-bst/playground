#include <iostream>
#include <vector>

#include <gsl/gsl>

using namespace gsl;
using namespace std;

//---------------------------------------------
// For span example
//---------------------------------------------
void process_ints(const span<int> s){
    for (auto& c : s) {
        // cout << c << endl;
    }

    if (s.size() > 0){}
}

//---------------------------------------------
// For not_null example
//---------------------------------------------
int * use( not_null<int *> p )
{
    // use p knowing it's not nullptr, NULL or 0.
    return p;
}

int main(int argc, char* argv[])
{
    //--------------------------------------------
    // span
    //
    // gsl::span is a replacement for (pointer, length) pairs to refer to a sequence of contiguous objects. It can be thought of as a pointer to an array, but that knows its bounds.
    // For example, a span<int,7> refers to a sequence of seven contiguous integers.
    // A span<T> is :
    // A very lightweight abstraction of a contiguous sequence of values of type T somewhere in memory.
    // Basically a struct { T * const ptr; size_t length; } with a bunch of convenience methods.
    // A non-owning type (i.e. a "reference-type" rather than a "value type"): It never allocates nor deallocates anything and does not keep smart pointers alive.
    //--------------------------------------------
    {
        int a[100];
        process_ints(a); // deduces correct length: 100 (constructs the span from a container)

        vector<int> v(200);
        process_ints(v); // deduces correct length: 200 (constructs the span from a container)

        int b[] = { 1, 2, 3};
        span<int> sa{b};

        vector<int> v2 = { 1, 2, 3 };
        span<int> sv{v2};

        assert(sa == sv); // sa and sv both point to contiguous ints with values 1, 2, 3
        assert(sa.data() != sv.data()); // but sa and sv point to different memory areas
    }

    //--------------------------------------------
    // not_null
    //--------------------------------------------
    {
        // not_null<int *> p0 = nullptr; // Impossible, gsl protect it
        // int *res =  use( nullptr );   // Impossible, gsl protect it
        not_null<int *> pInt(new int(10));
        int *res = use( pInt );
        delete pInt;
        //pInt = nullptr;
    }

    //--------------------------------------------
    // owner
    //--------------------------------------------
    {
        owner<int*> p;
    }

    //--------------------------------------------
    // Expects/Ensures
    //--------------------------------------------
    {
        int height = 10;
        int width = 2;
        Expects(height > 0);
        auto res = height * width;
        Ensures(res > 0);
    }

    //-------------------------------------------
    // finally  allows you to register a callable
    // that will run at the end of the scope.
    //--------------------------------------------
    {
        int n = 10;
        void* p = malloc(n);
        auto _ = finally([p] { free(p); });
    }

  return 0;
}
