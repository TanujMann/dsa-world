/*
 * ============================================================
 *  DSA & C++ Complete Project
 *  Covers: Arrays, Linked List, Stack, Queue, BST,
 *          Graph (BFS/DFS), Sorting, Searching, DP
 * ============================================================
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <string>
#include <functional>

using namespace std;

// ─────────────────────────────────────────────
//  COLOR HELPERS (terminal)
// ─────────────────────────────────────────────
#define RESET   "\033[0m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"
#define BOLD    "\033[1m"

void header(const string& title) {
    cout << "\n" << BOLD << CYAN
         << "══════════════════════════════════════\n"
         << "  " << title << "\n"
         << "══════════════════════════════════════" << RESET << "\n";
}

// ─────────────────────────────────────────────
//  1. SINGLY LINKED LIST
// ─────────────────────────────────────────────
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

class LinkedList {
    ListNode* head = nullptr;
public:
    void push_back(int v) {
        ListNode* node = new ListNode(v);
        if (!head) { head = node; return; }
        ListNode* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = node;
    }

    void push_front(int v) {
        ListNode* node = new ListNode(v);
        node->next = head;
        head = node;
    }

    void remove(int v) {
        if (!head) return;
        if (head->val == v) { ListNode* tmp = head; head = head->next; delete tmp; return; }
        ListNode* cur = head;
        while (cur->next && cur->next->val != v) cur = cur->next;
        if (cur->next) { ListNode* tmp = cur->next; cur->next = tmp->next; delete tmp; }
    }

    void reverse() {
        ListNode *prev = nullptr, *cur = head, *nxt = nullptr;
        while (cur) { nxt = cur->next; cur->next = prev; prev = cur; cur = nxt; }
        head = prev;
    }

    void print() const {
        ListNode* cur = head;
        cout << GREEN;
        while (cur) { cout << cur->val; if (cur->next) cout << " → "; cur = cur->next; }
        cout << RESET << "\n";
    }

    ~LinkedList() {
        while (head) { ListNode* tmp = head; head = head->next; delete tmp; }
    }
};

// ─────────────────────────────────────────────
//  2. STACK (using vector)
// ─────────────────────────────────────────────
template<typename T>
class Stack {
    vector<T> data;
public:
    void push(T v)      { data.push_back(v); }
    void pop()          { if (!data.empty()) data.pop_back(); }
    T    top()  const   { return data.back(); }
    bool empty() const  { return data.empty(); }
    int  size()  const  { return (int)data.size(); }
    void print() const {
        cout << GREEN << "Stack (top→bottom): ";
        for (int i = data.size()-1; i >= 0; --i) cout << data[i] << " ";
        cout << RESET << "\n";
    }
};

// Balanced parentheses checker using stack
bool isBalanced(const string& s) {
    stack<char> st;
    for (char c : s) {
        if (c=='(' || c=='{' || c=='[') st.push(c);
        else {
            if (st.empty()) return false;
            char top = st.top(); st.pop();
            if ((c==')' && top!='(') || (c=='}' && top!='{') || (c==']' && top!='['))
                return false;
        }
    }
    return st.empty();
}

// ─────────────────────────────────────────────
//  3. QUEUE
// ─────────────────────────────────────────────
template<typename T>
class Queue {
    deque<T> data;
public:
    void enqueue(T v)   { data.push_back(v); }
    void dequeue()      { if (!data.empty()) data.pop_front(); }
    T    front() const  { return data.front(); }
    bool empty() const  { return data.empty(); }
    int  size()  const  { return (int)data.size(); }
    void print() const {
        cout << GREEN << "Queue (front→back): ";
        for (auto& x : data) cout << x << " ";
        cout << RESET << "\n";
    }
};

// ─────────────────────────────────────────────
//  4. BINARY SEARCH TREE
// ─────────────────────────────────────────────
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class BST {
    TreeNode* root = nullptr;

    TreeNode* insert(TreeNode* node, int v) {
        if (!node) return new TreeNode(v);
        if (v < node->val) node->left  = insert(node->left,  v);
        else               node->right = insert(node->right, v);
        return node;
    }

    bool search(TreeNode* node, int v) const {
        if (!node) return false;
        if (node->val == v) return true;
        return v < node->val ? search(node->left, v) : search(node->right, v);
    }

    void inorder(TreeNode* node, vector<int>& out) const {
        if (!node) return;
        inorder(node->left, out);
        out.push_back(node->val);
        inorder(node->right, out);
    }

    int height(TreeNode* node) const {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    void destroy(TreeNode* node) {
        if (!node) return;
        destroy(node->left); destroy(node->right); delete node;
    }

public:
    void insert(int v)            { root = insert(root, v); }
    bool search(int v) const      { return search(root, v); }
    int  height()      const      { return height(root); }

    vector<int> inorderTraversal() const {
        vector<int> out; inorder(root, out); return out;
    }

    vector<int> levelOrder() const {
        vector<int> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            result.push_back(cur->val);
            if (cur->left)  q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return result;
    }

    ~BST() { destroy(root); }
};

// ─────────────────────────────────────────────
//  5. GRAPH — Adjacency List + BFS + DFS
// ─────────────────────────────────────────────
class Graph {
    int V;
    unordered_map<int, vector<int>> adj;
public:
    Graph(int v) : V(v) {}

    void addEdge(int u, int v, bool undirected = true) {
        adj[u].push_back(v);
        if (undirected) adj[v].push_back(u);
    }

    vector<int> bfs(int src) const {
        vector<int> visited;
        unordered_set<int> seen;
        queue<int> q;
        q.push(src); seen.insert(src);
        while (!q.empty()) {
            int node = q.front(); q.pop();
            visited.push_back(node);
            for (int nb : adj.at(node)) {
                if (!seen.count(nb)) { seen.insert(nb); q.push(nb); }
            }
        }
        return visited;
    }

    vector<int> dfs(int src) const {
        vector<int> visited;
        unordered_set<int> seen;
        function<void(int)> dfsHelper = [&](int node) {
            seen.insert(node);
            visited.push_back(node);
            if (adj.count(node))
                for (int nb : adj.at(node))
                    if (!seen.count(nb)) dfsHelper(nb);
        };
        dfsHelper(src);
        return visited;
    }
};

// ─────────────────────────────────────────────
//  6. SORTING ALGORITHMS
// ─────────────────────────────────────────────
void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n-1; ++i)
        for (int j = 0; j < n-1-i; ++j)
            if (a[j] > a[j+1]) swap(a[j], a[j+1]);
}

void selectionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n-1; ++i) {
        int minIdx = i;
        for (int j = i+1; j < n; ++j)
            if (a[j] < a[minIdx]) minIdx = j;
        swap(a[i], a[minIdx]);
    }
}

void insertionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; ++i) {
        int key = a[i], j = i-1;
        while (j >= 0 && a[j] > key) { a[j+1] = a[j]; --j; }
        a[j+1] = key;
    }
}

void merge(vector<int>& a, int l, int m, int r) {
    vector<int> left(a.begin()+l, a.begin()+m+1);
    vector<int> right(a.begin()+m+1, a.begin()+r+1);
    int i=0, j=0, k=l;
    while (i<(int)left.size() && j<(int)right.size())
        a[k++] = (left[i]<=right[j]) ? left[i++] : right[j++];
    while (i<(int)left.size())  a[k++] = left[i++];
    while (j<(int)right.size()) a[k++] = right[j++];
}

void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int m = l + (r-l)/2;
    mergeSort(a, l, m);
    mergeSort(a, m+1, r);
    merge(a, l, m, r);
}

int partition(vector<int>& a, int lo, int hi) {
    int pivot = a[hi], i = lo-1;
    for (int j = lo; j < hi; ++j)
        if (a[j] <= pivot) { ++i; swap(a[i], a[j]); }
    swap(a[i+1], a[hi]);
    return i+1;
}

void quickSort(vector<int>& a, int lo, int hi) {
    if (lo < hi) {
        int p = partition(a, lo, hi);
        quickSort(a, lo, p-1);
        quickSort(a, p+1, hi);
    }
}

// ─────────────────────────────────────────────
//  7. SEARCHING
// ─────────────────────────────────────────────
int linearSearch(const vector<int>& a, int target) {
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] == target) return i;
    return -1;
}

int binarySearch(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size()-1;
    while (lo <= hi) {
        int mid = lo + (hi-lo)/2;
        if (a[mid] == target) return mid;
        if (a[mid] < target)  lo = mid+1;
        else                  hi = mid-1;
    }
    return -1;
}

// ─────────────────────────────────────────────
//  8. DYNAMIC PROGRAMMING
// ─────────────────────────────────────────────

// 8a. Fibonacci (memoization)
unordered_map<int,long long> memo;
long long fib(int n) {
    if (n <= 1) return n;
    if (memo.count(n)) return memo[n];
    return memo[n] = fib(n-1) + fib(n-2);
}

// 8b. 0/1 Knapsack
int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for (int i = 1; i <= n; ++i)
        for (int w = 0; w <= W; ++w) {
            dp[i][w] = dp[i-1][w];
            if (wt[i-1] <= w)
                dp[i][w] = max(dp[i][w], dp[i-1][w-wt[i-1]] + val[i-1]);
        }
    return dp[n][W];
}

// 8c. Longest Common Subsequence
int lcs(const string& a, const string& b) {
    int m = a.size(), n = b.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = (a[i-1]==b[j-1]) ? dp[i-1][j-1]+1
                                          : max(dp[i-1][j], dp[i][j-1]);
    return dp[m][n];
}

// 8d. Coin Change (min coins)
int coinChange(const vector<int>& coins, int amount) {
    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i)
        for (int c : coins)
            if (c <= i && dp[i-c] != INT_MAX)
                dp[i] = min(dp[i], dp[i-c]+1);
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

// ─────────────────────────────────────────────
//  UTILITY: print vector
// ─────────────────────────────────────────────
void printVec(const vector<int>& v, const string& label = "") {
    if (!label.empty()) cout << YELLOW << label << ": " << RESET;
    cout << GREEN << "[ ";
    for (int x : v) cout << x << " ";
    cout << "]" << RESET << "\n";
}

// ─────────────────────────────────────────────
//  MAIN
// ─────────────────────────────────────────────
int main() {
    cout << BOLD << MAGENTA
         << "\n╔══════════════════════════════════════╗\n"
         << "║   DSA & C++ Complete Project Demo    ║\n"
         << "╚══════════════════════════════════════╝" << RESET << "\n";

    // ── Linked List ──────────────────────────
    header("1. SINGLY LINKED LIST");
    LinkedList ll;
    for (int v : {10, 20, 30, 40, 50}) ll.push_back(v);
    ll.push_front(5);
    cout << "After push_back(10..50), push_front(5):\n  "; ll.print();
    ll.remove(30);
    cout << "After remove(30):\n  "; ll.print();
    ll.reverse();
    cout << "After reverse:\n  "; ll.print();

    // ── Stack ────────────────────────────────
    header("2. STACK");
    Stack<int> st;
    for (int v : {1,2,3,4,5}) st.push(v);
    st.print();
    cout << GREEN << "Top: " << st.top() << RESET << "\n";
    st.pop(); cout << "After pop: "; st.print();

    cout << "\nBalanced Parentheses:\n";
    for (auto s : {"({[]})", "([)]", "{{}}", "((("}) {
        cout << "  " << YELLOW << s << RESET << " → "
             << (isBalanced(s) ? GREEN"✓ balanced" : "\033[31m✗ unbalanced")
             << RESET << "\n";
    }

    // ── Queue ────────────────────────────────
    header("3. QUEUE");
    Queue<int> q;
    for (int v : {100,200,300,400}) q.enqueue(v);
    q.print();
    q.dequeue(); cout << "After dequeue: "; q.print();

    // ── BST ──────────────────────────────────
    header("4. BINARY SEARCH TREE");
    BST bst;
    for (int v : {50,30,70,20,40,60,80}) bst.insert(v);
    printVec(bst.inorderTraversal(), "Inorder (sorted)");
    printVec(bst.levelOrder(),       "Level Order     ");
    cout << GREEN << "Height: " << bst.height() << RESET << "\n";
    cout << GREEN << "Search 40: " << (bst.search(40)?"found":"not found") << RESET << "\n";
    cout << GREEN << "Search 99: " << (bst.search(99)?"found":"not found") << RESET << "\n";

    // ── Graph ────────────────────────────────
    header("5. GRAPH — BFS & DFS");
    Graph g(6);
    g.addEdge(0,1); g.addEdge(0,2);
    g.addEdge(1,3); g.addEdge(1,4);
    g.addEdge(2,5);
    printVec(g.bfs(0), "BFS from 0");
    printVec(g.dfs(0), "DFS from 0");

    // ── Sorting ──────────────────────────────
    header("6. SORTING ALGORITHMS");
    vector<int> orig = {64,34,25,12,22,11,90};
    printVec(orig, "Original");

    auto run = [&](const string& name, function<void(vector<int>&)> fn) {
        vector<int> a = orig;
        fn(a);
        printVec(a, name);
    };

    run("Bubble Sort   ", bubbleSort);
    run("Selection Sort", selectionSort);
    run("Insertion Sort", insertionSort);
    run("Merge Sort    ", [](vector<int>& a){ mergeSort(a,0,(int)a.size()-1); });
    run("Quick Sort    ", [](vector<int>& a){ quickSort(a,0,(int)a.size()-1); });
    run("STL sort      ", [](vector<int>& a){ sort(a.begin(),a.end()); });

    // ── Searching ────────────────────────────
    header("7. SEARCHING");
    vector<int> arr = {2,5,8,12,16,23,38,56,72,91};
    printVec(arr, "Sorted Array");
    int target = 23;
    cout << GREEN << "Linear Search(" << target << "): index "
         << linearSearch(arr, target) << RESET << "\n";
    cout << GREEN << "Binary Search(" << target << "): index "
         << binarySearch(arr, target) << RESET << "\n";

    // ── Dynamic Programming ──────────────────
    header("8. DYNAMIC PROGRAMMING");

    cout << YELLOW << "Fibonacci:" << RESET << "\n  ";
    for (int i = 0; i <= 10; ++i) cout << GREEN << fib(i) << " " << RESET;
    cout << "\n";

    vector<int> weights = {1,3,4,5};
    vector<int> values  = {1,4,5,7};
    int capacity = 7;
    cout << YELLOW << "0/1 Knapsack (capacity=" << capacity << "):" << RESET
         << GREEN << " max value = " << knapsack(capacity,weights,values,4) << RESET << "\n";

    string s1 = "ABCBDAB", s2 = "BDCAB";
    cout << YELLOW << "LCS(\"" << s1 << "\", \"" << s2 << "\"):" << RESET
         << GREEN << " length = " << lcs(s1,s2) << RESET << "\n";

    vector<int> coins = {1,5,6,9};
    int amount = 11;
    cout << YELLOW << "Coin Change (coins={1,5,6,9}, amount=" << amount << "):" << RESET
         << GREEN << " min coins = " << coinChange(coins,amount) << RESET << "\n";

    cout << "\n" << BOLD << CYAN
         << "══════════════════════════════════════\n"
         << "  All demos completed successfully!   \n"
         << "══════════════════════════════════════" << RESET << "\n\n";

    return 0;
}
