#include <iostream>
using namespace std;

template <typename T>
class myBinNOde {
    T data;
    myBinNOde *left;
    myBinNOde *right;

public:
    myBinNOde(T d, myBinNOde *l = nullptr, myBinNOde *r = nullptr) {
        data = d;
        right = r;
        left = l;
    }

    void set_left(myBinNOde *x) {
        left = x;
    }

    void set_right(myBinNOde *x) {
        right = x;
    }

    myBinNOde *get_left() {
        return left;
    }

    myBinNOde *get_right() {
        return right;
    }

    T &get_data() {
        return data;
    }

    ~myBinNOde() {
        delete left;
        delete right;
    }

    void preorder() {
        if (this == nullptr)
            return;
        cout << data << " ";
        if (left) left->preorder();
        if (right) right->preorder();
    }

    void inorder() {
        if (this == nullptr)
            return;
        if (left) left->inorder();
        cout << data << " ";
        if (right) right->inorder();
    }

    void postorder() {
        if (this == nullptr)
            return;
        if (left) left->postorder();
        if (right) right->postorder();
        cout << data << " ";
    }
};

template <typename T>
myBinNOde<T> *create() {
    cout << "Enter value of node (x for no node): ";
    T data;
    cin >> data;
    if (data == 'x') return nullptr;

    myBinNOde<T> *root = new myBinNOde<T>(data);

    cout << "Enter left child info of " << data << "-->\n";
    root->set_left(create<T>());

    cout << "Enter right child info of " << data << "-->\n";
    root->set_right(create<T>());

    return root;
}

int main() {
    //FILE* in = freopen("in.txt","r",stdin);
    myBinNOde<char> *root = create<char>();
    cout << "Preorder Traversal: ";
    root->preorder();
    cout << endl;
    //fclose(in);
    return 0;
}
