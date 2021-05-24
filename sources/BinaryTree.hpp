#include <ostream>

using namespace std;
namespace ariel{
    template <typename T> class BinaryTree{
        
        private:
        struct Node{
            T value;
            Node* right;
            Node* left;
            Node(const T& v, Node* r , Node* l): value(v), right(r), left(l){}
        };
        
        Node* root;

        public:
        
        BinaryTree& add_root(const T& new_root){return *this;}
        BinaryTree& add_left(const T& exist_in_tree, const T& add_new_left_child){return *this;}
        BinaryTree& add_right(const T& exist_in_tree, const T& add_new_right_child){return *this;}

        /* print tree function */
        friend ostream& operator<<(ostream& out, BinaryTree const& b){
            return out;
        }

        //-------------------------------------------------------------------
        // iterator related code:
        // inner class and methods that return instances of it)
        //-------------------------------------------------------------------
        class iterator{

            private:
            Node* current_node;
            
            public:

            iterator(Node* pointer = nullptr): current_node(pointer){}
            
            T& operator*() const {
			//return *pointer_to_current_node;
			return current_node-> value;
		    }

            T* operator->() const {
                return &(current_node->value);
            }

            iterator& operator++() {
                return *this;
            }

            const iterator operator++(int) {
                iterator tmp= *this;
                // current_node= current_node->next;
                return tmp;
            }

            bool operator==(const iterator& rhs) const {
                return current_node == rhs.current_node;
            }

            bool operator!=(const iterator& rhs) const {
                return current_node != rhs.current_node;
            }
        
        };

        iterator begin_preorder() {
		// return &(m_first->m_value); 
		return iterator{root};
	    }
        iterator end_preorder() {
		// return nullptr; 
		    return iterator{root};
	    }
        iterator begin_inorder(){
            return iterator{root};
        }
        iterator end_inorder(){
            return iterator{root};
        }
        iterator begin_postorder(){
            return iterator{root};
        }
        iterator end_postorder(){
            return iterator{root};
        }

        iterator begin(){ return iterator{root};}
        iterator end() {return iterator{root};}
    };
    
}