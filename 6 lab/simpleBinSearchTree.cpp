#define _CRT_SECURE_NO_WARNINGS
#define strsize 20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct vertex
{
    long long val = 0;
    vertex * parent = nullptr;
    vertex * left = nullptr;
    vertex * right = nullptr;
} vertex;
 
int size = 0;
void delete_root(vertex * root);
void delete_vert(vertex * root, long long val);
 
void insert_vert(vertex * root, long long val) {
    if (size <= 0) {
        root->val = val;
        size = 1;
        return;
    }
    if (val < root->val && root->left == nullptr) {
        root->left = new vertex;
        root->left->val = val;
        root->left->parent = root;
        size++;
        return;
    }
    if (val > root->val && root->right == nullptr) {
        root->right = new vertex;
        root->right->val = val;
        root->right->parent = root;
        size++;
        return;
    }
 
    vertex * parent = nullptr;
    vertex * vert = root;
    while (vert != nullptr) {
        if (val < vert->val) {
            parent = vert;
            vert = vert->left;
        }
        else if (val > vert->val) {
            parent = vert;
            vert = vert->right;
        }
        else return;
    }
 
    vert = new vertex;
    vert->val = val;
    vert->parent = parent;
    if (val < parent->val)
        parent->left = vert;
    else parent->right = vert;
    size++;
}
bool exists_vert(vertex * root, long long val) {
    if (size <= 0)
        return false;
 
    if (val == root->val)
        return true;
 
    vertex * vert = root;
    while (vert != nullptr) {
        if (val < vert->val)
            vert = vert->left;
        else if (val > vert->val)
            vert = vert->right;
        else return true;
    }
 
    return false;
}
void delete_root(vertex * root) {
    vertex * vert = root;
    if (size <= 0)
        return;
 
    if (vert->left == nullptr && vert->right == nullptr) {
        size = 0;
        return;
    }
 
    if (size == 1) {
        size = 0;
        return;
    }
 
    if (vert->left != nullptr && vert->right != nullptr) {
        vertex * swap = vert->right;
        while (swap->left != nullptr)
            swap = swap->left;
 
        long long tmp = swap->val;
        delete_vert(root, swap->val);
        vert->val = tmp;
        return;
    }
    vertex * change;
    if (vert->left != nullptr)
        change = vert->left;
    else change = vert->right;
 
    *root = *change;
 
    if (change->left != NULL)
        change->left->parent = root;
    if (change->right != NULL)
        change->right->parent = root;
    size--;
    delete change;
}
void delete_vert(vertex * root, long long val) {
    if (size <= 0)
        return;
    if (root->val == val) {
        delete_root(root);
        return;
    }
 
    vertex * vert = root;
    while (vert != nullptr) {
        if (val < vert->val)
            vert = vert->left;
        else if (val > vert->val)
            vert = vert->right;
        else break;
    }
 
    if (vert == nullptr)
        return;
 
    if (vert->left == nullptr && vert->right == nullptr) {
        if (vert->parent->left == vert)
            vert->parent->left = nullptr;
        else vert->parent->right = nullptr;
        delete vert;
        size--;
    }
    else if (vert->left != nullptr && vert->right != nullptr) {
        vertex * swap = vert->right;
        while (swap->left != nullptr)
            swap = swap->left;
 
        long long tmp = swap->val;
        delete_vert(root, swap->val);
        vert->val = tmp;
    }
    else {
        vertex * change;
        if (vert->left != nullptr)
            change = vert->left;
        else change = vert->right;
 
        if (vert->parent->left == vert)
            vert->parent->left = change;
        else vert->parent->right = change;
        change->parent = vert->parent;
        delete vert;
        size--;
    }
}
vertex * next_vert(vertex * root, long long val) {
    if (size <= 0)
        return nullptr;
 
    if (size == 1) {
        if (val < root->val)
            return root;
        else return nullptr;
    }
 
    vertex * vert = root;
    while (vert != nullptr) {
        if (val < vert->val)
            if (vert->left != nullptr)
                vert = vert->left;
            else break;
        else if (val > vert->val)
            if (vert->right != nullptr)
                vert = vert->right;
            else break;
        else break;
    }
 
    if (vert == nullptr)
        return nullptr;
 
    if (val < vert->val)
        return vert;
 
    if (vert->right != nullptr) {
        vert = vert->right;
        while (vert->left != nullptr)
            vert = vert->left;
        return vert;
    }
 
    vertex * check = vert;
    vertex * parent = vert->parent;
    while (true)
    {
        if (parent == nullptr)
            return nullptr;
        else if (check == parent->right) {
            check = parent;
            parent = parent->parent;
        }
        else if (check == parent->left)
            return parent;
        else return nullptr;
    }
}
vertex * prev_vert(vertex * root, long long val) {
    if (size <= 0)
        return nullptr;
 
    if (size == 1) {
        if (val > root->val)
            return root;
        else return nullptr;
    }
 
    vertex * vert = root;
    while (vert != nullptr) {
        if (val < vert->val)
            if (vert->left != nullptr)
                vert = vert->left;
            else break;
        else if (val > vert->val)
            if (vert->right != nullptr)
                vert = vert->right;
            else break;
        else break;
    }
 
    if (vert == nullptr)
        return nullptr;
 
    if (val > vert->val)
        return vert;
 
    if (vert->left != nullptr) {
        vert = vert->left;
        while (vert->right != nullptr)
            vert = vert->right;
        return vert;
    }
 
    vertex * check = vert;
    vertex * parent = vert->parent;
    while (true)
    {
        if (parent == nullptr)
            return nullptr;
        else if (check == parent->left) {
            check = parent;
            parent = parent->parent;
        }
        else if (check == parent->right)
            return parent;
        else return nullptr;
    }
}
 
 
int main() {
    FILE * in = fopen("bstsimple.in", "r");
    FILE * out = fopen("bstsimple.out", "w");
 
    vertex root;
    char command[strsize];
    char arg[strsize];
    char * pEnd;
    long long val;
    vertex * check = nullptr;
 
    fscanf(in, "%s", command);
    fscanf(in, "%s", arg);
    val = strtoll(arg, &pEnd, 10);
 
    while (true) {
        if (strcmp(command, "insert") == 0)
            insert_vert(&root, val);
        else if (strcmp(command, "exists") == 0)
            if (exists_vert(&root, val))
                fprintf(out, "true\n");
            else fprintf(out, "false\n");
        else if (strcmp(command, "delete") == 0)
            delete_vert(&root, val);
        else if (strcmp(command, "next") == 0) {
            check = next_vert(&root, val);
            if (check != nullptr)
                fprintf(out, "%lld\n", check->val);
            else fprintf(out, "none\n");
        }
        else if (strcmp(command, "prev") == 0) {
            check = prev_vert(&root, val);
            if (check != nullptr)
                fprintf(out, "%lld\n", check->val);
            else fprintf(out, "none\n");
        }
 
        if (feof(in))
            break;
 
        strcpy(command, "");
        fscanf(in, "%s", command);
        fscanf(in, "%s", arg);
        val = strtoll(arg, &pEnd, 10);
    }
 
    fclose(in);
    fclose(out);
    return 0;
}