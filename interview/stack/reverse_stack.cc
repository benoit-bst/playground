#include <bits/stdc++.h>

using namespace std;

stack<int> st;

// Below is a recursive function
// that inserts an element
// at the bottom of a stack.
void insert_at_bottom(int x)
{

    if(st.size() == 0)
    st.push(x);

    else
    {

        // All items are held in Function Call
        // Stack until we reach end of the stack
        // When the stack becomes empty, the
        // st.size() becomes 0, the above if
        // part is executed and the item is
        // inserted at the bottom

        int a = st.top();
        st.pop();
        insert_at_bottom(x);

        // push allthe items held in
        // Function Call Stack
        // once the item is inserted
        // at the bottom
        st.push(a);
    }
}

// Below is the function that
// reverses the given stack using
// insert_at_bottom()
void reverse()
{
    if(st.size()>0)
    {

        // Hold all items in Function
        // Call Stack until we
        // reach end of the stack
        auto x = st.top();
        st.pop();
        reverse();

        // Insert all the items held
        // in Function Call Stack
        // one by one from the bottom
        // to top. Every item is
        // inserted at the bottom
        insert_at_bottom(x);
    }
}

// Time Complexity: O(N)
// Auxiliary Space: O(N)
stack<int> reverse_2(stack<int>& orig) {
    stack<int> result;
    while(!orig.empty()) {
        result.push(orig.top());
        orig.pop();
    }
    return result;
}

//Print function which prints all elements present in particular stack
void print(stack<int> s){
    //keep popping elements and print them until stack become empty
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout << endl;
}

//Print function which prints all elements present in particular stack
void print_2(){
    stack<int> buff = st;
    //keep popping elements and print them until stack become empty
    while(!buff.empty()){
        cout<<buff.top()<<" ";
        buff.pop();
    }
    cout << endl;
}

//Main function
int main(){

    {
        stack<int> s;
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);

        print(s);
        print(reverse_2(s));
    }
    {
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);

        print_2();
        reverse();
        print_2();
    }

}
