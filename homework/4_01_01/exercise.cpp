#include <iostream>

template<typename T>
class Set {
  struct Node {
    T value;
    Node *left;
    Node *right;
    Node *parent;

    Node(const T &val) : value(val), left(nullptr), right(nullptr), parent(nullptr) {}
  };

  Node *root{};
  size_t size_{};

public:
  void insert(const T &value) {
    Node *newNode = new Node(value);

    if (!root) {
      root = newNode;
    } else {
      Node *current = root;
      Node *parent = nullptr;

      while (current) {
        parent = current;

        if (value < current->value) {
          current = current->left;
        } else if (current->value < value) {
          current = current->right;
        } else {
          delete newNode;
          return;
        }
      }

      newNode->parent = parent;
      if (value < parent->value) {
        parent->left = newNode;
      } else {
        parent->right = newNode;
      }
    }

    size_++;
  }

  void print_inorder() {
    inorderTraversal(root);
    std::cout << std::endl;
  }

private:
  void inorderTraversal(Node *node) {
    if (node) {
      inorderTraversal(node->left);
      std::cout << node->value << " ";
      inorderTraversal(node->right);
    }
  }
};


int main() {
    Set<int> st;
    st.insert(10);
    st.insert(-10);
    st.insert(20);
    st.insert(10);
    st.insert(0);
    st.print_inorder(); // Output: -10 0 10 20

    return 0;

}

