#include <unordered_map>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>

class Node {
    private:
        std::unordered_map<char, Node*> mchildren;
        bool is_complete_word;
        char mcontent;
    public:
        Node *find_child(char c);
        void set_complete(bool val) {
           if(val) {
               is_complete_word = true;
           } else {
               is_complete_word = false; 
           }
        }
        bool is_complete() { return is_complete_word; }
        void set_content(char c) { mcontent = c; }
        char content() { return mcontent; }
        void add_child(Node *n) { mchildren[n->content()] = n; }
        bool has_children() { return !mchildren.empty(); }
        Node() { 
            is_complete_word = false;
            mcontent = ' ';
        }
};

class Trie {
    private:
        Node *root;
    public:
        bool add_word(std::string &s);
        bool search_word(std::string &s);
        void delete_word(std::string &s);
        Trie();
};

Trie::Trie() {
    root = new Node();
}

bool delete_until(Node *node, std::string &s, size_t level) {
    if(node != NULL) {
        size_t len = s.size();
        if( level == len) {
            if(node->is_complete()) {
                node->set_complete(false);
                return !node->has_children();
            }
        } else {
            if(delete_until(node->find_child(s.at(level)), s, level + 1))
            {
                delete node->find_child(s.at(level));
                return ( !node->is_complete() && !node->has_children());
            }
        }
    }

    return false;
}
void Trie::delete_word(std::string &s) {

    Node *rt = root;
    size_t len = s.size();
    if(len > 0) {
        delete_until(rt, s, 0);
    }
    if( len == 0 ) {
        rt->set_complete(false);
    }
}


                
Node *Node::find_child(char c) {
    if(mchildren.find(c) != mchildren.end())
        return mchildren[c];
    return NULL;
}

bool Trie::add_word(std::string &s) {
    Node *current = root;
    if(s.length() == 0) {
        current->set_complete(true);
        return true;
    }
    for(size_t i = 0; i < s.length(); ++i) {
        Node *child = current->find_child(s[i]);
        if(child != NULL) { 
            std::cout << "child != NULL" << " word = " << s << std::endl;
            current = child; }
        else if (child == NULL) {
            std::cout << "child = NULL" << " word = " << s << std::endl;
        Node *tmp = new Node();
        if(!tmp) { return false; }
        tmp->set_content(s[i]);
        current->add_child(tmp);
        current = tmp;
        }
        if(i == s.length() - 1)
            if(current -> is_complete()) {
                std::cout << "already a word" << std::endl;
                return false;
            }
            current->set_complete(true);
    }
    return true;
}

bool Trie::search_word(std::string &s)
{
    Node* current = root;

    while ( current != NULL )
    {
        for ( size_t i = 0; i < s.length(); i++ )
        {
            Node* tmp = current->find_child(s[i]);
            if ( tmp == NULL )
                return false;
            current = tmp;
        }

        return current->is_complete();
    }

    return false;
}

int main() {

    Trie *t = new Trie();
    std::string tes = "tes";
    t->add_word(tes);
    std::string test = "test";
    t->add_word(test);
    std::string hello = "hello";
    t->add_word(hello);

    if(t->search_word(hello)) { std::cout << "found Hello" <<std::endl;}
    t->delete_word(hello);
    if(!t->search_word(hello)) { std::cout << "Hello gone" <<std::endl;}
    if(t->search_word(test)) { std::cout << "found test" <<std::endl;}
    t->delete_word(test);
    if(!t->search_word(test)) { std::cout << "test gone" <<std::endl;}
    return 0;
}
